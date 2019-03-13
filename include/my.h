/*
** EPITECH PROJECT, 2018
** duostumper
** File description:
** my.h
*/

#ifndef MY_H_
	#define MY_H_

	#include <stdio.h>
	#include <unistd.h>
	#include <stdlib.h>
	#include <fcntl.h>
	#include <ncurses.h>

	#define BUFFSIZE 1000000

//checking.c
char **check_x(char **map, char **copy_map, int i, int j);
char **check_point(char **map, char **copy_map, int i, int j);

//game.c
int cell(char **map, char **copy_map, int nbr, WINDOW *win);

//main.c
void write_tab(char **tab);

//my_getnbr.c
int my_getnbr(char *const str);

//write.c
void print_character(char **tab, int i, int j);
void write_tab(char **tab);
int check_file(char *buf);

#endif
