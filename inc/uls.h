#define PATHFINDER_H
#ifdef PATHFINDER_H

#define MX_ERROR_FLAG "uls: illegal option -- "
#define MX_ERROR_USAGE "usage: uls [-l] [file ...]\n"
#define MX_ERROR_DIR ": No such file or directory\n"
#define MX_ULS "uls: " 

#define MX_FILE "\033[0m"           //Regular file
#define MX_EXEC "\033[31m"           //Directory
#define MX_DIR "\033[34m" 
#define MX_LINK "\033[35m"
#define MX_FIFO "\033[33m" 
#define MX_SOCKET "\033[32m" 
#define MX_BLK "" 
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

typedef struct s_array {
    char **names;
    unsigned char *type;
    struct stat **st;
} t_array;

typedef struct s_var {
    int delim;
    char **args;
} t_var;

int mx_print_flag_F(char **argv, t_array *dir, int i);
void mx_if_sock_blk_fifo(int delim, t_array *dir, int i, char **argv);
void mx_print_total(t_array *dir);
void mx_print_symlink(t_array *dir, char *buf, int i);
void mx_print_time_name(t_array *dir, int i, int flag, char **argv);
void mx_print_link_uid_gid_size(t_array *dir, int i);
void mx_acl_attr_if(int mode, char *str, t_array *dir, int i);
void mx_license_if(int mode, char *str);
void mx_print_mode(t_array *dir, int i);
char *mx_uid_to_name(int id);
void mx_ls_flag_l(t_array *dir, int flag, char **argv);
void mx_output_loop(t_array *dir, t_var *variable, int win_width, 
    void mx_print_output(int i, t_array *dir, int delim, char **argv));
void mx_free_dir(t_array *dir);
void mx_ls_dir(char *current_position, t_array *dir, int flag);
void mx_free_void_arr(void **arr, int lines);
int mx_find_flag(int argc, char **flags, char flag);
void mx_output(int argc,t_array *dir, char **argv);
void mx_print_dir(int i, t_array *dir, int delim, char **argv);
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
void mx_color_print(int i, t_array *dir, int delim, char **argv);
int mx_strcmp_ls(const char *s1_, const char *s2_);

#endif
