#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MAX 10

int stack[MAX];
int top = -1;

void push(int val) {
    if(top >= MAX - 1) {
        printf("Stack overflow\n");
    } else {
        top++;
        stack[top] = val;
    }
}

int pop() {
    if(top <= -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        int x = stack[top];
        top--;
        return x;
    }
}

int main() {
    printf("\n Bhavana M V \n 1AY23CS055\n");
    char* exp = "19*10/4+20-1%2^2";
    int i, val1, val2;

    for(i = 0; exp[i] != '\0'; i++) {
        if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '%' || exp[i] == '^') {
            val1 = pop();
            val2 = pop();
            if(exp[i] == '+') {
                push(val2 + val1);
            } else if(exp[i] == '-') {
                push(val2 - val1);
            } else if(exp[i] == '*') {
                push(val2 * val1);
            } else if(exp[i] == '/') {
                push(val2 / val1);
            } else if(exp[i] == '%') {
                push(val2 % val1);
            } else if(exp[i] == '^') {
                push(pow(val2, val1));
            }
        } else {
            push(exp[i] - '0');
        }
    }

    printf("\n Answer = %d", stack[top]);
    return 0;
}
