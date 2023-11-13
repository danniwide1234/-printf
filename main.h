#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1
#define NULL_STRING "(null)"
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2
/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned value
 *
 * @plus_flag: on if plus_flag specified
 * @space_flag: on if hashtag_flag specified
 * @hashtag_flag: on if _flag specified
 * @zero_flag: on if _flag specified
 * @minus_flag: on if _flag specified
 *
 * @width: field width specified
 * @precision: field precision specified
 *
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specified
 *
 */
typedef struct parameters
{
	unsigned int unsign		: 1;
	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;
	unsigned int width;
	unsigned int precision;
	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} params_t;

/**
 * struct specifier - Struct token
 *
 * @specifier: format token
 * @f: The function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

int _puts(char *str);
int _putchar(int c);
int _printf(const char *format, ...);
int prt_c(va_list ap, params_t *params);
int prt_int(va_list ap, params_t *params);
int prt_str(va_list ap, params_t *params);
int prt_prcnt(va_list ap, params_t *params);
int prt_S(va_list ap, params_t *params);
char *cnvrt(long int num, int base, int flags, params_t *params);
int prt_uns(va_list ap, params_t *params);
int prt_adrs(va_list ap, params_t *params);
int (*spec(char *s))(va_list ap, params_t *params);
int prt_fnc(char *s, va_list ap, params_t *params);
int flag(char *s, params_t *params);
int mod(char *s, params_t *params);
char *width(char *s, params_t *params, va_list ap);
int prt_hex(va_list ap, params_t *params);
int prt_HEX(va_list ap, params_t *params);
int prt_bin(va_list ap, params_t *params);
int prt_oct(va_list ap, params_t *params);
int prt_cstm(char *start, char *stop, char *except);
int prt_rev(va_list ap, params_t *params);
int prt_rot13(va_list ap, params_t *params);
int _isdigit(int c);
int _strlen(char *s);
int prt_num(char *str, params_t *params);
int prt_numr(char *str, params_t *params);
int prt_numl(char *str, params_t *params);
void prms(params_t *params, va_list ap);
char *prec(char *p, params_t *params, va_list ap);
#endif
