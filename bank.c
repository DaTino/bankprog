//bank.c
#include <stdio.h>

struct bank_account_list
{
    char first_name[100];
    char middle_ini;
    char last_name[100];
    int account_num;
    double account_balance;
};

int search_sa(FILE*, struct bank_account_list*, int);
void viewacct(struct bank_account_list*);
void newacct(struct bank_account_list*);
void withdraw(struct bank_account_list*);
void deposit(struct bank_account_list*);
void delacct(struct bank_account_list*);
void showall(struct bank_account_list*);

#define MAX_ACCOUNTS 50

int main() {


    int counter;
    FILE *fp;
    struct bank_account_list account[MAX_ACCOUNTS];
/*
//////////////////////INITIALIZE////////////////////////////////
    fp = fopen("bank.dat", "wb+");
    if (!fp) {
        printf("File open unsuccessful!\n");
        return 1;
    }
   
    for (counter = 0; counter < 50; counter++) {
        account[counter].first_name[0] = '\0';
        account[counter].middle_ini = ' ';
        account[counter].last_name[0] = '\0';
        account[counter].account_num = 0;
        account[counter].account_balance = 0.00;
    }
    
    fwrite(account, sizeof(struct bank_account_list), 50, fp);
    rewind(fp);
    fclose(fp);
///////////////////////////////////////////////////////////////
*/

    int anumlookup;
    int acctindex;

    int menu_selection = -1;
    while (menu_selection != 0) {

        printf("======================================================================\n");
        printf("Welcome to the interactive banking system. Please select an option:\n");
        printf("0. Exit\n");
        printf("1. Deposit\n");
        printf("2. Withdrawal\n");
        printf("3. Add account\n");
        printf("4. Remove account\n");
        printf("5. Balance inquiry\n");
        printf("6. View accounts\n");
        printf("======================================================================\n");
    
        scanf(" %d", &menu_selection);
        getchar();

        switch(menu_selection) {
            case 0:
                break;
            case 1:
                deposit(account);
                break;
            case 2:
                withdraw(account);
                break;
            case 3:
                newacct(account);
                break;
            case 4:
                delacct(account);
                break;
            case 5:
                viewacct(account);
                break;
            case 6:
                showall(account);
                break;
            default:
                printf("Incorrect selection. Try again.\n");
        }
    }

    return 0;

}

int search_sa(FILE* fp, struct bank_account_list account[50], int searchval) {

    int sindex = -1;
    int i;
    
    fread(account, sizeof(struct bank_account_list), 50, fp);
    
    for (i=0; i<50; i++) {
        if (account[i].account_num ==searchval) {
            sindex = i;
        }
    }

    rewind(fp);

    return sindex;
}

void viewacct(struct bank_account_list account[50]) {
    
    FILE* fp;
    fp = fopen("bank.dat", "rb");
    if (fp == NULL) {
        printf("File did not open!\n");
        return;
    }
    else {
        int choice;
        printf("Please enter your account: ");
        scanf(" %d", &choice);
        getchar();

        fread(account, sizeof(struct bank_account_list), 5, fp);
        int i=0;
        for(i=0; i<50; i++) {
            if(account[i].account_num == choice) {
                printf("%s", account[i].first_name);
                printf("%c\n", account[i].middle_ini);
                printf("%s", account[i].last_name);
                printf("%d\n", account[i].account_num);
                printf("%.2lf\n", account[i].account_balance);
            }
        }
    }

    rewind(fp);
    return;
}

void newacct(struct bank_account_list account[50]) {

    FILE* fp;
    fp = fopen("bank.dat", "rb+");
    if (fp == NULL) {
        printf("File did not open!\n");
        return;
    }
    else {
        int acctindex = search_sa(fp, account, 0);
        
        printf("First name: ");
        fgets(account[acctindex].first_name, 100, stdin);
        printf("Middle initial: ");
        scanf(" %c", &account[acctindex].middle_ini);
        getchar();
        printf("Last name: ");
        fgets(account[acctindex].last_name, 100, stdin);
        printf("Account number: ");
        scanf(" %d", &account[acctindex].account_num);
        getchar();
        printf("Account balance: ");
        scanf(" %lf", &account[acctindex].account_balance);
        getchar();

        fflush(stdin);
    }

    fwrite(account, sizeof(struct bank_account_list), 50, fp);
    rewind(fp);
    fclose(fp);

    return;
}

void showall(struct bank_account_list account[50]) {

    FILE* fp;
    fp = fopen("bank.dat", "rb");
    if ( fp == NULL) {
        printf("File did not open!\n");
        return;
    }
    else {
        int i = 0;
        fread(account, sizeof(struct bank_account_list), 50, fp);
        for (i = 0; i < 50; i++){
           if (account[i].account_num != 0) {
                printf("Account %d: \n", i);
                printf("First name: %s", account[i].first_name);
                printf("Middle initial: %c\n", account[i].middle_ini);
                printf("Last name: %s", account[i].last_name);
                printf("Account number: %d\n", account[i].account_num);
                printf("Account balance: %.2lf\n", account[i].account_balance);
            }
        }
    }

    rewind(fp);
    fclose(fp);

    return;
}

void deposit(struct bank_account_list account[50]) {

    FILE* fp;
    fp = fopen("bank.dat", "rb+");
    if ( fp == NULL) {
        printf("File did not open!\n");
        return;
    }
    else {
        int choice;
        printf("Please enter the account number: ");
        scanf(" %d", &choice);
        getchar();

        fread(account, sizeof(struct bank_account_list), 50, fp);
        int i=0;
        for (i=0; i<50; i++) {
            if (account[i].account_num == choice) {
                printf("Deposit amount: ");
                double depamt=0.00;
                scanf(" %lf", &depamt);
                getchar();
                account[i].account_balance += depamt;
            }
        }
    }
    rewind(fp);
    fwrite(account, sizeof(struct bank_account_list), 50, fp);
    rewind(fp);
    fclose(fp);
    return;
}

void withdraw(struct bank_account_list account[50]) {

    FILE* fp;
    fp = fopen("bank.dat", "rb");
    if ( fp == NULL) {
        printf("File did not open!\n");
        return;
    }
    else {
        int choice;
        printf("Please enter the account number: ");
        scanf(" %d", &choice);
        getchar();

        fread(account, sizeof(struct bank_account_list), 50, fp);
        int i=0;
        for (i=0; i<50; i++) {
            if (account[i].account_num == choice) {
                printf("Withdrawal amount: ");
                double wthamt = 0.00;
                scanf(" %lf", &wthamt);
                getchar();
                account[i].account_balance -= wthamt;
            }
        }
    }
    rewind(fp); 
    fwrite(account, sizeof(struct bank_account_list), 50, fp);
    rewind(fp);
    fclose(fp);
    return;
}

void delacct(struct bank_account_list account[50]) {
    
    FILE* fp;
    fp = fopen("bank.dat", "rb+");
    if (fp == NULL) {
        printf("File did not open!\n");
        return;
    }
    else {
        int choice;
        printf("Please enter your account: ");
        scanf(" %d", &choice);
        getchar();

        fread(account, sizeof(struct bank_account_list), 5, fp);
        int i=0;
        for(i=0; i<5; i++) {
            if(account[i].account_num == choice) {
                account[i].first_name[0] = '\0';
                account[i].middle_ini = '\0';
                account[i].last_name[0]  = '\0';
                account[i].account_num= 0;
                account[i].account_balance = 0.00;
            }
        }
    }
    
    fwrite(account, sizeof(struct bank_account_list), 50, fp);
    rewind(fp);
    fclose(fp);
    return;
}

