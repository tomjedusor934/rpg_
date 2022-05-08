/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-tetris-tom.dumort
** File description:
** error_manage
*/

#include "../../include/my_rpg.h"

char *concat_name(char *src)
{
    char *final_str = malloc(sizeof(char) * my_strlen(src) + 6);
    char *file = "map/";
    int i = 0;
    for (; file[i] != '\0'; i++)
        final_str[i] = file[i];
    for (int x = 0; src[x] != '\0'; i++, x++)
        final_str[i] = src[x];
    final_str[i] = '\0';
    return (final_str);
}
