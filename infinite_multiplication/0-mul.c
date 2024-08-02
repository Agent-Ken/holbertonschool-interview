#include "holberton.h"
#include <stdlib.h>

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	char *result;

	if (argc != 3)
	{
		_puts("Error");
		exit(98);
	}

	if (!is_digit(argv[1]) || !is_digit(argv[2]))
	{
		_puts("Error");
		exit(98);
	}

	result = multiply(argv[1], argv[2]);
	if (result == NULL)
	{
		_puts("Error");
		exit(98);
	}

	if (result[0] == '0' && result[1] == '\0')
	{
		_putchar('0');
		_putchar('\n');
	}
	else
	{
		print_result(result);
	}
	free(result);

	return (0);
}

/**
 * is_digit - checks if a string contains only digits
 * @s: string to check
 * Return: 1 if only digits, 0 otherwise
 */
int is_digit(char *s)
{
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

/**
 * _puts - prints a string followed by a new line
 * @str: string to print
 */
void _puts(char *str)
{
	while (*str)
		_putchar(*str++);
	_putchar('\n');
}

/**
 * multiply - multiplies two numbers represented as strings
 * @num1: first number
 * @num2: second number
 * Return: result of multiplication or NULL on failure
 */
char *multiply(char *num1, char *num2)
{
	int len1, len2, len, i, j, carry;
	int *result;
	char *str_result;

	len1 = _strlen(num1);
	len2 = _strlen(num2);
	len = len1 + len2;

	result = calloc(len, sizeof(int));
	if (result == NULL)
		return (NULL);

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			result[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
		}
	}

	for (i = len - 1; i > 0; i--)
	{
		carry = result[i] / 10;
		result[i - 1] += carry;
		result[i] %= 10;
	}

	str_result = malloc(len + 1);
	if (str_result == NULL)
	{
		free(result);
		return (NULL);
	}

	for (i = 0; i < len; i++)
		str_result[i] = result[i] + '0';
	str_result[len] = '\0';

	while (*str_result == '0' && *(str_result + 1) != '\0')
		str_result++;

	free(result);
	return (str_result);
}

/**
 * _strlen - returns the length of a string
 * @s: string to measure
 * Return: length of string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * print_result - prints the result
 * @result: string to print
 */
void print_result(char *result)
{
	while (*result)
		_putchar(*result++);
	_putchar('\n');
}
