#define PATHFINDER_H
#ifdef PATHFINDER_H

#define MX_ERROR_FLAG "uls: illegal option -- "
#define MX_ERROR_USAGE "usage: uls [-l] [file ...]\n"
#define MX_ERROR_DIR ": No such file or directory\n"
#define MX_ULS "uls: " 
#include "../libmx/inc/libmx.h"
#include <sys/types.h>
#include <dirent.h>
#include <sys/ioctl.h>

void mx_print_dir_new_line(char **arr, int delim, int count, int win_width);
char **mx_ls_show_directory(char *dir);
char **mx_ls_flag__A(char *current_position);
void mx_free_void_arr(void **arr, int lines);
char **mx_ls_flag_1(char *current_position);
int mx_find_flag(int argc, char **flags, char flag);
void mx_loop_print(int argc,char **arr);
char **mx_ls_flag_a(char *current_position);
char **mx_ls_no_flags(char *current_position);
void mx_print_dir(const char *s, int delim);
void mx_print_error(char *str);
void mx_print_error_flag(int index1, int index2, char **flags);
void mx_error_flag(int argc, char **flags);
void mx_error_dir(char **flags, int index);
void mx_sort_dir(char **dir, int count);
void mx_swaps_arr(char **arr, int i, int j);
int mx_winsize(void);

#endif
