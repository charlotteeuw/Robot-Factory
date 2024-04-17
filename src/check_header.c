/*
** EPITECH PROJECT, 2024
** check_header.c
** File description:
** functions related to checking the header
*/

#include <robot_factory.h>

static int check_prog_name(char *file, char **tab)
{
    char **line;
    int i = 0;

    for (; tab[i]; i++) {
        line = my_split(tab[i]);
        if (line[0])
            break;
        my_freetab(line);
    }
    if (tab[i] == NULL || line[1] == NULL)
        return asm_puterr(file, 1, "No name specified");
    if (my_strcmp(line[0], NAME_CMD_STRING))
        return asm_puterr(file, i,
            "The name of your program must be the first line");
    if (line[2] != NULL)
        return asm_puterr(file, i, "Syntax error");
    if (my_strlen(line[1]) > PROG_NAME_LENGTH)
        return asm_puterr(file, i, "The program name is too long");
    return 0;
}

static int go_to_comment(char **tab)
{
    char **line;
    int i = 0;

    for (int count = 0; tab[i]; i++) {
        line = my_split(tab[i]);
        if (line[0])
            count++;
        my_freetab(line);
        if (count == 2)
            break;
    }
    return i;
}

static int check_comment(char *file, char **tab)
{
    char **line;
    int i = go_to_comment(tab);

    if (tab[i] == NULL) {
        asm_puterr(file, i, "Warning: No comment specified");
        return 0;
    }
    line = my_split(tab[i]);
    if (line[1] == NULL)
        return asm_puterr(file, 1, "No comment specified");
    if (my_strcmp(line[0], COMMENT_CMD_STRING))
        return asm_puterr(file, i, "The comment must be just after the name");
    if (line[2] != NULL)
        return asm_puterr(file, i, "Syntax error");
    if (my_strlen(line[1]) > COMMENT_LENGTH)
        return asm_puterr(file, i, "The comment is too long");
    return 0;
}

int check_header(char *file, char **tab)
{
    if (check_prog_name(file, tab) == 84)
        return 84;
    if (check_comment(file, tab) == 84)
        return 84;
    return 0;
}
