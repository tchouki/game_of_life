/*
** EPITECH PROJECT, 2018
** duostumper
** File description:
** main.c
*/

#include "../include/my.h"

void print_character(char **tab, int i, int j)
{
    if (tab[i][j] == '.') {
        attron(COLOR_PAIR(1));
        printw("..");
    }
    if (tab[i][j] == 'X') {
        attron(COLOR_PAIR(3));
        printw("XX");
    }
}

void write_tab(char **tab)
{
    for (int i = 1; tab[i + 1] != NULL; i++) {
        for (int j = 0; tab[i][j] != '\0'; j++)
            print_character(tab, i, j);
        printw("\n");
    }
    refresh();
}

int check_file(char *buf)
{
    for (int i = 0; buf[i] != '\0'; i++)
        if (buf[i] != '.' && buf[i] != 'X' && buf[i] != '\n')
            return (84);
    return (0);
}