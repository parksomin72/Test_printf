#include "main.h"
/****************** WRITE NUMBER **************************/
/**
 * write_number - Print a string
 * @is_negative: LIsta of arguments
 * @ind: char types
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get Width
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int write_number(int is_negative, int ind, char buffer[], int flags,
int width, int precision, int size)
{
int length = BUFF_SIZE - ind - 1;
char padd = ' ', extra_ch = 0;
UNUSED(size);
if ((flags & F_ZERO) && !(flags & F_MINUS))
padd = '0';
if (is_negative)
extra_ch = '-';
else if (flags & F_PLUS)
extra_ch = '+';
else if (flags & F_SPACE)
extra_ch = ' ';
return (write_num(ind, buffer, flags, width, precision,
length, padd, extra_ch));
}
/**
 * write_num - Write a number using a buffer
 * @ind: Index at which the number starts ont the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: Width
 * @prec: Precision specifier
 * @length: Number length
 * @padd: Padding char
 * @extra_c: Extra char
 *
 * Return: Number of printed chars
 */
int write_num(int ind, char buffer[], int flags, int length
int width, int prec, char padd, char extra_c)
{
int i, padd_start = 1;
if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
/*printf(".0d", 0) no char is printed */
return (0);
if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
buffer[ind] = padd = ' ';
/*width is displayed with padding ' '*/
if (prec > 0 && prec < length)
padd = ' ';
while (prec > length)
buffer[--ind] = '0', length++;
if (extra_c != 0)
length++;
if (width > length)
{
for (i=1; i < width - length + 1; i++)
buffer[i] = padd;
buffer[i] = '\0';
if (flags & F_MINUS && padd == ' ')
/*Asign extra char to left of buffer*/
