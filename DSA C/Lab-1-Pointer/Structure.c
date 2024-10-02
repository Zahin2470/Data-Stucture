#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    char name[50];
    int id;
    float cgpa;
};

int main()
{
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));

    if (students == NULL)
    {
        printf("Fail \n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter details for student : %d :\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("ID: ");
        scanf("%d", &students[i].id);
        printf("CGPA: ");
        scanf("%f", &students[i].cgpa);
    }

    int highestIndex = 0;
    float highestCGPA = students[0].cgpa;

    for (int i = 1; i < n; i++) {
        if (students[i].cgpa > highestCGPA) {
            highestIndex = i;
            highestCGPA = students[i].cgpa;
        }
    }

    printf("\nStudent with the highest CGPA in CSE-207 is:\n");
    printf("Name: %s\n", students[highestIndex].name);
    printf("ID: %d\n", students[highestIndex].id);
    printf("CGPA: %.2f\n", students[highestIndex].cgpa);

    return 0;
}