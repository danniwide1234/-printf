#include "main.h"
/**
 *prt_hex - prints unsigned hex numbers in lowercase
 *@ap: the argument pointer
 *@params: the parameters struct
 *
 *Return: bytes printed
 */
int prt_hex(va_list ap, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = cnvrt(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag_flag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += prt_num(str, params));
}
/**
 *prt_HEX - prints unsigned hex numbers in uppercase
 *@ap: the argument pointer
 *@params: the parameters struct
 *
 *Return: bytes printed
 */
int prt_HEX(va_list ap, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = cnvrt(l, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += prt_num(str, params));
}
/**
 *prt_bin - prints unsigned binary number
 *@ap: the argument pointer
 *@params: the parameters struct
 *
 *Return: bytes printed
 */
int prt_bin(va_list ap, params_t *params)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = cnvrt(n, 2, CONVERT_UNSIGNED, params);
	int c = 0;

	if (params->hashtag_flag && n)
		*--str = '0';
	params->unsign = 1;
	return (c += prt_num(str, params));
}
/**
 *prt_oct - prints unsigned octal numbers
 *@ap: the argument pointer
 *@params: the parameters struct
 *
 *Return: bytes printed
 */
int prt_oct(va_list ap, params_t *params)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	str = cnvrt(l, 8, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && l)
		*--str = '0';
	params->unsign = 1;
	return (c += prt_num(str, params));
}
