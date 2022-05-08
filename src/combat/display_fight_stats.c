/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** display_fight_stats
*/

#include "../../include/my_rpg.h"

void print_text_fight(general_t *g, int x, int y, int text)
{
    sfText_setString(g->f->text_fight,
    my_int_to_char(text));
    sfText_setFont(g->f->text_fight, g->f->font_fight);
    sfText_setColor(g->f->text_fight, sfWhite);
    sfText_setCharacterSize(g->f->text_fight, 32);
    sfText_setPosition(g->f->text_fight, (sfVector2f) {x, y});
    sfRenderWindow_drawText(g->game->window, g->f->text_fight, NULL);
}

void display_test_fight(general_t *g)
{
    print_text_fight(g, 445, 1029, g->player->stat_player->info->pa);
    print_text_fight(g, 519, 1029, g->player->stat_player->info->pm);
    print_text_fight(g, 467, 920, g->player->stat_player->info->vie);
    print_text_fight(g, 467, 960, g->player->stat_player->info->max_vie);
    if (g->f->mob_life == 1) {
        print_text_fight(g, g->f->life_text->x,
        g->f->life_text->y, g->f->life_text->value);
    }
}

void display_victory(general_t *g)
{
    int decal_xp = intlen(g->f->reward_xp);
    int decal_kamas = intlen(g->f->reward_kama);

    sfSprite_setPosition(g->f->victory->sprite,
    (sfVector2f) {g->player->cam_posx + 650, g->player->cam_posy + 600});
    sfRenderWindow_drawSprite(g->game->window, g->f->victory->sprite, NULL);
    print_text_fight(g, g->player->cam_posx + 850 - decal_xp * 35,
    g->player->cam_posy + 653, g->f->reward_xp);
    print_text_fight(g, g->player->cam_posx + 980 - decal_kamas * 35,
    g->player->cam_posy + 653, g->f->reward_kama);
}
