NAME = uls
SRC = src/main.c src/mx_error_flag.c src/mx_print_error_flags.c src/mx_error_dir.c src/mx_ls_no_flags.c src/mx_print_dir.c src/mx_sort_dir.c
SRCOB = main.o mx_error_flag.o mx_print_error_flags.o mx_error_dir.o mx_ls_no_flags.o mx_print_dir.o mx_sort_dir.o
INC = inc/uls.h
OBJ = obj/main.o obj/mx_error_flag.o obj/mx_print_error_flags.o obj/mx_error_dir.o obj/mx_ls_no_flags.o obj/mx_print_dir.o obj/mx_sort_dir.o
DIR = obj/
LIBMX = libmx
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean

install:
	@make -C $(LIBMX)
	@mkdir obj
	@clang $(CFLAGS) -c $(SRC)
	@cp $(SRCOB) $(DIR)
	@clang $(CFLAGS) -o $(NAME) $(OBJ) -L./libmx -lmx

uninstall: clean
	@rm -rf $(NAME)
	@make uninstall -C $(LIBMX)

clean:	
	@rm -rf $(SRCOB)
	@rm -rf $(DIR)

reinstall: uninstall all
	@rm -rf $(SRCOB)
	@rm -rf $(DIR)