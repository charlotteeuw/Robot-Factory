/*
** EPITECH PROJECT, 2024
** mylib
** File description:
** mylib
*/

#ifndef LIB_H
    #define LIB_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>

    #define ISNUM(c) ('0' <= c && c <= '9')
    #define ISALPHA(c) (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))

typedef unsigned char bool_t;

int my_atoi(char *s);
char *my_itoa(int nb);
void my_putchar(char c);
int my_puterr(char *str);
int my_char_isnum(char c);
char **my_split(char *str);
void my_freetab(char **tab);
int my_char_isalpha(char c);
char *my_basename(char *path);
int my_count_words(char *str);
int my_str_isalpha(char *str);
int my_putstr(char const *str);
int my_strlen(char const *str);
int count_nb_lines(char *buffer);
char *my_strdup(char const *src);
int my_str_isnum(char const *str);
int count_nb_columns(char *buffer);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strncpy(char *dest, char *src, int n);
const char *my_strchr(const char *str, const char c);
bool_t my_stronly(const char *str, const char *only);
int my_strncmp(char const *s1, char const *s2, int n);
char **buffer_into_tab(char *buffer, int number_lines);

#endif /* LIB_H */
