/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** locked_scene
*/

#include "../../include/my_rpg.h"

static void on_iop_or_sac(general_t *g)
{
    if (is_on_button(g->menu->class_iop, g)) {
        g->mouse_on = IOP;
        return;
    } if (is_on_button(g->menu->class_sacrieur, g)) {
        g->mouse_on = SACRIEUR;
        return;
    }
    g->mouse_on = NOTHING;
}

static void on_eni_or_cra(general_t *g)
{
    if (is_on_button(g->menu->class_eniripsa, g)) {
        g->mouse_on = ENIRIPSA;
        return;
    } if (is_on_button(g->menu->class_cra, g)) {
        g->mouse_on = CRA;
        return;
    }
    on_iop_or_sac(g);
}

void on_locked_scene(general_t *g)
{
    on_eni_or_cra(g);
}
