#include "../inc/uls.h"

void mx_print_link_uid_gid_size(t_array *dir, int i, char flag) {
    int size = 0;
    int counter = 0; 

    mx_printint(dir->st[i]->st_nlink);
    mx_printstr(" ");
    if (flag == 0)
        mx_printstr(mx_uid_to_name(dir->st[i]->st_uid));
    if (flag == 0) {
        mx_printstr("  ");
        size = dir->st[i]->st_size;
        while (size > 0) {
            counter++;
            size /= 10;
        }
        mx_printint(dir->st[i]->st_gid);
        write(1, "       ", 7 - counter);
    }
    else if (flag == 'o') {
        size = dir->st[i]->st_size;
        while (size > 0) {
            counter++;
            size /= 10;
        }
        write(1, "       ", 7 - counter);
    }
    else if (flag == 'g') {
        size = dir->st[i]->st_size;
        while (size > 0) {
            counter++;
            size /= 10;
        }
        write(1, "       ", 7 - counter);
    }
    if (size == 0)
        counter = 1;
    mx_printint(dir->st[i]->st_size);
    mx_printstr(" ");
}
