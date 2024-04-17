/*
** EPITECH PROJECT, 2024
** my_strcomp
** File description:
** Check if a string is only composed of given characters
*/

#include <lib.h>

bool_t my_stronly(const char *str, const char *only)
{
    size_t i = 0;

    while (str[i]) {
        if (my_strchr(only, str[i]) == NULL)
            return 0;
        i++;
    }
    return 1;
}
