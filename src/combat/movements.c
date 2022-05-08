/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** movements
*/

#include "../../include/my_rpg.h"

sfVector2i *get_player_pos(general_t *g)
{
    sfVector2i *vector = malloc(sizeof(sfVector2i*));;
    for (int j = 0, i = 0; i != 18; j++) {
        (j == 32 ? j = 0, i++ : 0);
        if (g->f->map[i][j] == 'P') {
            vector->y = i;
            vector->x = j;
            return (vector);
        }
    }
    return (vector);
}

void get_mobs_pos(general_t *g)
{
    for (int j = 0, i = 0; i != 18; j++) {
        (j == 32 ? j = 0, i++ : 0);
        if (g->f->map[i][j] == 'E') {
            g->f->mobs_fight->posx = j;
            g->f->mobs_fight->posy = i;
            g->f->map[i][j] = 'M';
            return;
        }
    }
}

void fight_move2(general_t *g, int y, int x, sfVector2i *player_pos)
{
    if (x == player_pos->x && y == player_pos->y - 1 &&
    g->f->map[y][x] != 'M') {
        g->f->map[y][x] = 'P';
        g->f->map[player_pos->y][player_pos->x] = ' ',
        g->player->stat_player->info->pm--;
    }
    if (x == player_pos->x && y == player_pos->y + 1 &&
    g->f->map[y][x] != 'M') {
        g->f->map[y][x] = 'P';
        g->f->map[player_pos->y][player_pos->x] = ' ',
        g->player->stat_player->info->pm--;
    }
}

void fight_move(general_t *g, int y, int x)
{
    sfVector2i *player_pos = get_player_pos(g);
    if (x == player_pos->x - 1 && y == player_pos->y &&
    g->f->map[y][x] != 'M') {
        g->f->map[y][x] = 'P';
        g->f->map[player_pos->y][player_pos->x] = ' ',
        g->player->stat_player->info->pm--;
    }
    if (x == player_pos->x + 1 && y == player_pos->y &&
    g->f->map[y][x] != 'M') {
        g->f->map[y][x] = 'P';
        g->f->map[player_pos->y][player_pos->x] = ' ',
        g->player->stat_player->info->pm--;
    }
    fight_move2(g, y, x, player_pos);
}
