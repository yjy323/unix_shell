/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:29:03 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/25 18:14:14 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse/parser.h"
#include "parse/lex.h"
#include "parse/standardize.h"
#include "utils.h"

t_command			*parse(char *str);
static t_command	*parse_lex_list(t_lex_list *lex_list);
static void			parse_redirect(t_parser *parser, \
									char *word, char *filename);
static void			parse_connection(t_parser *parser, char *word);
static void			parse_simple(t_parser *parser, t_lex_node *lex_data);

t_command	*parse(char *str)
{
	t_lex_list	*lex_list;
	t_command	*command;

	command = 0;
	lex_list = lex(str);
	if (standardize(lex_list) == 0)
		command = parse_lex_list(lex_list);
	free_lex_list(lex_list);
	return (command);
}

static t_command	*parse_lex_list(t_lex_list *lex_list)
{
	t_parser	parser;
	t_command	*command;
	t_lex_list	*plex_list;

	parser.root = 0;
	parser.cur_command = 0;
	plex_list = lex_list;
	while (plex_list)
	{
		if (plex_list->data->type == cm_simple)
			parse_simple(&parser, plex_list->data);
		else if (plex_list->data->type == cm_redirect)
		{
			parse_redirect(&parser,
				plex_list->data->word, plex_list->next->data->word);
			plex_list = plex_list->next;
		}
		else if (plex_list->data->type == cm_connection)
			parse_connection(&parser, plex_list->data->word);
		plex_list = plex_list->next;
	}
	command = parser.root;
	return (command);
}

static void	parse_redirect(t_parser *parser, char *word, char *filename)
{
	t_redirect	*redirect;

	if (!parser->cur_command)
	{
		parser->root = get_command();
		parser->root->simple = get_simple_com();
		parser->root->type = cm_simple;
		parser->cur_command = parser->root;
	}
	redirect = get_redirect();
	redirect->word = ft_xstrdup(word);
	redirect->filename = ft_xstrdup(filename);
	push_redirect_list(&parser->cur_command->simple->redirects, redirect);
}

static void	parse_connection(t_parser *parser, char *word)
{
	t_command	*command;

	command = get_command();
	command->simple = get_simple_com();
	command->type = cm_connection;
	command->connection = get_connection();
	command->connection->word = ft_xstrdup(word);
	command->connection->first = parser->root;
	command->connection->second = get_command();
	command->connection->second->simple = get_simple_com();
	command->connection->second->type = cm_simple;
	parser->root = command;
	parser->cur_command = command->connection->second;
}

static void	parse_simple(t_parser *parser, t_lex_node *lex_data)
{
	t_command	*command;
	t_word_desc	*word_desc;

	if (!parser->cur_command)
	{
		parser->root = get_command();
		parser->root->simple = get_simple_com();
		parser->root->type = cm_simple;
		parser->cur_command = parser->root;
	}
	command = parser->cur_command;
	word_desc = get_word_desc();
	word_desc->flag = lex_data->flag;
	word_desc->word = ft_xstrdup(lex_data->word);
	push_word_list(&command->simple->words, word_desc);
}
