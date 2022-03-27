#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};

void append(struct node**, int); // ** when change in start
void display(struct node*);      // * when no change in start
void del_beg(struct node**);
void del_last(struct node**);
void del_any(struct node**, int);

int main(){
    struct node* start = NULL;
    append(&start, 10);
    append(&start, 20);
    append(&start, 30);
    append(&start, 40);
    append(&start, 50);
    append(&start, 60);
    display(start);
    del_beg(&start);
    cout << "After deleting one node from begning: " << endl;
    display(start);
    del_last(&start);
    cout << "After deleting one node from the end: " << endl;
    display(start);
    del_any(&start,50);
    cout << "After calling del any fun: " << endl;
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

void del_beg(struct node** ps){
    struct node *temp;
    if(*ps == NULL){
        cout << "List is empty" << endl;
    }
    temp = *ps;
    *ps = temp -> next;
    free(temp);
}

void del_last(struct node** ps){
    struct node* temp;
    if(*ps == NULL){
        cout << "List is empty";
        return;
    }
    if((*ps) -> next == NULL){
        free(*ps);
        *ps == NULL;
        return;
    }
    temp = *ps;
    while(temp -> next -> next != NULL){
        temp = temp -> next;
    }
    free(temp -> next);
    temp -> next = NULL;
}

void del_any(struct node** ps, int x){
    struct node* temp, * prev;
    if(*ps == NULL){
        cout << "List is empty";
        return;
    }
    temp = *ps;

    if((*ps) -> data == x){ // if req. node will be first one
        *ps = (*ps) -> next;
        free(temp);
        return;
    }
    while(temp != NULL && temp -> data != x){
        prev = temp;
        temp = temp -> next;
    }
    if(temp == NULL){
        cout << "Node to be deleted is not present!" << endl;
        return;
    }
    prev -> next = temp -> next;
    free(temp);
}