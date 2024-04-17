/*
** EPITECH PROJECT, 2024
** file.c
** File description:
** functions related to files
*/

#include <robot_factory.h>

char *get_binary_name(char *filepath)
{
    char *name = my_basename(filepath);
    int len = my_strlen(name);
    char *output = malloc(sizeof(char) * (len + 3));

    my_strncpy(output, name, len - 1);
    my_strcat(output, "cor");
    return output;
}

char *get_path(char *name)
{
    char path[1024];

    sprintf(path, "robots/%s", name);
    return path;
}

int compile(char *champion)
{
    FILE *src = fopen(champion, "r");
    FILE *dest = fopen(get_binary_name(champion), "w");
    struct stat sb;
    char *buffer;
    char **tab;
    int size_read = 0;

    if (!src || !dest)
        return 84;
    stat(champion, &sb);
    buffer = malloc(sizeof(char) * sb.st_size + 1);
    size_read = fread(buffer, sizeof(char), sb.st_size + 1, src);
    buffer[size_read] = '\0';
    tab = my_split(buffer);
    convert(tab, dest);
    fclose(src);
    fclose(dest);
    return 0;
}
