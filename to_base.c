#include <stdio.h>
#include "ft_printf.h"

char	*ft_swap_chars(char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++j])
		str[++i] = str[j];
	str[--j] = '\0';
	return (str);
}

char *base_exception(uintmax_t nb, char *base)
{
	if (!base)
		return (NULL);
	if (nb == 0)
		return (ft_strdup("0"));
	return (NULL);
}

char	*to_base(uintmax_t nb, char *base)
{
	intmax_t	i;
	uintmax_t	prod;
	uintmax_t	tmp;
	char		*result;

	//printf("nb-> %d\n");
	if (!base || nb == 0)
		return (base_exception(nb, base));
	prod = (ft_strcmp(base, BASE_O) == 0) ? 8 : 16;
	i = (nb < prod)? 1 : 0;
	tmp = nb;
	while (tmp > 0)
	{
		tmp = tmp / prod;
		i++;
	}
	if (!(result = ft_strnew(i)))
		return (NULL);
	result[i] = '\0';
	tmp = nb;
	while (--i >= 0)
	{
		result[i] = base[nb % prod];
		nb = nb / prod;
	}
	return ((result[++i] == '0' && tmp != 0) ? ft_swap_chars(result) : result);
}
