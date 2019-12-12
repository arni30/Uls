#include "../inc/uls.h"

int main(int argc, char **argv) {
    char **dir;
    mx_error_flag(argc,argv);
    if (argc == 1) {
        mx_ls_no_flags(".");
    }
    if (mx_find_flag(argc, argv, 'a') == 1) {
        dir = mx_ls_flag_a(".");
        mx_loop_print(argc, dir, "\n");
    }   
    if (mx_find_flag(argc, argv, 'A') == 1) {
        mx_ls_flag__A(".");
    }   
    //system("leaks -q uls");
    return 0;
}
