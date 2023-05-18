/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:37:34 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/18 15:04:27 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	tmp = *lst;
	if (!tmp)
		return ;
	while (tmp)
	{
		node = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = node;
	}
	*lst = NULL;
}
