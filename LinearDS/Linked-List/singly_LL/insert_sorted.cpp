#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};

void insert(struct node**, int);
void display(struct node*);

int main(){
    struct node* start = NULL;
    insert(&start, 60);
    insert(&start, 40);
    insert(&start, 20);
    insert(&start, 90);
    insert(&start, 5);
    insert(&start, 10);
    display(start);
    return 0;
}

void insert(struct node** ps, int x){
    struct node* p, * temp, * prev;
    p = (struct node*)malloc(sizeof(struct node));
    if(p == NULL){
        cout << "Insufficient Memory";
        return;
    }

    p -> data = x;
    if(*ps == NULL){
        *ps = p;
        p -> next = NULL;
        return;
    }

    if(x < (*ps) -> data){
        p -> next = *ps;
        *ps = p;
        return;
    }

    temp = *ps;
    while(temp != NULL && temp -> data < x){
        prev = temp;
        temp = temp -> next;
    }
    if(temp == NULL){
        prev -> next = p;
        p -> next = NULL;
    }
    else{
        prev -> next = p;
        p -> next = temp;
    }
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