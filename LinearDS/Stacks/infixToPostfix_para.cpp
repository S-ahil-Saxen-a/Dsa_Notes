#include <iostream>
using namespace std;

struct Stack
{
    char arr[10];
    int tos;
};

void push(struct Stack*, char);
char pop(struct Stack*);

void convert(char[], char[]);
// first char = infix exp. and second char = ans array (postfix)

int isOperand(char);
// returns 1 when ch == operand otherwise returns 0

int prcd(char op1, char op2);
// op1 = char, op2 = stack-top
// returns 1 when precedence of outside char > stack-top otherwise 0

int isEmpty(struct Stack);
// returns 1 when stack is empty otherwise 0

int main(){
    char infix[20], postfix[20];
    cout << "Enter parantesized valid infix expression: ";
    cin >> infix;
    convert(infix, postfix);
    cout << "Postfix expn. = " << postfix;
    return 0;
}

void convert(char infix[20], char postfix[20]){
    struct Stack S;
    char ch;
    int i,j = 0;
    int result;
    S.tos = -1;

    for(i = 0; infix[i]; i++){
        ch = infix[i];
        if(ch == '('){
            push(&S,ch);
        }
        else if(ch == ')'){
            while(1){
                char c = pop(&S);
                if(c == '('){
                    break;
                }
                postfix[j++] = c;
            }
        }
        else if(isOperand(ch)){
            postfix[j++] = ch;
        }
        else{
            while(!isEmpty(S)){
                if(S.arr[S.tos] != '(' && !prcd(ch, S.arr[S.tos])){
                    postfix[j++] = pop(&S);
                }
                else{
                    break;
                }
            }
            push(&S, ch);
        }
    }
    while(!isEmpty(S)){
        postfix[j++] = pop(&S);
    }

    postfix[j] = '\0';
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
    if(op2 == '$')
        return 0;
    else if(op1 == '$')
        return 1;
    else if((op2 == '*') || (op2 == '/') || (op2 == '%'))
        return 0;
    else if((op1 == '*') || (op1 == '/') || (op1 == '%'))
        return 1;
    else if((op2 == '+') || (op2 == '-'))
        return 0;
    else
        return 1;
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