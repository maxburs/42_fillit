#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include "libft.h"
#include <unistd.h>
#include <string.h>
#include "minos.c"

/*
This file has a very specific format : every Tetriminos
description consists of 4 lines and each Tetriminos are separated by an empty line
and the final tetrimoino has a single newline.
*/

char **make_lminos(int *nlmino, int num_minos)
{
	char **lminos;
	int i;

	i = 0;
	lminos = (char **)malloc(sizeof(char *)*(num_minos + 1));
	//printf("num_minos:%dwhat\n", num_minos);
	if (!lminos)
	{
		//printf("failed to created lminos\n");
		return (0);
	}
	lminos[num_minos] = NULL;
	while (i < num_minos)
	{
		//lminos[i] =
		//printf("strdup:\n%s", strdup(minos[(nlmino[i])]));
		lminos[i] = strdup(minos[(nlmino[i])]);
		//lminos[i] = strdup("###.\n..#.\n....\n....\n\n");
		i++;
	}
	//printf("past while\n");
	lminos[i - 1][20] = '\0';
	//lminos[i] = NULL;
	return (lminos);
}



int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("enter in a number for how many tetriminos you want\n");
		return (0);
	}
	int i, n;
	int fd;
	time_t t;
	int nlmino[atoi(av[1])];
	int rando;
	char **lmino;

	fd = open("tetriminos_file", O_RDWR | O_CREAT | O_TRUNC , 0666);
	if (!fd)
	{
		printf("error opening file");
		return (0);
	}

	i = 0;
	n = 5;
	rando = 0;
	srand((unsigned) time(&t));
	while (i < atoi(av[1]))
	{
		rando = ((rand() % 19));
		nlmino[i] = rando;
		//printf("%d\n", nlmino[i]);
		i++;
	}
	nlmino[i] = '\0';
	lmino = make_lminos(nlmino, atoi(av[1]));
	i = 0;
	while (i < atoi(av[1]))
	{
		//uncomment if you want to see the board on STDOUT
		//printf("%s", lmino[i]);
		ft_putstr_fd(lmino[i], fd);
		i++;
	}
	close(fd);
	return (0);
}

/*
int *rand_mino_nums(int num)
{

}
*/

/*
generate_lminos
-use position to create each lmino
-maybe have lmino position characteristic
-better than hard typing out 50 of them, but not much better. . .
-make an if in bounds function?
*/

/*
NEXT STEP:
MAKE IT OUTPUT TO A FILE!

THEN I CAN WORK ON SUPPORTING ALL TEH TETRIMINO TYPES :-)

*/
