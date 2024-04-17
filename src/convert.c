/*
** EPITECH PROJECT, 2024
** convert.c
** File description:
** functions related to converting into hex
*/

#include <robot_factory.h>

static char add_type(unsigned char result, char **line, int i)
{
    switch (line[i][0]) {
        case 'r':
            result = result << 2;
            result += 0b01;
            break;
        case DIRECT_CHAR:
            result = result << 2;
            result += 0b10;
            break;
        default:
            result = result << 2;
            result += 0b11;
    }
    return result;
}

static void check_type(char **line, FILE *dest, char nb_args)
{
    unsigned char result = 0;
    int i = 1;

    for (; i < nb_args + 1; i++)
        result = add_type(result, line, i);
    for (; i < 5; i++) {
        result = result << 2;
        result += 0b00;
    }
    my_fwrite(&result, 1, sizeof(unsigned char), dest);
}

static int coding_byte(char **line, FILE *dest, char nb_args)
{
    if (my_strcmp(line[0], "live") &&
        my_strcmp(line[0], "zjmp") &&
        my_strcmp(line[0], "fork") &&
        my_strcmp(line[0], "lfork"))
        check_type(line, dest, nb_args);
    return 0;
}

static void direct_or_index(char **line, int temp, FILE *dest)
{
    if (my_strcmp(line[0], "zjmp") == 0 || my_strcmp(line[0], "ldi") == 0
    || my_strcmp(line[0], "sti") == 0 || my_strcmp(line[0], "fork") == 0)
        my_fwrite(&temp, 1, IND_SIZE, dest);
    else
        my_fwrite(&temp, 1, DIR_SIZE, dest);
}

static int parameter(char **line, FILE *dest, char nb_args)
{
    int temp = 0;

    for (int i = 1; i < nb_args + 1; i++) {
        switch (line[i][0]) {
            case 'r':
                temp = my_atoi(&line[i][1]);
                my_fwrite(&temp, 1, sizeof(char), dest);
                break;
            case DIRECT_CHAR:
                temp = my_atoi(&line[i][1]);
                direct_or_index(line, temp, dest);
                break;
            default:
                temp = my_atoi(&line[i][0]);
                my_fwrite(&temp, 1, IND_SIZE, dest);
        }
    }
    return 0;
}

static int match_command(char **line, FILE *dest)
{
    for (int i = 0; i < 16; i++) {
        if (my_strcmp(line[0], op_tab[i].mnemonique) == 0) {
            my_fwrite(&op_tab[i].code, 1, sizeof(char), dest);
            coding_byte(line, dest, op_tab[i].nbr_args);
            parameter(line, dest, op_tab[i].nbr_args);
            return op_tab[i].nbr_args;
        }
    }
    return 0;
}

static int body(char **tab, FILE *dest)
{
    for (int i = 0; tab[i] != NULL; i++) {
        i += match_command(&tab[i], dest);
    }
    return 0;
}

int convert(char **tab, FILE *dest)
{
    header(tab, dest);
    body(tab, dest);
    return 0;
}
