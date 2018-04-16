//search_sa.c search struct array for value
#include <stdio.h>
#include "bankstruct.h"
#include "search_sa.h"

int search_sa(FILE* fp, struct bank_account_list account[50], int searchval) {

    int sindex = -1;
    int i;
    for (i=0; i<50; i++) {

        fread(&account, sizeof(account), 1, fp);
        if (account[i].account_num == searchval) {
            sindex = i;
        }
    }

    return sindex;
}
