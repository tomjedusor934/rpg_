/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** additionnal_functions2
*/

#include "../../include/my_rpg.h"

int len_of_word(char const *str, int pos, char del)
{
    int len = 0;
    for (; str[pos + len] != del && str[pos + len] != '\0'; len++);
    return (len);
}

int nb_of_colums(char const *str, char del)
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

char **my_str_to_wordarray(char const *str, char del)
{
    int row = nb_of_colums(str, del);
    char **array = malloc(sizeof(char *) * (row + 1));
    int pos = 0;
    for (int i = 0; i < row; i++) {
        for (; str[pos] == del; pos++);
        int size = len_of_word(str, pos, del);
        array[i] = malloc(sizeof(char) * (size + 1));
        for (int j = 0; str[pos + j] != del &&
        str[pos + j] != '\0'; j++)
            array[i][j] = str[pos + j];
        pos += size;
        array[i][size] = '\0';
        for (; str[pos] == del; pos++);
    }
    array[row] = NULL;
    return (array);
}

void load_m(char *filepath, general_t *g)
{
    struct stat buff;
    char *buffer = NULL;
    char **array = NULL;
    int file = 0;
    int reading_file = 0;

    if ((file = open(filepath, O_RDONLY)) == -1)
        return;
    stat(filepath, &buff);
    if (buff.st_size == 0)
        return;
    if ((buffer = malloc(sizeof(char) * buff.st_size + 1)) == NULL)
        return;
    reading_file = read(file, buffer, buff.st_size);
    if (reading_file == -1)
        return;
    buffer[reading_file] = '\0';
    if ((array = my_str_to_wordarray(buffer, '\n')) == NULL)
        return;
    g->f->map = array;
}