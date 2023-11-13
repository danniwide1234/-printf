#include "main.h"
/**
 *spec - finds the format func
 *@s: the format string in question
 *
 *Return: the number of bytes printed
 */
int (*spec(char *s))(va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", prt_c},
		{"d", prt_int},
		{"i", prt_int},
		{"s", prt_str},
		{"%", prt_prcnt},
		{"b", prt_bin},
		{"o", prt_oct},
		{"u", prt_uns},
		{"x", prt_hex},
		{"X", prt_HEX},
		{"p", prt_adrs},
		{"S", prt_S},
		{"r", prt_rev},
		{"R", prt_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}
/**
 *prt_fnc - finds the format func
 *@s: the format string
 *@ap: argument pointer
 *@params: the parameters struct
 *
 *Return: the number of bytes printed
 */
int prt_fnc(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = spec(s);

	if (f)
		return (f(ap, params));
	return (0);
}
/**
 *flag - finds the flag func
 *@s: the format string
 *@params: the parameters struct
 *
 *Return: if flag was valid
 */
int flag(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->plus_flag = 1;
			break;
		case ' ':
			i = params->space_flag = 1;
			break;
		case '#':
			i = params->hashtag_flag = 1;
			break;
		case '-':
			i = params->minus_flag = 1;
			break;
		case '0':
			i = params->zero_flag = 1;
			break;
	}
	return (i);
}
/**
 *mod - finds the modifier func
 *@s: the format string
 *@params: the parameters struct
 *
 *Return: if modifier was valid
 */
int mod(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
	case 'h':
		i = params->h_modifier = 1;
		break;
	case 'l':
		i = params->l_modifier = 1;
		break;
	}
	return (i);
}
/**
 *width - gets the width from the format string
 *@s: the format string
 *@params: the parameters struct
 *@ap: the argument pointer
 *
 *Return: new pointer
 */
char *width(char *s, params_t *params, va_list ap)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->width = d;
	return (s);
}
