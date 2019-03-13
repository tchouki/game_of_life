/*
** EPITECH PROJECT, 2018
** duostumper
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

static int check_around(char **map, const int x, int j, int nbr_x)
{
    for (int y = j - 1; y <= j + 1; y++)
        if (map[x][y] == 'X')
            nbr_x++;
    return (nbr_x);
}

char **check_x(char **map, char **copy_map, int i, int j)
{
    int nbr_x = 0;

    if (map[i][j] == 'X') {
        for (int x = i - 1; x <= i + 1; x++)
            nbr_x = check_around(map, x, j, nbr_x);
        nbr_x--;
        if (nbr_x <= 1 || nbr_x >= 4)
            copy_map[i][j] = '.';
    }
    return (copy_map);
}

char **check_point(char **map, char **copy_map, int i, int j)
{
    int nbr_x = 0;

    if (map[i][j] == '.') {
        for (int x = i - 1; x <= i + 1; x++)
            nbr_x = check_around(map, x, j, nbr_x);
        if (nbr_x == 3)
            copy_map[i][j] = 'X';
    }
    return (copy_map);
}