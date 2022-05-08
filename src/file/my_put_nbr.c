/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "../../include/my_rpg.h"


int my_strlen(char const *str)
{
    int len = 0;
    for (; str[len] != '\0'; len++);
    return (len);
}

int my_intlen(int n)
{
    int count = 1;
    while (n >= 10 || n <= -10) {
        n /= 10;
        count++;
    }
    return count;
}

char *my_revstr(char *str)
{
    int longeur = my_strlen(str) -1;

    for (int j = 0; j <= longeur / 2; j++) {
        int temp = *(str + j);
        *(str + j) = *(str + longeur - j);
        *(str + longeur - j) = temp;
    }
    return str;
}

char *my_int_to_char(int nbr)
{
    int nb = nbr;
    int i = 0;
    int tmp = 0;
    int div = 1;
    int lengh = my_intlen(nbr);
    char *str = malloc(sizeof(char) * my_intlen(nbr) + 1);
    for (; i != lengh; i++) {
        if (nbr >= 10) {
            nbr = nb / div;
            div *= 10;
        }
        tmp = nbr % 10;
        str[i] = tmp + 48;
    }
    str[i] = '\0';
    my_revstr(str);
    return (str);
}
