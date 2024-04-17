/*
** EPITECH PROJECT, 2024
** label
** File description:
** label
*/

#include <robot_factory.h>

int label_isdef(char *str)
{
    int len = my_strlen(str);

    if (str[len - 1] == LABEL_CHAR)
        return 1;
    return 0;
}

int label_iscall(char *str)
{
    if (str[0] == LABEL_CHAR ||
        (str[0] == DIRECT_CHAR && str[1] == LABEL_CHAR))
        return 1;
    return 0;
}

static int is_new_label(char *arg, label_t *label, int size)
{
    int len = my_strlen(arg);

    if (arg[len - 1] == LABEL_CHAR) {
        label->name = malloc(sizeof(char) * len);
        my_strncpy(label->name, arg, len - 1);
        label->pos = size;
        return 1;
    }
    return 0;
}

void get_labels(char **tab, label_t *labels)
{
    unsigned size = 0;
    int j = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        is_command(&tab[i], &size);
        j += is_new_label(tab[i], &labels[j], size);
    }
}

int count_label(char **tab)
{
    int nb = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        if (tab[i][my_strlen(tab[i]) - 1] == (LABEL_CHAR))
            nb++;
    }
    return nb;
}

static void replace_value_direct(char **tab, label_t *labels, int size)
{
    unsigned short value;

    for (int i = 0; labels[i].name != NULL; i++) {
        if (my_strcmp(labels[i].name, &tab[0][2]) == 0) {
            value = labels[i].pos - size;
            free(tab[0]);
            tab[0] = malloc(sizeof(char) * (my_strlen(my_itoa(value)) + 2));
            tab[0][0] = DIRECT_CHAR;
            my_strcpy(&tab[0][1], my_itoa(value));
        }
    }
}

static void replace_value_indirect(char **tab, label_t *labels, int size)
{
    unsigned short value;

    for (int i = 0; labels[i].name != NULL; i++) {
        if (my_strcmp(labels[i].name, &tab[0][1]) == 0) {
            value = labels[i].pos - size;
            free(tab[0]);
            tab[0] = malloc(sizeof(char) * (my_strlen(my_itoa(value)) + 1));
            my_strcpy(tab[0], my_itoa(value));
        }
    }
}

static void is_label_call(char **tab, label_t *labels, int size)
{
    if (tab[0][0] == LABEL_CHAR)
        replace_value_indirect(tab, labels, size);
    else if (tab[0][0] == DIRECT_CHAR && tab[0][1] == LABEL_CHAR)
        replace_value_direct(tab, labels, size);
}

void replace_labels(char **tab, label_t *labels)
{
    unsigned size = 0;
    unsigned temp1 = 0;
    unsigned temp2 = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        if (is_command(&tab[i], &size))
            temp2 = temp1;
        temp1 = size;
        is_label_call(&tab[i], labels, temp2);
    }
}
