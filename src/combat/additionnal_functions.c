/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** additionnal_functions
*/

#include "../../include/my_rpg.h"

int count_line(char *str)
{
    int count = 0;

    for (int i = 0; i != my_strlen(str); i++) {
        if (str[i] == '\n')
            count++;
    }
    return (count++);
}

int intlen(int nb)
{
    int i = 0;

    if (nb == 0)
        return (1);

    while (nb > 0) {
        i++;
        nb = nb / 10;
    }
    return (i);
}
char *get_str_until(char *str, char separator)
{
    int i = 0;
    char *new_str = NULL;
    while (str[i] != separator)
        i++;
    new_str = malloc(sizeof(char) * i + 2);
    for (int a = 0; a != i; a++) {
        new_str[a] = str[a];
    }
    new_str[i] = '\0';
    return new_str;
}

char *remove_line(char *str)
{
    while (str[0] != '\n') {
        str++;
    }
    return (++str);
}

int my_atoi(char const *str, int pos)
{
    char *tmp = (char *) str;
    int res = 0;
    int index = 0;
    int retain = 10;
    int signe = 1;
    for (int i = 0; i < my_strlen(tmp) && (tmp[pos + i] !=
    '\0' && tmp[pos + i] != '\n'); i++) {
        if (tmp[pos + i] == '-')
            signe *= -1;
        if ((tmp[pos + i] > '9' || tmp[pos + i] < '0') && index == 1) {
            break;
        }
        if (tmp[pos + i] >= '0' && tmp [pos + i] <= '9') {

            res += (tmp[pos + i] - 48);
            res *= retain;
            index = 1;
        }
    }
    return ((res * signe) /10);
}
