import numpy as np
import time
from numba import njit

MAX_STRIDE = 10
SEED = 86456

N = 100000
a = np.zeros(N*MAX_STRIDE, dtype=np.double);
np.random.seed(SEED)



for i_stride in range(1,MAX_STRIDE):
    mean = 0.0

    start=time.time()
    for i in range(0, N*i_stride, i_stride):
    	mean = mean + a[i];
    end=time.time()
    
    msec = (end-start) * 1000.0; # time in milli-second;
    rate = 8 * N * (1000.0 / msec) / (1024*1024);
    
    print(i_stride, mean, msec, rate)
    
    
    
# Code en C

# define int MAX_STRIDE 10;
#  define int SEED 86456;

int main(){
int N = 100000,i_stride,i;
double mean,start,end,rate,msec;
double*a;
a=(double*)malloc((N*MAX_STRIDE)*sizeof(double));    
for(i_stride=1;i_stride<MAX_STRIDE;i_stride++){
   mean=0;
   start=chock();
   printf("i_stride   mean    msec     rate"); 
    for(i=0;i<N*i_stride;i+=i_stride){
       mean=mean+a[i];
       end=chock();
       msec=(end-start)*1000.0;
      rate=sizeof(double)*N*(1000.0/msec)/(1024*1024);
     printf("%d  %f  %f   %f",i_stride, mean, msec, rate);
    }
    
}

}

