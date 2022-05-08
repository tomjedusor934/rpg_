/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** trader
*/

#include "../../include/my_rpg.h"

void init_trader(general_t *g, sfVector2f pos)
{
    g->trader = malloc(sizeof(trader_t));
    g->trader->change_item = 0;
    g->trader->open_trader = 0;
    g->trader->trader = create_object("asset/trader.png", pos, (sfIntRect)
    {0, 0, 204, 416}, (sfVector2f) {0.8, 0.8});
    g->trader->name_trader = create_object("asset/trader_name.png",
    (sfVector2f) {g->trader->trader->pos.x - 130, g->trader->trader->pos.y -
    50}, (sfIntRect) {0, 0, 932, 147}, (sfVector2f) {0.5, 0.5});
    g->trader->inv_trader = create_object("asset/inv_trader.png",
    (sfVector2f) {g->trader->trader->pos.x - 100, g->trader->trader->pos.y +
    55}, (sfIntRect) {0, 0, 438, 218}, (sfVector2f) {1, 1});
    g->trader->clinv_trader = create_object("asset/close_bouton.png",
    (sfVector2f) {g->trader->inv_trader->pos.x + 410, g->trader->inv_trader->
    pos.y + 3}, (sfIntRect) {0, 0, 24, 24}, (sfVector2f) {1, 1});
    g->trader->textprice = text_gener(" Kamas", (sfVector2f) {0, 0}, 25);
    g->trader->name1 = NULL, g->trader->name2 = NULL;
    g->trader->name3 = NULL, g->trader->name4 = NULL;
    g->trader->price1 = 0, g->trader->price2 = 0;
    g->trader->price3 = 0, g->trader->price4 = 0;
}

void open_trader(general_t *g)
{
    if (g->trader->open_trader == 1 && is_on_button(g->trader->clinv_trader, g) == 1)
        g->trader->open_trader = 0;
    if (g->trader->open_trader == 1) {
        (is_on_button(g->trader->item1, g) == 1 && g->player->stat_player->kama
        >= g->trader->price1 ? g->player->stat_player->kama -= g->trader->
        price1, add_item_to_inv(g, g->trader->name1),  trader_randitem(g) : 0);
        (is_on_button(g->trader->item2, g) == 1 && g->player->stat_player->kama
        >= g->trader->price2 ? g->player->stat_player->kama -= g->trader->
        price2, add_item_to_inv(g, g->trader->name2), trader_randitem(g) : 0);
        (is_on_button(g->trader->item3, g) == 1 && g->player->stat_player->kama
        >= g->trader->price3 ? g->player->stat_player->kama -= g->trader->
        price3, add_item_to_inv(g, g->trader->name3), trader_randitem(g) : 0);
        (is_on_button(g->trader->item4, g) == 1 && g->player->stat_player->kama
        >= g->trader->price4 ? g->player->stat_player->kama -= g->trader->
        price4, add_item_to_inv(g, g->trader->name4), trader_randitem(g) : 0);
    }
    if (is_on_button(g->trader->trader, g) == 1)
        g->trader->open_trader = 1;
}

void draw_trader2(general_t *g)
{
    sfRenderWindow_drawText(g->game->window ,g->trader->textprice->text,
    NULL);
    sfRenderWindow_drawSprite(g->game->window, g->trader->item2->sprite,
    NULL);
    sfText_setString(g->trader->textprice->text, mstrcat(my_int_to_char
    (g->trader->price3), " Kamas"));
    sfText_setPosition(g->trader->textprice->text, (sfVector2f)
    {g->trader->item3->pos.x + 70, g->trader->item3->pos.y + 25});
    sfRenderWindow_drawText(g->game->window ,g->trader->textprice->text,
    NULL);
    sfRenderWindow_drawSprite(g->game->window, g->trader->item3->sprite,
    NULL);
    sfText_setString(g->trader->textprice->text, mstrcat(my_int_to_char
    (g->trader->price4), " Kamas"));
    sfText_setPosition(g->trader->textprice->text, (sfVector2f) 
    {g->trader->item4->pos.x + 70, g->trader->item4->pos.y + 25});
    sfRenderWindow_drawText(g->game->window ,g->trader->textprice->text,
    NULL);
    sfRenderWindow_drawSprite(g->game->window, g->trader->item4->sprite,
    NULL);
}

void draw_trader(general_t *g)
{
    sfRenderWindow_drawSprite(g->game->window, g->trader->trader->sprite ,NULL);
    sfRenderWindow_drawSprite(g->game->window, g->trader->name_trader->sprite ,NULL);
    if (g->trader->open_trader == 1){
        sfRenderWindow_drawSprite(g->game->window, g->trader->inv_trader->
        sprite ,NULL);
        sfText_setString(g->trader->textprice->text, mstrcat(my_int_to_char
        (g->trader->price1), " Kamas"));
        sfText_setPosition(g->trader->textprice->text, (sfVector2f) 
        {g->trader->item1->pos.x + 70, g->trader->item1->pos.y + 25});
        sfRenderWindow_drawText(g->game->window ,g->trader->textprice->
        text, NULL);
        sfRenderWindow_drawSprite(g->game->window, g->trader->item1->
        sprite ,NULL);
        sfText_setString(g->trader->textprice->text, mstrcat(my_int_to_char
        (g->trader->price2), " Kamas"));
        sfText_setPosition(g->trader->textprice->text, (sfVector2f) 
        {g->trader->item2->pos.x + 70, g->trader->item2->pos.y + 25});
        draw_trader2(g);
    }
}
