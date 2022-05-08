/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** resetup
*/

#include "../../include/my_rpg.h"

int setup_camx(general_t *g)
{
    g->player->cam_posx = 1920 * (g->pos_playe_x / 1920);
    return (1920 * (g->pos_playe_x / 1920) + (1920 / 2));
}

int setup_camy(general_t *g)
{
    g->player->cam_posy = 1080 * (g->pos_player_y / 1080);
    return (1080 * (g->pos_player_y / 1080) + (1080 / 2));
}
void recenter_cam(general_t *g)
{
    sfView_setCenter(g->game->cam, (sfVector2f) {setup_camx(g),
    setup_camy(g)});

    g->inv->inventaire->pos.x = g->player->cam_posx + 530;
    g->inv->inventaire->pos.y = g->player->cam_posy + 200;
    sfSprite_setPosition(g->inv->inventaire->sprite, (sfVector2f)
    {g->inv->inventaire->pos.x, g->inv->inventaire->pos.y});
    //dad_inv_slot(g);
    //dad_inv_eq(g);
    dad_ep_item(g);
    sfRenderWindow_setView(g->game->window, g->game->cam);
}
