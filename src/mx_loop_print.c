#include "../inc/uls.h"

void mx_loop_print(int argc,char **arr) {
    int count = 0;
<<<<<<< HEAD
    int i = 0;
    int win_width; 
    char *delim = "                        ";
=======
    int count_char = 0;
    int delim = 8;
    int i = 0;
    int win_width; 
>>>>>>> 096bc3070d76f26a3dd2f84a93abf526e4cad386
    
    win_width = mx_winsize();

    while (arr[count]) {
<<<<<<< HEAD
=======
        count_char = 0;
        while(arr[count][count_char]){
            count_char++;
        }
        if(count_char / 8 >= delim) {
            delim = (count_char / 8) + 1;
        }
>>>>>>> 096bc3070d76f26a3dd2f84a93abf526e4cad386
        count++;
    }
    if(mx_find_flag(argc , arr, '1') == 1 || isatty(1) == 0){
        while (i < count - 1) {
<<<<<<< HEAD
            mx_print_dir(arr[i], "\n");
=======
            mx_print_dir(arr[i], -1);
>>>>>>> 096bc3070d76f26a3dd2f84a93abf526e4cad386
            i++;
        }
        write(1, arr[i], mx_strlen(arr[i]));
        mx_printchar('\n');
    }
<<<<<<< HEAD
    else {//if (count <= win_width /16) {
        while (i < count - 1) {
            mx_print_dir(arr[i], delim);
=======
    else if (count <= win_width /delim) {
        while (i < count - 1) {
            mx_print_dir(arr[i], delim);// сделать под кол-во пробеловб если \n  delim = -1
>>>>>>> 096bc3070d76f26a3dd2f84a93abf526e4cad386
            i++;
        }
         write(1, arr[i], mx_strlen(arr[i]));
         mx_printchar('\n');
    }
//     else {
<<<<<<< HEAD
//         mx_print_dir_new_line(arr, delim, count, i);
=======
//         mx_print_dir_new_line(arr, delim, count, win_width);
>>>>>>> 096bc3070d76f26a3dd2f84a93abf526e4cad386
//         mx_printchar('\n');
//    }
}

<<<<<<< HEAD
void mx_print_dir_new_line(char **arr, char *delim, int count, int i) {
=======
void mx_print_dir_new_line(char **arr, int delim, int count, int win_width) {
    int i = 0;
    int e_line = win_width/16;
    e_line++;

>>>>>>> 096bc3070d76f26a3dd2f84a93abf526e4cad386
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
