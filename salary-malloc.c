//Total salary of N employees for annual expenditure using dynamic memory allocation
#include <stdio.h>
#include <stdlib.h>

struct Employee {
    float monthly_salary;
};

int main() {
    int N, i;
    float total = 0.0;
    struct Employee *employees;

    printf("Enter the number of employees: ");
    scanf("%d", &N);

    employees = (struct Employee *)malloc(N * sizeof(struct Employee));

    if (employees == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (i = 0; i < N; i++) {
        printf("Enter monthly salary of employee %d: ", i + 1);
        scanf("%f", &employees[i].monthly_salary);
        total += employees[i].monthly_salary * 12;
    }

    printf("\nTotal annual salary expenditure: %.2f\n", total);

    free(employees);

    return 0;
}
