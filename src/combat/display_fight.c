/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** display_fight
*/

#include "../../include/my_rpg.h"

void display_fight2(general_t *g)
{
    mobs_fight_t *backup = g->f->mobs_fight;
    while (g->f->mobs_fight) {
        if (g->f->mobs_fight->is_dead == 0) {
            g->f->mobs_fight->mobs->pos = (sfVector2f)
            {g->f->mobs_fight->posx * 60, g->f->mobs_fight->posy * 60};
            sfSprite_setPosition(g->f->mobs_fight->mobs->sprite,
            g->f->mobs_fight->mobs->pos);
            sfRenderWindow_drawSprite(g->game->window,
            g->f->mobs_fight->mobs->sprite, NULL);
        }
        g->f->mobs_fight = g->f->mobs_fight->next;
    }
    g->f->mobs_fight = backup;
}

void display_spells(general_t *g)
{
    int i = 578;

    while (g->player->stat_player->sort->next != NULL) {
        sfSprite_setPosition(g->player->stat_player->sort->s->logo->sprite,
        (sfVector2f) {i, 930});
        g->player->stat_player->sort->s->logo->pos =
        sfSprite_getPosition(g->player->stat_player->sort->s->logo->sprite);
        sfRenderWindow_drawSprite(g->game->window,
        g->player->stat_player->sort->s->logo->sprite, NULL);
        i += 62;
        g->player->stat_player->sort = g->player->stat_player->sort->next;
    }
}

void display_fight(general_t *g)
{
    spells_list_t *backup = g->player->stat_player->sort;
    sfRenderWindow_drawSprite(g->game->window, g->f->go[1]->sprite, NULL);
    sfRenderWindow_drawSprite(g->game->window, g->f->go[2]->sprite, NULL);
    if (g->f->selected != NULL) {
        sfSprite_setPosition(g->f->selected->logo->sprite, g->game->pos_mouse);
        sfRenderWindow_drawSprite(g->game->window,
        g->f->selected->logo->sprite, NULL);
    }
    display_spells(g);
    sfSprite_setPosition(g->f->logo->sprite,
    (sfVector2f) {get_player_pos(g)->x * 60, get_player_pos(g)->y * 60});
    sfRenderWindow_drawSprite(g->game->window, g->f->logo->sprite, NULL);
    g->player->stat_player->sort = backup;
    display_fight2(g);
}
