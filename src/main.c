#include "../inc/uls.h"

int main(int argc, char **argv) {
    mx_ls_flag_G(".");
    argc++;
    argv++;
    
    // char **dir;
    // mx_error_flag(argc,argv);
    // if (argc == 1 || (mx_find_flag(argc, argv, '1') == 1 
    //     && argc == 2 && mx_strlen(argv[1]) == 2)) {
    //     dir = mx_ls_no_flags(".");
    //     mx_loop_print(argc, dir, argv);
    // }
    // if (mx_find_flag(argc, argv, 'A') == 1) {
    //     //flag_A = 1;
    //     dir = mx_ls_flag__A(".");
    //     mx_loop_print(argc, dir, argv);
    // }   
    // if (mx_find_flag(argc, argv, 'a') == 1) {
    //     //flag_a = 1;
    //     dir = mx_ls_flag_a(".");
    //     mx_loop_print(argc, dir, argv);
    // }
       

    //system("leaks -q uls");
    // mx_free_void_arr((void**)dir, count);
    return 0;
}
