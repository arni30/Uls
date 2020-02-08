#include "../inc/uls.h"
void mx_sort_ascii(int count, char **arr) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (mx_strcmp_ls(arr[i], arr[j]) > 0){
                mx_swaps_arr(arr, i, j);
            }
        }
    }
}
static char** mx_copy_argv(char **argv, int argc) {
    char **arr = (char**) malloc(sizeof(char*) * argc);
    for (int i = 0; i < argc; i++){
        arr[i] = mx_strdup(argv[i]);
    }
    return arr;
}
static void mx_find_all_flags(t_var *variables, int argc, char **argv) {
    variables->flag_1 = mx_find_flag(argc, argv, '1');
    variables->flag_a = mx_find_flag(argc, argv, 'a');
    variables->flag_A = mx_find_flag(argc, argv, 'A');
    variables->flag_C = mx_find_flag(argc, argv, 'C');
    variables->flag_c = mx_find_flag(argc, argv, 'c');
    variables->flag_g = mx_find_flag(argc, argv, 'g');
    variables->flag_G = mx_find_flag(argc, argv, 'G');
    variables->flag_f = mx_find_flag(argc, argv, 'f');
    variables->flag_F = mx_find_flag(argc, argv, 'F');
    variables->flag_o = mx_find_flag(argc, argv, 'o');
    variables->flag_u = mx_find_flag(argc, argv, 'u');
    variables->flag_s = mx_find_flag(argc, argv, 's');
    variables->flag_R = mx_find_flag(argc, argv, 'R');
    variables->flag_l = mx_find_flag(argc, argv, 'l');
    variables->flag_S = mx_find_flag(argc, argv, 'S');
    variables->flag_r = mx_find_flag(argc, argv, 'r');
}
static char **loop_position(int argc, char **argv, char **pos, int *count) {
    int flag_stop = 0;
    DIR *dp;
    char buf[1024];
    char *path = NULL;

    for (int i = 1; i < argc ; i++) {
        path = mx_path(NULL, argv[i], 1);
        dp = opendir(argv[i]);
        if (mx_strcmp("--",argv[i]) == 0)
            flag_stop = 1;
        if ((dp != NULL && (argv[i][0] != '-' || flag_stop == 1)) && (mx_find_flag(argc, argv, 'l') == 0 || readlink(path, buf, 1024) == -1)) {
            pos = (char**) mx_realloc(pos, ((*count) + 1) * sizeof(char*));
            pos[*count] = mx_strdup(argv[i]);
            (*count)++;
            flag_stop = 1;
        }
        if (dp != NULL)
            closedir(dp);
        mx_strdel(&path);
    }
    return pos;
}
static char** if_count_flag_0(t_var *var, char **position) {
    if (var->count == 0 && var->flag_files == 0) {
        position[0] = mx_strdup(".");
        var->count = 1;
    }
    if (var->flag_f == 0) {
        mx_sort_ascii(var->count, position);
        if (var->flag_r == 1)
            mx_sort_reverse(var->count, position);
    }
    return position;
}
static void loop_dirs_if(char **position, t_var *var, t_array *dir) {
    for (int i = 0; i < var->count; i++) {
        if (mx_strcmp(position[i], ".") != 0 && var->count > 1) {
            mx_printstr(position[i]);
            mx_printstr(":\n");
        }
        mx_ls_dir(position[i], dir, var);
        var->flag_files = 0;
        if (var->count > 1 && i + 1 != var->count) {
            mx_printstr("\n");
        }
    }
    mx_free_void_arr((void **) var->args, var->argc1);
    mx_free_void_arr((void**)position, var->count);
    free(var);
    free(dir);
}
int main(int argc, char **argv) {
    t_array *dir = (t_array*) malloc(sizeof(t_array));
    t_var *var = (t_var*) malloc(sizeof(t_var));
    char **position = (char**) malloc(sizeof(char*));
    var->count = 0;
    var->flag_files = mx_error_flag(argc,argv);
    if (var->flag_files == 1) {
        position[var->count] = mx_strdup(".");
        var->count = 1;
    }
    position = loop_position(argc, argv, position, &var->count);
    mx_find_all_flags(var, argc, argv);
    position = if_count_flag_0(var, position);
    var->argc1 = argc;
    var->args = mx_copy_argv(argv, argc);
    loop_dirs_if(position, var, dir);
    //system("leaks -q a.out");
    return 0;
}
