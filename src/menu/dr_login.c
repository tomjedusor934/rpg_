/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** loading_menu
*/

#include "../../include/my_rpg.h"

void login_menu(general_t *g)
{
    log_one(g), log_two(g), log_three(g);
    if (g->surscene != NOTHING) return;
    (g->selected == NOTHING ? class_message(g) : g->selected == ENIRIPSA ?
    class_eniripsa(g) : g->selected == CRA ? class_cra(g) : g->selected ==
    SACRIEUR ? class_sacrieur(g) : g->selected == IOP ? class_iop(g) : 0);
}
