#include "../inc/uls.h"

void mx_sort_dir(int count, t_array *dir) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (mx_strcmp_ls(dir->names[i], dir->names[j]) > 0){
                mx_swaps_arr(dir->names, i, j);
                struct stat *temp = dir->st[i];
                dir->st[i] = dir->st[j];
                dir->st[j] = temp;
                mx_swap_char((char*)&dir->type[i], (char*)&dir->type[j]);
            }
        }
    }
//    dir->names = mx_realloc(dir->names, count * sizeof(char*));
//    dir->type = mx_realloc(dir->type, count * sizeof(unsigned char));
}
