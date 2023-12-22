/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:39:04 by yliew             #+#    #+#             */
/*   Updated: 2023/09/06 10:46:29 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
/*
int	main(void)
{
	char	*test[9] = {"a", "A", "0", "7", "@", "+", " ", "	", ""};
	int	i = 0;

	while (i < 9)
	{
		printf("%s: %i\n", test[i], ft_isprint((int)(*test[i])));
		i++;
	}
	return (0);
}
*/
