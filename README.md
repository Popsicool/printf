# printf

# Welcome

This is our take on the printf function in C, it is a project for the ALX Africa Software Engineering Program. we were asked to build a _printf function capable of printing with the %d, %c, %s, and %% specifiers to standard output. 

We added %x ,%X, %b, %o, %u, %r, %R, and %p formatting. We relied on the library we have been building at Alx as well as new concepts gathered during this project.
# Supported Format Types
TYPE - OUTPUT

%c - Single character

%s - String of character

%d - Integer in decimal

%i - integer

%u - unsigned integer

%p - pointer address

%% - Percent sign

%r - String in reverse

%R - String in rot13

%x - Lowercase hex(loervase)

%X - Uppercase hex (unsigned)

%b -  signed binary

%o -  signed octal

# Example

Character: printf("%c", I); Output = I

Integer: printf("%i", 22); Output: 22

String: printf("%s", HELLO world.); Output = HELLO world.

# File Functions

_printf.c
Printf Function That Performs Formatted Output Conversion And Prints Data.

 # main.h
Header File Were All Prototypes Are Saved.

# get_print_func.c
Pointer To A Function That Selects The Correct Function To Perform The Operation.

# print_buf.c
Function That Prints The Buffer.

# handl_buf.c
Function That Concatenates The Buffer Characters.

# print_chr.c
Function That Writes The Character C To Stdout.

/* Indetifier : %c */
# print_str.c
Function That Writes The String To Stdout.

/* Indetifier : %s */
# print_int.c
Function That Prints An Integer.

/* Indetifier : %i or %d */
# print_bnr.c
Function That Prints Decimal In Binary.

/* Indetifier : %b */
# print_oct.c
Function That Prints Decimal In Octal.

/* Indetifier : %o */
# print_hex.c
Function That Prints Decimal In Hexadecimal.

/* Indetifier : %x */
# print_upx.c
Function That Prints Decimal In Uppercase Hexadecimal.

/* Indetifier : %X */
# print_usr.c
Function That Prints A String And Values Of Non-Printed Chars.

/* Indetifier : %S */
# print_unt.c
Function That Prints An Unsigned Integer.

/* Indetifier : %u */
# print_rev.c
Function That Writes The String To Stdout In Reverse.

/* Indetifier : %r */
# print_rot.c
Function That Writes The String To Stdout In Rot13.

/* Indetifier : %R */
# print_add.c
Function That Prints The Address Of An Input Variable.

/* Indetifier : %p */
# print_long_oct.c
Function That Prints Long Decimal Number In Octal.

/* Indetifier : %lo */
# print_long_hex.c
Function That Prints Long Decimal Number In Hexadecimal.

/* Indetifier : %lx */
# print_long_int.c
Function That Prints A Long Integer.

/* Indetifier : %li */
# print_long_upx.c
Function That Prints A Long Decimal In Uppercase Hexadecimal.

/* Indetifier : %lX */
# print_long_unt.c
Function That Prints A Long Unsigned Integer.

/* Indetifier : %lu */
# print_short_oct.c
Function That Prints Short Decimal Number In Octal.

/* Indetifier : %ho */
# print_short_hex.c
Function That Prints Short Decimal Number In Hexadecimal.

/* Indetifier : %hx */
# print_short_int.c
Function That Prints A Short Integer.

# print_short_upx.c
Function That Prints A Short Decimal In Uppercase Hexadecimal.

/* Indetifier : %hX */
# print_short_unt.c
Function That Prints A Short Unsigned Integer.

/* Indetifier : %hu */
# print_num_hex.c
Function That Print A Number In Hexadecimal Begining With 0 And x.

/* Indetifier : %#x */
# print_num_oct.c
Function That Prints A Number In Octal Begining With 0 And o.

/* Indetifier : %#o */
# print_num_upx.c
Function That Prints A Number In Uppercase Hexadecimal.

/* Indetifier : %#X */
# print_plus_int.c
Function That Prints An Integer With Plus Symbol.

/* Indetifier : %+i */
# print_space_int.c
Function That Prints An Integer Begining With 0 And u.

/* Indetifier : % i */
# ev_print_func.c
Function That Returns The Amount Of Indetifiers.


# Authors

Jamal Ibrahim Umar And
Adebimpe Adefila 
 
 # End