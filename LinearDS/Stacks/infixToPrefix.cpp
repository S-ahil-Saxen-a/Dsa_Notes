#include <iostream>
#include <cstring>
using namespace std;

struct Stack{
    char arr[10];
    int tos;
};

void push(struct Stack*, char);
char pop(struct Stack*);

int isOperand(char);
// return 1 when char will be operand otherwise 0

int prcd(char, char);
// first char will be outside operator and second will be stack-top.
// If prcd of outside op >= stack-top then returns 1 otherwise 0

int isEmpty(struct Stack);
// returns 1 when stack is empty otherwise 0

void convert(char[], char[]);
// first char[] = infix expn. and second char[] = empty ans array (prefix)

int main(){
    char infix[20],prefix[20];
    cout << "Enter a valid infix expression: ";
    cin >> infix;
    convert(infix, prefix);
    cout << "Prefix Expression: " << prefix << endl;
    return 0;
}

void convert(char infix[20], char prefix[20]){
    struct Stack S;
    int i,result,j = 0;
    S.tos = -1;
    
    for(i = strlen(infix)-1; i >= 0; i--){
        char ch = infix[i];
        if(isOperand(ch)){
            prefix[j++] = ch;
        }
        else{
            while(!isEmpty(S)){
                if(!prcd(ch,S.arr[S.tos])){
                    prefix[j++] = pop(&S);
                }
                else{
                    break;
                }
            }
            push(&S,ch);
        }
    }
    while(!isEmpty(S)){
        prefix[j++] = pop(&S);
    }
    prefix[j] = '\0';
    strrev(prefix);
    return;
}

int isOperand(char ch){
     if((ch >= 'a' && ch <= 'z') || 
       (ch >= 'A' && ch <= 'Z') || 
       (ch >= '1' && ch <= '9')){
           return 1;
    }
    return 0;
}

int isEmpty(struct Stack S){
    return S.tos == -1;
}

int prcd(char op1, char op2){
    if(op1 == '$')
        return 1;
    else if(op2 == '$')
        return 0;
    else if(op1 == '*' || op1 == '/' || op1 == '%')
        return 1;
    else if(op2 == '*' || op2 == '/' || op2 == '%')
        return 0;
    else if(op1 == '+' || op1 == '-')
        return 1;
    else
        return 0;
}

void push(struct Stack *S, char ch){
    if(S->tos == 9){
        cout << "Stack Overflow!";
        return;
    }
    S->arr[++S->tos] = ch;
}

char pop(struct Stack *S){
    if(S->tos == -1){
        cout << "Stack Underflow";
        return -1;
    }
    return S->arr[S->tos--];
}