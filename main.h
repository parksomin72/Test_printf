#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
/*********SIZES*************/
#define S_LONG 2
#define S_SHORT 1
/*********FLAGS****************/
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
/**
 * struct fmt - Struct op
 *
 * @fmt: The format
 * @fn: The associated function
 */
struct fmt
{
char fmt;
int(*fn)(va_list, char[], int, int, int, int);
};
/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format
 * @fm_t: The associated function
 */
typedef struct fmt fmt_t;
int _printf(const  char *format, ...);
int handle _print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);
/**********************FUNCTIONS*********************************/
/***** Functions to print numbers ************/
int print_int(va_list types, char buffer[], int flags, int width,
      int precision, int size);
int print_binary(va_list types, char buffer[], int flags, int width,
      int precision, int size);
int print_octal(va_list types, char buffer[], int flags, int width,
      int precision, int size);
int print_hexadecimal(va_list types, char buffer[], int flags, int width,
      int precision, int size);
int print_unsigned(va_list types, char buffer[], int flags, int width,
      int precision, int size);
int print_hexa(va_list types, char buffer[], int flags, int width,
      int precision, int size);
int print_hexa_upper(va_list types, char buffer[], int flags, int width,
      int precision, int size);
/***** Functions to print strings and chars ************/
int print_int(va_list types, char buffer[], int flags, int width,
      int precision, int size);
