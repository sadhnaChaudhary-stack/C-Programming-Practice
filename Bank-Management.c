#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define FILE_NAME "accounts.dat"

struct Account
{
    int id;
    int account_number;
    char name[50];
    char phone[11];
    char pin[5];
    float balance;
};

/* Function Declarations */
void createAccount();
void viewAllAccounts();
void searchAccount();
void checkBalance();
void depositMoney();
void withdrawMoney();

int getNextAccountNumber();
int getNextId();

void pauseProgram();


int main()
{
    int choice;

    do
    {
        printf("\n====================================\n");
        printf("       BANK MANAGEMENT SYSTEM\n");
        printf("====================================\n");

        printf("1. Create Account\n");
        printf("2. View All Accounts\n");
        printf("3. Search Account\n");
        printf("4. Check Balance\n");
        printf("5. Deposit Money\n");
        printf("6. Withdraw Money\n");
        printf("7. Exit\n");

        printf("------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice)
        {
            case 1:
                createAccount();
                break;

            case 2:
                viewAllAccounts();
                break;

            case 3:
                searchAccount();
                break;

            case 4:
                checkBalance();
                break;

            case 5:
                depositMoney();
                break;

            case 6:
                withdrawMoney();
                break;

            case 7:
                printf("\n====================================\n");
                printf(" Thank you for using our bank system\n");
                printf("====================================\n");

                Sleep(2000);
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
                Sleep(2000);
        }

    } while(choice != 7);

    return 0;
}


/* =========================================
   PAUSE PROGRAM
   ========================================= */

void pauseProgram()
{
    printf("\nPlease wait...");
    Sleep(2000);
}


/* =========================================
   GET NEXT ACCOUNT NUMBER
   ========================================= */

int getNextAccountNumber()
{
    FILE *file;
    struct Account account;

    int lastAccountNumber = 100000;

    file = fopen(FILE_NAME, "rb");

    if(file == NULL)
    {
        return 100001;
    }

    while(fread(&account, sizeof(struct Account), 1, file))
    {
        if(account.account_number > lastAccountNumber)
        {
            lastAccountNumber = account.account_number;
        }
    }

    fclose(file);

    return lastAccountNumber + 1;
}


/* =========================================
   GET NEXT ID
   ========================================= */

int getNextId()
{
    FILE *file;
    struct Account account;

    int lastId = 0;

    file = fopen(FILE_NAME, "rb");

    if(file == NULL)
    {
        return 1;
    }

    while(fread(&account, sizeof(struct Account), 1, file))
    {
        if(account.id > lastId)
        {
            lastId = account.id;
        }
    }

    fclose(file);

    return lastId + 1;
}


/* =========================================
   CREATE ACCOUNT
   ========================================= */

void createAccount()
{
    FILE *file;
    struct Account account;

    account.id = getNextId();
    account.account_number = getNextAccountNumber();

    printf("\n====================================\n");
    printf("          CREATE ACCOUNT\n");
    printf("====================================\n");


    /* Name */

    printf("Enter your name: ");

    fgets(account.name, sizeof(account.name), stdin);

    account.name[strcspn(account.name, "\n")] = '\0';


    /* Phone Number */

    while(1)
    {
        printf("Enter your phone number: ");

        fgets(account.phone, sizeof(account.phone), stdin);

        account.phone[strcspn(account.phone, "\n")] = '\0';

        if(strlen(account.phone) == 10)
        {
            break;
        }

        printf("\nPhone number must contain exactly 10 digits.\n");
    }


    /* PIN */

    while(1)
    {
        printf("Create 4-digit PIN: ");

        fgets(account.pin, sizeof(account.pin), stdin);

        account.pin[strcspn(account.pin, "\n")] = '\0';

        if(strlen(account.pin) == 4)
        {
            break;
        }

        printf("\nPIN must contain exactly 4 digits.\n");
    }


    /* Initial Deposit */

    printf("Enter initial deposit: ");

    scanf("%f", &account.balance);

    getchar();


    /* Open File */

    file = fopen(FILE_NAME, "ab");

    if(file == NULL)
    {
        printf("\nError opening file!\n");

        pauseProgram();

        return;
    }


    /* Store Account */

    fwrite(&account, sizeof(struct Account), 1, file);

    fclose(file);


    /* Display Account Details */

    printf("\n====================================\n");
    printf("     ACCOUNT CREATED SUCCESSFULLY\n");
    printf("====================================\n");

    printf("ID             : %d\n", account.id);
    printf("Account Number : %d\n", account.account_number);
    printf("Name           : %s\n", account.name);
    printf("Phone          : %s\n", account.phone);
    printf("Balance        : %.2f\n", account.balance);


    pauseProgram();
}


/* =========================================
   VIEW ALL ACCOUNTS
   ========================================= */

void viewAllAccounts()
{
    FILE *file;
    struct Account account;

    int count = 0;

    file = fopen(FILE_NAME, "rb");

    if(file == NULL)
    {
        printf("\nNo accounts found.\n");

        pauseProgram();

        return;
    }


    printf("\n====================================\n");
    printf("           ALL ACCOUNTS\n");
    printf("====================================\n");


    while(fread(&account, sizeof(struct Account), 1, file))
    {
        printf("\n------------------------------------\n");

        printf("ID             : %d\n", account.id);
        printf("Account Number : %d\n", account.account_number);
        printf("Name           : %s\n", account.name);
        printf("Phone          : %s\n", account.phone);
        printf("Balance        : %.2f\n", account.balance);

        count++;
    }


    if(count == 0)
    {
        printf("\nNo accounts found.\n");
    }


    fclose(file);

    pauseProgram();
}


/* =========================================
   SEARCH ACCOUNT
   ========================================= */

void searchAccount()
{
    FILE *file;
    struct Account account;

    int accountNumber;
    int found = 0;


    file = fopen(FILE_NAME, "rb");

    if(file == NULL)
    {
        printf("\nNo accounts found.\n");

        pauseProgram();

        return;
    }


    printf("\nEnter Account Number: ");

    scanf("%d", &accountNumber);

    getchar();


    while(fread(&account, sizeof(struct Account), 1, file))
    {
        if(account.account_number == accountNumber)
        {
            printf("\n====================================\n");
            printf("          ACCOUNT FOUND\n");
            printf("====================================\n");

            printf("ID             : %d\n", account.id);
            printf("Account Number : %d\n", account.account_number);
            printf("Name           : %s\n", account.name);
            printf("Phone          : %s\n", account.phone);
            printf("Balance        : %.2f\n", account.balance);

            found = 1;

            break;
        }
    }


    if(found == 0)
    {
        printf("\nAccount not found.\n");
    }


    fclose(file);

    pauseProgram();
}


/* =========================================
   CHECK BALANCE
   ========================================= */

void checkBalance()
{
    FILE *file;
    struct Account account;

    int accountNumber;
    char pin[5];

    int found = 0;


    file = fopen(FILE_NAME, "rb");

    if(file == NULL)
    {
        printf("\nNo accounts found.\n");

        pauseProgram();

        return;
    }


    printf("\nEnter Account Number: ");

    scanf("%d", &accountNumber);

    getchar();


    printf("Enter PIN: ");

    fgets(pin, sizeof(pin), stdin);

    pin[strcspn(pin, "\n")] = '\0';


    while(fread(&account, sizeof(struct Account), 1, file))
    {
        if(account.account_number == accountNumber)
        {
            found = 1;


            if(strcmp(account.pin, pin) == 0)
            {
                printf("\n====================================\n");
                printf("          ACCOUNT BALANCE\n");
                printf("====================================\n");

                printf("Account Holder : %s\n", account.name);
                printf("Account Number : %d\n", account.account_number);
                printf("Current Balance: %.2f\n", account.balance);
            }
            else
            {
                printf("\nIncorrect PIN!\n");
            }

            break;
        }
    }


    if(found == 0)
    {
        printf("\nAccount not found.\n");
    }


    fclose(file);

    pauseProgram();
}


/* =========================================
   DEPOSIT MONEY
   ========================================= */

void depositMoney()
{
    FILE *file;
    struct Account account;

    int accountNumber;
    float amount;

    int found = 0;


    file = fopen(FILE_NAME, "r+b");

    if(file == NULL)
    {
        printf("\nNo accounts found.\n");

        pauseProgram();

        return;
    }


    printf("\nEnter Account Number: ");

    scanf("%d", &accountNumber);


    printf("Enter amount to deposit: ");

    scanf("%f", &amount);

    getchar();


    if(amount <= 0)
    {
        printf("\nInvalid amount.\n");

        fclose(file);

        pauseProgram();

        return;
    }


    while(fread(&account, sizeof(struct Account), 1, file))
    {
        if(account.account_number == accountNumber)
        {
            found = 1;


            /* Add money */

            account.balance = account.balance + amount;


            /*
                Move file pointer back
                to the current record.
            */

            fseek(
                file,
                -(long)sizeof(struct Account),
                SEEK_CUR
            );


            /* Update record */

            fwrite(
                &account,
                sizeof(struct Account),
                1,
                file
            );


            printf("\n====================================\n");
            printf("        DEPOSIT SUCCESSFUL\n");
            printf("====================================\n");

            printf("Deposited Amount : %.2f\n", amount);
            printf("New Balance      : %.2f\n", account.balance);

            break;
        }
    }


    if(found == 0)
    {
        printf("\nAccount not found.\n");
    }


    fclose(file);

    pauseProgram();
}


/* =========================================
   WITHDRAW MONEY
   ========================================= */

void withdrawMoney()
{
    FILE *file;
    struct Account account;

    int accountNumber;
    float amount;

    int found = 0;


    file = fopen(FILE_NAME, "r+b");

    if(file == NULL)
    {
        printf("\nNo accounts found.\n");

        pauseProgram();

        return;
    }


    printf("\nEnter Account Number: ");

    scanf("%d", &accountNumber);


    printf("Enter amount to withdraw: ");

    scanf("%f", &amount);

    getchar();


    if(amount <= 0)
    {
        printf("\nInvalid amount.\n");

        fclose(file);

        pauseProgram();

        return;
    }


    while(fread(&account, sizeof(struct Account), 1, file))
    {
        if(account.account_number == accountNumber)
        {
            found = 1;


            /* Check Balance */

            if(amount > account.balance)
            {
                printf("\n====================================\n");
                printf("       INSUFFICIENT BALANCE\n");
                printf("====================================\n");

                printf("Current Balance : %.2f\n", account.balance);
            }
            else
            {
                /* Subtract money */

                account.balance = account.balance - amount;


                /*
                    Move file pointer back
                    to the current record.
                */

                fseek(
                    file,
                    -(long)sizeof(struct Account),
                    SEEK_CUR
                );


                /* Update record */

                fwrite(
                    &account,
                    sizeof(struct Account),
                    1,
                    file
                );


                printf("\n====================================\n");
                printf("       WITHDRAWAL SUCCESSFUL\n");
                printf("====================================\n");

                printf("Withdrawn Amount : %.2f\n", amount);
                printf("Remaining Balance: %.2f\n", account.balance);
            }

            break;
        }
    }


    if(found == 0)
    {
        printf("\nAccount not found.\n");
    }


    fclose(file);

    pauseProgram();
}