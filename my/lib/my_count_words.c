/*
** EPITECH PROJECT, 2024
** my_count_words
** File description:
** my_count_words
*/

#include <lib.h>

int my_count_words(char *str)
{
    int count = 0;
    int index = 0;

    while (str[index] != '\0') {
        while (str[index] == ' ' || str[index] == '\t'
        || str[index] == '\n' || str[index] == ',')
            index++;
        if (str[index] != '\0')
            count++;
        while (str[index] != ' ' && str[index] != '\t'
            && str[index] != ',' &&
            str[index] != '\n' && str[index] != '\0')
            index++;
    }
    return count;
}
