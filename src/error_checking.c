/*
** EPITECH PROJECT, 2024
** error_checking
** File description:
** functions related to error checking
*/

#include <robot_factory.h>

int asm_puterr(char *file, int line, char *error)
{
    my_puterr("\033[1m\033[37m");
    my_puterr("asm, ");
    my_puterr(file);
    my_puterr(", line ");
    my_puterr(my_itoa(line + 1));
    my_puterr(": ");
    my_puterr("\033[36m");
    my_puterr(error);
    my_puterr(".\n");
    my_puterr("\033[0m");
    return 84;
}

int check_file(char *filepath)
{
    int size = my_strlen(filepath);
    FILE *src;

    if (my_strcmp(&filepath[size - 2], ".s") != 0)
        return 84;
    src = fopen(filepath, "r");
    if (src == NULL)
        return 84;
    fclose(src);
    return 0;
}

static int command_getid(char *str)
{
    for (int j = 0; j < 16; j++) {
        if (my_strcmp(str, op_tab[j].mnemonique) == 0)
            return j;
    }
    return -1;
}

static int body_goto(char **tab)
{
    int i = 0;
    char **line;

    while (tab[i] != NULL) {
        line = my_split(tab[i]);
        if (line[0] != NULL &&
            my_strcmp(line[0], COMMENT_CMD_STRING) &&
            my_strcmp(line[0], NAME_CMD_STRING))
            break;
        my_freetab(line);
        i++;
    }
    return i;
}

static int check_instruction(char *file, char **line, int line_id)
{
    int i = 0;

    if (line[i] != NULL && label_isdef(line[i]))
        i++;
    if (line[i] != NULL && command_getid(line[i]) == -1) {
        my_freetab(line);
        return asm_puterr(file, line_id, "Invalid instruction");
    }
    return 0;
}

static int check_nb_args(char *file, char **line, int line_id)
{
    int i = 0;
    int count = 0;
    int nb_args = 0;

    if (line[i] != NULL && label_isdef(line[i]))
        i++;
    if (line[i] == NULL)
        return 0;
    for (int j = i + 1; line[j]; j++)
        count++;
    nb_args = op_tab[command_getid(line[i])].nbr_args;
    if (count != nb_args) {
        if (count > nb_args)
            return asm_puterr(file, line_id,
                "Too many arguments given to the instruction");
        if (count < nb_args)
            return asm_puterr(file, line_id,
                "The argument given to the instruction is invalid");
    }
    return 0;
}

static int check_register_number(char *file, char **line, int line_id)
{
    int i = 0;
    int nb = 1;

    while (line[i] != NULL) {
        if (!label_isdef(line[i]) && line[i][0] == 'r')
            nb = my_atoi(&line[i][1]);
        if (nb < 1 || REG_NUMBER < nb) {
            asm_puterr(file, line_id, "Invalid register number");
            return 84;
        }
        i++;
    }
    return 0;
}

int check_body(char *file, char **tab)
{
    int i = body_goto(tab);
    char **line;

    while (tab[i] != NULL) {
        line = my_split(tab[i]);
        while (line[0] == NULL && tab[i + 1] != NULL) {
            i++;
            line = my_split(tab[i]);
        }
        if (tab[i] == NULL)
            break;
        if (check_instruction(file, line, i) == 84 ||
            check_nb_args(file, line, i) == 84 ||
            check_register_number(file, line, i) == 84)
            return 84;
        my_freetab(line);
        i++;
    }
    return 0;
}

int call_error_functions(char **argv, char **tab)
{
    if (check_header(argv[1], tab) == 84)
        return 84;
    if (check_body(argv[1], tab) == 84)
        return 84;
    if (check_label(argv[1], tab) == 84)
        return 84;
    return 0;
}

int error_checking(int argc, char **argv)
{
    char *buffer;
    struct stat sb;
    FILE *src;
    char **tab;

    if (argc != 2)
        return 1;
    if (check_file(argv[1]) == 84)
        return 1;
    stat(argv[1], &sb);
    src = fopen(argv[1], "r");
    buffer = malloc(sizeof(char) * sb.st_size + 1);
    buffer[fread(buffer, sizeof(char), sb.st_size, src)] = '\0';
    fclose(src);
    tab = buffer_into_tab(buffer, count_nb_lines(buffer));
    if (call_error_functions(argv, tab) == 84)
        return 1;
    return 0;
}
