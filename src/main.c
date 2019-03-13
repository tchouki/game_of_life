/*
** EPITECH PROJECT, 2018
** duostumper
** File description:
** main.c
*/

#include "../include/my.h"

char **put_last_line(char **tab, int size2, int x)
{
    int y;

    for (y = 0; y < size2 + 2; y++)
       	tab[x][y] = '0';
    tab[x][y - 1] = '\0';
    tab[x + 1] = NULL;
    return (tab);
}

char **put_element(char **tab, int size2, int y, char *buf)
{
    int x = 1;

    for (int i = 0; buf[i] != '\0'; i++) {
        if (buf[i] == '\n') {
            tab[x][y] = '0';
            tab[x][y + 1] = '\0';
            x++;
            y = 0;
        } else if (y == 0) {
            tab[x][y] = '0';
            y++;
            i--;
        } else {
            tab[x][y] = buf[i];
            y++;
        }
    }
    tab = put_last_line(tab, size2, x);
    return (tab);
}

int put_2d_tab(char *buf, int size, int size2, int nbr, WINDOW *win)
{
    char **tab;
    char **copy_tab;
    int x = 0;
    int y = 0;

	if (check_file(buf) == 84) {
        endwin();
        system("stty -raw && stty echo && stty onlcr");
	    return (84);
    }
    tab = malloc(sizeof(char *) * (size + 3));
    copy_tab = malloc(sizeof(char *) * (size + 3));
    for (int j = 0; j < size + 3; j++) {
        tab[j] = malloc(sizeof(char) * size2 + 3);
        copy_tab[j] = malloc(sizeof(char) * size2 + 3);
    }
    for (; x < size2 + 2; x++) {
        tab[0][x] = '0';
        copy_tab[0][x] = '0';
    }
    tab = put_element(tab , size2, y, buf);
    copy_tab = put_element(copy_tab, size2, y, buf);
    return (cell(tab, copy_tab, nbr, win));
}

int fs_open_file(char *filepath, int nbr, WINDOW *win)
{
    int fd;
    int ret;
    char buf[BUFFSIZE];
    int size = 0;
    int size2 = 0;

    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        endwin();
        system("stty -raw && stty echo && stty onlcr");
        return (84);
    }
    ret = read(fd, buf, BUFFSIZE);
    if (ret == -1 || ret == 0) {
        endwin();
        system("stty -raw && stty echo && stty onlcr");
        return (84);
    }
    for (int x = 0; buf[x] != '\0'; x++)
        if (buf[x] == '\n')
            size++;
    for (size2 = 0; buf[size2] != '\n'; size2++);
    close(fd);
    buf[(size2 + 1) * size] = '\0';
    return (put_2d_tab(buf, size, size2, nbr, win));
}

void init_all_color(void)
{
    start_color();

    init_pair(1, COLOR_BLACK, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_GREEN);
    init_pair(3, COLOR_RED, COLOR_RED);
    init_pair(4, COLOR_BLUE, COLOR_BLUE);
    init_pair(5, COLOR_WHITE, COLOR_BLACK);
    init_pair(6, COLOR_RED, COLOR_BLACK);
    init_pair(7, COLOR_GREEN, COLOR_BLACK);
}

int main(int argc, char **argv)
{
    int nbr;
    WINDOW *win;

    if (argc != 3)
        return (84);

    initscr();
    clear();
    noecho();
    cbreak();
    win = newwin(10, 30, (24 - 10) / 2, (80 - 30) / 2);
    keypad(win, TRUE);
    refresh();
    curs_set(0);
    init_all_color();
    nbr = my_getnbr(argv[2]);
    if (nbr < 0) {
        endwin();
        system("stty -raw && stty echo && stty onlcr");
        return (84);
    }
    return (fs_open_file(argv[1], nbr, win));
}