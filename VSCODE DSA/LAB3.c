#include <stdio.h>
#include <string.h>

char stk[20];
int top = -1;
int max = 20;

void push()
{
    char ele;
    printf("Enter element for pushing: ");
    scanf(" %c", &ele);
    if (top >= max - 1)
    {
        printf("Stack Overflow!\n");
        return;
    }
    top++;
    stk[top] = ele;
    printf("%c pushed to stack.\n", ele);
}

char pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!\n");
        return '\0';
    }
    else
    {
        char ele = stk[top];
        top--;
        printf("%c popped from stack.\n", ele);
        return ele;
    }
}

int palindrome()
{
    char str[50];
    printf("Enter a word to check: ");
    scanf("%s", str);
    int len = strlen(str); 
    char pstk[len];
    for (int i = 0; i < len; i++)
    {
        pstk[i] = str[len - i - 1];
    }
    for (int i = 0; i < len; i++)
    {
        if (str[i] != pstk[i])
        {
            printf("Not a palindrome!\n");
            return 1;
        }
    }
    printf("It is a palindrome!\n");
    return 0;
}
void display()
{
    if (top == max - 1)
    {
        printf("Stack is full!\n");
    }
    else if (top == -1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Stack is partially full! Current size: %d\n", top + 1);
    }
}
int main()
{
    printf("BHAVYA\n 1AY23CS056\n");
    int choice;
    while (1)
    {
        printf("\n1.Push\n2.Pop\n3.Display status\n4.Check palindrome\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            palindrome();
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}