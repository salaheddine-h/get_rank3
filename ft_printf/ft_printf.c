#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	put_string(char *str, int *len)
{
	if(!str)
		str = "(null)";
	while(*str)
		*len += write(1, str++, 1);
}

void	put_digite(long long int nbr, int base, int *len)
{
	char	*str = "0123456789abcdef";
	if(nbr < 0)
	{
		nbr *= -1;
		*len = write(1, "-", 1);
	}
	if(nbr >= base)
		put_digite((nbr / base), base, len);
	*len += write(1, &str[nbr % base], 1);
}
void	check_printf(char *format, ...)
{
	int	len;
	va_list ptr;

	len = 0;
	va_start(ptr, format);
	while(*format)
	{
		if((*format == '%') && *(format + 1))
		{
			format++;
			if(*format == 's')
				put_string(va_arg(ptr, char *), &len);
			else if(*format == 'd')
				put_digite((long long int)va_arg(ptr, int), 10, &len);
			else if(*format == 'x')
				put_digite((long long int)va_arg(ptr, unsigned int), 16, &len);
		}
		else
			len += write(1, format, 1);
		format++;
	}
}

int	main()
{
	check_printf("%s\n", "Mult string it's working !!");
	check_printf("%d\n", 59);
	check_printf("%x\n", 77);
	return(0);
}
