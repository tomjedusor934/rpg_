/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** compare_paswd
*/

#include "../../include/my_rpg.h"

int my_str_compare(char *str , char *str2)
{
    if (my_strlen(str) != my_strlen(str2)) {
        return (0);
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != str2[i]) {
            return (0);
        }
    }
    return (1);
}

int compare_wiw(char *desired, char *str)
{
    for (int i = 0; desired[i] != '\0'; i++) {
        if (desired[i] != str[i]) {
            return (0);
        }
    }
    return (1);
}
