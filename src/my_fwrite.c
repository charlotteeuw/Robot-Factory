/*
** EPITECH PROJECT, 2024
** my_fwrite.c
** File description:
** fwrite
*/

#include <robot_factory.h>

size_t my_fwrite(void *ptr, size_t size, size_t n, FILE *restrict stream)
{
    unsigned char *p = ptr + size * n;

    for (size_t i = 0; i < size * n; i++) {
        p--;
        fwrite(p, 1, sizeof(char), stream);
    }
    return size * n;
}
