#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

struct Stack {
    float arr[10];
    int tos;
};

void push(struct Stack*, float);
float pop(struct Stack*);
int isOperand(char);
float calculate(float, float, char);
float solve(char[]);

int main(){
    char pretfix[20];
    float ans;
    cout << "Enter a valid prefix expression: ";
    cin >> pretfix;
    ans = solve(pretfix);
    cout << "Result of prefix expression is " << ans;
    return 0;
}

float solve(char prefix[20]){
    struct Stack S;
    int i;
    float op1,op2;
    float res;
    char ch;

    S.tos = -1;
    for(i = strlen(prefix)-1; i >= 0; i--){
        ch = prefix[i];
        if(isOperand(ch) == 1){
            push(&S, ch-48); // 48 is face value, like '1'->49 so 49-48 = 1
        }
        else{
            op1 = pop(&S);
            op2 = pop(&S);
            res = calculate(op1, op2, ch);
            push(&S, res);
        }
    }
    res = pop(&S);
    return res;
}

void push(struct Stack* S, float val){
    if(S->tos == 9){
        cout << "Stack Overflow";
        return;
    }
    S->arr[++S->tos] = val;
}

float pop(struct Stack* S){
    if(S->tos == -1){
        cout << "Stack Underflow";
        return -1;
    }
    return S->arr[S->tos--];
}

int isOperand(char ch){
    if(ch >= '0' && ch <= '9'){ // ch>=48 && ch<=57
        // operand encountered ...
        return 1;
    }
    else{
        // operator encountered ...
        return 0;
    }
}

float calculate(float op1, float op2, char op){
    switch (op)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    case '%':
        return fmod(op1,op2);
    case '^':
    case '$':
        return (pow(op1,op2));
    default:
        return 0.0;
    }
}