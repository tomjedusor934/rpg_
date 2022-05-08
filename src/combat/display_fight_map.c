/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** display_fight_map
*/

#include "../../include/my_rpg.h"

void draw_map(general_t *g)
{
    int y = 0;

    for (; g->f->go[0]->pos.y <= 1020; g->f->go[0]->pos.y += 60) {
        draw_line(g, y);
    }
    g->f->go[0]->pos.y = 0;
    g->f->go[0]->pos.x = 0;
}

void draw_line(general_t *g, int y)
{
    int x = g->f->go[0]->pos.x;
    for (; g->f->go[0]->pos.x <= 1860; g->f->go[0]->pos.x += 60) {
        x = g->f->go[0]->pos.x;
        y = g->f->go[0]->pos.y;
        draw_line2(g, y, x);
    }
    g->f->go[0]->pos.x = 0;
}

void draw_line3(general_t *g, int y, int x)
{
    if (g->f->map[y / 60][x / 60] == 'M') {
        sfSprite_setPosition(g->f->go[0]->sprite, g->f->go[0]->pos);
        sfSprite_setColor(g->f->go[0]->sprite, sfRed);
        sfRenderWindow_drawSprite(g->game->window, g->f->go[0]->sprite, NULL);
        sfSprite_setColor(g->f->go[0]->sprite, sfWhite);
    }
}

void draw_line2(general_t *g, int y, int x)
{
    if (g->f->map[y / 60][x / 60] == ' ') {
        sfSprite_setPosition(g->f->go[0]->sprite, g->f->go[0]->pos);
        sfRenderWindow_drawSprite(g->game->window, g->f->go[0]->sprite, NULL);
    }
    if (g->f->map[y / 60][x / 60] == 'V') {
        sfSprite_setPosition(g->f->go[0]->sprite, g->f->go[0]->pos);
        sfSprite_setColor(g->f->go[0]->sprite, sfGreen);
        sfRenderWindow_drawSprite(g->game->window, g->f->go[0]->sprite, NULL);
        sfSprite_setColor(g->f->go[0]->sprite, sfWhite);
    }
    if (g->f->map[y / 60][x / 60] == 'U') {
        sfSprite_setPosition(g->f->go[0]->sprite, g->f->go[0]->pos);
        sfSprite_setColor(g->f->go[0]->sprite, sfBlue);
        sfRenderWindow_drawSprite(g->game->window, g->f->go[0]->sprite, NULL);
        sfSprite_setColor(g->f->go[0]->sprite, sfWhite);
    }
    draw_line3(g, y, x);
}
