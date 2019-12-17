#include "../inc/uls.h"

void mx_loop_print(int argc,char **arr, char **argv) {
    int count = 0;
    int delim = 8;
    int i = 0;
    int win_width; 

    while (arr[count]) {
        i = 0;
        while(arr[count][i]){
            i++;
        }
        if(i >= delim) {
            delim = (i / 8) * 8 + 8;
        }
        count++;
    }
    i = 0;
    if(mx_find_flag(argc , argv, '1') == 1 || isatty(1) == 0){
        while (i < count - 1) {
            mx_print_dir(arr[i], -1);
            i++;
        }
        write(1, arr[i], mx_strlen(arr[i]));
        mx_printchar('\n');
    }
    else {
        win_width = mx_winsize();
        mx_print_dir_new_line(arr, delim, count, win_width);
   }
}

void mx_print_dir_new_line(char **arr, int delim, int count, int win_width) {
    int i;
    int y = 0;
    int e_line = win_width / delim;
    int e_col = 0;
    int k = 0;

    while (count % e_line != 0 && count % e_line != e_line - 1){
        if(count % e_line != 0 || count % e_line != e_line - 1){
            break;
        }
        e_line--;
    }
    e_col = (count / e_line);    
    if (count % e_line != 0 ) {
        e_col += 1;
    }
    while (y < e_col) {
        k = e_line;
        i = y;
        while (k != 1) {
            mx_print_dir(arr[i], delim);
            i += e_col;
            k--;
        }
        if(arr[i] != NULL){
        write(1, arr[i], mx_strlen(arr[i])); //without last space
        }
        mx_printchar('\n');
        y++;
    }
}
