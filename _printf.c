#include "main.h"
/**
 *_printf - printf simulator
 *@format: the format string
 *
 *Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list ap;
	char *p, *start;
	params_t params = PARAMS_INIT;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		prms(&params, ap);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (flag(p, &params))
		{
			p++;
		}
		p = width(p, &params, ap);
		p = prec(p, &params, ap);
		if (mod(p, &params))
			p++;
		if (!spec(p))
			sum += prt_cstm(start, p,
				params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			sum += prt_fnc(p, ap, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(ap);
	return (sum);
}
