#include "../inc/uls.h"

char *mx_strrchr(char *str, int ch) {
    char *temp = NULL;
    int i = 0;
    int  index = 0;

    while (str[i]) {
        if (str[i] == ch) {
            index = i;
        }
        i++;
    }
    temp = mx_strnew(mx_strlen(str) - index - 1);
    for (int j = index + 1, k = 0; str[j]; j++, k++)
        temp[k] = str[j];
    return temp;
}

void mx_sort_dir_reverse(int count, t_array *dir) {
    struct stat *temp = NULL;

    for (int i = 0, j = count - 1; i < count / 2; i++, j--) {
        mx_swaps_arr(dir->names, i, j);
        temp = dir->st[i];
        dir->st[i] = dir->st[j];
        dir->st[j] = temp;
        mx_swap_char((char*) &dir->type[i], (char*) &dir->type[j]);
    }
}

void mx_sort_reverse(int count, char **arr) {
    for (int i = 0, j = count - 1; i < count / 2; i++, j--) {
        mx_swaps_arr(arr, i, j);
    }
}
