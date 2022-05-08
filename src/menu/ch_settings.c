/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** ch_settings
*/

#include "../../include/my_rpg.h"

static void ch_fps(general_t *g)
{
    if (g->menu->om_fps->rect.left >= 341 &&
    is_on_button(g->menu->om_less1, g)) {
        g->menu->om_fps->rect.left -= 341;
        framerates(g, '-');
        sfSprite_setTextureRect(g->menu->om_fps->sprite,
        g->menu->om_fps->rect);
        return;
    } if (g->menu->om_fps->rect.left < 1705 &&
    is_on_button(g->menu->om_more1, g)) {
        g->menu->om_fps->rect.left += 341;
        framerates(g, '+');
        sfSprite_setTextureRect(g->menu->om_fps->sprite,
        g->menu->om_fps->rect);
        return;
    } if (!is_on_button(g->menu->option_menu, g))
        (g->old_scene == NOTHING ? g->surscene = NOTHING :
        g->old_scene == MAIN_MENU ? g->surscene = MAIN_MENU : 0);
}

static void ch_musique(general_t *g)
{
    if (g->menu->om_musique->rect.left >= 341 &&
    is_on_button(g->menu->om_less2, g) == 1) {
        g->menu->om_musique->rect.left -= 341;
        sfSprite_setTextureRect(g->menu->om_musique->sprite,
        g->menu->om_musique->rect);
        g->music -= 20;
        sfSound_setVolume(g->menu->s_intro, g->music);
        return;
    } if (g->menu->om_musique->rect.left < 1705 &&
    is_on_button(g->menu->om_more2, g) == 1) {
        g->menu->om_musique->rect.left += 341;
        sfSprite_setTextureRect(g->menu->om_musique->sprite,
        g->menu->om_musique->rect);
        g->music += 20;
        sfSound_setVolume(g->menu->s_intro, g->music);
        return;
    }
    ch_fps(g);
}

static void ch_fx(general_t *g)
{
    if (g->menu->om_fx->rect.left >= 341 &&
    is_on_button(g->menu->om_less3, g)) {
        g->menu->om_fx->rect.left -= 341;
        sfSprite_setTextureRect(g->menu->om_fx->sprite, g->menu->om_fx->rect);
        g->fx -= 20;
        sfSound_setVolume(g->menu->s_clicked, g->fx);
        sfSound_setVolume(g->menu->s_released, g->fx);
        return;
    } if (g->menu->om_fx->rect.left < 1705 &&
    is_on_button(g->menu->om_more3, g)) {
        g->menu->om_fx->rect.left += 341;
        sfSprite_setTextureRect(g->menu->om_fx->sprite, g->menu->om_fx->rect);
        g->fx += 20;
        sfSound_setVolume(g->menu->s_clicked, g->fx);
        sfSound_setVolume(g->menu->s_released, g->fx);
        return;
    }
    ch_musique(g);
}

void ch_settings(general_t *g)
{
    if (is_on_button(g->menu->mom_cross, g)) {
        (g->old_scene == NOTHING ? g->surscene = NOTHING :
        g->old_scene == MAIN_MENU ? g->surscene = MAIN_MENU,
        g->old_scene = NOTHING : 0);
        return;
    }
    ch_fx(g);
}
