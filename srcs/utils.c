#include "../include/so_long.h"

// Function to compare two strings char by char and returns the
// diff between the first two non-matching char (in ASCII value)
int ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while(s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}