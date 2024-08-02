#include "holberton.h"

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

	print_result(result);
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
	int len1, len2, len, i, j, n1, n2, sum;
	char *result;

	len1 = _strlen(num1);
	len2 = _strlen(num2);
	len = len1 + len2;

	result = calloc(len + 1, sizeof(char));
	if (result == NULL)
		return (NULL);

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			n1 = num1[i] - '0';
			n2 = num2[j] - '0';
			sum = (result[i + j + 1] - '0') + (n1 * n2);
			result[i + j + 1] = (sum % 10) + '0';
			result[i + j] += sum / 10;
		}
	}

	for (i = 0; i < len; i++)
	{
		if (result[i] != '0')
			break;
	}

	if (i == len)
	{
		free(result);
		result = calloc(2, sizeof(char));
		if (result == NULL)
			return (NULL);
		result[0] = '0';
		return (result);
	}

	return (_strcpy(result, result + i));
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
 * _strcpy - copies a string
 * @dest: destination buffer
 * @src: source string
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
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
