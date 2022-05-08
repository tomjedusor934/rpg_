/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include "../../include/my_rpg.h"

static int len_of_word(char const *str, int pos, char del)
{
    int len = 0;

    for (; str[pos + len] != del && str[pos + len] != '\0'; len++);
    return (len);
}

static int nb_col(char const *str, char del)
{
    int row = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        while (str[i] == del)
            i++;
        if (str[i] == '\0')
            break;
        row++;
        while (str[i] != del && str[i] != '\0')
            i++;
        i--;
    }
    return (row);
}

char **str_to_warray(char *str, char const del)
{
    char **array = malloc(sizeof(char *) * (nb_col(str, del) + 1));
    int pos = 0;
    int size = 0;
    if (array == NULL)
        return (NULL);
    for (int i = 0; i < nb_col(str, del); i++) {
        for (; str[pos] == del; pos++);
        size = len_of_word(str, pos, del);
        array[i] = malloc(sizeof(char) * (size + 1));
        if (array[i] == NULL)
            return (NULL);
        for (int j = 0; str[pos + j] != del &&
        str[pos + j] != '\0'; j++)
            array[i][j] = str[pos + j];
        pos += size;
        array[i][size] = '\0';
        for (; str[pos] == del; pos++);
    }
    array[nb_col(str, del)] = NULL;
    return (array);
}
