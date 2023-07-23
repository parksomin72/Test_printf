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
int (*fn)(va_list, char[], int, int, int, int);
};
/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format
 * @fm_t: The associated function
 */
typedef struct fmt fmt_t;
int _printf(const  char *format, ...);
int handle_print(const char *fmt, int *i,
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
int print_string(va_list types, char buffer[], int flags, int width,
int precision, int size);
int print_char(va_list types, char buffer[], int flags, int width,
int precision, int size);
int print_precent(va_list types, char buffer[], int flags, int width,
int precision, int size);
/*********** Function to print string in reverse **********/
int print_reverse(va_list types, char buffer[], int flags, int width,
int precision, int size);
/*********** Function to print a string in rot 13 *************/
int print_rot13string(va_list types, char buffer[], int flags, int width,
int precision, int size);
/*********** Function to print memory address *************/
int print_pointer(va_list types, char buffer[], int flags, int width,
int precision, int size);
/*********** Functions to handle other specifiers **********/
int get_flags(const char *format, int *i);
int get_size(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
/*********** Function to print non printable characters *********/
int print_non_printable(va_list types, char buffer[], int flags, int width,
int precision, int size);
/******************* width handler ***************************/
int handle_write_char(va_list types, char buffer[], int flags, int width,
int precision, int size);
int write_number(va_list types, char buffer[], int flags, int width,
int precision, int size);
int write_unsgnd(va_list types, char buffer[], int flags, int width,
int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
int length, char padd, char extra_c);
int write_pointer(char buffer[], char extra_c, char padd, int ind,
int length, int width, int flags, int padd_start);
/************************** UTILS *******************************/
int is_digit(char);
int is_printable(char);
int append_hexa_code(char, char[], int);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);
#endif /*MAIN_H*/
