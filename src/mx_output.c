#include "../inc/uls.h"

void mx_output(int argc,t_array *dir, char **argv) {
    int i = 0;
    int win_width;
    int count;
    int delim;
    
    win_width = mx_winsize();
    count = mx_count_arr_el(dir->names); 
    delim = mx_count_delim(dir->names, argc, argv);
    if (mx_find_flag(argc , argv, '1') == 1)
            delim = -1;
    if (isatty(1) == 0) {
        while (i < count) {
            mx_print_dir(i, dir, -1);
            i++;
        }
    }
    else if (mx_find_flag(argc , argv, 'G') == 1)
        mx_output_loop(dir, delim, win_width, mx_color_print);
    else 
        mx_output_loop(dir, delim, win_width, mx_print_dir);
}
