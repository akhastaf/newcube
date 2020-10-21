#include "../include/cub3d.h"

void write_exit(char *s)
{
	write(1, s, ft_strlen(s));
	exit(1);
}

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;
	char	*to_find;

	str = (char*)haystack;
	to_find = (char*)needle;
	if (to_find[0] == '\0')
		return ((char*)haystack);
	i = 0;
	j = 0;
	while (str[i + j] != '\0' && i < len)
	{
		while (str[i + j] == to_find[j] && i + j < len)
		{
			j++;
			if (to_find[j] == '\0')
				return ((char*)haystack + i);
		}
		j = 0;
		i++;
	}
	return (NULL);
}

int		ft_atoi(const char *str)
{
	int		i;
	int		signe;
	size_t	n;

	i = 0;
	signe = 1;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			signe = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57 && str[i] != '\0')
	{
		n = n * 10 + str[i] - 48;
		if (n > 9223372036854775807)
			return ((signe > 0) ? -1 : 0);
		i++;
	}
	return ((int)(n * signe));
}

int		ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*cdst;
	unsigned char	*csrc;
	size_t			i;

	cdst = (unsigned char*)dst;
	csrc = (unsigned char*)src;
	i = 0;
	if (cdst == csrc)
		return (cdst);
	if (!cdst && !csrc)
		return (NULL);
	while (i < n)
	{
		cdst[i] = csrc[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = (char*)malloc((ft_strlen(s1) * sizeof(char)) + 1)))
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = s1[i];
	return (str);
}

int bigger(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int spaces(char *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	return (i);
}

void skip_spaces(char **s)
{
	while (**s == ' ' || **s == '\t')
		(*s)++;
}

void	skip_digit(char **s)
{
	while (ft_isdigit(**s))
		(*s)++;
}

t_pos    set_pos(t_pos *pos, float x, float y)
{
    pos->x = x;
    pos->y = y;
    return *pos;
}

t_pos    copy_pos(t_pos *pos, t_pos s)
{
    pos->x = s.x;
    pos->y = s.y;
    return *pos;
}

float normalize_angle(float angle)
{
    angle = remainderf(angle, 2 * M_PI);
    if (angle < 0)
         angle += 2 * M_PI; 
    return (angle);
}

float distance(float x1, float y1, float x2, float y2)
{
    return (hypotf((x2 - x1), (y2 - y1)));
}