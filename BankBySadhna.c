#include <stdio.h>
#include <string.h>

struct Account
{
  int id;
  int accountNumber;
  char name[40];
  char phone[20];
  char pin[5];
  int intitalDeposit;
};

int tempId = 1;
int tempAccountNumber = 101;

void createAccount();
void viewAccount(int);

int main()
{
  int i;

  do
  {
    printf("\n------Welcome-------");
    printf("\n1.Create Account");
    printf("\n2.Check Balance");
    printf("\n3.Deposit");
    printf("\n4.Withdrawl");
    printf("\n5.View Account");

    printf("\n \nEnter Your Choice : ");
    scanf("%d", &i);

    switch (i)
    {
    case 1:
      createAccount();
      break;
    case 5:
      int checkAccount;
      printf("\nEnter Your Account Number : ");
      scanf("%d", &checkAccount);
      viewAccount(checkAccount);
      break;
    default:
      printf("invalid input");
    }
  } while (i < 100);

  // return 0;
  return 0;
}

void createAccount()
{

  struct Account account;
  char tempNumber[11];
  char tempPin[5];

  printf("Enter your Name :");
  scanf("%s", account.name);
  printf("Enter your phone :");
  scanf("%s", account.phone);
  if (strlen(account.phone) != 10)
  {
    printf("Invalid Phone Number");
    printf("\nEnter Correct phone Number :");

    scanf("%s", tempNumber);

    strcpy(account.phone, tempNumber);
  }

  printf("Generate pin :");
  scanf("%s", account.pin);
  if (strlen(account.pin) != 4)
  {
    printf("\nIncorrect pin");
    printf("\nEnter a 4 digit Pin : ");
    scanf("%s", tempPin);
    strcpy(account.pin, tempPin);
  }
  printf("Enter your inital deposit :");
  scanf("%d", &account.intitalDeposit);

  account.id = tempId;
  tempId++;

  account.accountNumber = tempAccountNumber;
  tempAccountNumber++;

  FILE *fp;
  fp = fopen("accountDetail", "a");

  fprintf(fp, "%d %d %s %s %s %d\n",
          account.id,
          account.accountNumber,
          account.name,
          account.phone,
          account.pin,
          account.intitalDeposit);

  fclose(fp);

  printf("\nAccount created Sucessfully!");
  printf("\n your Account Details");

  viewAccount(account.accountNumber);
}

void viewAccount(int checkAccount)
{
  FILE *fp;
  struct Account account;

  fp = fopen("accountDetail", "r");

  while (fscanf(fp, "%d %d %s %s %s %d",
                &account.id,
                &account.accountNumber,
                account.name,
                account.phone,
                account.pin,
                &account.intitalDeposit) == 6)
  {
    if (account.accountNumber == checkAccount)
    {
      printf("\nAccount Number: %d", account.accountNumber);
      printf("\nAccount Holder Name : %s", account.name);
      printf("\nAccount Phone: %s", account.phone);
      printf("\nAccount pin: %s", account.pin);
      printf("\nAccount balance: %d", account.intitalDeposit);
    }
  }
}