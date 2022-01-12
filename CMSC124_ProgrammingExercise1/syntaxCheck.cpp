#include "syntaxCheck.h"
#include <stdio.h>
#include <ctype.h>

int checkChars(char x) { // This function checks whether the character in the expression is valid
    switch (x) {  // This switch statement checks every character case, if there is no match then returns false, else returns true
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case '(':
    case ')':
        return 1;
    }
    return 0;
}

int checkExpValidity(char* exp) {  // This function checks whether the entire expression has proper syntax and characters
    int parenthesis_count = 0;  // Counts the number of parenthesis in the expression for checking
    int i;  // Iterating variable for the string
    for (i = 0; i < 20 && exp[i] != '\0'; i++) {  // This loop checks if every character is valid
      // printf("Current char: %c\n",exp[i]);

        if (exp[i] == '(') parenthesis_count++;  // Increments parenthesis_count if there is an opening parenthesis
        else if (exp[i] == ')') parenthesis_count--; // Decrements parenthesis_count if there is a closing parenthesis
        if (parenthesis_count < 0) {  // If there are more closing parenthesis than opening parenthesis the input is invalid
            printf("Invalid infix expression\n");
            return 0;
        }

        // printf("Parenthesis Count:%d\n\n",parenthesis_count);
        if (isdigit(exp[i])) continue; // If the character is a digit, then continue
        if (checkChars(exp[i])) continue;  // If the character is a parenthesis or operator then continue
        else { // If the character is invalid, then return to main menu
            printf("Invalid infix expression\n");
            return 0;
        }
    }
    if (parenthesis_count != 0) { // IF the parenthesis number is uneven, then return to main menu
        printf("Invalid infix expression\n");
        return 0;
    }
    printf("Good input\n");
    return 1;
}