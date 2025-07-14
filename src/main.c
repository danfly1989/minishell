/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:03:00 by daflynn           #+#    #+#             */
/*   Updated: 2025/07/14 20:35:16 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <ctype.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_TOKENS_CAP 8
#define INITIAL_TOKEN_SIZE 64

// Append a char to a dynamic buffer (resizing if needed)
void	append_char(char **buf, int *size, int *len, char c)
{
	if (*len + 1 >= *size)
	{
		*size *= 2;
		*buf = realloc(*buf, *size);
		if (!*buf)
		{
			perror("realloc");
			exit(1);
		}
	}
	(*buf)[(*len)++] = c;
	(*buf)[*len] = '\0';
}

// Simple quote-aware lexer that splits input on spaces outside quotes
// Returns a NULL-terminated array of tokens (caller must free)
char	**lexer(const char *input)
{
	int		in_single_quote;
	int		tokens_cap;
	char	**tokens;
	int		buf_size;
	int		buf_len;
	char	*buf;
	char	c;
	int		in_double_quote;
	int		tokens_count;

	in_single_quote = 0;
	in_double_quote = 0;
	tokens_cap = INITIAL_TOKENS_CAP;
	tokens_count = 0;
	in_single_quote = 0;
	tokens_cap = INITIAL_TOKENS_CAP, tokens_count = 0;
	tokens = malloc(sizeof(char *) * tokens_cap);
	if (!tokens)
	{
		perror("malloc");
		exit(1);
	}
	buf_size = INITIAL_TOKEN_SIZE;
	buf_len = 0;
	buf = malloc(buf_size);
	if (!buf)
	{
		perror("malloc");
		exit(1);
	}
	buf[0] = '\0';
	for (int i = 0; input[i]; i++)
	{
		c = input[i];
		if (c == '\'' && !in_double_quote)
		{
			in_single_quote = !in_single_quote;
			// Do not include the quote char itself in token
			continue ;
		}
		else if (c == '"' && !in_single_quote)
		{
			in_double_quote = !in_double_quote;
			// Do not include the quote char itself in token
			continue ;
		}
		else if ((c == ' ' || c == '\t') && !in_single_quote
			&& !in_double_quote)
		{
			// End token if buffer not empty
			if (buf_len > 0)
			{
				// Add token to tokens array
				if (tokens_count + 1 >= tokens_cap)
				{
					tokens_cap *= 2;
					tokens = realloc(tokens, sizeof(char *) * tokens_cap);
					if (!tokens)
					{
						perror("realloc");
						exit(1);
					}
				}
				tokens[tokens_count++] = strdup(buf);
				buf_len = 0;
				buf[0] = '\0';
			}
			// else skip consecutive spaces
			continue ;
		}
		else
		{
			append_char(&buf, &buf_size, &buf_len, c);
		}
	}
	// Add last token if any
	if (buf_len > 0)
	{
		if (tokens_count + 1 >= tokens_cap)
		{
			tokens_cap *= 2;
			tokens = realloc(tokens, sizeof(char *) * tokens_cap);
			if (!tokens)
			{
				perror("realloc");
				exit(1);
			}
		}
		tokens[tokens_count++] = strdup(buf);
	}
	free(buf);
	tokens[tokens_count] = NULL;
	return (tokens);
}

// Free tokens array
void	free_tokens(char **tokens)
{
	for (int i = 0; tokens[i]; i++)
		free(tokens[i]);
	free(tokens);
}

// Test
int	main(void)
{
	char	*input;
	char	**tokens;

	while (1)
	{
		input = readline("myshell");
		if (!input)
		{
			printf("\n");
			return (1);
		}
		// Strip newline
		input[strcspn(input, "\n")] = 0;
		tokens = lexer(input);
		printf("Tokens:\n");
		for (int i = 0; tokens[i]; i++)
		{
			printf("[%d]: %s\n", i, tokens[i]);
		}
		free_tokens(tokens);
		free(input);
	}
	return (0);
}
