#include "../inc/uls.h"

int main(int argc, char **argv) {
    t_array *dir = malloc(sizeof(t_array));
    // dir->type = malloc(sizeof(unsigned char));
    // dir->names = malloc(sizeof(char *) * INT_MAX/16);
    // mx_ls_flag_G(".");
    // argc++;
    // argv++;

    mx_error_flag(argc,argv);
    mx_ls_no_flags(".", dir);
    if (mx_find_flag(argc, argv, 'A') == 1) {
        mx_free_dir(dir);
        mx_ls_flag__A(".",dir);
    }   
    if (mx_find_flag(argc, argv, 'a') == 1) {
        //flag_a = 1;//R
        mx_free_dir(dir);
        mx_ls_flag_a(".",dir);
    }
    mx_loop_print(argc, dir->names, argv);  
    mx_free_dir(dir);
    system("leaks -q uls");
   
    // mx_free_void_arr((void**)dir, count);
    return 0;
}


void mx_free_dir(t_array *dir){
    mx_free_void_arr((void*)dir->names, mx_count_arr_el(dir->names));//freedir
    free(dir->type);
}
