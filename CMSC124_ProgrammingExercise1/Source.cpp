/* Creator: Andrew Louis R. Hermo
   Course: BS Computer Science
   University: University of the Philippines - Mindanao
   Date Created: March 10, 2021
   Project Name: Programming Exercise 1: Procedural Programming
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "syntaxCheck.h"
#include "infix_to_prefix.h"

void Welcome(); // This function is used to display the Welcome Display Text
int CheckChoice(char choice); // This function is used to check if the user's choice is valid
void ProgDesc();  // This function is used to display the Program Description
void EvalExp();  // This function is used to evaluate expressions inputted by the user and return their answer

int main() { // Main Function
    char choice; // Variable to store user's choice
    while (1) { // Loops until the user exits the program
        system("cls");  // Clears the console
        Welcome();  // Outputs the main menu
        scanf("%c", &choice);  // Takes the user's input for the choice
        while ((getchar()) != '\n');
        if (!CheckChoice(choice)) {  // Checks if the user's choice is not viable; if true, then continue the Loop
            printf("\tInput error\n");
            system("pause");
            continue;
        }
        if (choice == 'P' || choice == 'p') {
            ProgDesc();
        }
        else if (choice == 'E' || choice == 'e') {
            EvalExp();
            system("pause");
        }
        else if (choice == 'X' || choice == 'x') break;
    }
    return 0;
}

void Welcome() { // This function is used to display the Welcome Display Text
    printf("Welcome to this Expression Evaluator Program! Please choose an action to\nperform...\n"); // Opening output
    printf("\t [P] Program Description\n");
    printf("\t [E] Evaluate expression(s)\n");
    printf("\t [X] Exit\n");
    printf("Choice: ");
}

int CheckChoice(char choice) { // This function is used to check if the user's choice is valid
    char list[6] = { 'p','e','x','P','E','X' }; // Array that stores every viable letter to use in the choices
    int i = 0, res = 0; // i is the iterating variable in the for loop, while res is the resulting "boolean" type variable to check if the choice is valid
    for (; i < 6; i++) {  // Loops the entire array for any matches
        if (choice == list[i]) return 1; // If a match is found returns a 1 or true
    }
    return 0; // If none has been found then return 0 or false
}

void ProgDesc() {  // This function is used to display the Program Description
    printf("\nCreated by: Andrew Louis Hermo\n");
    printf("Student Number: 2019-01621\n");
    printf("Date Created: March 10, 2021\n");
    printf("Date Completed: March 10, 2021\n");
    printf("Choice Descriptions: \n");
    printf("\t [P] Program Description is to display these texts\n");
    printf("\t [E] Evaluate expression(s) assesses an infix expression and outputs the answer\n");
    printf("\t [X] Exits the program\n");
    printf("Creator: Andrew Louis Hermo\n");
    printf("LinkedIn: https://www.linkedin.com/in/alrhermo/\n");
    system("pause");
    fflush(stdin);
}

void EvalExp() {  // This function is used to evaluate expressions
    char exp[20]; // String storage for the expression

    while (1) {
        printf("\nInput infix expression: ");
        scanf("%s", &exp); // Inputs the expression
        while ((getchar()) != '\n');  // Removes the newline in the input buffer
        if (checkExpValidity(exp)) break;   // Returns true and breaks the loop if the expression is valid
        else break; // Else if it returned false then continue
    }
}
