#include "holberton.h"
#include <stdlib.h>

void putword(char *str);
void error(void);
void check_digit(char *str);
int _strlen(char *s);
int *__calloc(unsigned int nmemb, unsigned int size);
void check_alloc(int *p);
void multiply(int *finalRes, int len1, char *s1, int len2, char *s2);
char *_memset(char *s, char b, unsigned int n);

/**
 * main - Run the process, make two inputed arg multiply
 *
 * @argc: Number of arg
 * @argv: Array of arg
 *
 * Return: 0 (succes)
 */
int main(int argc, char *argv[])
{
	int len1, len2;
	int *finalRes;

	if (argc != 3 || argv[1] == NULL || argv[2] == NULL)
		error();

	check_digit(argv[1]);
	check_digit(argv[2]);

	len1 = _strlen(argv[1]);
	len2 = _strlen(argv[2]);

	finalRes = __calloc((len1 + len2), sizeof(int));

	multiply(finalRes, len1, argv[1], len2, argv[2]);
	free(finalRes);
	return (0);
}

/**
 * putword - Print a word
 *
 * @str: Word to print
 *
 * Return: Anything, cause void function.
 */
void putword(char *str)
{
	while (*str)
	{
		_putchar(*str);
		str++;
	}
}

/**
 * error - exit the code if any error.
 *
 * Return: Anything, cause void function
 */
void error(void)
{
	putword("Error\n");
	exit(98);
}

/**
 * check_digit - Check if the str contain only digit
 *
 * @str: String to test
 *
 * Return: Anything, cause void function
 */
void check_digit(char *str)
{
	int i;

	for (i = 0; *(str + i); i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			error();
	}
}

/**
 * _strlen - Calculate the length of a string.
 *
 * @s: String to manipulate.
 *
 * Return: The length of the inputed string.
 */

int _strlen(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		;
	return (i);
}

/**
 * __calloc - Recode the calloc function
 *
 * @nmemb: Length of the array that contain pointers
 * @size: Size of the elements pointed
 *
 * Return: NULL if any problem, pointer to the array else (succes)
 */
int *__calloc(unsigned int nmemb, unsigned int size)
{
	void *pointer;

	if (nmemb == 0 || size == 0)
		error();

	pointer = malloc(nmemb * size);
	check_alloc(pointer);

	_memset(pointer, 0, nmemb * size);

	return (pointer);
}

/**
 * _memset - fills memory with a constant byte
 *
 * @s: Buffer adress
 * @b: Constant byte to fill memory
 * @n: Number of contant byte to fill
 *
 * Return: The buffer adress.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		*(s + i) = b;
	return (s);
}

/**
 * check_alloc - check if the malloc is a succes
 *
 * @p: Pointer that been malloc
 *
 * Return: Anything, cause void function
 */
void check_alloc(int *p)
{
	if (p == NULL)
		error();
}

/**
 * multiply - multiply two sting and print it
 *
 * @finalRes: Reslut array
 * @len1: Length of the first str
 * @s1: First str
 * @len2: Length of the second str
 * @s2: Second str
 *
 * Return: Anything, cause void function.
 */
void multiply(int *finalRes, int len1, char *s1, int len2, char *s2)
{
	int i, j, carry, n1, n2;

	for (i = (len1 - 1); i >= 0; i--)
	{
		carry = 0;
		n1 = s1[i] - '0';
		for (j = (len2 - 1); j >= 0; j--)
		{
			n2 = s2[j] - '0';
			carry += n1 * n2 + finalRes[i + j + 1];
			finalRes[i + j + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			finalRes[i + j + 1] += carry;
	}
	i = 0;
	while (finalRes[i] == 0)
		i++;
	if (i >= len1 + len2 + 1)
		_putchar('0');

	for (; i < (len1 + len2); i++)
		_putchar(finalRes[i] + '0');
	_putchar('\n');
}
