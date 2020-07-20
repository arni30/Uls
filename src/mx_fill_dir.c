#include "../inc/uls.h"

void mx_realloc_dir(t_array *dir, int count) {
    dir->st = mx_realloc(dir->st, sizeof (struct stat *) * (count + 1));
    dir->type = mx_realloc(dir->type, sizeof (unsigned char) * (count + 1));
    dir->names = mx_realloc(dir->names, sizeof (char *) * (count + 1));
}

void mx_fill_file_dir(char *file, t_array *dir, int count) {
    char *path = mx_path(NULL, file, 1);

    mx_realloc_dir(dir, count);
    dir->st[count] = (struct stat *) malloc(sizeof(struct stat));
    if (lstat(path, dir->st[count]) < 0)
        perror("uls:");
    else if ((dir->st[count]->st_mode > 0)
             && (S_IEXEC & dir->st[count]->st_mode)
             && (S_IFMT & dir->st[count]->st_mode) != S_IFDIR) {
        dir->type[count] = 0;
    }
    else if ((S_IFMT & dir->st[count]->st_mode) == S_IFREG)
        dir->type[count] = DT_REG;
    else if ((S_IFMT & dir->st[count]->st_mode) == S_IFLNK)
        dir->type[count] = DT_LNK;
    dir->names[count] = mx_strdup(file);
    mx_strdel(&path);
}

void mx_fill_dir(t_array *dir, struct dirent *ep, int count, char *pathName) {
    char *path = mx_path(pathName, ep->d_name, 0);

    mx_realloc_dir(dir, count);
    dir->st[count] = (struct stat*) malloc(sizeof (struct stat));
    if (lstat(path, dir->st[count]) < 0)
        perror("uls:");
    dir->type[count] = ep->d_type;
    if (mx_strcmp(ep->d_name, ".HFS+ Private Directory Data\r") == 0)
        dir->names[count] = mx_strdup(".HFS+ Private Directory Data?");
    else
        dir->names[count] = mx_strdup(ep->d_name);
    mx_strdel(&path);
}

char *mx_path(char *pathName, char *file, int flag) {
    char *p = NULL;

    if (flag == 1) {
        if (mx_strchr(file, '/') == NULL) {
            p = mx_strdup("./");
            p = mx_realloc(p, sizeof (char) * (mx_strlen(file) + 3));
            p = mx_strcat(p, file);
        }
        else
            p = mx_strdup(file);
    }
    else {
        p = mx_strdup(pathName);
        p = mx_realloc(p, sizeof (char) * (mx_strlen(p) + 2));
        if (mx_strcmp(pathName, "/") != 0)
            p = mx_strcat(p, "/");
        p = mx_realloc(p, sizeof (char) * (mx_strlen(p) + mx_strlen(file) + 1));
        p = mx_strcat(p, file);
    }
    return p;
}
