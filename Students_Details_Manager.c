/*Demo C Program To Maintain Students Personal Details
Author : Neeraj
Date : January 11, 2022
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define max 70

struct student
{
    char name[50];
    int rno;
    int marks;
} s1[max];

void main()
{
    int x, n, n1 = 0, ch, i = 0, no;
    printf("\nEnter Number of Student You Want To Enter Details Of : ");
    scanf("%d", &n);
more:
    if (ch == 1)
    {
        printf("\nEnter Number of Student You Want To Enter Details Of : ");
        scanf("%d", &n1);
        n = n + n1;
    }
    for (; i < n; i++)
    {
        printf("Enter Name of Student %d : ", i + 1);
        scanf("%s", s1[i].name);
        printf("Enter Roll no. of Student %d : ", i + 1);
        scanf("%d", &s1[i].rno);
        printf("Enter Marks of Student %d : ", i + 1);
        scanf("%d", &s1[i].marks);
    }
again:
    printf("\n\t\t::::SELECTION MENU::::\n");
    printf("\n(1)Want To Enter More Details\n(2)Want To Check Details of a Student\n(3)Exit - Details Entered Will Be Deleted After Exiting\nEnter Choice : ");
    scanf("%d", &ch);
    if (ch == 1)
    {
        goto more;
    }
    else if (ch == 2)
    {
        printf("\nEnter Roll no. of the Student : ");
        scanf("%d", &no);
        printf("\n\t\t::::DETAILS ARE AS BELOW::::\n");
        for (i = 0; i < max; i++)
        {
            if (no == s1[i].rno)
            {
                printf("\nThe Name of Student is : %s", s1[i].name);
                printf("\nThe Roll no. of %s is : %d", s1[i].name, s1[i].rno);
                printf("\nMarks of %s is : %d", s1[i].name, s1[i].marks);
                getch();
                system("cls");
                goto again;
            }
        }
    }
    else if (ch == 3)
    {
        exit(0);
    }
    else
    {
        printf("Invalid Choice!");
    }
    getch();
}