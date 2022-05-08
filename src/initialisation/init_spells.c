/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** init_spells
*/

#include "../../include/my_rpg.h"

void set_spells_eni2(general_t *g)
{
    g->f->s->eni->s->name = get_str_until(g->f->spells_file, '=');
    g->f->spells_file = g->f->spells_file +
    my_strlen(get_str_until(g->f->spells_file, '=')) + 1;
    g->f->s->eni->s->logo = create_object(astrcat("asset/",
    g->f->s->eni->s->name, ".png"), (sfVector2f) {0, 0},
    (sfIntRect) {0, 0, 55, 55}, (sfVector2f) {1, 1});
    g->f->s->eni->s->element = my_atoi(g->f->spells_file, 0);
    g->f->spells_file = g->f->spells_file +
    intlen(my_atoi(g->f->spells_file, 0)) + 1;
    g->f->s->eni->s->pa = my_atoi(g->f->spells_file, 0);
    g->f->spells_file = g->f->spells_file +
    intlen(my_atoi(g->f->spells_file, 0)) + 1;
    g->f->s->eni->s->min_range = my_atoi(g->f->spells_file, 0);
    g->f->spells_file = g->f->spells_file +
    intlen(my_atoi(g->f->spells_file, 0)) + 1;
    g->f->s->eni->s->max_range = my_atoi(g->f->spells_file, 0);
    g->f->spells_file = g->f->spells_file +
    intlen(my_atoi(g->f->spells_file, 0)) + 1;
    g->f->s->eni->s->damage = my_atoi(g->f->spells_file, 0);
}

void set_spells_eni3(general_t *g)
{
    g->f->spells_file = g->f->spells_file +
    intlen(my_atoi(g->f->spells_file, 0)) + 1;
    g->f->s->eni->s->zone = my_atoi(g->f->spells_file, 0);
    g->f->spells_file = g->f->spells_file +
    intlen(my_atoi(g->f->spells_file, 0)) + 1;
    g->f->s->eni->s->lifesteal = my_atoi(g->f->spells_file, 0);
    g->f->spells_file = g->f->spells_file +
    intlen(my_atoi(g->f->spells_file, 0)) + 1;
    g->f->s->eni->next = malloc(sizeof(spells_list_t));
    g->f->s->eni = g->f->s->eni->next;
    g->f->s->eni->s = malloc(sizeof(spell_t));
}

void set_spells_eni(general_t *g)
{
    g->f->s->eni = malloc(sizeof(spells_list_t));
    g->f->s->eni->s = malloc(sizeof(spell_t));
    spells_list_t *backup =  g->f->s->eni;
    g->f->spells_file = g->f->spells_file + my_strlen(get_str_until(g->f->spells_file, ':')) + 1;
    for (int i = 0; i != 5; i++) {
        set_spells_eni2(g);
        if (g->f->s->eni->s->damage < 0)
        g->f->spells_file++;
        set_spells_eni3(g);
    }
    g->f->s->eni->next = NULL;
    g->f->s->eni = backup;
    g->f->spells_file++;
    set_spells_iop(g);
}

void init_spells(general_t *g)
{
    g->f->s = malloc(sizeof(spells_t));
    g->f->spells_file = load_file("src/file/player_spells");
    set_spells_cra(g);
}