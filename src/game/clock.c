/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** clock
*/

#include "../../include/my_rpg.h"

void draw_good_sprite(general_t *g)
{
    if (g->player->player_ap->go_left->rect.left >= 400)
        g->player->player_ap->go_left->rect.left = 0;
    if (g->player->player_ap->go_up->rect.left >= 400)
        g->player->player_ap->go_up->rect.left = 0;
    if (g->player->player_ap->go_right->rect.left >= 400)
        g->player->player_ap->go_right->rect.left = 0;
    if (g->player->player_ap->go_down->rect.left >= 400)
        g->player->player_ap->go_down->rect.left = 0;
    sfSprite_setTextureRect(g->player->player_ap->go_right->sprite, g->player->player_ap->go_right->rect);
    sfSprite_setTextureRect(g->player->player_ap->go_left->sprite, g->player->player_ap->go_left->rect);
    sfSprite_setTextureRect(g->player->player_ap->go_up->sprite, g->player->player_ap->go_up->rect);
    sfSprite_setTextureRect(g->player->player_ap->go_down->sprite, g->player->player_ap->go_down->rect);
    sfSprite_setPosition(g->player->player_ap->go_left->sprite, (sfVector2f) {g->pos_playe_x, g->pos_player_y});
    sfSprite_setPosition(g->player->player_ap->go_right->sprite, (sfVector2f) {g->pos_playe_x, g->pos_player_y});
    sfSprite_setPosition(g->player->player_ap->go_up->sprite, (sfVector2f) {g->pos_playe_x, g->pos_player_y});
    sfSprite_setPosition(g->player->player_ap->go_down->sprite, (sfVector2f) {g->pos_playe_x, g->pos_player_y});
}

void clock_animation(general_t *g, int dir)
{
    g->s_clock->time_anim = sfClock_getElapsedTime(g->s_clock->animation);
    g->s_clock->second = g->s_clock->time_anim.microseconds / 1000000.0;
    if (g->s_clock->second >= 0.15) {
        if (dir == 1)
            g->player->player_ap->go_right->rect.left += 200;
        if (dir == 2)
            g->player->player_ap->go_left->rect.left += 200;
        if (dir == 3)
            g->player->player_ap->go_down->rect.left += 200;
        if (dir == 4)
            g->player->player_ap->go_up->rect.left += 200;
        draw_good_sprite(g);
        sfClock_restart(g->s_clock->animation);
    }
}
