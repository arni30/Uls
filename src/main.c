#include "../inc/uls.h"

int main(int argc, char **argv) {
    t_array *dir = malloc(sizeof(t_array));
    int flag = 0;

    mx_error_flag(argc,argv);
    mx_ls_dir(".", dir, flag);
    if (mx_find_flag(argc, argv, 'A') == 1) {
        flag = 1;
        mx_free_dir(dir);
        mx_ls_dir(".", dir, flag);
    }   
    if (mx_find_flag(argc, argv, 'a') == 1) {
        flag = -1;
        mx_free_dir(dir);
        mx_ls_dir(".", dir, flag);
    }
    mx_ls_flag_l(dir);
    mx_output(argc, dir, argv);  
    mx_free_dir(dir);
    system("leaks -q uls");
    return 0;
}
