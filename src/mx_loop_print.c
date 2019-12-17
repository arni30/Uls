#include "../inc/uls.h"

void mx_loop_print(int argc,char **arr) {
    int count = 0;
    int count_char = 0;
    int delim = 8;
    int i = 0;
    int win_width; 
    
    win_width = mx_winsize();

    while (arr[count]) {
        count_char = 0;
        while(arr[count][count_char]){
            count_char++;
        }
        if(count_char / 8 >= delim) {
            delim = (count_char / 8) + 1;
        }
        count++;
    }
    if(mx_find_flag(argc , arr, '1') == 1 || isatty(1) == 0){
        while (i < count - 1) {
            mx_print_dir(arr[i], -1);
            i++;
        }
        write(1, arr[i], mx_strlen(arr[i]));
        mx_printchar('\n');
    }
    else if (count <= win_width /delim) {
        while (i < count - 1) {
            mx_print_dir(arr[i], delim);// сделать под кол-во пробеловб если \n  delim = -1
            i++;
        }
         write(1, arr[i], mx_strlen(arr[i]));
         mx_printchar('\n');
    }
//     else {
//         mx_print_dir_new_line(arr, delim, count, win_width);
//         mx_printchar('\n');
//    }
}

void mx_print_dir_new_line(char **arr, int delim, int count, int win_width) {
    int i = 0; 
    
    while (i < count - 1) {
        if (i % 2 == 0){
            mx_print_dir(arr[i], delim);
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
