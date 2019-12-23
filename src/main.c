#include "../inc/uls.h"

int main(int argc, char **argv) {
    t_array *dir = malloc(sizeof(t_array));

    mx_error_flag(argc,argv);
    mx_ls_no_flags(".", dir);
    //mx_ls_flag_l(dir);
    // if (mx_find_flag(argc, argv, 'A') == 1) {
    //     mx_free_dir(dir);
    //     mx_ls_flag__A(".",dir);
    // }   
    // if (mx_find_flag(argc, argv, 'a') == 1) {
    //     //flag_a = 1;//R
    //     mx_free_dir(dir);
    //     mx_ls_flag_a(".",dir);
    // }
    mx_loop_print(argc, dir, argv);  
    mx_free_dir(dir);
    system("leaks -q uls");
    return 0;
}
