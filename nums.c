#include "main.h"
/**
 *cnvrt - converter function
 *@num: number in question
 *@base: base
 *@flags: argument flags
 *@params: paramater struct
 *
 *Return: string
 */
char *cnvrt(long int num, int base, int flags, params_t *params)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}
/**
 *prt_uns - prints unsigned integer numbers
 *@ap: argument pointer
 *@params: the parameters struct
 *
 *Return: bytes printed
 */
int prt_uns(va_list ap, params_t *params)
{
	unsigned long l;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	params->unsign = 1;
	return (prt_num(cnvrt(l, 10, CONVERT_UNSIGNED, params), params));
}
/**
 *prt_adrs - prints address
 *@ap: argument pointer
 *@params: the parameters struct
 *
 *Return: bytes printed
 */
int prt_adrs(va_list ap, params_t *params)
{
	unsigned long int n = va_arg(ap, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)"));

	str = cnvrt(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (prt_num(str, params));
}
