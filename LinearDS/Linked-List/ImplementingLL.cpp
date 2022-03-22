// By using structure --->
 #include <iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};

void append(struct node**, int); // ** when change in start
void display(struct node*);      // * when no change in start

int main(){
    struct node* start = NULL;
    append(&start, 10);
    append(&start, 20);
    append(&start, 30);
    append(&start, 40);
    display(start);
    return 0;
}

void append(struct node** ps, int x){
    struct node* p;
    p = (struct node*)malloc(sizeof(struct node));
    p -> data = x;
    p -> next = NULL;

    if(*ps == NULL){ // checking whether it will be first node or not
        *ps = p;
        return;
    }
    struct node* temp = *ps;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = p;
}

void display(struct node* p){
    if(p == NULL){
        cout << "List is empty";
        return;
    }

    while(p != NULL){
        cout << p -> data << endl;
        p = p -> next;
    }
}

/*
// using class and objects -->
#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;

    // constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void append(Node* &, int);
void display(Node*);

int main(){
    Node* start = new Node(10);
    append(start, 20);
    append(start, 30);
    append(start, 40);
    append(start, 50);
    display(start);
    
    return 0;
}

void append(Node* &ps, int x){
    Node* p = new Node(x);
    if(ps == NULL){ // checking whether it will be first node or not
        ps = p;
        return;
    }
    Node* temp = ps;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = p;
}

void display(Node* p){
    if(p == NULL){
        cout << "List is empty";
        return;
    }
    while(p != NULL){
        cout << p -> data << endl;
        p = p -> next;
    }
}
*/
