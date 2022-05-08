/*
** EPITECH PROJECT, 2022
** newlib
** File description:
** strcmp
*/

#include "../../include/my_rpg.h"

int mstrcmp(char const *a, char const *b)
{
    return (*a == 0 && *b == 0 ? 0 : *a == *b ? mstrcmp(++a, ++b) : 1);
}
