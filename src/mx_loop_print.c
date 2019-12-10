#include "../inc/uls.h"

void mx_loop_print(char **arr, char *delim) {
    int count = 0;
    int i = 0;

    while (arr[count]) {
        count++;
    }
    if (count <= 7) {
        while (i < count - 1) {
            mx_print_dir(arr[i], delim);
            i++;
        }
        write(1, arr[i], mx_strlen(arr[i]));
    }
    else{
        while (i < count - 1) {
            if (i % 2 == 0){
                mx_print_dir(arr[i], delim);
            }
            i++;
        }
        if (i % 2 == 0) {
            write(1, arr[i], mx_strlen(arr[i]));
        }
        mx_printchar('\n');
        i = 0;
        while (i < count - 1) {
            if (i % 2 == 1){
                mx_print_dir(arr[i], delim);
            }
            i++;
        }
       if (i % 2 == 1) {
            write(1, arr[i], mx_strlen(arr[i]));
        }
    }
}
