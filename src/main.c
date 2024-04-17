/*
** EPITECH PROJECT, 2024
** main
** File description:
** main function for RobotFactory
*/

#include <robot_factory.h>

int main(int argc, char **argv)
{
    if (argc < 2) {
        write(2, "Not enough arguments, try again with -h\n",
        my_strlen("Not enough arguments, try again with -h\n"));
        return 84;
    }
    if (usage(argv[1]) == 1)
        return 0;
    if (error_checking(argc, argv) == 1)
        return 84;
    compile(argv[1]);
}
