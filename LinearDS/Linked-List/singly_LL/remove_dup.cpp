#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};

void insert(struct node**, int);
void display(struct node*);
void remove_dup(struct node*);

int main(){
    struct node* start = NULL;
    insert(&start, 60);
    insert(&start, 40);
    insert(&start, 20);
    insert(&start, 40);
    insert(&start, 60);
    insert(&start, 40);
    insert(&start, 10);
    display(start);
    cout << "After remove duplicates -> " << endl;
    remove_dup(start);
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

void remove_dup(struct node* p){
    struct node* temp = p;
    if(p == NULL){
        cout << "List is empty";
        return;
    }
    while(temp -> next != NULL){ // temp != NULL creates problem when temp -> next == NULL 
        if(temp -> data == temp -> next -> data){
            // data equal to next node
            struct node* temp2 = temp -> next;
            temp -> next = temp -> next -> next;
            free(temp2);
        }else{
            // not equal
            temp = temp -> next;
        }
    }
}