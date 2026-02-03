/*
** EPITECH PROJECT, 2025
** G-MUL-100-LIL-1-1-myradar-8
** File description:
** count_tokens
*/

#include "my.h"

int count_tokens(char *str)
{
    int count = 0;
    int is_token = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\r' &&
            str[i] != '\n' && str[i] != '\t' && is_token == 0) {
            count++;
            is_token = 1;
        }
        if (str[i] == ' ' || str[i] == '\r' || str[i] == '\n' ||
            str[i] == '\t')
            is_token = 0;
    }
    return count;
}

char **alloc_tokens(int nb_tokens)
{
    char **tokens = malloc(sizeof(char *) * (nb_tokens + 1));

    if (!tokens)
        return NULL;
    return tokens;
}

char *check_token_and_cpy(char *str, int start, int len)
{
    char *token = malloc(sizeof(char) * (len + 1));

    if (!token)
        return NULL;
    for (int j = 0; j < len; j++)
        token[j] = str[start + j];
    token[len] = '\0';
    return token;
}

int fill_toks_and_check(char **tokens, char *str, char delim,
    int nb_tokens)
{
    int i = 0;
    int start;
    int len;

    for (int idx_tok = 0; idx_tok < nb_tokens; idx_tok++) {
        len = 0;
        for (; str[i] && (str[i] == delim || str[i] == '\r'
                || str[i] == '\n' || str[i] == '\t'); i++);
        start = i;
        for (; str[i] && str[i] != delim && str[i] != '\r'
            && str[i] != '\n' && str[i] != '\t'; i++)
            len++;
        tokens[idx_tok] = check_token_and_cpy(str, start, len);
        if (!tokens[idx_tok]) {
            free_tokens(tokens, idx_tok);
            return 84;
        }
    }
    return 0;
}

char **my_split(char *str, char delimiter)
{
    int nb_tokens = count_tokens(str);
    char **tokens = alloc_tokens(nb_tokens);

    if (!tokens)
        return NULL;
    if (fill_toks_and_check(tokens, str, delimiter, nb_tokens) == 84)
        return NULL;
    tokens[nb_tokens] = NULL;
    return tokens;
}
