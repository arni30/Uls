#include "../inc/uls.h"

void mx_sort_dir(char **dir, int count){
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (mx_strcmp(dir[i], dir[j]) > 0){
                mx_swaps_arr(dir, i, j);
            }
        }
    }
}

void mx_swaps_arr(char **arr, int i, int j) {
    char *temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
