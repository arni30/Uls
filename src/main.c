#include "../inc/uls.h"

int main(int argc, char **argv) {
    mx_error_flag(argc,argv);
    if (argc == 1){
        mx_ls_no_flags("../Uls");
    }
    //system("leaks -q uls");
    return 0;
}
