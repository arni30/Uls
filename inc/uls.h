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
#include <pwd.h>
#include <grp.h>
#include <sys/xattr.h>
#include <sys/acl.h>

typedef struct t_array {
    char **names;
    unsigned char *type;
    struct stat **st;
} t_array;
char *mx_uid_to_name(int id);
void mx_ls_flag_l(t_array *dir);
void mx_output_loop(t_array *dir, int delim, int win_width, 
    void mx_print_output(int i, t_array *dir, int delim));
void mx_free_dir(t_array *dir);
void mx_ls_dir(char *current_position, t_array *dir, int flag);
void mx_free_void_arr(void **arr, int lines);
int mx_find_flag(int argc, char **flags, char flag);
void mx_output(int argc,t_array *dir, char **argv);
void mx_print_dir(int i, t_array *dir, int delim);
void mx_print_error(char *str);
void mx_print_error_flag(int index1, int index2, char **flags);
void mx_error_flag(int argc, char **flags);
void mx_error_dir(char **flags, int index);
void mx_sort_dir(int count, t_array *dir);
int mx_winsize(void);
int mx_count_delim(char **dir, int argc, char **argv);
void mx_malloc_dir(t_array *dir);
void mx_fill_dir(t_array *dir, struct dirent *ep, int count);
int count_el_in_line(int count, int e_line);
void mx_color_print(int i, t_array *dir, int delim);
int mx_strcmp_ls(const char *s1_, const char *s2_);

#endif
