#include<stdio.h>
int main(){
    int i, sum = 0, n= 500;
    for(i = 1;i <= n;++i){
       sum += i;
    }
    printf("The Sum of numbers from 1 to %d is %d\n",n,sum);
    return 0;
}
