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

    fp = fopen("bank.dat", "rb+");
    if (!fp) {
        printf("File open unsuccessful!\n");
        return 1;
    }
/*
    for (counter = 0; counter < 50; counter++) {
        account[counter].first_name[0] = '\0';
        account[counter].middle_ini = ' ';
        account[counter].last_name[0] = '\0';
        account[counter].account_num = 0;
        account[counter].account_balance = 0.00;
        fseek(fp, sizeof(account)*counter, SEEK_SET);
        fwrite(&account, sizeof(account), 1, fp);
    }

*/
///////////////////////////////////////
/*    fp = fopen("bank.dat", "rb+");
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

*/

    int anumlookup;
    int acctindex;

    int choice = -1;
    while (choice != 0) {

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
        scanf(" %d", &choice);
        getchar();

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
                acctindex = search_sa(fp, account, anumlookup);

                if (acctindex == -1) {
                    printf("Your account number was not found.\n");
                    break;
                 }
                else {
                    fseek(fp, sizeof(account)*acctindex, SEEK_SET);
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
                acctindex = search_sa(fp, account, anumlookup);

                if (acctindex == -1) {
                    printf("Your account number was not found.\n");
                    break;
                }
                else {
                    fseek(fp, sizeof(account)*acctindex, SEEK_SET);
                    int wthamt=0;
                    printf("Enter withdrawal amount: ");
                    scanf(" %d", wthamt);
                    account[acctindex].account_balance -= wthamt;
                    fwrite(&account, sizeof(account), 1, fp);
                    printf("Your new balance is: %d", account[acctindex].account_balance);
                }
                break;
            case 3:
                /* asks for info about new customer, then creates account for customer.
                 * if account number already in use, program complains and doesnt update.
                 */
                acctindex = search_sa(fp, account, 0);
                fseek(fp, sizeof(account)*acctindex, SEEK_SET);

                printf("First name %d: ", acctindex);
                fgets(account[acctindex].first_name, 100, stdin);
                printf("Middle ini %d: ", acctindex);
                scanf(" %c", &account[acctindex].middle_ini);
                getchar();
                printf("Last name %d: ", acctindex);
                fgets(account[acctindex].last_name, 100, stdin);
                printf("acnt num %d: ", acctindex);
                scanf(" %d", &account[acctindex].account_num);
                getchar();
                printf("account balance %d: ", acctindex);
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
                acctindex = search_sa(fp, account, anumlookup);

                if (acctindex == -1) {
                    printf("Your account number was not found.\n");
                    break;
                }
                else {
                    fseek(fp, sizeof(account)*acctindex, SEEK_SET);
                    account[acctindex].first_name[0]    = '\0';
                    account[acctindex].middle_ini       = ' ';
                    account[acctindex].last_name[0]     = '\0';
                    account[acctindex].account_num      = 0;
                    account[acctindex].account_balance  = 0.00;

                }
                break;
            case 5:
                 /* program asks for account number and prints out all info about account.
                 * if number doesnt exist, reports it and nothing changes.
                 */
                fseek(fp, sizeof(account)*0, SEEK_SET);
                printf("Please enter your account number: ");
                scanf(" %d", anumlookup);
                getchar();
                acctindex = search_sa(fp, account, anumlookup);
                
                printf("tits");

                if (acctindex == -1) {
                    printf("Your account number was not found.\n");
                    break;
                }
                else {
                    fseek(fp, sizeof(account)*acctindex, SEEK_SET);
                    fread(&account, sizeof(account), 1, fp);
                    printf("First name: %s", account[acctindex].first_name);
                    printf("Middle ini: %c\n", account[acctindex].middle_ini);
                    printf("Last name : %s", account[acctindex].last_name);
                    printf("Acct num  : %d\n", account[acctindex].account_num);
                    printf("Acct Balnc: %.2lf\n", account[acctindex].account_balance);
                }
                break;
            case 6:
                 /* program reports all information about all acounts one by one.
                 */
                for (acctindex=1; acctindex < 50; acctindex++) {
                    fread(&account, sizeof(account), 1, fp);
                    if (account[acctindex].account_num != 0) {
                        printf("First name: %s", account[acctindex].first_name);
                        printf("Middle ini: %c\n", account[acctindex].middle_ini);
                        printf("Last name : %s", account[acctindex].last_name);
                        printf("Acct num  : %d\n", account[acctindex].account_num);
                        printf("Acct Balnc: %.2lf\n", account[acctindex].account_balance);
                    }
                }
                break;
            default:
                 /* print that they didnt select a correct option and try again.
                 */
                 printf("Whoa! Something didn't go right.\n");
        }

    }


    fclose(fp);

    return 0;

}
