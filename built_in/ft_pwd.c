/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:24:25 by minsukan          #+#    #+#             */
/*   Updated: 2022/10/31 18:56:35 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(char **arg, int pipe_cnt)
{
	char	*pwd;

	(void)arg;
	pwd = get_env("PWD");
	if (*pwd)
	{
		write(1, pwd, ft_strlen(pwd));
		write(1, "\n", 1);
		free(pwd);
		if (pipe_cnt)
			exit(0);
		set_exit_code(0);
	}
	else
	{
		if (pipe_cnt)
			exit(1);
		set_exit_code(1);
	}
}
