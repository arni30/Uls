#include "../inc/uls.h"

void mx_loop_print(int argc,char **arr) {
    int count = 0;
    int i = 0;
    int win_width; 
    char *delim = "                        ";
    
    win_width = mx_winsize();

    while (arr[count]) {
        count++;
    }
    if(mx_find_flag(argc , arr, '1') == 1 || isatty(1) == 0){
        while (i < count - 1) {
            mx_print_dir(arr[i], "\n");
            i++;
        }
        write(1, arr[i], mx_strlen(arr[i]));
        mx_printchar('\n');
    }
    else {//if (count <= win_width /16) {
        while (i < count - 1) {
            mx_print_dir(arr[i], delim);
            i++;
        }
         write(1, arr[i], mx_strlen(arr[i]));
         mx_printchar('\n');
    }
//     else {
//         mx_print_dir_new_line(arr, delim, count, i);
//         mx_printchar('\n');
//    }
}

void mx_print_dir_new_line(char **arr, char *delim, int count, int i) {
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
