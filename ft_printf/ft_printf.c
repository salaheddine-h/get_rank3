#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	put_str(char *str, int *len)
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
		*len += write(1, "-", 1);
	}
	if(nbr >= base)
		put_digite((nbr / base), base, len);
	*len += write(1, &str[nbr % base], 1);
}
void	ft_printf(char	*format, ...)
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
				put_str(va_arg(ptr, char *), &len);
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
	ft_printf("%d\n", 7777);
	ft_printf("%x\n", 77);
	ft_printf("%s\n","salaheddine");
       	return(0);	
}
