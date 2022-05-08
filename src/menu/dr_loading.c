/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** loading_menu
*/

#include "../../include/my_rpg.h"

void main_menu(general_t *g)
{
    g->menu->mom_cross->pos.x = g->menu->main_menu->pos.x + 354 * 2;
    g->menu->mom_cross->pos.y = g->menu->main_menu->pos.y + 8 * 2;
    sfSprite_setPosition(g->menu->mom_cross->sprite,
    g->menu->mom_cross->pos);
    sfRenderWindow_drawSprite(g->game->window,
    g->menu->main_menu->sprite, NULL);
    sfRenderWindow_drawSprite(g->game->window,
    g->menu->mm_option->sprite, NULL);
    sfRenderWindow_drawSprite(g->game->window,
    g->menu->mm_resume->sprite, NULL);
    sfRenderWindow_drawSprite(g->game->window,
    g->menu->mm_exit->sprite, NULL);
}

void option_menu(general_t *g)
{
    g->menu->mom_cross->pos.x = g->menu->option_menu->pos.x + 868 * 1.5;
    g->menu->mom_cross->pos.y = g->menu->option_menu->pos.y + 23 * 1.5;
    sfSprite_setPosition(g->menu->mom_cross->sprite,
    g->menu->mom_cross->pos);
    sfRenderWindow_drawSprite(g->game->window,
    g->menu->option_menu->sprite, NULL);
    sfRenderWindow_drawSprite(g->game->window,
    g->menu->om_fps->sprite, NULL);
    sfRenderWindow_drawSprite(g->game->window,
    g->menu->om_musique->sprite, NULL);
    sfRenderWindow_drawSprite(g->game->window,
    g->menu->om_fx->sprite, NULL);
}

sfFtp *connect_to_ftp(sfFtp * ftp)
{
    sfIpAddress sf = sfIpAddress_fromString("104.248.192.97");
    sfFtp_connect(ftp, sf, 21, sfSeconds (0));
    sfFtp_login(ftp, "tom_ftp", "C4limer0");
    sfFtp_changeDirectory(ftp, "rpg_data");
    return (ftp);
}

void download_file(sfFtp *ftp, general_t *g)
{
    int add = 1920 / 63;
    int defaut = 1920 % 63;
    // char *asset = NULL;
    // char *check_file
    g->menu->loading_bar->rect.width += defaut;
    for (int i = 0; i < 63; i++) {
        sfRenderWindow_clear(g->game->window, sfBlack);
        char asset[256];
        char check_file[256];
        sprintf (asset, "%d.png", i);
        sprintf (check_file, "asset/%d.png", i);

        FILE *check;
        if ((check = fopen(check_file, "r")) == NULL)
            sfFtp_download(ftp, asset, "./asset/", sfFtpAscii);
        if (g->menu->loading_bar->rect.width < 1920) {
            g->menu->loading_bar->rect.width += add;
        }
        sfSprite_setTextureRect(g->menu->loading_bar->sprite, g->menu->loading_bar->rect);
        sfRenderWindow_drawSprite(g->game->window, g->menu->loading_bar->sprite, NULL);
        sfRenderWindow_drawSprite(g->game->window, g->menu->loading_bg->sprite, NULL);
        sfRenderWindow_display(g->game->window);
    }
}

void loading_menu(general_t *g)
{
    if (g->menu->loading_bar->rect.width >= 1920) {
        sfRenderWindow_drawSprite(g->game->window, g->menu->loading_bar->sprite, NULL);
        sfRenderWindow_drawSprite(g->game->window, g->menu->loading_bg->sprite, NULL);
        sfRenderWindow_drawSprite(g->game->window, g->menu->play_but->sprite, NULL);
        sfRenderWindow_drawSprite(g->game->window, g->menu->option_but->sprite, NULL);
        sfRenderWindow_drawSprite(g->game->window, g->menu->exit_but->sprite, NULL);
        return;
    }
    sfFtp *ftp = sfFtp_create();
    ftp = connect_to_ftp(ftp);
    download_file(ftp, g);
    sfFtp_disconnect(ftp);
    sfSprite_setTextureRect(g->menu->loading_bar->sprite, g->menu->loading_bar->rect);
    sfRenderWindow_drawSprite(g->game->window, g->menu->loading_bg->sprite, NULL);
    if (g->menu->loading_bar->rect.width >= 1920) {
        g->scene = LOADED;
        sfRenderWindow_drawSprite(g->game->window, g->menu->play_but->sprite, NULL);
        sfRenderWindow_drawSprite(g->game->window, g->menu->option_but->sprite, NULL);
        sfRenderWindow_drawSprite(g->game->window, g->menu->exit_but->sprite, NULL);
    }
}
