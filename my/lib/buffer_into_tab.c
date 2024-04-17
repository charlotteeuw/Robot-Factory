/*
** EPITECH PROJECT, 2024
** buffer_into_tab
** File description:
** converts buffer into array
*/

#include <lib.h>

int count_nb_lines(char *buffer)
{
    int nb_lines = 1;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            nb_lines++;
    }
    return nb_lines;
}

int count_nb_columns(char *buffer)
{
    int nb_columns = 0;

    for (int i = 0; buffer[i] != '\n' && buffer[i] != '\0'; i++) {
        nb_columns++;
    }
    return nb_columns;
}

char **buffer_into_tab(char *buffer, int number_lines)
{
    int j = 0;
    char **tab = malloc(sizeof(char *) * (number_lines + 1));
    int k = 0;
    int i = 0;
    int nb_cols = 0;

    for (; i < number_lines; i++) {
        j = 0;
        nb_cols = count_nb_columns(&buffer[k]);
        tab[i] = malloc(sizeof(char) * (nb_cols + 1));
        for (; j < nb_cols; j++) {
            tab[i][j] = buffer[k];
            k++;
        }
        tab[i][j] = '\0';
        k++;
    }
    tab[i] = NULL;
    return tab;
}
