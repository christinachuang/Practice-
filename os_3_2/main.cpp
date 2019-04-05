#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define threadss 1         //number of threads
#define total 10000055      //total number of iterations

/* generate a random number and makes it between 0 and 1*/
float randNumGen(){

   int random_value = rand();
   float unit_random = random_value / (float) RAND_MAX;
   return unit_random;
}

int main(int argc, char *argv[])
{

   int i;
   float x, y, pi;
   float z=0;
   //use openmp to parallel the generation of points and calculation
   #pragma omp parallel for private(x, y) reduction(+:z) num_threads(threadss)
      //to determine whether the point is in the circle
        for(i=0; i<total; ++i){
            //randomly generate a point
              x = randNumGen();
              y = randNumGen();
            if(sqrt((x*x)+(y*y))<=1.0){ //calculate the distance between the point and the origin point
                z++;        //indicate that the generated value is inside a unit circle
            }
        }
    pi=((float)z/(float)total)*4.0;     //estimate the value of pi
    printf("Value: %f\n", pi);
    return 0;
}
