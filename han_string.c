/**
 * _strcmp - compare string.
 * @s1: string 1
 * @s2: string 1
 * Return: no return
 */
int _strcmp(char *s1, char *s2)
{
	int x = 0, y = 0;

	for (; s1[x] && s2[y]; x++, y++)
		if (s1[x] != s2[y])
			return (0);
	if (!s1[x] && !s2[y])
		return (1);
	return (0);
}

/**
 * _strlen - function that helps find the length of a string.
 * @str: pointer to string
 *
 * Return: size
 */
int _strlen(char *str)
{
	int x = 0;

	if (str)
	{
		for (; str[x]; x++)
			;
		return (x + 1);
	}
	return (-1);
}
