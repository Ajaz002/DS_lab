
// Write a C program for tower of hanoi

#include<stdio.h>

void tower_of_hanoi(int n, char frompeg, char topeg, char auxpeg) {
    if(n==1) {
        printf("Move disk 1 from peg %c to peg %c\n",frompeg,topeg);
        return;
    }
    tower_of_hanoi(n-1, frompeg, auxpeg, topeg);
    printf("Move disk %d from peg %c to peg %c\n",n,frompeg,topeg);
    tower_of_hanoi(n-1, auxpeg, topeg, frompeg);
}

int main() {
    int n;
    printf("Enter the number of disks : ");
    scanf("%d",&n);
    printf("Steps involved in solving are ...\n");
    tower_of_hanoi(n,'A','C','B');
    return 0;
}
