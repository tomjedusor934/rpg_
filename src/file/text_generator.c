/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** text_generator
*/

#include "../../include/my_rpg.h"

text_gen_t *text_gener(char *str, sfVector2f pos, int size)
{
    text_gen_t *text_gener = malloc(sizeof(text_gen_t));
    text_gener->text = sfText_create();
    text_gener->font = sfFont_createFromFile("text/police.ttf");
    sfText_setString(text_gener->text, str);
    sfText_setCharacterSize(text_gener->text, size);
    sfText_setColor(text_gener->text, sfBlack);
    sfText_setFont(text_gener->text, text_gener->font);
    text_gener->pos = pos;
    sfText_setPosition(text_gener->text, text_gener->pos);
    return (text_gener);
}

text_gen_t *text_gener2(char *str, sfVector2f pos, int size)
{
    text_gen_t *text_gener = malloc(sizeof(text_gen_t));
    text_gener->text = sfText_create();
    text_gener->font = sfFont_createFromFile("text/code.otf");
    sfText_setString(text_gener->text, str);
    sfText_setCharacterSize(text_gener->text, size);
    sfText_setColor(text_gener->text, sfWhite);
    sfText_setFont(text_gener->text, text_gener->font);
    text_gener->pos = pos;
    sfText_setPosition(text_gener->text, text_gener->pos);
    return (text_gener);
}
