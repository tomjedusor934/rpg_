/*
** EPITECH PROJECT, 2022
** clean_defender
** File description:
** text
*/

#include "../../include/my_rpg.h"

int count_nbr(int nb)
{
    int s = 0;

    if (nb < 0) {
        nb = nb * (-1);
    }
    for (s = 0; nb >= 10; s++)
        nb = nb / 10;
    return (s);
}

char *int_to_str(int nb)
{
    int lent = count_nbr(nb);
    char *str = malloc(sizeof(char) * (lent + 1));

    for (int i = 0; i <= lent; i++) {
        str[i] = nb % 10 + '0';
        nb /= 10;
    }
    str[lent + 1] = '\0';
    str = my_revstr(str);
    return (str);
}
