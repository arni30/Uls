#include "../inc/uls.h"

static void sort_dir_filesize(int count, t_array *dir) {
    struct stat *temp;

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (dir->st[j]->st_size > dir->st[i]->st_size) {
                mx_swaps_arr(dir->names, i, j);
                temp = dir->st[i];
                dir->st[i] = dir->st[j];
                dir->st[j] = temp;
                mx_swap_char((char*) &dir->type[i], (char*) &dir->type[j]);
            }
        }
    }
}

void mx_sort_dir(int count, t_array *dir) {
    struct stat *temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (mx_strcmp_ls(dir->names[i], dir->names[j]) > 0) {
                mx_swaps_arr(dir->names, i, j);
                temp = dir->st[i];
                dir->st[i] = dir->st[j];
                dir->st[j] = temp;
                mx_swap_char((char*) &dir->type[i], (char*) &dir->type[j]);
            }
        }
    }
}

void mx_sort(t_array *dir, int num_of_files, t_var *variable) {
    if (variable->flag_S == 1 && variable->flag_f == 0)
        sort_dir_filesize(num_of_files, dir);
    else if (variable->flag_f == 0)
        mx_sort_dir(num_of_files, dir);
    if (variable->flag_f == 0 && variable->flag_r == 1)
        mx_sort_dir_reverse(num_of_files, dir);
}

void mx_sort_ascii(int count, char **arr) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (mx_strcmp_ls(arr[i], arr[j]) > 0)
                mx_swaps_arr(arr, i, j);
        }
    }
}
