/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** complement_file3
*/

#include "../../include/my_rpg.h"

void print_carac(general_t *g)
{
    print_text(g , g->inv->invcarac->pos.x + 250, g->inv->invcarac->pos.y + 68,
    g->player->stat_player->info->max_vie);
    print_text(g , g->inv->invcarac->pos.x + 250, g->inv->invcarac->pos.y +
    102, g->player->stat_player->info->pa);
    print_text(g , g->inv->invcarac->pos.x + 250, g->inv->invcarac->pos.y +
    140, g->player->stat_player->info->pm);
    print_text(g , g->inv->invcarac->pos.x + 230, g->inv->invcarac->pos.y +
    195, g->player->stat_player->info->max_vie);
    print_text(g , g->inv->invcarac->pos.x + 230, g->inv->invcarac->pos.y +
    230, g->player->stat_player->info->agilite);
    print_text(g , g->inv->invcarac->pos.x + 230, g->inv->invcarac->pos.y +
    265, g->player->stat_player->info->chance);
    print_text(g , g->inv->invcarac->pos.x + 230, g->inv->invcarac->pos.y +
    300, g->player->stat_player->info->force);
    print_text(g , g->inv->invcarac->pos.x + 230, g->inv->invcarac->pos.y +
    335, g->player->stat_player->info->inteligence);
    print_text(g , g->inv->invcarac->pos.x + 230, g->inv->invcarac->pos.y +
    370, g->player->stat_player->info->sagesse);
    print_text(g , g->inv->invcarac->pos.x + 200, g->inv->invcarac->pos.y +
    410, g->player->stat_player->point_caract);
}

void mu_intro(general_t *g)
{
    g->menu->b_intro = sfSoundBuffer_createFromFile("asset/intro.ogg");
    g->menu->s_intro = sfSound_create();
    sfSound_setBuffer(g->menu->s_intro, g->menu->b_intro);
    sfSound_play(g->menu->s_intro);
    sfSound_getLoop(g->menu->s_intro);
    sfSound_setVolume(g->menu->s_intro, g->music);
}

void mu_clicked(general_t *g)
{
    g->menu->b_clicked = sfSoundBuffer_createFromFile("asset/click.ogg");
    g->menu->s_clicked = sfSound_create();
    sfSound_setBuffer(g->menu->s_clicked, g->menu->b_clicked);
    sfSound_setVolume(g->menu->s_clicked, g->fx);
}

void mu_released(general_t *g)
{
    g->menu->b_released = sfSoundBuffer_createFromFile("asset/released.ogg");
    g->menu->s_released = sfSound_create();
    sfSound_setBuffer(g->menu->s_released, g->menu->b_released);
    sfSound_setVolume(g->menu->s_released, g->fx);
}

void musics(general_t *g)
{
    mu_intro(g);
    mu_clicked(g);
    mu_released(g);
}
