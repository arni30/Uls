#include "../inc/uls.h"

void mx_free_dir(t_array *dir, int num_of_files){
    mx_free_void_arr((void**)dir->st, num_of_files);

//    mx_memset(dir->st, 0, sizeof(dir->st));
//    free(dir->st);
//    dir->st = NULL;
//    mx_memset(dir->names, 0, sizeof(dir->names));
//    free(dir->names);
//    dir->names = NULL;
    mx_free_void_arr((void**)dir->names, num_of_files);
    free(dir->type);
}
