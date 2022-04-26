#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};

void append(struct node**, int); // ** when change in start
void display(struct node*);      // * when no change in start
void print_reverse(struct node**);

int main(){
    struct node* start = NULL;
    append(&start, 10);
    append(&start, 20);
    append(&start, 30);
    append(&start, 40);
    append(&start, 50);
    append(&start, 60);
    display(start);
    
    cout << "Reverse printing the linked list" << endl;
    
    print_reverse(&start);
    display(start);

    return 0;
}

void print_reverse(struct node** ps){
     struct node* temp = *ps;
     struct node* prev = NULL;
     struct node* curr;

     while(temp){
         curr = temp;
         temp = temp -> next;
         curr -> next = prev;
         prev = curr;
     }
     *ps = curr;
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