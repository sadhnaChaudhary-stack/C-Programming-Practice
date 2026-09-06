#include <stdio.h>
void main()
{

  // Q1.Print numbers from 1 to 10.

  /*for(int i=1 ; i<=10 ; i++){
      printf("\ni : %d",i);
  }*/

  // Q.2 Print numbers from 10 to 1.

  /*for(int i=10 ; i>=1 ; i--){
    printf("\ni : %d",i);
  }*/

  // Q.3 Print numbers from 1 to 100.

  /*for(int i=1 ; i<=100 ; i++){
    printf("\ni = %d",i);
  }*/

  // Q.4 Print all even numbers from 1 to 100.

  /*for(int i=1 ;  i<=100 ; i++){
    if(i%2==0){
      printf("\ni : %d",i);
    }
  }*/

  // Q.5 Print all odd numbers from 1 to 100.

  /*for(int i=1 ; i<=100 ; i++){
    if(i%2!=0){
      printf("\ni : %d",i);
    }
  }*/

  // Q.6 Print numbers between two given numbers.
  // Suppose the user enters :

  //     Start = 5 End = 10

  //     Output :

      
  //     5 6 7 8 9 10 
      
      
     /* int a , b ;
      printf("Enter Starting Value : ");
      scanf("%d",&a);

      printf("Enter Ending Value : ");
      scanf("%d",&b);

      for(int i=a ; i<=b ; i++){
        printf("\n %d",i);
      }*/


      // Q.7 Print the first n natural numbers.
      /*int n ,i ;
      printf("Enter the Value of n : ");
      scanf("%d",&n);

      for(i=1 ; i<=n ; i++){
        printf("\n%d",i);
      }*/

      // Q.8 Print the first n even numbers.

      /*int n,i;
      printf("Enter Value of n : ");
      scanf("%d",&n);

      for(i=1 ; i<=n ; i++){
        if(i%2==0){
          printf("\n%d",i);
        }
      }*/


      // Q.9 Print the first n odd numbers.

      int n,i;
      printf("Enter Value for n : ");
      scanf("%d",&n);

      for(i=1 ; i<=n ; i++){
        if(i%2!=0){
          printf("\n%d",i);
        }
      }

}