//search_sa.c search struct array for value
#include <stdio.h>

int search_sa(FILE* fp, struct s, int searchval) {

    int sindex = -1;
    int i;
    for (i=0; i<50; i++) {

        fread(&s, sizeof(s), 1, fp);
        if (account[i].account_num == searchval) {
            sindex = i;
        }
    }

    return sindex;
}
