#include "../inc/uls.h"

void mx_print_total(t_array *dir, int num) {
    int i = 0;
    int total = 0;

    if (num > 0) {
        while (i < num) {
            total += dir->st[i]->st_blocks;
            i++;
        }
        mx_printstr("total ");
        mx_printint(total);
        mx_printchar('\n');
    }
}
