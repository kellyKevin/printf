#include "main.h"
/**
 * get_flags - To calculate all the active flags.
 * @format: The format of the string
 * @a: parameter
 * Return: flags
 */
int get_flags(const char *format, int *a)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int b, curr_a;
	int flags = 0;
	const int FLAGS_ARR[] = {F_SPACE, F_ZERO, F_MINUS, F_HASH, F_PLUS, 0};
	const char FLAGS_CH[] = {' ', '0', '-', '#', '+', '\0'};

	for (curr_a = *a + 1; format[curr_a] != '\0'; curr_a++)
	{
		for (b = 0; FLAGS_CH[b] != '\0'; b++)
			if (format[curr_a] == FLAGS_CH[b])
			{
				flags |= FLAGS_ARR[b];
				break;
			}

		if (FLAGS_CH[b] == 0)
			break;
	}

	*a = curr_a - 1;
	return (flags);
}
