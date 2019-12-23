#include "../inc/uls.h"

int mx_strcmp_ls(const char *s1_, const char *s2_){
    const unsigned char *s1 = (const unsigned char*) s1_;
    const unsigned char *s2 = (const unsigned char*) s2_;
    while (*s1 != '\0' || *s2 != '\0'){
        if(*s1 != *s2){
            return *s1 - *s2;
        }
        s1++;
        s2++;
    }
    return 0;
}

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
}
void mx_swaps_arr(char **arr, int i, int j) {
    char *temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
