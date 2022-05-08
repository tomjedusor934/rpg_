/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** enter_id
*/

#include "../../include/my_rpg.h"

void choose_file(general_t *g, char letter)
{
    char *str = NULL;
    if (g->game->file == 1)
        str = g->game->login;
    if (g->game->file == 2)
        str = g->game->pasword_login;
    if (g->game->file == 3)
        str = g->game->user_name;
    if (g->game->file == 4)
        str = g->game->new_pasword;
    if (g->game->file != 0)
        enter_id(g, str, letter);
}

void choose_output(general_t *g, char *str)
{
    if (g->game->file == 1)
        g->game->login = str;
    if (g->game->file == 2)
        g->game->pasword_login = str;
    if (g->game->file == 3)
        g->game->user_name = str;
    if (g->game->file == 4)
        g->game->new_pasword = str;
}

void fill_id(char letter, char *str)
{
    int x = 0;

    if (((letter >= 'a' && letter <= 'z') || letter == 57) && my_strlen(str) != 20) {
        for (; str[x] != '\0'; x++);
        if (letter != 57)
            str[x] = letter;
        else
            str[x] = ' ';
        str[x + 1] = '\0';
    }
    if (letter == 59) {
        for (; str[x] != '\0'; x++);
        if (x != 0)
            str[x - 1] = '\0';
    }

}

void secure_pasword(general_t *g)
{
    int i = 0;
    int j = 0;

    if (g->game->pasword_login) {
        for(; g->game->pasword_login[i] != '\0'; i++)
            g->game->hidden_pasword[i] = 'x';
        g->game->hidden_pasword[i] = '\0';
    }
    if (g->game->new_pasword) {
        for(; g->game->new_pasword[j] != '\0'; j++)
            g->game->hidd_new_paswd[j] = 'x';
        g->game->hidd_new_paswd[j] = '\0';
    }
}

void enter_id(general_t *g, char *new_str, char letter)
{
    char *str = NULL;
    if (new_str  == NULL) {
        str = malloc(sizeof(char) * 21);
        str[0] = '\0';
    }
    else
        str = new_str;
    fill_id(letter, str);
    choose_output(g, str);
    secure_pasword(g);
}
