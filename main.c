/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wopark <wopark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:07:54 by wopark            #+#    #+#             */
/*   Updated: 2021/05/28 19:21:57 by wopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minish.h"

char	*realloc_input(char *ptr, size_t size)
{
	char	*ret;

	ret = (char *)malloc(size);
	if (!ret)
		return (0);
	ft_memmove(ret, ptr, size);
	free(ptr);
	return (ret);
}

int		get_input(char **input)
{
	int		r_nbr;
	int		idx;
	int		cnt;
	char	buf;

	idx = 0;
	cnt = 1;
	*input = malloc(1);
	if (*input == NULL)
		return (READ_ERR);
	while (1)
	{
		r_nbr = read(0, &buf, 1);
		if (r_nbr == 0 || buf == '\n')
		{
			*(*input + idx) = 0;
			return (READ_SUC);
		}
		*(*input + idx) = buf;
		idx++;
		*input = realloc_input(*input, cnt + 1);
		cnt++;
	}
	return (READ_ERR);
}

int		main(int argc, char **argv, char **envv)
{
	char	*input;

	argc = 0;
	argv = 0;
	g_archive.buf = 0;
	signal_init(argc, argv);
	envv_lst_make(envv);
	while (1)
	{
		write(1, "minish $> ", 10);
		if (get_input(&input) == READ_ERR)
			printf("Error");
		if (parse_input(input) == ERROR)
			parse_error_msg(SYNTAX_ERROR_MSG);
		free(input);
	}
	return (0);
}
