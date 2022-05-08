/*
** EPITECH PROJECT, 2022
** newlib
** File description:
** strlen
*/

#include "../../include/my_rpg.h"

int mstrlen(char const *s)
{
    int i = 0;
    while (*s) i++, *s++;
    return (i);
}
