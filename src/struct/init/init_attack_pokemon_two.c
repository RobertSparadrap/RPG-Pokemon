/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_attack_pokemon_two
*/

#include "../../../include/rpg.h"
#include "../../../include/struct.h"

attack_t **infernape_att(pokemon_t *pers)
{
    pers->attack = malloc(sizeof(attack_t *) * 4);
    pers->attack[0] = att(-1, FEU, 120, 1);
    pers->attack[1] = att(-1, COMBAT, 130, 0);
    pers->attack[2] = att(-1, FEU, 60, 0);
    pers->attack[3] = att(2, SOL, 60, 0);
    return pers->attack;
}

attack_t **torterra_att(pokemon_t *pers)
{
    pers->attack = malloc(sizeof(attack_t *) * 4);
    pers->attack[0] = att(-1, PLANTE, 150, 1);
    pers->attack[1] = att(0, SOL, 100, 0);
    pers->attack[2] = att(-1, TENEBRE, 90, 1);
    pers->attack[3] = att(-1, ROCHE, 60, 1);
    return pers->attack;
}

attack_t **staraptor_att(pokemon_t *pers)
{
    pers->attack = malloc(sizeof(attack_t *) * 4);
    pers->attack[0] = att(-1, VOL, 130, 0);
    pers->attack[1] = att(-1, COMBAT, 120, 0);
    pers->attack[2] = att(3, NORMALE, 60, 0);
    pers->attack[3] = att(1, VOL, 100, 0);
    return pers->attack;
}

attack_t **milotic_att(pokemon_t *pers)
{
    pers->attack = malloc(sizeof(attack_t *) * 4);
    pers->attack[0] = att(-1, EAU, 130, 1);
    pers->attack[1] = att(-1, GLACE, 120, 1);
    pers->attack[2] = att(-1, DRAGON, 85, 1);
    pers->attack[3] = att(-1, EAU, 100, 1);
    return pers->attack;
}

attack_t **gliscor_att(pokemon_t *pers)
{
    pers->attack = malloc(sizeof(attack_t *) * 4);
    pers->attack[0] = att(0, SOL, 130, 0);
    pers->attack[1] = att(1, VOL, 110, 0);
    pers->attack[2] = att(-1, TENEBRE, 70, 0);
    pers->attack[3] = att(-1, ECLAIRE, 65, 0);
    return pers->attack;
}
