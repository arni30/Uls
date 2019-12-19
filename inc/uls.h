#define PATHFINDER_H
#ifdef PATHFINDER_H

#define MX_ERROR_FLAG "uls: illegal option -- "
#define MX_ERROR_USAGE "usage: uls [-l] [file ...]\n"
#define MX_ERROR_DIR ": No such file or directory\n"
#define MX_ULS "uls: " 

#define MX_FILE "\033[0m"           //Regular file
#define MX_EXEC "\033[31m"           //Directory
#define MX_DIR "\033[34m" 

#include "../libmx/inc/libmx.h"
#include <sys/types.h>
#include <dirent.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <limits.h>

typedef struct t_array {
    char **names;
    unsigned char *type;
    struct stat *st;
} t_array;

void mx_print_dir_flag_G(t_array *dir, int delim, int count, int win_width);
void mx_free_dir(t_array *dir);
void mx_print_dir_new_line(t_array *arr, int delim, int count, int win_width);
char **mx_ls_show_directory(char *dir);
void mx_ls_flag__A(char *current_position, t_array *dir);
void mx_free_void_arr(void **arr, int lines);
int mx_find_flag(int argc, char **flags, char flag);
void mx_loop_print(int argc,t_array *dir, char **argv);
void mx_ls_flag_a(char *current_position, t_array *dir);
void mx_ls_no_flags(char *current_position, t_array *dir);
void mx_print_dir(const char *s, int delim);
void mx_print_error(char *str);
void mx_print_error_flag(int index1, int index2, char **flags);
void mx_error_flag(int argc, char **flags);
void mx_error_dir(char **flags, int index);
void mx_sort_dir(char **name, int count, unsigned char *type);
void mx_swaps_arr(char **arr, int i, int j);
int mx_winsize(void);

#endif
