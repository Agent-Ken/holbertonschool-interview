#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <holberton.h>

/**
 * _isdigit - checks if a string is a number
 * @str: string to check
 *
 * Return: 1 if str is a number, 0 otherwise
 */
int _isdigit(char *str)
{
	int i = 0;

	if (str[0] == '-')
		i = 1;
	for (; str[i]; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}

/**
 * _puts - prints a string
 * @str: string to print
 *
 * Return: void
 */
void _puts(char *str)
{
	while (*str)
	{
		putchar(*str);
		str++;
	}
	putchar('\n');
}

/**
 * main - multiplies two large numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	int len1, len2, len, i, j, carry, n1, n2, *result;
	char *num1, *num2;

	if (argc != 3 || !_isdigit(argv[1]) || !_isdigit(argv[2]))
	{
		_puts("Error");
		exit(98);
	}

	num1 = argv[1];
	num2 = argv[2];
	len1 = strlen(num1);
	len2 = strlen(num2);
	len = len1 + len2;
	result = calloc(len, sizeof(int));

	if (result == NULL)
	{
		_puts("Error");
		exit(98);
	}

	for (i = len1 - 1; i >= 0; i--)
	{
		if (num1[i] == '-')
			continue;
		n1 = num1[i] - '0';
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			if (num2[j] == '-')
				continue;
			n2 = num2[j] - '0';
			carry += result[i + j + 1] + (n1 * n2);
			result[i + j + 1] = carry % 10;
			carry /= 10;
		}
		if (carry)
			result[i + j + 1] += carry;
	}

	i = 0;
	while (i < len && result[i] == 0)
		i++;
	if (i == len)
		putchar('0');
	else
	{
		for (; i < len; i++)
			putchar(result[i] + '0');
	}
	putchar('\n');
	free(result);
	return (0);
}
