/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** init_cra
*/

#include "../../include/my_rpg.h"

void set_spells_cra2(general_t *g)
{
    g->f->s->cra->s->name = get_str_until(g->f->spells_file, '=');
    g->f->spells_file = g->f->spells_file +
    my_strlen(get_str_until(g->f->spells_file, '=')) + 1;
    g->f->s->cra->s->logo = create_object(astrcat("asset/",
    g->f->s->cra->s->name, ".png"), (sfVector2f) {0, 0},
    (sfIntRect) {0, 0, 55, 55}, (sfVector2f) {1, 1});
    g->f->s->cra->s->element = my_atoi(g->f->spells_file, 0);
    g->f->spells_file = g->f->spells_file +
    intlen(my_atoi(g->f->spells_file, 0)) + 1;
    g->f->s->cra->s->pa = my_atoi(g->f->spells_file, 0);
    g->f->spells_file = g->f->spells_file +
    intlen(my_atoi(g->f->spells_file, 0)) + 1;
    g->f->s->cra->s->min_range = my_atoi(g->f->spells_file, 0);
}

void set_spells_cra3(general_t *g)
{
    g->f->spells_file = g->f->spells_file +
    intlen(my_atoi(g->f->spells_file, 0)) + 1;
    g->f->s->cra->s->max_range = my_atoi(g->f->spells_file, 0);
    g->f->spells_file = g->f->spells_file +
    intlen(my_atoi(g->f->spells_file, 0)) + 1;
    g->f->s->cra->s->damage = my_atoi(g->f->spells_file, 0);
    g->f->spells_file = g->f->spells_file +
    intlen(my_atoi(g->f->spells_file, 0)) + 1;
    g->f->s->cra->s->zone = my_atoi(g->f->spells_file, 0);
    g->f->spells_file = g->f->spells_file +
    intlen(my_atoi(g->f->spells_file, 0)) + 1;
    g->f->s->cra->s->lifesteal = my_atoi(g->f->spells_file, 0);
    g->f->spells_file = g->f->spells_file +
    intlen(my_atoi(g->f->spells_file, 0)) + 1;
    g->f->s->cra->next = malloc(sizeof(spells_list_t));
    g->f->s->cra = g->f->s->cra->next;
    g->f->s->cra->s = malloc(sizeof(spell_t));
}

void set_spells_cra(general_t *g)
{
    g->f->s->cra = malloc(sizeof(spells_list_t));
    g->f->s->cra->s = malloc(sizeof(spell_t));
    spells_list_t *backup =  g->f->s->cra;
    g->f->spells_file = g->f->spells_file +
    my_strlen(get_str_until(g->f->spells_file, ':')) + 1;
    for (int i = 0; i != 5; i++) {
        set_spells_cra2(g);
        set_spells_cra3(g);
    }
    g->f->s->cra->next = NULL;
    g->f->s->cra = backup;
    g->f->spells_file++;
    set_spells_eni(g);
}
