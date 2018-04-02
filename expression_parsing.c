#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char stack[25];
int top = -1, int_stack[25], int_top = -1;

void push(char symbol)
{
    stack[++top] = symbol;
}

char pop()
{
    return stack[top--];
}

void int_push(int no)
{
    int_stack[++int_top] = no;
}

int int_pop()
{
    return int_stack[int_top--];
}

int isOperator(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
    case '(':
    case ')':
        return 1;
        break;
    default:
        return 0;
    }
}

int precedence(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
        return 2;
        break;
    case '/':
    case '*':
        return 3;
        break;
    case '^':
        return 4;
        break;
    default:
        return 1;
        break;
    }
}
void convert(char infix[], char postfix[])
{
    stack[++top] = '#';
    int j = 0; char symbol;
    for (int i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        if (isOperator(symbol) == 0)
        {
            postfix[j++] = symbol;
        }
        else
        {
            if (symbol == '(')
            {
                push(symbol);
            }
            else if (symbol == ')')
            {
                while (stack[top] != '(')
                {
                    postfix[j++] = pop();
                }

                pop();
            }
            else
            {
                if (precedence(symbol) > precedence(stack[top]))
                {
                    push(symbol);
                }
                else
                {
                    while (precedence(symbol) <= precedence(stack[top]))
                    {
                        postfix[j++] = pop();
                    }
                    push(symbol);
                }
            }
        }
    }

    while (stack[top] != '#')
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

void evaluate(char postfix[])
{
    int i = 0, operand1, operand2;
    char ch;
    while ((ch = postfix[i++]) != '\0')
    {
        if (isdigit(ch))
        {
            int_stack[++int_top] = ch-'0';
        }
        else
        {
            operand1 = int_pop();
            operand2 = int_pop();

            switch (ch)
            {
            case '+':
                int_push(operand1 + operand2);
                break;
            case '-':
                int_push(operand1 - operand2);
                break;
            case '*':
                int_push(operand1 * operand2);
                break;
            case '/':
                int_push(operand1 / operand2);
                break;
            case '^':
                int_push(pow(operand2,operand1));
                break;
            }
        }
    }

    printf("Evalution Result: %d \n", int_stack[int_top]);
}

int main()
{
    char infix[25] = "1*(2^3)", postfix[25];
    convert(infix, postfix);

    printf("Infix expression is: %s\n", infix);
    printf("Postfix expression is: %s\n", postfix);
    evaluate(postfix);

    return 0;
}