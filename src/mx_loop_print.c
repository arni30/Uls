#include "../inc/uls.h"

void mx_loop_print(int argc,char **arr) {
    int count = 0;
    int delim = 8;
    int i = 0;
    int win_width; 
    
    win_width = mx_winsize();

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
            mx_print_dir(arr[i], delim);
            i++;
        }
         write(1, arr[i], mx_strlen(arr[i]));
         mx_printchar('\n');
    }
    else {
        mx_print_dir_new_line(arr, delim, count, win_width);
        mx_printchar('\n');
   }
}

void mx_print_dir_new_line(char **arr, int delim, int count, int win_width) {
    int i;
    int y = 0;
    int e_line = win_width / delim;
    int e_col = (count / e_line);

    if (win_width % delim != 0 && win_width % delim != e_line - 1) {
        i = e_line;
        
    }
    if (count % e_line != 0 ) {
        e_col += 1;
    }
    printf("ec= %d\nel=%d\n",e_col, e_line);

    while (y < e_col) {
        if (y == e_col - 1 && count % e_line != 0) {
            e_line = count % e_line;
        }
        i = y;
        while (e_line != 1) {
            mx_print_dir(arr[i], delim);
            i += e_col;
            e_line--;
        }
        write(1, arr[i], mx_strlen(arr[i])); //without last space
        mx_printchar('\n');
        y++;
    }
    // if (i % 2 == 0){
    //         mx_print_dir(arr[i], delim);
    //     }
    //         i++;
    //     }
    //     if (i % 2 == 0) {
    //         write(1, arr[i], mx_strlen(arr[i]));
    //     }
    //     mx_printchar('\n');
    //     i = 0;
    //     while (i < count - 1) {
    //         if (i % 2 == 1){
    //             mx_print_dir(arr[i], delim);
    //         }
    //         i++;
    //     }
    //    if (i % 2 == 1) {
    //         write(1, arr[i], mx_strlen(arr[i]));
    //     }   
}
