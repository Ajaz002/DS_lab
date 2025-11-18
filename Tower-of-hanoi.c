#include <stdio.h>

void TowerofHanoi(int n, char from, char to, char aux)
{
    if(n==1)
    {
        printf("\n Move %d from %c to %c\n",n,from,to);
        return;
    }
    TowerofHanoi(n-1,from,aux,to);
    printf("\n Move %d from %c to %c\n",n,from,to);
    TowerofHanoi(n-1,aux,to,from);
}

void main()
{
    int n;
    printf("Enter number of towers: ");
    scanf("%d",&n);
    printf("Steps are:- \n");
    TowerofHanoi(n,'A','C','B');
}
