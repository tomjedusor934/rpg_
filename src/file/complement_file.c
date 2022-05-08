/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** complement_file
*/

#include "../../include/my_rpg.h"



void add_item_to_eq3(general_t *g, char *name, char *str)
{
    if (g->inv->equip->is_eq == 1 && g->inv->equip->item_type == 3) {
        g->inv->equip = g->inv->equip->next;
        g->inv->equip = g->inv->equip->next;
        str = mstrcpy(str, "asset/");
        str = mstrcat(str, name);
        str = mstrcat(str, ".png");
        g->inv->equip->name = mstrcpy(g->inv->equip->name, name);
        g->inv->equip->item = create_object(str,
        (sfVector2f) {g->inv->equip->eq->pos.x, g->inv->equip->eq->pos.y},
        (sfIntRect) {0, 0, 59, 59}, (sfVector2f) {1, 1});
        g->inv->equip->is_eq = 1;
    }
}

void add_item_to_eq2(general_t *g, char *name, char *str)
{
    if (g->inv->equip != NULL && g->inv->equip->is_eq == 0) {
        str = mstrcpy(str, "asset/");
        str = mstrcat(str, name);
        str = mstrcat(str, ".png");
        g->inv->equip->name = mstrcpy(g->inv->equip->name, name);
        g->inv->equip->item = create_object(str, (sfVector2f)
        {g->inv->equip->eq->pos.x, g->inv->equip->eq->pos.y},
        (sfIntRect) {0, 0, 59, 59}, (sfVector2f) {1, 1});
        g->inv->equip->is_eq = 1;
    }
    add_item_to_eq3(g, name, str);

}

int add_item_to_eq(general_t *g, char *name)
{
    equip_t *tmp = g->inv->equip;
    char *str = NULL;
    int i = 0;
    while (g->inv->equip && g->inv->equip->item_type != verif_equipement(name)) {
        g->inv->equip = g->inv->equip->next;
        i++;
    }
    add_item_to_eq2(g, name, str);
    g->inv->equip = tmp;
    return (0);
}

void draw_text(general_t *g)
{
    sfText_setString(g->login->text, g->game->login);
    sfText_setString(g->paswd->text, g->game->hidden_pasword);
    sfText_setString(g->user_name->text, g->game->user_name);
    sfText_setString(g->user_paswd->text, g->game->hidd_new_paswd);
    sfRenderWindow_drawText(g->game->window, g->login->text, NULL);
    sfRenderWindow_drawText(g->game->window, g->paswd->text, NULL);
    sfRenderWindow_drawText(g->game->window, g->user_name->text, NULL);
    sfRenderWindow_drawText(g->game->window, g->user_paswd->text, NULL);
}


void print_text(general_t *g, int x, int y, int text)
{
    sfText_setString(g->inv->text_caract,
    my_int_to_char(text));
    sfText_setFont(g->inv->text_caract, g->inv->font_caract);
    sfText_setColor(g->inv->text_caract, sfWhite);
    sfText_setCharacterSize(g->inv->text_caract, 15);
    sfText_setPosition(g->inv->text_caract, (sfVector2f) {x, y});
    sfRenderWindow_drawText(g->game->window, g->inv->text_caract, NULL);
}
