#include <stdlib.h>
#include <stdio.h>
#include "mpi.h"
#include <time.h>
#include <math.h>
#include <sys/time.h>


#define N 100

MPI_Status status;

int m=3,n=3,p=3,q=3;
double a[N]= {1,2,2,3,7}, b[N]= {-1,6,7,-6,5};
//double a[]= {1,1}, b[2][4]= {{0,1,-1,-2},{-3,-2,0,1}},c[4];
double data,result;

int main(int argc, char **argv)
{
struct timeval start, end;
  int processCount, processId, slaveTaskCount, source, dest, rows, offset,n=0;

  //struct timeval start, stop;

// MPI environment is initialized
  MPI_Init(&argc, &argv);
// Each process gets unique ID (rank)
  MPI_Comm_rank(MPI_COMM_WORLD, &processId);
// Number of processes in communicator will be assigned to variable -> processCount
  MPI_Comm_size(MPI_COMM_WORLD, &processCount);


 gettimeofday(&start, NULL);
 
 data= (a[processId]-b[processId])*(a[processId]-b[processId]);
 MPI_Barrier(MPI_COMM_WORLD);
 MPI_Reduce(&data, &result,1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
 
 if (processId == 0) {
  
result=sqrt(result);
gettimeofday(&end, NULL);

 	printf("\nResult : %.2f\n\n",result);

	long seconds = (end.tv_sec - start.tv_sec);
    long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
    printf("The elapsed time is %ld seconds and %ld micros\n", seconds, micros);

      
  }
  

  MPI_Finalize();
}
