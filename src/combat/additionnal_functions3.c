/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** additionnal_functions3
*/

#include "../../include/my_rpg.h"

char *astrcat(char *str1, char *str2, char *str3)
{
    char *returned = malloc(sizeof(char) * (my_strlen(str1) +
    my_strlen(str2) + my_strlen(str3) + 1));

    for (int i = 0; i != my_strlen(str1); i++)
        returned[i] = str1[i];
    for (int i = my_strlen(str1); i != my_strlen(str1) + my_strlen(str2); i++)
        returned[i] = str2[i - my_strlen(str1)];
    for (int i = my_strlen(str1) + my_strlen(str2); i != my_strlen(str1) +
    my_strlen(str2) +  my_strlen(str3); i++)
        returned[i] = str3[i - my_strlen(str1) - my_strlen(str2)];
    returned[my_strlen(str1) + my_strlen(str2) + my_strlen(str3)] = '\0';
    return returned;
}

void reset_the_map(general_t *g)
{
    mobs_fight_t *backup = g->f->mobs_fight;
    while (g->f->mobs_fight != NULL) {
        if (g->f->mobs_fight->is_dead == 0)
            g->f->map[g->f->mobs_fight->posy][g->f->mobs_fight->posx] = 'M';
        g->f->mobs_fight = g->f->mobs_fight->next;
    }
    g->f->mobs_fight = backup;
}
