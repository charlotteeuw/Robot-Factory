/*
** EPITECH PROJECT, 2024
** error_checking2.c
** File description:
** functions related to error handling
*/

#include <robot_factory.h>

int compare_labels(char *file, int line_id, char *word, char **label)
{
    if (!label_iscall(word))
        return 0;
    for (int i = 0; label[i] != NULL; i++) {
        if (my_strcmp(label[i], word + 1) == 0 ||
            (my_strcmp(label[i], word + 2) == 0))
            return 0;
    }
    return asm_puterr(file, line_id, "Undefined label");
}

static int count_labels(char **tab)
{
    int count = 0;
    char **line;

    for (int i = 0; tab[i] != NULL; i++) {
        line = my_split(tab[i]);
        if (line[0] != NULL && label_isdef(line[0]) == 1)
            count++;
        my_freetab(line);
    }
    return count;
}

static char **find_labels(char **tab)
{
    int size = 0;
    char **labels = malloc(sizeof(char *) * (count_labels(tab) + 1));
    char **line;
    int len;

    for (int i = 0; tab[i] != NULL; i++) {
        line = my_split(tab[i]);
        if (line[0] != NULL && label_isdef(line[0]) == 1) {
            len = my_strlen(line[0]);
            labels[size] = malloc(sizeof(char) * len);
            my_strncpy(labels[size], line[0], len - 1);
            size++;
        }
        my_freetab(line);
    }
    labels[size] = NULL;
    return labels;
}

static int check_labels_char(char *file, char **labels)
{
    int i = 0;

    while (labels[i] != NULL) {
        if (!my_stronly(labels[i], LABEL_CHARS))
            return asm_puterr(file, 0, "Invalid label name");
        i++;
    }
    return 0;
}

int check_label(char *file, char **tab)
{
    char **line;
    int j = 0;
    char **labels = find_labels(tab);

    if (check_labels_char(file, labels) == 84)
        return 84;
    for (int i = 0; tab[i] != NULL; i++) {
        line = my_split(tab[i]);
        j = 0;
        while (line[j] != NULL &&
            compare_labels(file, i + 1, line[j], labels) == 0)
            j++;
        if (line[j] != NULL)
            return 84;
    }
    return 0;
}
