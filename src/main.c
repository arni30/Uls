#include "../inc/uls.h"

int main(int argc, char **argv) {
    t_array *dir = malloc(sizeof(t_array));
    dir->type = malloc(sizeof(unsigned char));
    dir->names = malloc(sizeof(char *) * INT_MAX/16);
    // mx_ls_flag_G(".");
    // argc++;
    // argv++;

    mx_error_flag(argc,argv);
    if (argc == 1 || ((mx_find_flag(argc, argv, '1') == 1
        ||  mx_find_flag(argc, argv, 'G') == 1)
        && argc == 2 && mx_strlen(argv[1]) == 2)) {
        mx_ls_no_flags(".", dir);
        mx_loop_print(argc, dir->names, argv);
    }
    // if (mx_find_flag(argc, argv, 'A') == 1) {
    //     //flag_A = 1;
    //     mx_ls_flag__A(".",dir);
    //     mx_loop_print(argc, dir->names, argv);
    // }   
    // if (mx_find_flag(argc, argv, 'a') == 1) {
    //     //flag_a = 1;
    //     mx_ls_flag_a(".",dir);
    //     mx_loop_print(argc, dir->names, argv);
    // }
       

    //system("leaks -q uls");
    // mx_free_void_arr((void**)dir, count);
    return 0;
}
