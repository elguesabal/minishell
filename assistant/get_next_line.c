#include "../minishell.h"

char	*get_line(char *rest_line)
{
	int		i;
	char	*str;

	i = 0;
	if (!rest_line[i])
		return (NULL);
	while (rest_line[i] && rest_line[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (rest_line[i] && rest_line[i] != '\n')
	{
		str[i] = rest_line[i];
		i++;
	}
	if (rest_line[i] == '\n')
	{
		str[i] = rest_line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*new_line(char *rest_line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (rest_line[i] && rest_line[i] != '\n')
		i++;
	if (!rest_line[i])
	{
		free(rest_line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(rest_line) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (rest_line[i])
		str[j++] = rest_line[i++];
	str[j] = '\0';
	free(rest_line);
	return (str);
}

char	*read_rest_line(int fd, char *rest_line)
{
	char	*buffer;
	int		rd_bytes;

	buffer = malloc((100 + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(rest_line, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buffer, 100);
		if (rd_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[rd_bytes] = '\0';
		rest_line = ft_strjoin(rest_line, buffer);
	}
	free(buffer);
	return (rest_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest_line;

	if (fd < 0 || 100 <= 0)
		return (0);
	rest_line = read_rest_line(fd, rest_line);
	if (!rest_line)
		return (NULL);
	line = get_line(rest_line);
	rest_line = new_line(rest_line);
	return (line);
}
