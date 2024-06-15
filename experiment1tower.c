#include <stdio.h>

void move(int n, char source, char dest, char spare);

int main()
{
    int n;
    printf("\n Enter the number of rings: ");
    scanf("%d", &n);
    move(n, 'A', 'C', 'B');
    return 0;
}

void move(int n, char source, char dest, char spare)
{
    if (n == 1)
        printf("\n Move disk 1 from %c to %c", source, dest);
    else
    {
        move(n - 1, source, spare, dest);
        printf("\n Move disk %d from %c to %c", n, source, dest);
        move(n - 1, spare, dest, source);
    }
}
