#include "../inc/uls.h"

void mx_free_dir(t_array *dir){
    mx_free_void_arr((void*)dir->names, mx_count_arr_el(dir->names));//freedir
    free(dir->type);
}
