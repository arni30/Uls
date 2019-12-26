#include "../inc/uls.h"

int main(int argc, char **argv) {
    t_array *dir = malloc(sizeof(t_array));
    int flag = 0;
    int g_fl = 0;

    mx_error_flag(argc,argv);
    mx_ls_dir(".", dir, flag, argv);
    if (mx_find_flag(argc, argv, 'G') == 1) {
        g_fl = 1;
    }
    if (mx_find_flag(argc, argv, 'A') == 1) {
        flag = 1;
        mx_free_dir(dir);
        mx_ls_dir(".", dir, flag, argv);
    }   
    if (mx_find_flag(argc, argv, 'a') == 1 || mx_find_flag(argc, argv, 'f') == 1) {
        flag = -1;
        mx_free_dir(dir);
        mx_ls_dir(".", dir, flag, argv);
    }
    if (mx_find_flag(argc, argv, 'l') == 1)
        mx_ls_flag_l(dir, g_fl, argv);
    else
        mx_output(argc, dir, argv);  
    mx_free_dir(dir);
    system("leaks -q uls");
    return 0;
}
