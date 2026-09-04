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