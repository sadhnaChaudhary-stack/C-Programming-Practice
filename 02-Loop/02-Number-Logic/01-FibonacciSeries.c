// Q.17 Your program starts with a and b, calculates sum = a + b, then shifts the values:

// a  b  sum
// 0  1   1
// 1  1   2
// 1  2   3
// 2  3   5
// 3  5   8
// ...

#include<stdio.h>
#include<conio.h>
void main()
{
int a,b,c,sum;
clrscr();
printf("Emter value of a : ");
scanf("%d",&a);
printf("Enter value of b : ");
scanf("%d",&b);

for(int i=1;i<=10;i++){
sum = a+b;
printf("\n a = %d ",a);
printf("\n b = %d ",b);
printf("\nSum = %d",sum);

c=a;
a=b;
b=sum;

}
getch();
}