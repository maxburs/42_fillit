/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgould <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 09:46:02 by mgould            #+#    #+#             */
/*   Updated: 2016/12/15 16:44:12 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fillit.h>

char	*get_input_string(char *av)
{
	int		i;
	int		fd;
	char	buf[1];
	char	*string;

	i = 0;
	if ((fd = open(av, O_RDONLY)) < 1)
		return (NULL);
	while ((read(fd, buf, 1)))
		i++;
	if (!(string = (char*)malloc(sizeof(char) * i)))
		return (NULL);
	close(fd);
	if ((fd = open(av, O_RDONLY)) < 1)
		return (NULL);
	i = 0;
	while ((read(fd, buf, 1)))
	{
		string[i] = buf[0];
		i++;
	}
	close(fd);
	string[i] = '\0';
	return (string);
}

int		*adjust_num(int *input)
{
	int i;

	i = 0;
	while (input[i] != -1)
	{
		if (input[i] <= 83)
		{
			input[i] = (input[i] / 6);
		}
		else if (input[i] <= 87)
			input[i] = 14;
		else if (input[i] <= 91)
			input[i] = 15;
		else if (input[i] <= 100)
			input[i] = 16;
		else if (input[i] <= 106)
			input[i] = 17;
		else if (input[i] <= 112)
			input[i] = 18;
		i++;
	}
	return (input);
}

int		*input_parse(int ac, char **av)
{
	char	*string;
	int		*input;
	int		i;

	input = (int *)malloc(sizeof(int) * (MAX_INPUT_SIZE + 1));
	i = 0;
	while (i < (MAX_INPUT_SIZE + 1))
	{
		input[i] = -1;
		i++;
	}
	if (ac != 2)
		return (0);
	if (!(string = get_input_string(av[1])))
		return (0);
	if (string_not_val(string, input))
		return (0);
	i = 0;
	input = adjust_num(input);
	return (input);
}
