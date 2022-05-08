/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** init_iop
*/

#include "../../include/my_rpg.h"

void set_spells_iop2(general_t *g)
{
    g->f->s->iop->s->name = get_str_until(g->f->spells_file, '=');
    g->f->spells_file = g->f->spells_file +
    my_strlen(get_str_until(g->f->spells_file, '=')) + 1;
    g->f->s->iop->s->logo = create_object(astrcat("asset/",
    g->f->s->iop->s->name, ".png"), (sfVector2f) {0, 0},
    (sfIntRect) {0, 0, 55, 55}, (sfVector2f) {1, 1});
    g->f->s->iop->s->element = my_atoi(g->f->spells_file, 0);
    g->f->spells_file = g->f->spells_file +
    intlen(my_atoi(g->f->spells_file, 0)) + 1;
    g->f->s->iop->s->pa = my_atoi(g->f->spells_file, 0);
    g->f->spells_file = g->f->spells_file +
    intlen(my_atoi(g->f->spells_file, 0)) + 1;
    g->f->s->iop->s->min_range = my_atoi(g->f->spells_file, 0);
}

void set_spells_iop3(general_t *g)
{
    g->f->spells_file = g->f->spells_file +
    intlen(my_atoi(g->f->spells_file, 0)) + 1;
    g->f->s->iop->s->max_range = my_atoi(g->f->spells_file, 0);
    g->f->spells_file = g->f->spells_file +
    intlen(my_atoi(g->f->spells_file, 0)) + 1;
    g->f->s->iop->s->damage = my_atoi(g->f->spells_file, 0);
    g->f->spells_file = g->f->spells_file +
    intlen(my_atoi(g->f->spells_file, 0)) + 1;
    g->f->s->iop->s->zone = my_atoi(g->f->spells_file, 0);
    g->f->spells_file = g->f->spells_file +
    intlen(my_atoi(g->f->spells_file, 0)) + 1;
    g->f->s->iop->s->lifesteal = my_atoi(g->f->spells_file, 0);
    g->f->spells_file = g->f->spells_file +
    intlen(my_atoi(g->f->spells_file, 0)) + 1;
    g->f->s->iop->next = malloc(sizeof(spells_list_t));
    g->f->s->iop = g->f->s->iop->next;
    g->f->s->iop->s = malloc(sizeof(spell_t));
}

void set_spells_iop(general_t *g)
{
    g->f->s->iop = malloc(sizeof(spells_list_t));
    g->f->s->iop->s = malloc(sizeof(spell_t));
    spells_list_t *backup =  g->f->s->iop;
    g->f->spells_file = g->f->spells_file +
    my_strlen(get_str_until(g->f->spells_file, ':')) + 1;
    for (int i = 0; i != 5; i++) {
        set_spells_iop2(g);
        set_spells_iop3(g);
    }
    g->f->s->iop->next = NULL;
    g->f->s->iop = backup;
    g->f->spells_file++;
    set_spells_sacri(g);
}
