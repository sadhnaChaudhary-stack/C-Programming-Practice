#include<stdio.h>
void main(){
  // Q.9 Declare an integer variable and print it.
  int a = 12;
  printf("%d",a);

  // Q.10 Store your age in a variable and print it.
  int age = 21;
  printf("\nMy age : %d",age);

  // Q.11 Store two numbers and print both.
  int i = 25 , j = 35;
  printf("\ni = %d , j = %d" , i,j);

  // Q.12 Create variables for name, age and percentage and display them.
  int age1 = 21 ;
  char name[] = "Sadhna Chaudhary";
  float per = 98.8;

  printf("\n Age : %d",age1);
  printf("\n Name : %s",name);
  printf("\n Percentage : %.2f",per);

  // Q.13 Swap two variables using a third variable.
  int b = 21 , c = 45 , d;
  printf("\nb : %d and c : %d",b,c);
  d=b;
  b=c;
  c=d;
  printf("\nb : %d and c : %d",b,c);


  // Q.14 Calculate the sum of two variables.
  int e = 5 , f = 98 , sum;
  sum = e+f;
  printf("\nSum : %d",sum);

  // Q.15 Calculate the average of three numbers.
  int g = 89 ,h = 65 , k = 99 , sum1 = 0;
  float avg = 0;

  sum1 = g+h+k;
  avg = sum1/3;

  printf("\nAvg : %.2f",avg);

  // Q.16 Store the length and width of a rectangle and calculate its area.
  int len = 45 , bre = 65 , area;

  area = len*bre;
  printf("\n area : %d",area);

  
}