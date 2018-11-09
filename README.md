

# A printf clone

**printf** is a function for printing strings and conversion formats. It is a function from the standard library of the C language, and we had to reimplement it.

This project might seem useless, and it maybe is. But it is not just about reinventing the wheel. It is more about understanding more deeply how the `printf` function works.
For someone who has never tried to understand the behind the scenes of this function he would see it as magical, and maybe that it is too hard to understand anyway. And that is wrong, it is actually easier than he thinks.

I am not planning to explain how the function works, but keep in mind that there are two major concept to understand its working, parsing and [variadic argument](https://www.thegeekstuff.com/2017/05/c-variadic-functions/), i will let you with this.

## ft_printf

The function has the same behavior than the standard one, so does its prototype
```C
#include "libft/include/ft_printf.h"

int ft_printf(const char *format, ...);
```

The `format` argument will tell the function how and what to print. There are the literal characters and the modulus character. A literal character is everything that is not a modulus character, as it is literal, once the function meets it, it will print it as it is, if it sees an *a* it will print an *a* etc.

But the modulus character works differently and has more control on what should be printed, it will make use of the `...` argument, which is a variadic argument meaning that there can be an undefined number of arguments.

What follows the modulus character ('*%*') is called a format, it will simply format the collected argument(s).
For example the *%s* format will print the argument as a string, so the argument should be a string, if it not, the result is undefined.

As you expect there is not just the *%s* format, so here is a table of all the important formats

| Format | Description | Prototype |
| --- | --- | --- |
| `s` | Prints the string | `const char *` |
| `d`, `i` | Prints the integer | `int` |
| `u` | Print the unsigned integer | `unsigned int` |
| `x` | Prints the integer in hexadecimal | `int` |
| `o` | Prints the integer in octal | `int` |
| `p` | Prints the address of the pointer in hexadecimal | `int` |
| `f` | Print the floating point number | `double` |

There are way more formats, but i am not listing them all as this wiki is just about introducing the function with a minimum of explanation. But keep in mind that this function also implements identifiers, precision, length modifier etc. So here is a link to understand the various combination and possibilities of this function: [printf format identifiers](https://www.lix.polytechnique.fr/~liberti/public/computing/prog/c/C/FUNCTIONS/format.html)

The `ft_printf` function also implements a format that is not a part of the standards. The format is the color format, it alows you to enable style's (like bold, italic underlines etc.) and colors (you know what is a color, right ?) with this syntax `%{red/bold}%#{yellow}`, in this context the `#` means that the color is for the background instead of the foreground.
The printed characters that follows this format will be bold red in a yellow background. To reset the styles by default you must put a 0 between the curly brackets `%{0}`.

## man ft_printf

`ft_printf, ft_printf_fd, ft_printf_s, ft_vprintf, ft_vprintf_fd, ft_vprintf_s` are functions for formatted output conversion.

```C
int ft_printf(const char *format, ...);
int ft_printf_fd(int fd, const char *format, ...);
int ft_printf_s(char **buffer, const char *format, ...);

int ft_vprintf(const char *format, va_list ap);
int ft_vprintf_fd(int fd, const char *format, va_list ap);
int ft_vprintf_s(char **buffer, const char *format, va_list ap);
```

The **ft_printf** and **ft_vprintf** functions writes the output to the standard output, while the **ft_printf_fd** and **ft_vprintf_fd** writes the output to the specified file descriptor. The **ft_printf_s** and **ft_vprintf_s** functions does not print anywhere they will instead store the output in a buffer `char **buffer`.

The functions preceded by a **v** are equivalent by those who are not, except that they are called with a **va_list** instead of a variable number of arguments.

The format string is a character string, beginning and ending in its initial shift state, if any. The format string is composed of zero or more directives: ordinary characters (not %), which are copied unchanged to the output stream; and conversion specifications, each of which results in fetching zero or more subsequent arguments. Each conversion specification is introduced by the character %,  and  ends  with  a conversion  specifier. In between there may be (in this order) zero or more flags, an optional minimum field width, an optional precision and an optional length modifier.
