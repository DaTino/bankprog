//bank.c
#include <stdio.h>
#define MAX_ACCOUNTS 50

struct account
{
    char *first_name;
    char middl_ini;
    char *last_name;
    int account_num;
    double account_balance;
};

int main() {

    /* the accounts will be an array of structs and the name of each struct will be
     * the account name. this will make searching easier.
     */

    int counter;
    FILE *fp;
    struct account my_account;

    fp = fopen("test.dat", "wb");
    if (!fp) {
        printf("File open unsuccessful!\n");
        return 1;
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
                printf("Thank you. Have a nice day.\n"
                break;
            case 1:
                /* Deposit: ask account number and amt to deposit. afterwards reports
                 * new value.if wrong number no changes are made
                 */
                break;
            case 2:
                /* Withdrawal: same as Deposit but takes money out.
                 */
                break;
            case 3:
                /* asks for info about new customer, then creates account for customer.
                 * if account number already in use, program complains and doesnt update.
                 */
                break;
            case 4:
                /* asks for account number. deletes account if it exits.
                 * if number doesn't exist, program reports this ant nothing changes.
                 */
                break;
            case 5:
                /* program asks for account number and prints out all info about account.
                 * if number doesnt exist, reports it and nothing changes.
                 */
                break;
            case 6:
                /* program reports all information about all acounts one by one.
                 */
                break;
            default:
                /* print that they didnt select a correct option and try again.
                 */
        }

    }

    return 0;

}
