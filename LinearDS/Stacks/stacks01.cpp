/* #include <iostream>
using namespace std;

struct Stack {
    int arr[5];
    int toss;
};

void display(int* p, int n){
    for(int i = 0; i <= n; i++,p++){
        cout << *p << " " ;
    }
    cout << endl;
}

int main(){ 
    struct Stack S;
    S.toss = -1;
    
    //push
    S.toss = S.toss + 1;
    S.arr[S.toss] = 10;

    S.toss = S.toss + 1;
    S.arr[S.toss] = 20;

    S.toss = S.toss + 1;
    S.arr[S.toss] = 30;

    S.toss = S.toss + 1;
    S.arr[S.toss] = 40;

    S.toss = S.toss + 1;
    S.arr[S.toss] = 50;

    display(S.arr, S.toss);

    // pop
    int x;
    x = S.arr[S.toss];
    S.toss = S.toss - 1;
    cout << "Popped Element: " << x << endl;

    //pop
    x = S.arr[S.toss];
    S.toss = S.toss - 1;
    cout << "Popped Element: " << x << endl;

    display(S.arr, S.toss);
    
    return 0;
}

*/

//  < *********** Optimzed Code For PUSH AND POP ********* />

#include <iostream>
using namespace std;

struct Stack{
    int arr[5];
    int tos;
};

void push(struct Stack* p, int x){
    if(p->tos == 4){
        cout << "stack Overflow!";
        return;
    }
    p -> tos = p -> tos + 1;
    p -> arr[p -> tos] = x; // or delete 71 line and write p->arr[++p->tos]=x;
    cout << "\nPushed Element = " << x << endl;
}

int pop(struct Stack* p){
    if(p -> tos == -1){
        cout << "Stack Underflow!" << endl;
        return -1;
    }
    int x;
    x = p -> arr[p -> tos];
    p -> tos = p -> tos - 1;
    return x; // or delete 82 and 83 and write return p->arr[p->tos--];
}

int main(){
    struct Stack S;
    int i, x;
    S.tos = -1;

    for(i = 1; i <= 6; i++){
        cout << "Enter no. ";
        cin >> x;
        push(&S, x);
    }

    for(i = 1; i <= 6; i++){
        x = pop(&S);
        if(x != -1){
            cout << "\nPopped element = " << x << endl;
        }
    }
    return 0;
}

