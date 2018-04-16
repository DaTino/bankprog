//bank.c
#include <stdio.h>
#include "bankstruct.h"
#include "search_sa.h"

#define MAX_ACCOUNTS 50

int main() {
    /* the accounts will be an array of structs and the name of each struct will be
     * the account name. this will make searching easier.
     */
    int counter;
    FILE *fp;
    struct bank_account_list account[MAX_ACCOUNTS];
/*
    fp = fopen("bank.dat", "wb");
    if (!fp) {
        printf("File open unsuccessful!\n");
        return 1;
    }
    for (counter = 1; counter < 3; counter++) {
        printf("First name %d: ", counter);
        fgets(account[counter].first_name, 100, stdin);
        printf("Middle ini %d: ", counter);
        scanf(" %c", &account[counter].middle_ini);
        getchar();
        printf("Last name %d: ", counter);
        fgets(account[counter].last_name, 100, stdin);
        printf("acnt num %d: ", counter);
        scanf(" %d", &account[counter].account_num);
        getchar();
        printf("account balance %d: ", counter);
        scanf(" %lf", &account[counter].account_balance);
        getchar();  
        fflush(stdin);
     }
    fwrite(&account, sizeof(account), 1, fp);
    fclose(fp);
    */
///////////////////////////////////////
    fp = fopen("bank.dat", "rb+");
    if (!fp) {
        printf("File open unsuccessful!\n");
        return 1;
    }

     for (counter=1; counter < 4; counter++) {
         fread(&account, sizeof(account), 1, fp);
         printf("First name: %s", account[counter].first_name);
         printf("Middle ini: %c\n", account[counter].middle_ini);
         printf("Last name : %s", account[counter].last_name);
         printf("Acct num  : %d\n", account[counter].account_num);
         printf("Acct Balnc: %.2lf\n", account[counter].account_balance);
     }

    int anumlookup;
    int acctindex;
    printf("What account you want: ");
    scanf(" %d", &choice);
    acctindex = search_sa(fp, account, choice);
    if (choice == -1) {
        printf("Not found!\n");
    }
    else {
        printf("Found it, at index %d", saindex);
    }


    int choice;
    while (chioce != 0) {

        printf("Welcome to the interactive banking system. Please select and option:\n
                0. Exit\n
                1. Deposit\n
                2. Withdrawal\n
                3. Add account\n
                4. Remove account\n
                5. Balance inquiry\n
                6. View accounts\n
               " );
        choice = getchar();

        switch(choice) {
            
            case 0:
                printf("Thank you. Have a nice day.\n");
                break;
            case 1:
                /* Deposit: ask account number and amt to deposit. afterwards reports
                 * new value.if wrong number no changes are made
                 */
                
                printf("Please enter your account number: ");
                scanf(" %d", anumlookup);
                acctindex = search_sa(fp, account, choice);

                if (acctindex == -1) {
                    printf("Your account number was not found.\n");
                    break;
                 }
                else {
                    int depamt=0;
                    printf("Enter deposit amount: ");
                    scanf(" %d", depamt);
                    account[acctindex].account_balance += depamt;
                    fwrite(&account, sizeof(account), 1, fp);
                    printf("Your new balance is: %d", account[acctindex].account_balance);
                }
                break;
            case 2:
                 /* Withdrawal: same as Deposit but takes money out.
                 */

                printf("Please enter your account number: ");
                scanf(" %d", anumlookup);
                acctindex = search_sa(fp, account, choice);

                if (acctindex == -1) {
                    printf("Your account number was not found.\n");
                    break;
                }
                else {
                    int wthamt=0;
                    printf("Enter withdrawal amount: ");
                    scanf(" %d", wthamt);
                    account[acctindex].account_balance -= depamt;
                    fwrite(&account, sizeof(account), 1, fp);
                    printf("Your new balance is: %d", account[acctindex].amount_balance;
                }
                break;
            case 3:
                /* asks for info about new customer, then creates account for customer.
                 * if account number already in use, program complains and doesnt update.
                 */
                acctindex = search_sa(fp, account, 0);

                printf("First name %d: ", counter);
                fgets(account[acctindex].first_name, 100, stdin);
                printf("Middle ini %d: ", counter);
                scanf(" %c", &account[acctindex].middle_ini);
                getchar();
                printf("Last name %d: ", counter);
                fgets(account[acctindex].last_name, 100, stdin);
                printf("acnt num %d: ", counter);
                scanf(" %d", &account[acctindex].account_num);
                getchar();
                printf("account balance %d: ", counter);
                scanf(" %lf", &account[acctindex].account_balance);
                getchar();
                
                fflush(stdin);

                fwrite(&account, sizeof(account), 1, fp);

                break;
            case 4:
                 /* asks for account number. deletes account if it exits.
                 * if number doesn't exist, program reports this ant nothing changes.
                 */
                printf("Please enter your account number: ");
                scanf(" %d", anumlookup);
                acctindex = search_sa(fp, account, choice);

                if (acctindex == -1) {
                    printf("Your account number was not found.\n");
                    break;
                }
                else {
                    account[acctindex] = {" ", ' ', " ", 0, 0.00};
                }
                break;
            case 5:
                 /* program asks for account number and prints out all info about account.
                 * if number doesnt exist, reports it and nothing changes.
                 */
                printf("Please enter your account number: ");
                scanf(" %d", anumlookup);
                acctindex = search_sa(fp, account, choice);

                if (acctindex == -1) {
                    printf("Your account number was not found.\n");
                    break;
                }
                else {
                    fread(&account, sizeof(account), 1, fp);
                    printf("First name: %s", account[counter].first_name);
                    printf("Middle ini: %c\n", account[counter].middle_ini);
                    printf("Last name : %s", account[counter].last_name);
                    printf("Acct num  : %d\n", account[counter].account_num);
                    printf("Acct Balnc: %.2lf\n", account[counter].account_balance);
                }
                break;
            case 6:
                 /* program reports all information about all acounts one by one.
                 */
                for (counter=1; counter < 4; counter++) {
                    fread(&account, sizeof(account), 1, fp);
                    printf("First name: %s", account[counter].first_name);
                    printf("Middle ini: %c\n", account[counter].middle_ini);
                    printf("Last name : %s", account[counter].last_name);
                    printf("Acct num  : %d\n", account[counter].account_num);
                    printf("Acct Balnc: %.2lf\n", account[counter].account_balance);
                }
                break;
            default:
                 /* print that they didnt select a correct option and try again.
                 */
        }

    }


    fclose(fp);

    return 0;

}
