#include "../inc/uls.h"

void mx_loop_print(int argc,t_array *dir, char **argv) {
    int count = 0;
    int delim = 8;
    int i = 0;
    int win_width; 

 while (dir->names[count]) {
        i = 0;
        while(dir->names[count][i]){
            i++;
        }
        if (mx_find_flag(argc , argv, 'G') == 1 && i >= delim) {
            delim = i + 1;
        }
        else if(i >= delim) {
            delim = (i / 8) * 8 + 8;
        }
        count++;
    }
    i = 0;
    if (mx_find_flag(argc , argv, '1') == 1 || isatty(1) == 0) {
        while (i < count - 1) {
            mx_print_dir(dir->names[i], -1);
            i++;
        }
        write(1, dir->names[i], mx_strlen(dir->names[i]));
        mx_printchar('\n');
    }
    else if (mx_find_flag(argc , argv, 'G') == 1){
        win_width = mx_winsize();
        mx_print_dir_flag_G(dir, delim, count, win_width);
    }
    else {
        win_width = mx_winsize();
        mx_print_dir_new_line(dir, delim, count, win_width);
   }
}





