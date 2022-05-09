/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** init_fight
*/

#include "../../include/my_rpg.h"

void init_fight(general_t *g)
{
    load_m("asset/map_custom.txt", g);
    g->f->text_fight = sfText_create();
    g->f->font_fight = sfFont_createFromFile("text/police.ttf");
    g->f->go[0] = create_object("asset/square.png", (sfVector2f) {0, 0},
    (sfIntRect) {0, 0, 60, 60}, (sfVector2f) {1, 1});
    g->f->go[1] = create_object("asset/spell_bar.png", (sfVector2f) {400, 900},
    (sfIntRect) {0, 0, 751, 130}, (sfVector2f) {1.5, 1.5});
    g->f->go[2] = create_object("asset/tour.png", (sfVector2f) {1275, 928},
    (sfIntRect) {0, 0, 156, 69}, (sfVector2f) {1.5, 1.5});
    g->f->victory = create_object("asset/victory.png", (sfVector2f) {500, 700},
    (sfIntRect) {0, 0, 597, 118}, (sfVector2f) {1, 1});
    g->f->map[10][10] = 'P';
    g->f->is_fg = 0;
    g->f->is_mturn = 0;
    g->f->selected = NULL;
    g->f->mob_life = 0;
    g->f->victory_screen = 0;
    g->f->life_text = malloc(sizeof(text_f_t));
}

void reset_map(general_t *g)
{
    for (int i = 0; i != 18; i++) {
        for (int j = 0; j != 32; j++) {
            (g->f->map[i][j] != 'P' && g->f->map[i][j] != 'M' ? g->f->map[i][j] = ' ' : 0);
        }
    }
    if (g->f->selected != NULL)
        spell_range(get_player_pos(g), g,
        g->f->selected->max_range, g->f->selected->min_range);
}

void init_fight_mobs(general_t *g)
{
    mobs_fight_t *elemen = malloc(sizeof(mobs_fight_t));
    elemen->name = g->f->mobs->name;
    elemen->level = g->f->mobs->level;
    elemen->max_damage = g->f->mobs->max_damage;
    elemen->mobs = create_object(astrcat("asset/", elemen->name, ".png"),
    (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 200, 200}, (sfVector2f) 
    {0.30, 0.30});
    elemen->health = g->f->mobs->max_health - rand() % 
    (g->f->mobs->max_health - g->f->mobs->min_health);
    elemen->max_health = elemen->health;
    elemen->maxpm = g->f->mobs->pm;
    elemen->pm = g->f->mobs->pm;
    elemen->range = g->f->mobs->range;
    elemen->posx = 0;
    elemen->posy = 0;
    elemen->base_posx = elemen->posx;
    elemen->base_posy = elemen->posy;
    elemen->is_dead = 0;
    elemen->next = g->f->mobs_fight;
    g->f->mobs_fight = elemen;
}

void find_mob(general_t *g, char **array)
{
    mobs_t *tmp = g->f->mobs;
    while (g->f->mobs) {
        for (int i = 0; array[i]; i++)
            (mstrcmp(array[i], g->f->mobs->name) == 0 ? init_fight_mobs(g) : 0);
        g->f->mobs = g->f->mobs->next;
    }
    mobs_fight_t *tmp2 = g->f->mobs_fight;
    while (g->f->mobs_fight) {
        get_mobs_pos(g);
        g->f->mobs_fight->base_posx = g->f->mobs_fight->posx;
        g->f->mobs_fight->base_posy = g->f->mobs_fight->posy;
        g->f->mobs_fight = g->f->mobs_fight->next;
    }
    g->f->mobs_fight = tmp2;
    g->f->mobs = tmp;
}
