/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** settings
*/

#include "../../include/my_rpg.h"

static void on_fps(general_t *g)
{
    if (is_on_button(g->menu->om_less1, g) == 1) {
        g->menu->sm_crack->pos.x = g->menu->om_fps->pos.x;
        g->menu->sm_crack->pos.y = g->menu->om_fps->pos.y;
        sfSprite_setPosition(g->menu->sm_crack->sprite,
        g->menu->sm_crack->pos);
        g->mouse_on = CRACK;
        return;
    } if (is_on_button(g->menu->om_more1, g) == 1) {
        g->menu->sm_crack->pos.x = g->menu->om_fps->pos.x + 314 * 1.5;
        g->menu->sm_crack->pos.y = g->menu->om_fps->pos.y;
        sfSprite_setPosition(g->menu->sm_crack->sprite,
        g->menu->sm_crack->pos);
        g->mouse_on = CRACK;
        return;
    }
    g->mouse_on = NOTHING;
}

static void on_music(general_t *g)
{
    if (is_on_button(g->menu->om_less2, g) == 1) {
        g->menu->sm_crack->pos.x = g->menu->om_musique->pos.x;
        g->menu->sm_crack->pos.y = g->menu->om_musique->pos.y;
        sfSprite_setPosition(g->menu->sm_crack->sprite,
        g->menu->sm_crack->pos);
        g->mouse_on = CRACK;
        return;
    } if (is_on_button(g->menu->om_more2, g) == 1) {
        g->menu->sm_crack->pos.x = g->menu->om_musique->pos.x + 314 * 1.5;
        g->menu->sm_crack->pos.y = g->menu->om_musique->pos.y;
        sfSprite_setPosition(g->menu->sm_crack->sprite,
        g->menu->sm_crack->pos);
        g->mouse_on = CRACK;
        return;
    }
    on_fps(g);
}

static void on_fx(general_t *g)
{
    if (is_on_button(g->menu->om_less3, g) == 1) {
        g->menu->sm_crack->pos.y = g->menu->om_fx->pos.y;
        g->menu->sm_crack->pos.x = g->menu->om_fx->pos.x;
        sfSprite_setPosition(g->menu->sm_crack->sprite,
        g->menu->sm_crack->pos);
        g->mouse_on = CRACK;
        return;
    } if (is_on_button(g->menu->om_more3, g) == 1) {
        g->menu->sm_crack->pos.x = g->menu->om_fx->pos.x + 314 * 1.5;
        g->menu->sm_crack->pos.y = g->menu->om_fx->pos.y;
        sfSprite_setPosition(g->menu->sm_crack->sprite,
        g->menu->sm_crack->pos);
        g->mouse_on = CRACK;
        return;
    }
    on_music(g);
}

void on_settings(general_t *g)
{
    on_fx(g);
}
