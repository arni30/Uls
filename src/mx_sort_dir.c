#include "../inc/uls.h"

int mx_strcmp_ls(const char *s1, const char *s2){
    while (*s1 != '\0' || *s2 != '\0'){
        if (*s1 < 0) {
            return *s2 - (-1 * (*s1));
        }
        else if (*s2 < 0) {
            return -1 * (*s2) - *s1;
        }
        else {
            return *s1 - *s2;
        }
        s1++;
        s2++;
    }
    return 0;
}
void mx_sort_dir(char **name, int count, unsigned char *type) {
    for (int i = 0; i < count - 1; i++) {
        //printf("s= %s, %d\n", dir[i], *dir[i]);
        for (int j = i + 1; j < count; j++) {
            //printf("s= %s, %d\n", dir[i], *dir[i]);
            if (mx_strcmp_ls(name[i], name[j]) > 0){
                mx_swaps_arr(name, i, j);
                mx_swap_char((char*)&type[i], (char*)&type[j]);
            }
        }
    }
}
void mx_swaps_arr(char **arr, int i, int j) {
    char *temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
