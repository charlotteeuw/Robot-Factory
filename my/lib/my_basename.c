/*
** EPITECH PROJECT, 2024
** my_basename.c
** File description:
** my_basename
*/

#include <lib.h>

char *my_basename(char *path)
{
    char *name;
    int final_slash = -1;

    for (int i = 0; path[i]; i++) {
        if (path[i] == '/')
            final_slash = i;
    }
    name = my_strdup(path + final_slash + 1);
    return name;
}
