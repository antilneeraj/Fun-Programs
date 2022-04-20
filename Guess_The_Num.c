/*
A simple game in C to Guess The Number
Author : Neeraj
Date : January 27, 2022
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    int num, guess, count = 1, choice;
    char choice_1;
again:
    system("cls");
    printf("\n\t\t::::Guess The Number::::\n\n");
again_1:
    printf("\n\t\t::::SELECTION MENU::::\n(1) Start Game\n(2) Exit\nEnter Your Choice : ");
    scanf("%d", &choice);
    if (choice == 1)
    {

        srand(time(0));
        num = rand() % 100 + 1;
    more:
        printf("Enter Your Guess : ");
        scanf("%d", &guess);
        if (guess == num)
        {
            if (count == 1)
            {
                printf("\n\t\t::::You Guessed %d In %dst try::::\n", num, count);
                getch();
            }
            else
            {
                printf("\n\t\t::::You Guessed %d In %d tries::::\n", num, count);
                getch();
                count = 1;
                goto again;
            }
        iterate:
            printf("\n\t\t::::SELECTION MENU::::\nPlay Again\nEnter Your Choice (Yes/No): ");
            scanf("%s", &choice_1);
            if (choice_1 == 'Yes')
            {
                count = 1;
                goto again;
            }
            else if (choice_1 == 'No')
            {
                printf("::::I Hope you will be back soon::::");
                exit(0);
            }
            else
            {
                printf("\n\t\t...Invalid Choice! Entered (Opt as only Yes or No)...\n");
                goto iterate;
            }
        }
        else if (guess > num)
        {
            printf("\n\nLower Number Please\n\n");
            count++;
            goto more;
        }
        else if (guess < num)
        {
            printf("\n\nHigher Number Please\n\n");
            count++;
            goto more;
        }
        goto again;
    }
    else if (choice == 2)
    {
        printf("::::I Hope you will be back soon::::");
        exit(0);
    }
    else
    {
        printf("\n\t\t...Invalid Choice! Entered (Opt as only 1 or 2)...\n");
        goto again_1;
    }
}