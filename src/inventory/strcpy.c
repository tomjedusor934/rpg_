/*
** EPITECH PROJECT, 2022
** newlib
** File description:
** strcpy
*/

#include "../../include/my_rpg.h"

char *mstrcpy(char *a, char const *b)
{
    a = malloc(sizeof(char) * (my_strlen(b) + 1));
    int i = 0;
    for (; b[i]; i++) a[i] = b[i];
    a[i] = '\0';
    return (a);
}
