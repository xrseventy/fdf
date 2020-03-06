int		ft_isalnum(int i)
{
	if ((i >= '0' && i <= '9') || (i >= 'A' && i <= 'Z') ||
			(i >= 'a' && i <= 'z'))
		return (1);
	return (0);
}
