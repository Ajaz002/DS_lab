//Total salary of N employees for annual expenditure using dynamic memory allocation
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, i;
    float *salaries, total = 0.0;

    printf("Enter the number of employees: ");
    scanf("%d", &N);

    salaries = (float *)malloc(N * sizeof(float));

    if (salaries == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (i = 0; i < N; i++) {
        printf("Enter monthly salary of employee %d: ", i + 1);
        scanf("%f", &salaries[i]);
        total += salaries[i] * 12;  
    }

    printf("\nTotal annual salary expenditure: %.2f\n", total);

    free(salaries);

    return 0;
}