#include <stdio.h>
#include <stdlib.h>

struct Employee {
    char name[30];
    unsigned short age;
    unsigned int id;
    float salary;
};

int main() {
    unsigned int nofemp;
    printf("Enter the number of employees: ");
    scanf("%u", &nofemp);

    struct Employee emp[nofemp];

    for (int i = 0; i < nofemp; i++) {
        printf("Enter employee %d info as id, name, age, salary: ", i+1);
        scanf("%u %29s %hu %f", &emp[i].id, emp[i].name, &emp[i].age, &emp[i].salary);
    }



    FILE *fp;
    fp = fopen("employeedata.txt","w");
    
    if(fp == NULL){
        printf("Error 69:");
        return -1;
    }

    fprintf(fp,"ID\t\tName\t\tAge\t\tSalary\n");
    for(int i=0;i<nofemp;i++){
        fprintf(fp,"%u\t\t%s\t\t%d\t%.2f\n",emp[i].id,emp[i].name,emp[i].age,emp[i].salary);
    }

    fclose(fp);

    return 0;
}
