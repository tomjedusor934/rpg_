/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** game_object
*/

#include "../../include/my_rpg.h"

struct class_object *create_object(const char *path_to_spritesheet,
sfVector2f pos, sfIntRect rect, sfVector2f scale)
{
    game_object_t *create = malloc(sizeof(game_object_t));
    create->tex = sfTexture_createFromFile(path_to_spritesheet, NULL);
    create->sprite = sfSprite_create();
    create->rect = rect;
    create->pos = pos;
    create->scale = scale;
    sfSprite_setTexture(create->sprite, create->tex, sfTrue);
    sfSprite_setTextureRect(create->sprite, create->rect);
    sfSprite_setPosition(create->sprite, create->pos);
    sfSprite_setScale(create->sprite, create->scale);
    return (create);
}
