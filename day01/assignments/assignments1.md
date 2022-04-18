### Exercise 1:

- Implement C or Fortran version for the code below

```python
do i =1 , N * i_stride , i_stride
   mean = mean + a ( i )
end do
```
 
    
# Code en C

define int MAX_STRIDE 10;
define int SEED 86456;

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



- Compute the cpu time and bandwith for different stride (1 to 20) and plot the results
- We compile the above Fortran code with all optimization and vectorization disabled (-O0) and we run it for different strides
- We do the same thing, with (-O2) that activates some optimizations
- What is the conclusion?

- Expected output (Not necessary the same result):

![](../data/strides_cputime.png)

![](../data/strides_bandwidth.png)


### Exercise 2:

- Implement the MxM multiplication using the block version
- Naive version:
```fortran
program main
implicit none
integer, parameter :: N = 1000
integer, parameter :: SIZE_OF = 8 ! for double precision
integer,parameter :: SEED = 86456
real(8), dimension(N,N) :: x,y,z,tx
integer :: i,j,k
real(8) :: msec, rate
real(8) :: start, finish

call srand(SEED)

z(:,:) = 0.0
do i=1, N
  do j=1, N
    x(i,j) = rand() + 1.0
    y(i,j) = rand() + 1.0
  end do
end do

! .......................................................
do i=1, N
  do j=1, N
    do k=1, N
      z(i,j) = z(i,j) + x(i,k) * y(k,j)  
    end do
  end do
end do

```
- Compute the cpu time and bandwith for different block size, which block size is the optimal one ? Why ?

- Expected output (Not necessary the same result):

![](../data/mxm_block_cputime.png)

![](../data/mxm_block_bandwidth.png)

