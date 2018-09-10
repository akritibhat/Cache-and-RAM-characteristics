#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>

int main() {
    int loop = 900000;
    int arr[900000];
    
    int i;
    double timeTaken;
    clock_t start;
    int stride=1;
    int sum=0;
    int misscount=0;
    double avg = 0;
    int t = 1;
 	
   	for(int i=0; i<loop; i++){
	start = clock();
        arr[i]=i;
	}

	for(int i=0; i<loop; i=i+stride){
	start = clock();

	sum= sum+ arr[i];
	arr[i]=sum;
	printf("\nelement: %d ,", arr[i]); 

	timeTaken = (double)(clock()-start)/CLOCKS_PER_SEC;
	timeTaken =  timeTaken*100000000;

	avg += (timeTaken-avg)/t;
	t++;
 

	if(timeTaken>100){
	printf("Time for read of %d: mem %d bytes : %.12f ", i , (i+1)*sizeof(arr[i]), timeTaken);
	printf("Time average %.9f \n", avg);
	
	if(misscount==0){
		misscount=i;
	}
	else  if(misscount==i-1){
		printf("***********************************************");
	}
	else{
	misscount=i;
	}
    	
	}
	}

	printf("\nTime average %.9f", avg);

}
