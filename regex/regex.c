#include "regex.h"

/**
 * match_star - Handle star operator in pattern
 * @c: Character before star
 * @pattern: Rest of pattern after star
 * @str: String to match
 *
 * Return: 1 if matches, 0 if not
 */
static int match_star(char c, char const *pattern, char const *str);

/**
 * match_here - Helper function to match pattern at current position
 * @str: String to match
 * @pattern: Pattern to match against
 *
 * Return: 1 if matches, 0 if not
 */
static int match_here(char const *str, char const *pattern)
{
	if (!*pattern)
		return (!*str);

	if (pattern[1] == '*')
		return (match_star(pattern[0], pattern + 2, str));

	if (*str && (pattern[0] == '.' || pattern[0] == *str))
		return (match_here(str + 1, pattern + 1));

	return (0);
}

/**
 * match_star - Handle star operator in pattern
 * @c: Character before star
 * @pattern: Rest of pattern after star
 * @str: String to match
 *
 * Return: 1 if matches, 0 if not
 */
static int match_star(char c, char const *pattern, char const *str)
{
	const char *s;

	if (match_here(str, pattern))
		return (1);

	s = str;
	while (*s && (c == '.' || *s == c))
	{
		if (match_here(s + 1, pattern))
			return (1);
		s++;
	}

	return (0);
}

/**
 * regex_match - Check if pattern matches string
 * @str: String to scan
 * @pattern: Regular expression pattern
 *
 * Return: 1 if pattern matches string, 0 if not
 */
int regex_match(char const *str, char const *pattern)
{
	if (!str || !pattern)
		return (0);

	return (match_here(str, pattern));
}
