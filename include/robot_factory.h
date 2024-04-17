/*
** EPITECH PROJECT, 2024
** robot factory
** File description:
** Header file for robot factory project
*/

#ifndef ROBOT_FACTORY_H
    #define ROBOT_FACTORY_H

    #include <op.h>
    #include <lib.h>

    #include <sys/stat.h>
    #include <fcntl.h>

typedef struct label_s {
    char *name;
    unsigned int pos;
} label_t;

int usage(char *param);
int error_checking(int argc, char **argv);

int compile(char *filepath);
int convert(char **tab, FILE *dest);
int header(char **tab, FILE *dest);
int is_command(char **tab, unsigned *size);

void replace_labels(char **tab, label_t *labels);
int count_label(char **tab);
void get_labels(char **tab, label_t *labels);

int label_isdef(char *str);
int label_iscall(char *str);
int check_label(char *file, char **tab);
int asm_puterr(char *file, int line, char *error);

int check_header(char *file, char **tab);

size_t my_fwrite(void *ptr, size_t size, size_t n, FILE *restrict stream);

#endif /* !ROBOT_FACTORY_H */
