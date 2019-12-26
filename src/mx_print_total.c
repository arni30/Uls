#include "../inc/uls.h"

void mx_print_total(t_array *dir) {
    int count = 0;
    int i = 0;
    int total = 0;
    
    count = mx_count_arr_el(dir->names);
    while (i < count){
       total += dir->st[i]->st_blocks;
       i++;
    }
    mx_printstr("total ");
    mx_printint(total);
    mx_printchar('\n');
}
