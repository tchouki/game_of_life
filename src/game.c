/*
** EPITECH PROJECT, 2018
** duostumper
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

char **start_checking(char **map, char **copy_map, int i, int j)
{
    if (map[i][j] != '0') {
        copy_map = check_x(map, copy_map , i, j);
        copy_map = check_point(map, copy_map, i, j);
    }
    return (copy_map);
}

char **life_game(char **map, char **copy_map)
{
    for (int i = 0; map[i] != NULL; i++)
        for (int j = 0; map[i][j] != '\0'; j++)
            copy_map = start_checking(map, copy_map, i, j);
    return (copy_map);
}

char **tab_copy(char **map, char **copy_map)
{
    for (int i = 0; copy_map[i] != NULL; i++)
        for (int j = 0; copy_map[i][j] != '\0'; j++)
            map[i][j] = copy_map[i][j];
    return (map);
}

int cell(char **map, char **copy_map, int nbr, WINDOW *win)
{
    int c = 0;

    if (nbr == 0) {
        attron(COLOR_PAIR(5));
        printw("GENERATION 0\n");
        write_tab(map);
        attron(COLOR_PAIR(7));
        printw("\n\n--PRESS SPACE--\n");
        refresh();
        while (c != ' ')
            c = wgetch(win);
        endwin();
        system("stty -raw && stty echo && stty onlcr");
        return (0);
    }
    clear();
    attron(COLOR_PAIR(5));
    printw("GENERATION 1\n");
    write_tab(map);
    attron(COLOR_PAIR(7));
    printw("\n\n------PRESS  SPACE------\n");
    attron(COLOR_PAIR(6));
    printw("\n-PRESS KEY DOWN TO QUIT-\n");
    refresh();
    while (c != ' ' && c != KEY_DOWN)
        c = wgetch(win);
    for (int i = 0; i < nbr && c != KEY_DOWN; i++) {
        copy_map = life_game(map, copy_map);
        map = tab_copy(map, copy_map);
        clear();
        attron(COLOR_PAIR(5));
        printw("GENERATION %d\n", i + 1);
        write_tab(map);
        attron(COLOR_PAIR(7));
        printw("\n\n------PRESS  SPACE------\n");
        attron(COLOR_PAIR(6));
        printw("\n-PRESS KEY DOWN TO QUIT-\n");
        refresh();
        while (c != ' ' && c != KEY_DOWN)
            c = wgetch(win);
        if (c != KEY_DOWN)
            c = 0;
    }
    for (int i = 0; map[i] != NULL; i++) {
    	free(map[i]);
    	free(copy_map[i]);
    }
    free(map);
    free(copy_map);
    endwin();
    system("stty -raw && stty echo && stty onlcr");
    return (0);
}