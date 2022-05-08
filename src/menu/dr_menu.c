/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** menu
*/

#include "../../include/my_rpg.h"

void menu(general_t *g)
{
    (g->scene == LOADING || g->scene == LOADED ? loading_menu(g) :
    g->scene == LOGIN || g->scene == LOCKED ? login_menu(g) : 0);
    (g->surscene == SETTINGS ? option_menu(g) :
    g->surscene == MAIN_MENU ? main_menu(g) : 0);
    (g->mouse_on != NOTHING ? mouse_on(g) : 0);
}
