#include<stdio.h>
#define senpa printf("--------------------------------\n");

int main() {
    char emp_id[5], emp_name[30];
    double emp_salary, tax, social, salary_total;

    senpa
    printf(" Calculate Salary Total\n");
    senpa
    printf("Enter employee ID : "); scanf("%s", emp_id);
    printf("Enter employee name : "); scanf("%s", emp_name);
    printf("Enter employee salary : "); scanf("%lf", &emp_salary);
    senpa
    tax = emp_salary * 0.07; // หรือ emp_salary *7/100
    social = emp_salary * 0.03; // หรือ emp_salary *3/100
    salary_total = emp_salary - tax - social;
    printf("Employee ID : %s\n", emp_id);
    printf("Employee Name : %s\n", emp_name);
    printf("Employee Salary : %.2lf\n", emp_salary);
    printf("Tax 7%% : %.2lf\n", tax);
    printf("Social 3%% : %.2lf\n", social);
    senpa
    printf("Salary Total : %.2lf\n", salary_total);
    senpa
    return 0;
}