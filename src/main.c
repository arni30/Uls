#include "../inc/uls.h"

int main(int argc, char **argv) {
    mx_error_flag(argc,argv);
    char **arr= mx_ls_no_flags("../Uls");
    while (*arr) {
        mx_print_dir(*arr);
        arr++;
    }
    //system("leaks -q uls");
    return 0;
}
