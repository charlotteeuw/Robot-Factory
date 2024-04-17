/*
** EPITECH PROJECT, 2024
** clean_comments
** File description:
** clean comments
*/

#include <robot_factory.h>

char **without_comments(char *buffer)
{
    char **tab = buffer_into_tab(buffer);
    char **copy = malloc(sizeof(char *) * (count_nb_lines(buffer) + 1));
    int j = 0;

    for (int i = 0; tab[i]; i++) {
        if (tab[i][0] == '#' || tab[i][0] == '\n')
            continue;
        copy[j] = my_strdup(tab[i]);
        j++;
    }
    copy[j] = NULL;
    return copy;
}
