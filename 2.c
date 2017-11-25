#include <stdio.h>
#include <omp.h>
#include <sys/time.h> // for gettimeofday()
void main()
{
  struct timeval start,end;
    gettimeofday(&start, NULL );
 int i,j,sum=0;
#pragma omp parallel for private(j) num_threads(8)
    for(i=2;i<1000000;i++)
{
    for(j=2;j<i;j++)
{
    if(i%j==0)break;
}
  if(i==j)
{
      sum+=1;
}
}
  printf("����Ϊ��%d\n",sum);
gettimeofday(&end, NULL );
long timeuse =1000000 * ( end.tv_sec - start.tv_sec ) + end.tv_usec - start.tv_usec;
printf("time=%f\n",timeuse /1000000.0);
}
