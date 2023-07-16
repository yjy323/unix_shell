/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:27:34 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/14 12:32:41 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/type.h"
#include "../../libft/includes/libft.h"

t_token	*get_token(void);
void	free_token(t_token *token);
t_token	*get_token_with_data(const char *word, t_type type);

t_token	*get_token(void)
{
	t_token	*new_token;

	new_token = (t_token *)malloc(1 * sizeof(t_token));
	if (!new_token)
		print_error(ENOMEM);
	new_token->word = 0;
	new_token->type = 0;
	return (new_token);
}

void	free_token(t_token *token)
{
	if (token->word)
		free(token->word);
	free(token);
}

t_token	*get_token_with_data(const char *word, t_type type)
{
	t_token	*new_token;

	new_token = get_token();
	if (!new_token)
		print_error(ENOMEM);
	if (word)
	{
		new_token->word = ft_strdup(word);
		if (!new_token->word)
			print_error(ENOMEM);
	}
	new_token->type = type;
	return (new_token);
}
