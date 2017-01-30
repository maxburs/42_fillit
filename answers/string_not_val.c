/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_not_val.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgould <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 09:50:35 by mgould            #+#    #+#             */
/*   Updated: 2016/12/10 13:02:51 by mgould           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fillit.h>
#include <libft.h>

int	invalid_chars(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] == '#' || s[i] == '.' || s[i] == '\n'))
			return (1);
		i++;
	}
	return (0);
}

int	good_len(int len)
{
	if (len == 20)
		return (1);
	else if ((((len - 20) % 21) == 0) &&\
		(len <= (((MAX_INPUT_SIZE - 1) * 21) + 20)))
		return (1);
	else
		return (0);
}

int	minos_not_match(int count, int *input, char *string)
{
	int i;
	int flag;
	int len;

	len = ft_strlen(string);
	if (len != 20)
		len = 21;
	i = 0;
	flag = 0;
	while (g_minos[i])
	{
		if (!(ft_strncmp(g_minos[i], string, len)))
		{
			flag = 1;
			input[count] = i;
			break ;
		}
		i++;
	}
	if (!(flag))
	{
		return (1);
	}
	return (0);
}

int	string_not_val(char *string, int *input)
{
	int len;
	int flag;
	int count;

	flag = 0;
	count = 0;
	len = ft_strlen(string);
	if (!(good_len(len)))
		return (1);
	else if (invalid_chars(string))
		return (1);
	while (*string)
	{
		if (minos_not_match(count, input, string))
			return (1);
		string += 21;
		count++;
	}
	return (0);
}
