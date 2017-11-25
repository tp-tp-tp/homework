#include <stdio.h>
#include <omp.h>
#include <sys/time.h> // for gettimeofday()
//reduction
int main(){
    struct timeval start,end;
    gettimeofday(&start, NULL );
    int i,n,chunk;
    double a[100],b[100],result;
    //some initializations
    n=100;
    chunk=10;
    result=0.0;
    for(i=0;i<n;i++){
        a[i]=i*1.0;
        b[i]=i*2.0;
    }
#pragma omp parallel for default(shared)private(i)schedule(static,chunk)reduction(+:result)

    for(i=0;i<n;i++)
        result=result+(a[i]*b[i]);

    printf("%f\n",result);
gettimeofday(&end, NULL );
long timeuse =1000000 * ( end.tv_sec - start.tv_sec ) + end.tv_usec - start.tv_usec;
printf("time=%f\n",timeuse /1000000.0);
}
