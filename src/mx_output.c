#include "../inc/uls.h"

static char** mx_copy_argv(char **argv, int argc) {
    char **arr = malloc(sizeof(char*) * CHAR_MAX/8);

    for (int i = 0, j = 0; i < argc; i++, j++){
        arr[j] = mx_strdup(argv[i]);
    }
    
    return arr;
}

void mx_output(int argc,t_array *dir, char **argv) {
    int win_width = 0;
    int count;
    t_var *variables = malloc(sizeof(t_var));

    win_width = mx_winsize();
    if (isatty(1) == 0 && mx_find_flag(argc, argv, 'C')==1)
         win_width = 80;
    count = mx_count_arr_el(dir->names); 
    variables->delim = mx_count_delim(dir->names, argc, argv);
    variables->args = mx_copy_argv(argv, argc);
    if (mx_find_flag(argc , argv, 's') == 1) {
        mx_print_total(dir);
    }
    if (mx_find_flag(argc , argv, '1') == 1)
            variables->delim = -1;
    if (isatty(1) == 0 && mx_find_flag(argc, argv, 'C') != 1) {
        for (int i = 0; i < count; i++) {
            mx_print_dir(i, dir, -1, variables->args);
        }
    }
    else if (mx_find_flag(argc , argv, 'G') == 1)
        mx_output_loop(dir, variables, win_width, mx_color_print);
    else 
        mx_output_loop(dir, variables, win_width, mx_print_dir);
    mx_free_void_arr((void**)variables->args, mx_count_arr_el(variables->args));
    free(variables);
}
