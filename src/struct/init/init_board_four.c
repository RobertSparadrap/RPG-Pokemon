/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_board_four
*/

#include "../../../include/rpg.h"
#include "../../../include/struct.h"

sfVector2f init_board_feu_next(game_t *pers, int i)
{
    if (i == 1) {
        pers->position.x = 1130;
        pers->position.y = 50;
    }
    if (i == 2) {
        pers->position.x = 1255;
        pers->position.y = 50;
    }
    if (i == 3) {
        pers->position.x = 1138;
        pers->position.y = 215;
    }
    if (i == 4) {
        pers->position.x = 1260;
        pers->position.y = 215;
    }
    return (pers->position);
}

game_t *init_board_feu(int i)
{
    game_t *pers = malloc(sizeof(struct s_game));
    pers->sprite_f = create_sprite("Ressources/game/att_board.png");
    pers->scale.x = 3;
    pers->scale.y = 3;
    pers->position = init_board_feu_next(pers, i);
    pers->ar.left = 140;
    pers->ar.top = 695;
    pers->ar.width = 125;
    pers->ar.height = 55;
    sfSprite_setPosition(pers->sprite_f, pers->position);
    sfSprite_setScale(pers->sprite_f, pers->scale);
    sfSprite_setTextureRect(pers->sprite_f, pers->ar);
    return pers;
}

game_t *init_board_acier(int i)
{
    game_t *pers = malloc(sizeof(struct s_game));
    pers->sprite_f = create_sprite("Ressources/game/att_board.png");
    pers->scale.x = 3;
    pers->scale.y = 3;
    if (i == 1) {
        pers->position.x = 1130;
        pers->position.y = 50;
    }
    if (i == 2) {
        pers->position.x = 1255;
        pers->position.y = 50;
    }
    pers->ar.left = -70;
    pers->ar.top = 640;
    pers->ar.width = 210;
    pers->ar.height = 55;
    sfSprite_setPosition(pers->sprite_f, pers->position);
    sfSprite_setScale(pers->sprite_f, pers->scale);
    sfSprite_setTextureRect(pers->sprite_f, pers->ar);
    return pers;
}

sfVector2f init_board_fight_next(game_t *pers, int i)
{
    if (i == 1) {
        pers->position.x = 1130;
        pers->position.y = 50;
    }
    if (i == 2) {
        pers->position.x = 1460;
        pers->position.y = 50;
    }
    if (i == 3) {
        pers->position.x = 1138;
        pers->position.y = 215;
    }
    if (i == 4) {
        pers->position.x = 1260;
        pers->position.y = 215;
    }
    return (pers->position);
}

game_t *init_board_fight(int i)
{
    game_t *pers = malloc(sizeof(struct s_game));
    pers->sprite_f = create_sprite("Ressources/game/att_board.png");
    pers->scale.x = 3;
    pers->scale.y = 3;
    pers->position = init_board_fight_next(pers, i);
    pers->ar.left = 0;
    pers->ar.top = 528;
    pers->ar.width = 140;
    pers->ar.height = 55;
    sfSprite_setPosition(pers->sprite_f, pers->position);
    sfSprite_setScale(pers->sprite_f, pers->scale);
    sfSprite_setTextureRect(pers->sprite_f, pers->ar);
    return pers;
}