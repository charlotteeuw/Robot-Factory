/*
** EPITECH PROJECT, 2024
** my_strchr
** File description:
** Searches a character in a string
*/

#include <lib.h>

const char *my_strchr(const char *str, const char c)
{
    size_t i = 0;

    while (str[i]) {
        if (str[i] == c)
            return str + i;
        i++;
    }
    if (str[i] == c)
        return str + i;
    return NULL;
}
