#include "../inc/uls.h"

static char** mx_copy_argv(char **argv, int argc) {
    char **arr = malloc(sizeof(char*) * CHAR_MAX/8);

    for (int i = 0, j = 0; i < argc; i++, j++){
        arr[j] = mx_strdup(argv[i]);
    }
    
    return arr;
}

void mx_output(int argc,t_array *dir, char **argv) {
    int win_width;
    int count;
    t_var *variables = malloc(sizeof(t_var));
    
    win_width = mx_winsize();
    count = mx_count_arr_el(dir->names); 
    variables->delim = mx_count_delim(dir->names, argc, argv);
    variables->args = mx_copy_argv(argv, argc);
    if (mx_find_flag(argc , argv, '1') == 1)
            variables->delim = -1;
    if (isatty(1) == 0) {
        for (int i = 0; i < count; i++) {
            mx_print_dir(i, dir, -1, variables->args);
        }
    }
    else if (mx_find_flag(argc , argv, 'G') == 1)
        mx_output_loop(dir, variables, win_width, mx_color_print);
    else 
        mx_output_loop(dir, variables, win_width, mx_print_dir);
}
