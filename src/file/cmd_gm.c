/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-arthur.prevot
** File description:
** cmd_gm
*/

#include "../../include/my_rpg.h"
void cmd_tp(general_t *g, char **array)
{
    g->pos_playe_x = my_atoi(array[1], 0);
    g->pos_player_y = my_atoi(array[2], 0);
}

int valide_cmd(char **array, general_t *g)
{
    if (compare_wiw("tp", array[0])) {
        cmd_tp(g, array);
        return (1);
    }
    return (0);
}

void cmd_give(general_t *g, char *cmd)
{
    char **array = str_to_warray(cmd, ':');
    for (int i = 1; array[i]; i++)
        add_item_to_inv(g, array[i]);
}

void check_cmd(general_t *g)
{
    int cmd_valide = 0;
    if (compare_wiw("give", g->game->god_mode->cmd)) {
        cmd_give(g, g->game->god_mode->cmd);
        cmd_valide = 1;
}
    char **array_cmd = str_to_warray(g->game->god_mode->cmd, ' ');
    if (valide_cmd(array_cmd, g))
        cmd_valide = 1;
    if (cmd_valide == 1)
        g->game->god_mode->cmd[0] = '\0';
    sfText_setString(g->game->god_mode->text_cmd->text,
    g->game->god_mode->cmd);
}

void write_cmd(general_t *g, char letter, char *str)
{
    int x = 0;
    if (((letter >= 'a' && letter <= 'z') || letter == 57 ||
    (letter >= '0' && letter <= '9') || letter == 58) &&
    my_strlen(str) != 50) {
        for (; str[x] != '\0'; x++);
        if (letter >= 'a' && letter <= 'z')
            str[x] = letter;
        else if (letter == 57)
            str[x] = ' ';
        else
            str[x] = letter;
        str[x + 1] = '\0';
    }
    if (letter == 59) {
        for (; str[x] != '\0'; x++);
        if (x != 0)
            str[x - 1] = '\0';
    }
    sfText_setString(g->game->god_mode->text_cmd->text,
    g->game->god_mode->cmd);
}
