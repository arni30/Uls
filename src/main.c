#include "../inc/uls.h"

int main(int argc, char **argv) {
    char **dir;
    mx_error_flag(argc,argv);
    if (argc == 1) {
<<<<<<< HEAD
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
=======
        dir = mx_ls_no_flags(".");
        mx_loop_print(argc, dir);
    }
    if (mx_find_flag(argc, argv, 'A') == 1) {
        //flag_A = 1;
        dir = mx_ls_flag__A(".");
        mx_loop_print(argc, dir);
    }   
    if (mx_find_flag(argc, argv, 'a') == 1) {
        //flag_a = 1;
        dir = mx_ls_flag_a(".");
        mx_loop_print(argc, dir);
    }   

    //system("leaks -q uls");
    // mx_free_void_arr((void**)dir, count);
>>>>>>> 096bc3070d76f26a3dd2f84a93abf526e4cad386
    return 0;
}
