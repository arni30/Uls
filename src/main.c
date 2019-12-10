#include "../inc/uls.h"

int main(int argc, char **argv) {
    mx_error_flag(argc,argv);
    if (argc == 1) {
        mx_ls_no_flags(".");
    }
    if (mx_find_flag(argc, argv, '1') == 1) {
        mx_ls_flag_1(".");
    }
    if (mx_find_flag(argc, argv, 'a') == 1) {
        mx_ls_flag_a(".");
    }   
    if (mx_find_flag(argc, argv, 'A') == 1) {
        mx_ls_flag__A(".");
    }   
    //system("leaks -q uls");
    return 0;
}
