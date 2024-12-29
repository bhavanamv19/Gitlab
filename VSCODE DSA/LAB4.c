#include <stdio.h>
#include <ctype.h>
#define SIZE 10
char stack[SIZE];
int top = -1;

void push(char elem)
{
    ++top;
    stack[top] = elem;
}

char pop()
{
    return (stack[top--]);
}

int precedence(char elem) /* Function for precedence */
{
    switch (elem)
    {
        case '#': return 0;
        case '(': return 1;
        case '+':
        case '-': return 2;
        case '*':
        case '/':
        case '%': return 3;
        case '$':
        case '^': return 4;
    }
    return elem;
}

void main() {
    printf("BHAVYA\tUSN-1AY23CS056\n");
    char infix[50], postfix[50], ch, elem;
    int i = 0, k = 0;
    
    printf("\nEnter the Infix Expression: ");
    scanf("%s", infix);
    
    push('#'); // first item to push is # to indicate an empty stack
    
    while ((ch = infix[i++]) != '\0')
    {
        if (ch == '(')
            push(ch);
        else if (isalnum(ch))
            postfix[k++] = ch;
        else if (ch == ')')
        {
            while (stack[top] != '(')
                postfix[k++] = pop();
            elem = pop(); // Remove '('
        }
        else // Operator
        {
            while (precedence(stack[top]) >= precedence(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }
    
    while (stack[top] != '#') // Pop remaining operators from the stack
        postfix[k++] = pop();
    
    postfix[k] = '\0'; // Null-terminate the postfix expression
    
    printf("Given Infix Expression is: %s\n", infix);
    printf("Postfix Expression is: %s\n", postfix);
}