#include <unistd.h>

void    ft_putnbr(int n)
{
    long nb;
    char c;

    nb = n;
    if (nb < 0)
    {
        nb = -nb;
        write(1, "-", 1);
    }
    if (nb >= 10)
    {
        ft_putnbr(nb / 10);
        ft_putnbr(nb % 10);
    }
    if (nb < 10)
    {
        c = nb + '0';
        write(1, &c, 1);
    }
}

/*int main(void)
{
    ft_putnbr(245);
}*/