#include "../inc/uls.h"

void mx_realloc_dir(t_array *dir, int count) {
    dir->st = mx_realloc(dir->st, sizeof(struct stat *) * (count + 1));
    dir->type = mx_realloc(dir->type, sizeof(unsigned char) * (count + 1));
    dir->names = mx_realloc(dir->names, sizeof(char *) * (count + 1));
}

void mx_fill_file_dir(char *file, t_array *dir, int count) {
    char *path = NULL;

    path = mx_path(file, NULL, -1);
    mx_realloc_dir(dir, count);
    dir->st[count] = (struct stat *) malloc(sizeof(struct stat));
    if ((lstat(path, dir->st[count]) >= 0)
        && (dir->st[count]->st_mode > 0)
        && (S_IEXEC & dir->st[count]->st_mode)
        && (S_IFMT & dir->st[count]->st_mode) != S_IFDIR) {
        dir->type[count] = 0;
    }
    else if ((S_IFMT & dir->st[count]->st_mode) == S_IFREG) {
        dir->type[count] = DT_REG;
    }
    else if ((S_IFMT & dir->st[count]->st_mode) == S_IFLNK) {
        dir->type[count] = DT_LNK;
    }
    dir->names[count] = mx_strdup(file);
    mx_strdel(&path);
}

void mx_fill_dir(t_array *dir, struct dirent *ep, int count, char *pathName) {
    char *path = mx_strdup(pathName);

    path = mx_path(path, ep->d_name, 1);
    mx_realloc_dir(dir, count);
    dir->st[count] = (struct stat *) malloc(sizeof(struct stat));
    if ((lstat(path, dir->st[count]) >= 0)
        && (dir->st[count]->st_mode > 0)
        && (S_IEXEC & dir->st[count]->st_mode)
        && (S_IFMT & dir->st[count]->st_mode) != S_IFDIR) {
        dir->type[count] = 0;
    }
    else if ((S_IFMT & dir->st[count]->st_mode) == S_IFREG) {
        dir->type[count] = DT_REG;
    }
    else if ((S_IFMT & dir->st[count]->st_mode) == S_IFLNK) {
        dir->type[count] = DT_LNK;
    }
    else {
        dir->type[count] = ep->d_type;
    }
    dir->names[count] = mx_strdup(ep->d_name);
    mx_strdel(&path);
}

char *mx_path(char *pathName, char *file, int flag) {
    char *path = NULL;

    if (flag == -1) {
        if (mx_strchr(pathName, '/') == NULL) {
            path = mx_strdup("./");
            path = mx_realloc(path, sizeof(char) * (mx_strlen(pathName) + 3));
            path = mx_strcat(path, pathName);
            return path;
        }
        else {
            path = mx_strdup(pathName);
            return path;
        }
    }
    else {
        path = mx_realloc(pathName, sizeof(char) * (mx_strlen(pathName) + mx_strlen(file) + 2));
        path = mx_strcat(path, "/");
        path = mx_strcat(path, file);
        return path;
    }
}
