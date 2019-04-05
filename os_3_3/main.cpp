#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define threadss 8          //number of threads
#define total 10000055      //total number of iterations
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;  //initialize the mutex lock
float tot_in=0;     //a global variance to record the total point number that in the circle

/* generate a random number and makes it between 0 and 1*/
float randNumGen(){
   int random_value = rand();
   float unit_random = random_value / (float) RAND_MAX;
   return unit_random;
}

/* execute a thread */
void *doCalcs(void *threadid)
{
   long longTid;
   longTid = (long)threadid;
   int tid = (int)longTid;       //obtain the integer value of thread id

   //using malloc for the return variable in order make sure that it is not destroyed once the thread call is finished
   float *in_count = (float *)malloc(sizeof(float));
   *in_count=0;

   //get the total number of iterations for a thread
   float tot_iterations= total/threadss;

   int counter=0;

   //to determine whether the point is in the circle
   for(counter=0;counter<tot_iterations;counter++){
      //randomly generate a point
      float x = randNumGen();
      float y = randNumGen();

      float result = sqrt((x*x) + (y*y));//calculate the distance between the point and the origin point

      if(result<1){
         *in_count+=1;         //indicate that the generated value is inside a unit circle
      }

   }

   //get the remaining iterations calculated by thread 0
   if(tid==0){
      float remainder = total%threadss;
      for(counter=0;counter<remainder;counter++){
      //randomly generate a point
      float x = randNumGen();
      float y = randNumGen();

      float result = sqrt((x*x) + (y*y)); //calculate the distance between the point and the origin point
    pthread_mutex_lock(&mutex); //use mutex lock to lock the region below so that once there is only one thread to enter and change the variance
      if(result<1){
         *in_count+=1;         //indicate that the generated value is inside a unit circle
      }
    pthread_mutex_unlock(&mutex); //release the lock so that other threads can enter the region now
   }
   }

   pthread_exit((void *)in_count);     //return the number of the points that inside the circle of the thread
}

int main(int argc, char *argv[])
{
   pthread_t threads[threadss];
   int rc;
   long t;
   void *status;
    //create threads
   for(t=0;t<threadss;t++){
     rc = pthread_create(&threads[t], NULL, doCalcs, (void *)t);
     if (rc){
       printf("ERROR, %d\n", rc);   //if error
       exit(-1);
       }
     }

   //join the threads
   for(t=0;t<threadss;t++){
      pthread_join(threads[t], &status);
      tot_in+=*(float*)status;           //add the value of points of each threads of the total in count

     }
    printf("Value for Pi is %f \n",1, 4*(tot_in/total));   //estimate the value of pi
    pthread_mutex_destroy(&mutex);  //destroy the mutex lock

   pthread_exit(NULL);  //exit the pthread
}
