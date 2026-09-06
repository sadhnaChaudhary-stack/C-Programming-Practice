#include<stdio.h>
int main(){

  // Q.20 Find the factorial of a number.
  int i , n ,fact=1;
  printf("Enter the value of n : ");
  scanf("%d",&n);

  for(i=n;i>1;i--){
    fact *= i;
  }

  printf("Factorial of %d : %d",n , fact);

  return 0;
}