/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** is_on_button
*/

#include "../../include/my_rpg.h"

int is_on_button(game_object_t *button, general_t *g)
{
    g->game->mouse = sfMouse_getPositionRenderWindow(g->game->window);
    if (g->game->pos_mouse.x > button->pos.x && g->game->pos_mouse.x <
    button->pos.x + button->rect.width * button->scale.x) {
        if (g->game->pos_mouse.y > button->pos.y && g->game->pos_mouse.y <
        button->pos.y + button->rect.height * button->scale.y) {
            return (1);
        }
    }
    return (0);
}

int is_on_text(text_gen_t *button, general_t *g)
{
    g->game->mouse = sfMouse_getPositionRenderWindow(g->game->window);
    if (g->game->pos_mouse.x > button->pos.x && g->game->pos_mouse.x <
    button->pos.x + 300) {
        if (g->game->pos_mouse.y > button->pos.y && g->game->pos_mouse.y <
        button->pos.y + 25) {
            return (1);
        }
    }
    return (0);
}
