#include "../inc/uls.h"

void mx_free_dir(t_array *dir){
    for (int i = 0; i < mx_count_arr_el(dir->names); i++) {
       free(dir->st[i]); 
    }
    mx_free_void_arr((void*)dir->names, mx_count_arr_el(dir->names));//freedir
    //free(dir->st);
    free(dir->type);
}
