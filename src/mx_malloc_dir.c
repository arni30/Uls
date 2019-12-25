#include "../inc/uls.h"

void mx_malloc_dir(t_array *dir) {
    dir->st = malloc(sizeof(struct stat *) * INT_MAX/144);//почистить для вызова a и A
    dir->type = malloc(sizeof(unsigned char) * UCHAR_MAX);
    dir->names = malloc(sizeof(char *) * INT_MAX/16);
}
