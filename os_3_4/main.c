#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

// constants
#define TRUE 1
#define FALSE 0
#define NUMBER_OF_CUSTOMERS 5
#define NUMBER_OF_RESOURCES 3

// method signatures
int bankers();
void printResources();
int init( char *,  char *, char *);
void updateNeed( int );
void *requestResource( void * );
int allocate( int, int * );

// the global variables required for the Banker's Algorithm
int Available[NUMBER_OF_RESOURCES];
int Allocation[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];
int Max[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES]
		={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
int Need[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];
int Finish[NUMBER_OF_CUSTOMERS];
int resources = NUMBER_OF_RESOURCES;
int processes = NUMBER_OF_CUSTOMERS;

// set up mutexes for threading
pthread_mutex_t mutexAvailable;
pthread_mutex_t mutexAllocation;
pthread_mutex_t mutexMax;
pthread_mutex_t mutexNeed;

int main(int argc, char *argv[]) {

	int i;				//loop index
	srand(time(NULL));	//set up random function

	// check that we provided an arguement
	if( argc < resources+1 ) {
		printf("Not though instances  for %d resources!\n", resources);
		return 1;
	}

	// set up variables
	init(argv[1], argv[2], argv[3]);
	pthread_t threads[processes];

	// initialize running to true for all processes
	for( i=0; i<processes; i++)
		Finish[i] = FALSE;

	// start the main loop
	int count = 0;
	int return_code;
	do {
		count = 0;
		// check the number of running processes
		for( i=0; i<processes; i++ ) {
			if( Finish[i] == FALSE ) {
				count++;
				return_code = pthread_create(&threads[i], NULL, requestResource, (void *)(long)i);
				if (return_code) {
					printf("ERROR; return code from pthread_create() is %d\n", return_code);
					exit(-1);
				}


			}

		}
	} while( count != 0 );
	// Wait for all processes finished
	for( i=0; i<processes; i++ )
		pthread_join(threads[i], NULL);

	// All processes succeed
	printf("\n = Success! =\n");
	printf("All processes finished without deadlock.\n");
	return 0;
}

int bankers() {
	int i,j;
	printf("\n    == Running Banker's Algorithm ==\n");

	// assume the state is unsafe
	int safe = FALSE;
	int count = 0;

	// set up Work array
	int *Work;
	if( !(Work = malloc( resources * sizeof( int ) ))){
		printf("Work malloc fail!\n");
		return -1;
	}

	// copy the Available array into the temporary array
	for( i=0; i<resources; i++ ) {
		if ( Available[i]<0 ){
			free(Work);
			return FALSE;
		}
		Work[i] = Available[i];
	}

	// Find an index i such that...
	for( i=0; i<processes; i++ ) {
		// ...Finish[i] == FALSE and...
		if( Finish[i] == FALSE ) {
			// ...Need[i] <= Work
			for( j=0; j<resources; j++ ) {
				if( Need[i][j] > Work[j] ) {
					printf("Result is: UNSAFE.\n");
					Finish[i] = FALSE;
					free(Work);
                    return safe;
				}
				Work[j] += Allocation[i][j];
				Finish[i] = TRUE;
			}
		}
	}

	//Check if Finish array is TRUE
	for( i=0; i<processes; i++ ){
		if( Finish[i]==TRUE)
			count++;
	}
	if( count == processes){
		safe=TRUE;
	}
	printf("Result is: %s.\n", safe ? "SAFE" : "UNSAFE");
	printResources();
	free(Work);
	return safe;
}

void printResources() {
	int i,j;
	printf("\n    == Current system resources ==\n");

	// print status of Available
	printf("\n  === Available ===\n");
	for( i=0; i<resources; i++ )
		printf("\tR%d", i);
	printf("\n");

	for( i=0; i<resources; i++ )
		printf("\t%d", Available[i]);

	// print status of Allocation
	printf("\n\n  === Allocation ===\n");
	for( i=0; i<resources; i++ )
		printf("\tR%d",i);
	printf("\n");

	for( i=0; i<processes; i++) {
			printf("P%d\t", i);
			for( j=0; j<resources; j++)
				printf("%d\t", Allocation[i][j]);
			printf("\n");
	}

	// print status of Max
	printf("\n  === Max ===\n");
	for( i=0; i<resources; i++ )
		printf("\tR%d", i);
	printf("\n");

	for( i=0; i<processes; i++) {
			printf("P%d\t", i);
			for( j=0; j<resources; j++)
				printf("%d\t", Max[i][j]);
			printf("\n");
	}

	// print status of Need
	printf("\n  === Need ===\n");
	for( i=0; i<resources; i++ )
		printf("\tR%d", i);
	printf("\n");

	for( i=0; i<processes; i++) {
			printf("P%d\t", i);
			for( j=0; j<resources; j++)
				printf("%d\t", Need[i][j]);
			printf("\n");
	}

}

int init( char *fir, char *sec, char *thr ) {

	int i, j;

	//Initial Available array
	Available[0] = atoi(fir);
	Available[1] = atoi(sec);
	Available[2] = atoi(thr);
	// set up Allocation array (2D)
	for(i=0; i<processes; i++)
		for(j=0; j<resources; j++)
			Allocation[i][j]=0;

	// fill in Need array for each process
	for(i=0; i<processes; i++)
		updateNeed(i);
	return 0;
}
//to update the Need matrix
void updateNeed(int process) {
	int i;	//loop index
	for( i=0; i<resources; i++ ){
		Need[process][i] = Max[process][i] - Allocation[process][i];
	}
}

void *requestResource( void *proc ) {
	int i,j;

  	// Assume the interval between processes
	sleep(1+rand()%10);
	int Request[resources];
	int process = (int)(long)proc;

	// generate a random request vector
	for(i=0; i<resources; i++) {
		if (Need[process][i]!=0){
			Request[i] = rand() % Need[process][i];
			//request have to > Need & Available matrix
			while(Request[i]>Need[process][i] || Request[i]>Available[i]){
                Request[i] = rand() % Need[process][i];
			}
		}
		else
			Request[i] = 0;
	}
  	// allocate the resource to the process
	if( allocate( process, Request) == TRUE ) {
		printf("Approved.\n");
        if(checkCompletion(process)==TRUE){
            printf("\nProcess %d has completed\n", process);
        }
		//Assume working time
		sleep(1+rand() % 10);
	}
	else {
		printf("Denied.\n");
		//wait
		sleep(1+rand()%10);
	}
  	// exit the thread
	pthread_exit(NULL);

}

int allocate(int process, int *Request) {

	int i;	//loop index

	// banker's algorithm (assume)
	for(i=0; i<resources; i++) {
		pthread_mutex_lock( &mutexAllocation );
		Allocation[process][i] += Request[i];
		pthread_mutex_unlock( &mutexAllocation );
		pthread_mutex_lock( &mutexAvailable );
		Available[i] -= Request[i];
		pthread_mutex_unlock( &mutexAvailable );
		pthread_mutex_lock( &mutexNeed );
		Need[process][i] -= Request[i];
		pthread_mutex_unlock( &mutexNeed );

	}
	//safety algorithm is false, release request
	if( bankers() == FALSE) {
		for(i=0; i<resources; i++) {
			pthread_mutex_lock( &mutexAllocation );
			Allocation[process][i] -= Request[i];
			pthread_mutex_unlock( &mutexAllocation );
			pthread_mutex_lock( &mutexAvailable );
			Available[i] += Request[i];
			pthread_mutex_unlock( &mutexAvailable );
			pthread_mutex_lock( &mutexNeed );
			Need[process][i] += Request[i];
			pthread_mutex_unlock( &mutexNeed );
		}
		return FALSE;
	}
	return TRUE;
}
//to check whether the process is finished
int checkCompletion(int process){
    int i, n;
    for(i=0; i<resources; i++){
        if(!(Allocation[process][i]==Max[process][i]))
            return FALSE;
    }
    if(i==resources-1){
        for(n=0; n<resources; n++){
            Available[n] += Max[process][n];
        }
        Finish[process]=TRUE;
    }
        	//Check if Finish array is TRUE
        return TRUE;
}
