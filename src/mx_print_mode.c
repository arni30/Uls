#include "../inc/uls.h"


void mx_print_mode(t_array *dir, int i, char *position, int num_of_files) {
    char *str = mx_strnew(10 * sizeof(char) + 1);
    char curentFile[PATH_MAX + 1];
    int flag = 0;
    int size = dir->st[i]->st_nlink;
    int counter = 0;

    mx_strcpy(curentFile, position);
    mx_strcat( curentFile, "/");
    mx_strcat( curentFile, dir->names[i]);
    mx_strcpy(str,"---------- ");
    mx_license_if(dir->st[i]->st_mode,str);
    flag = mx_acl_attr_if(dir->st[i]->st_mode, str, curentFile);
    mx_printstr(str);
    if (size == 0) {
        counter = 1;
    }
    while (size > 0) {
        counter++;
        size /= 10;
    }
    write(1, "                 ", mx_count_max_sym(dir, 'l', num_of_files) + 1 - counter);
    free(str);
}

