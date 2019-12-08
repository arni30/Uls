#include "../inc/uls.h"

void mx_loop_print(char **arr, char *delim) {
    int count = 0;
    int i = 0;

    while (arr[count]) {
        count++;
    }
    while (i < count - 1) {
        mx_print_dir(arr[i], delim);
        i++;
    }
    write(1, arr[i], mx_strlen(arr[i]));
}
