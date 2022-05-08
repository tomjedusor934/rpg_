/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-tetris-tom.dumort
** File description:
** error_manage
*/

#include "../../include/my_rpg.h"

char *conc_name(char *src)
{
    char *final_str = malloc(sizeof(char) * my_strlen(src) + 6);
    char *file = "map/";
    int i = 0;
    for (; file[i] != '\0'; i++)
        final_str[i] = file[i];
    for (int x = 0; src[x] != '\0'; i++, x++)
        final_str[i] = src[x];
    final_str[i] = '\0';
    return (final_str);
}

maping_col_t *fill_list_map_col(char *buffer, char *name)
{
    maping_col_t *node = malloc(sizeof(maping_col_t));
    node->chunk_nb = my_atoi(name, 0);
    node->chunk_mapped = str_to_warray(buffer, '\n');
    return (node);
}

int put_in_file(char *name, struct stat buf, general_t *g)
{
    int file = open(conc_name(name), O_RDONLY);
    int error = 0;
    if (file == -1)
        error = 1;
    stat(conc_name(name), &buf);
    if (buf.st_size == 0)
        error = 1;
    char *buffer = malloc(sizeof(char) * buf.st_size + 1);
    int reading_file = read(file, buffer, buf.st_size);
    if (reading_file == -1)
        error = 1;
    buffer[reading_file] = '\0';
    if (error == 1) {
        g->maping[my_atoi(name, 0)] = NULL;
        return (1);
    }
    g->maping[my_atoi(name, 0)] = fill_list_map_col(buffer, name);
    close(file);
    return (1);
}

 int charging_map(general_t *g)
 {
    struct stat buf;
    DIR *dir_d = NULL;
    struct dirent *dir = NULL;
    dir_d = opendir("map");
    if (!(dir = readdir(dir_d)))
        return (0);
    while (dir != NULL) {
    if (dir == NULL)
        break;
    if (dir->d_name[0] == '.') {
        dir = readdir(dir_d);
        continue;
    }
    if (dir->d_type != DT_DIR)
        put_in_file(dir->d_name, buf, g);
    dir = readdir(dir_d);
    }
    closedir(dir_d);
    g->maping[73] = NULL;
    return (1);
 }

char *file_name(char *src)
{
    char *str = malloc(sizeof(char) * my_strlen(src) + 6);
    str = mstrcpy(str, "asset/");
    str = mstrcat(str, src);
    str = mstrcat(str, ".png");
    return (str);

}

void init_map(general_t *g)
{
    int x = 0;
    int y = 0;
    int i = 1;
    for (; i < 64; i++) {
        g->map[i - 1] = create_object(file_name(my_int_to_char(i - 1)),
        (sfVector2f) {x, y}, (sfIntRect) {0, 0, 1920, 1080},
        (sfVector2f) {1, 1});
        x += 1920;
        if (i % 9 == 0) {
            y += 1080;
            x = 0;
        }
    }
    g->map[63] = NULL;
}
