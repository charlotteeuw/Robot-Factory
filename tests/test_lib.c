/*
** EPITECH PROJECT, 2024
** test_lib.c
** File description:
** lib unit test
*/

#include <robot_factory.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(my_strcat, valid_strings)
{
    char *dest = "hello";
    char *src = "world";
    char *output = my_strcat(dest, src);

    cr_redirect_stdout();
    cr_assert_stdout_eq_str(output);
}

Test(my_count_words, null_str)
{
    char *s = NULL;
    int result = my_count_words(s);

    cr_assert_eq(result, 0);
}

Test(my_count_words, multiple_words)
{
    char *s = "hi hello hey";
    int result = my_count_words(s);

    cr_assert_eq(result, 3);
}

Test(my_count_words, one_word)
{
    char *s = "hi";
    int result = my_count_words(s);

    cr_assert_eq(result, 1);
}

Test(my_strcmp, s1_greater)
{
    char *s1 = "hello";
    char *s2 = "hi";
    int result = my_strcmp(s1, s2);

    cr_assert(result > 0);
}

Test(my_strcmp, s2_greater)
{
    char *s1 = "hi";
    char *s2 = "hello";
    int result = my_strcmp(s1, s2);

    cr_assert(result < 0);
}

Test(my_strcmp, equal_strings)
{
    char *s1 = "hi";
    char *s2 = "hi";
    int result = my_strcmp(s1, s2);

    cr_assert_eq(result, 0);
}

Test(my_strcmp, s1_null)
{
    char *s1 = NULL;
    char *s2 = "hello";
    int result = my_strcmp(s1, s2);

    cr_assert_eq(result, 0);
}

Test(my_strcmp, s2_null)
{
    char *s1 = "hello";
    char *s2 = NULL;
    int result = my_strcmp(s1, s2);

    cr_assert_eq(result, 0);
}

Test(my_strncpy, null_dest)
{
    char *src = "hi";
    char *dest = NULL;
    int n = 2;
    char *result = my_strncpy(dest, src, n);

    cr_assert_null(result);
}

Test(my_strncpy, null_src)
{
    char *src = NULL;
    char dest[3];
    int n = 2;
    char *result = my_strncpy(dest, src, n);

    cr_assert_null(result);
}

Test(my_strncpy, valid_strings)
{
    char *src = "hi";
    char dest[3];
    int n = 2;
    char *result = my_strncpy(dest, src, n);

    cr_assert_str_eq(result, src);
    cr_assert_str_eq(dest, src);
}

Test(my_strcpy, null_dest)
{
    char *src = "hi";
    char *dest = NULL;
    char *result = my_strcpy(dest, src);

    cr_assert_null(result);
}

Test(my_strcpy, null_src)
{
    char *src = NULL;
    char dest[3];
    char *result = my_strcpy(dest, src);

    cr_assert_null(result);
}

Test(my_strcpy, valid_strings)
{
    char *src = "hi";
    char dest[3];
    char *result = my_strcpy(dest, src);

    cr_assert_str_eq(result, src);
    cr_assert_str_eq(dest, src);
}

Test(my_strdup, valid_strings)
{
    char *input = "hi";
    char *result = my_strdup(input);

    cr_assert_str_eq(result, input);
}

Test(my_strdup, empty_input)
{
    char *input = "";
    char *result = my_strdup(input);

    cr_assert_null(result);
}

Test(my_strdup, null_input)
{
    char *input = NULL;
    char *result = my_strdup(input);

    cr_assert_null(result);
}

Test(my_itoa, convert_characters)
{
    int nb = 1024;
    char *result = my_itoa(nb);

    cr_redirect_stdout();
    cr_assert_stdout_eq_str(result);
}

Test(my_itoa, negative_number)
{
    int nb = -1024;
    char *result = my_itoa(nb);

    cr_redirect_stdout();
    cr_assert_stdout_eq_str(result);
}

Test(my_atoi, convert_numbers)
{
    char *str = "1024";
    int result = my_atoi(str);

    cr_assert_eq(result, 1024);
}

Test(my_atoi, negative_str)
{
    char *str = "-1024";
    int result = my_atoi(str);

    cr_assert_eq(result, -1024);
}

Test(my_atoi, convert_alphanumbers)
{
    char *str = "1024abc";
    int result = my_atoi(str);

    cr_assert_eq(result, 1024);
}

Test(my_strlen, test_null_string)
{
    char *input = NULL;
    int result = my_strlen(input);

    cr_assert_eq(result, 0);
}

Test(my_strlen, valid_input)
{
    char *input = "hi";
    int result = my_strlen(input);

    cr_assert_eq(result, 2);
}

Test(my_strlen, empty_input)
{
    char *input = "";
    int result = my_strlen(input);

    cr_assert_eq(result, 0);
}

Test(my_putstr, valid_input)
{
    char *input = "hi";

    cr_redirect_stdout();
    my_putstr(input);
    cr_assert_stdout_eq_str(input);
}

Test(my_putstr, empty_input)
{
    char *input = "";

    cr_redirect_stdout();
    my_putstr(input);
    cr_assert_stdout_eq_str("");
}

Test(my_putstr, null_input)
{
    char *input = NULL;

    cr_redirect_stdout();
    my_putstr(input);
    cr_assert_stdout_eq_str("");
}
