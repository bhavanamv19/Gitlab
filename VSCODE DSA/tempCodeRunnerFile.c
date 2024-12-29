#include<stdio.h>

void tower(int n, char source, char aux, char destination) {
    if (n == 1) {
        printf("\nMove disc from %c to %c", source, destination);
    } else {
        tower(n - 1, source, destination, aux);
        printf("\nMove disc from %c to %c", source, destination);
        tower(n - 1, aux, source, destination);
    }
}

int main() {
    int n;
    char a = 'A', b = 'B', c = 'C';
    printf("Enter Number of Discs: ");
    scanf("%d", &n);
    printf("\nTower of Hanoi for %d discs:\n", n);
    tower(n, a, b, c);
     return 0;
}