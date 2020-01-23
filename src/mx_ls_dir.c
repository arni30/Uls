#include "../inc/uls.h"


static void mx_sort_dir_filesize(int count, t_array *dir) {
    for(int i = 0 ; i < count - 1; i++) { 
       for(int j = i + 1 ; j < count ; j++) {  
            if (dir->st[j]->st_size > dir->st[i]->st_size){
                mx_swaps_arr(dir->names, i, j);
                struct stat *temp = dir->st[i];
                dir->st[i] = dir->st[j];
                dir->st[j] = temp;
                mx_swap_char((char*)&dir->type[i], (char*)&dir->type[j]);
            }
        }
    }
    dir->names = mx_realloc(dir->names, count * sizeof(char**));
    dir->type = mx_realloc(dir->type, count * sizeof(unsigned char));
}

void mx_ls_dir(char *current_position, t_array *dir, int flag, char **argv) {
    struct dirent *ep = NULL;
    DIR *dp = opendir(current_position);
    int count = 0;

    char pathName[PATH_MAX + 1];

    mx_malloc_dir(dir);
    if (dp != NULL) {
        while ((ep = readdir(dp)) != NULL) {
            mx_strcpy(pathName, current_position);
            if (flag == 0 && ep->d_name[0] != '.')
                mx_fill_dir(dir, ep, count++, pathName);
            else if (flag == 1 && (mx_isalpha(ep->d_name[1]) 
                    || ep->d_name[0] != '.')){
                mx_fill_dir(dir, ep, count++, pathName);
            }
            else if (flag == -1)
                mx_fill_dir(dir, ep, count++, pathName);
        }
    }
    closedir(dp);
    if (mx_find_flag(mx_count_arr_el(argv), argv, 'f') == 0)
        mx_sort_dir(count, dir);
    else if (mx_find_flag(mx_count_arr_el(argv), argv, 'S') == 1
             && mx_find_flag(mx_count_arr_el(argv), argv, 'f') == 0){
        mx_sort_dir_filesize(count, dir);
    }

}



