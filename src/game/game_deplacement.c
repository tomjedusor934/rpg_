/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** game_deplacement
*/

#include "../../include/my_rpg.h"

int arrow_movement(general_t *g)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        g->in_mouvement = 2;
        g->pos_playe_x -= 2;
        g->player->player_ap->player->pos.x = g->pos_playe_x;
        return (1);
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        g->in_mouvement = 2;
        g->pos_playe_x += 2;
        g->player->player_ap->player->pos.x = g->pos_playe_x;
        return (1);
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        g->in_mouvement = 2;
        g->pos_player_y -= 2;
        g->player->player_ap->player->pos.y = g->pos_player_y;
        return (1);
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        g->in_mouvement = 2;
        g->pos_player_y += 2;
        g->player->player_ap->player->pos.y = g->pos_player_y;
        return (1);
    }
    return (0);
}

void *arrow_deplacement(general_t *g)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight) &&
    sfKeyboard_isKeyPressed(sfKeyUp)) {
        g->in_mouvement = 2;
        g->pos_playe_x += 2;
        g->player->player_ap->player->pos.x = g->pos_playe_x;
        g->pos_player_y -= 2;
        g->player->player_ap->player->pos.y = g->pos_player_y;
        return (NULL);
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) &&
    sfKeyboard_isKeyPressed(sfKeyDown)) {
        g->in_mouvement = 2;
        g->pos_playe_x += 2;
        g->player->player_ap->player->pos.x = g->pos_playe_x;
        g->pos_player_y += 2;
        g->player->player_ap->player->pos.y = g->pos_player_y;
        return (NULL);
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft) &&
    sfKeyboard_isKeyPressed(sfKeyUp)) {
        g->in_mouvement = 2;
        g->pos_playe_x -= 2;
        g->player->player_ap->player->pos.x = g->pos_playe_x;
        g->pos_player_y -= 2;
        g->player->player_ap->player->pos.y = g->pos_player_y;
        return (NULL);
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft) &&
    sfKeyboard_isKeyPressed(sfKeyDown)) {
        g->in_mouvement = 2;
        g->pos_playe_x -= 2;
        g->player->player_ap->player->pos.x = g->pos_playe_x;
        g->pos_player_y += 2;
        g->player->player_ap->player->pos.y = g->pos_player_y;
        return (NULL);
    }

    if (!arrow_movement(g))
        g->in_mouvement = 0;
    return (NULL);
}

int chose_dir(general_t *g, int pos_x, int pos_y)
{
    int check_x = abs(pos_x - g->pos_playe_x);
    int check_y = abs(pos_y - g->pos_player_y);
    if (g->player->dir_anim == 0) {
        if (pos_x > g->pos_playe_x && check_x >= check_y)
            g->player->side = 1;
        if (pos_x < g->pos_playe_x && check_x >= check_y)
            g->player->side = 2;
        if (pos_y > g->pos_player_y && check_y > check_x)
            g->player->side = 3;
        if (pos_y < g->pos_player_y && check_y > check_x)
            g->player->side = 4;
        g->player->dir_anim = 1;
    }
    return (0);
}

void *mouse_deplacement(general_t *g, int pos_x, int pos_y)
{

    if (!check_colision(g, pos_x, pos_y)) {
        g->i = 0;
        g->in_mouvement = 0;
        g->player->side = 0;
        return (NULL);
    }

    chose_dir(g, pos_x, pos_y);

    g->pos_playe_x = set_x((sfVector2f) {g->player->tmp_pos_x,
    g->player->tmp_pos_y}, (sfVector2f) {pos_x, pos_y}, g->i, g->j);
    g->pos_player_y = set_y((sfVector2f) {g->player->tmp_pos_x,
    g->player->tmp_pos_y}, (sfVector2f) {pos_x, pos_y}, g->i, g->j);
    g->player->player_ap->player->pos.x = g->pos_playe_x;
    g->player->player_ap->player->pos.y = g->pos_player_y;
    if (g->player->side != 0)
        clock_animation(g, g->player->side);
    if (g->i > 1)
        g->i -= 1;
    if (g->i == 1) {
        g->player->side = 0;
        g->in_mouvement = 0;
    }
    return (NULL);
}

int set_x(sfVector2f turret_pos, sfVector2f mob_pos, int i, int j)
{
    return ((turret_pos.x * i + mob_pos.x * (j - i)) / j);
}

int set_y(sfVector2f turret_pos, sfVector2f mob_pos, int i, int j)
{
    return ((turret_pos.y * i + mob_pos.y * (j - i)) / j);
}

int set_speed(sfVector2f start, sfVector2f dest)
{
    int speedx = pow(dest.x - start.x, 2);
    int speedy = pow(dest.y - start.y, 2);
    int speed = (3 * (sqrt((speedx) + (speedy))));
    return (speed);
}
