/*
** EPITECH PROJECT, 2024
** header
** File description:
** header
*/

#include <robot_factory.h>

static unsigned reverse(unsigned nb)
{
    unsigned rev = 0;

    for (int i = 0; i < 4; i++) {
        rev = rev << 8;
        rev += nb % 256;
        nb = nb >> 8;
    }
    return rev;
}

static void has_coding_byte(char **tab, unsigned *size)
{
    if (my_strcmp(tab[0], "live") &&
        my_strcmp(tab[0], "zjmp") &&
        my_strcmp(tab[0], "fork") &&
        my_strcmp(tab[0], "lfork"))
        (*size)++;
}

static void is_index(char **tab, unsigned *size)
{
    if (my_strcmp(tab[0], "zjmp") == 0 || my_strcmp(tab[0], "ldi") == 0
        || my_strcmp(tab[0], "sti") == 0 || my_strcmp(tab[0], "fork") == 0)
        *size += 2;
    else
        *size += 4;
}

static void parameter_size(char **tab, int nb_args, unsigned *size)
{
    for (int i = 1; i < nb_args + 1; i++) {
        switch (tab[i][0]) {
            case 'r':
                (*size)++;
                break;
            case DIRECT_CHAR:
                is_index(tab, size);
                break;
            default:
                *size += 2;
        }
    }
}

int is_command(char **tab, unsigned *size)
{
    for (int i = 0; i < 16; i++) {
        if (my_strcmp(tab[0], op_tab[i].mnemonique) == 0) {
            (*size)++;
            has_coding_byte(tab, size);
            parameter_size(tab, op_tab[i].nbr_args, size);
            return op_tab[i].nbr_args;
        }
    }
    return 0;
}

static unsigned get_prog_size(char **tab)
{
    unsigned size = 0;

    for (int i = 0; tab[i] != NULL; i++)
        i += is_command(&tab[i], &size);
    return size;
}

int header(char **tab, FILE *dest)
{
    header_t header = {0};
    int nb_labels = count_label(tab);
    label_t *labels = malloc(sizeof(label_t) * (nb_labels + 1));

    labels[nb_labels].name = NULL;
    get_labels(tab, labels);
    replace_labels(tab, labels);
    header.magic = reverse(COREWAR_EXEC_MAGIC);
    my_strcpy(header.prog_name, tab[1]);
    if (tab[2] != NULL)
        my_strcpy(header.comment, tab[3]);
    header.prog_size = reverse(get_prog_size(tab));
    fwrite(&header, sizeof(header_t), 1, dest);
    return 0;
}
