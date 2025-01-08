#include<stdio.h>
#define MAX 40

typedef enum { lparen, rparen, plus, minus, times, divide, mod, eos, operand } precedence;

char EXPR[MAX];
int stack[20];
int top = -1;

precedence get_token(char *symbol, int *n) {
    *symbol = EXPR[(*n)++];
    switch (*symbol) {
        case '(': return lparen;
        case ')': return rparen;
        case '+': return plus;
        case '-': return minus;
        case '*': return times;
        case '/': return divide;
        case '%': return mod;
        case '\0': return eos;
        default: return operand;
    }
}

void push(int num) {
    stack[++top] = num;
}

int pop() {
    return stack[top--];
}

int eval() {
    precedence token;
    char symbol;
    int op1, op2, n = 0;
    token = get_token(&symbol, &n);
    
    while (token != eos) {
        if (token == operand) {
            push(symbol - '0');
        } else {
            op2 = pop();
            op1 = pop();
            
            switch (token) {
                case plus:
                    push(op1 + op2);
                    break;
                case minus:
                    push(op1 - op2);
                    break;
                case times:
                    push(op1 * op2);
                    break;
                case divide:
                    if (op2 == 0) {
                        printf("Error: Division by zero\n");
                        return -1;
                    }
                    push(op1 / op2);
                    break;
                case mod:
                    if (op2 == 0) {
                        printf("Error: Modulo by zero\n");
                        return -1;
                    }
                    push(op1 % op2);
                    break;
                default:
                    printf("Invalid operator\n");
                    return -1;
            }
        }
        token = get_token(&symbol, &n);
    }
    return pop();
}

int main() {
    int res;
    printf("\nEnter the postfix expression: ");
    scanf("%s", EXPR);
    
    res = eval();
    
    if (res != -1)
        printf("\nAfter evaluation: %d\n", res);
    
    return 0;
}
