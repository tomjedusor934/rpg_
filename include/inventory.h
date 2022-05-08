/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** inventory
*/

#ifndef INVENTORY_H_
    #define INVENTORY_H_
    #include "my_rpg.h"

typedef struct slot {
    game_object_t *slots;
    game_object_t *item;
    int is_empty;
    int item_type;
    char *name;
    struct slot *next;
}slot_t;

typedef struct equip {
    game_object_t *eq;
    game_object_t *item;
    int is_eq;
    int item_type;
    char *name;
    struct equip *next;
}equip_t;

typedef struct inventaire {
    game_object_t *inventaire;
    int is_open;
    int dad_inv;
    int dadx;
    int dady;
    int dad_item;
    float dad_itemx;
    float dad_itemy;
    int dad_eq;
    game_object_t *invcarac;
    game_object_t *bouton[7];
    int caract_open;
    sfFont *font_caract;
    sfText *text_caract;
    slot_t *slot;
    equip_t *equip;
}inventaire_t;

#endif /* !INVENTORY_H_ */
