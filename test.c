#include <stdio.h>

int ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while(str && str[i])
		i++;
	return (i);
}

int main(void)
{
	unsigned long long int test;
	void *oui = "test";

	test = (unsigned long long int)&oui;
	printf("%lld\n", test);
}