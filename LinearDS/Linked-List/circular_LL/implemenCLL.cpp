#include <iostream>
using namespace std;

struct cnode{
    int data;
    struct cnode* next;
};

void append(struct cnode**, int);
void del_first(struct cnode**);
void del_last(struct cnode**);
void del_any(struct cnode**, int);
void display(struct cnode*);

int main(){
    struct cnode* start = NULL;
    append(&start, 10);
    append(&start, 20);
    append(&start, 30);
    append(&start, 40);
    append(&start, 50);
    append(&start, 60);
    display(start);
    del_first(&start);
    cout << "After calling del_first fun: " << endl;
    display(start);
    del_last(&start);
    cout << "After calling del_last fun: " << endl;
    display(start);
    del_any(&start,30);
    cout << "After calling del_any fun: " << endl;
    display(start);
    return 0;
}

void append(struct cnode** ps, int x){
    struct cnode* p, * temp;
    p = (struct cnode*)malloc(sizeof(struct cnode));
    if(p == NULL){
        cout << "Insufficient Memory";
        return;
    }
    p -> data = x;
    if(*ps == NULL){
        p -> next = p;
        *ps = p;
        return;
    }
    temp = *ps;
    while(temp -> next != *ps){
        temp = temp -> next;
    }
    temp -> next = p;
    p -> next = *ps;
}

void display(struct cnode* p){
    struct cnode* temp;
    if(p == NULL){
        cout << "List is empty";
        return;
    }
    temp = p;
    do
    {
        cout << temp -> data << endl;
        temp = temp -> next;
    } while (temp != p);
}

void del_first(struct cnode** ps){
    struct cnode *temp;
    if(*ps == NULL){
        cout << "List is empty";
        return;
    }
    if((*ps) -> next == *ps){
        free(*ps);
        *ps = NULL;
        return;
    }
    temp = *ps;
    while(temp -> next != *ps){
        temp = temp -> next;
    }
    temp -> next = (*ps) -> next;
    free(*ps);
    *ps = temp -> next;
}

void del_last(struct cnode** ps){
    struct cnode* temp;
    if(*ps == NULL){
        cout << "List is empty";
        return;
    }
    if((*ps) -> next == *ps){
        free(*ps);
        *ps = NULL;
        return;
    }
    while(temp -> next -> next != *ps){
        temp = temp -> next;
    }
    free(temp -> next);
    temp -> next = *ps;
}

void del_any(struct cnode** ps, int x){
    struct cnode* temp, * prev;
    if(*ps == NULL){
        cout << "List is empty";
        return;
    }
    temp = *ps;
    if((*ps) -> data == x){
        if((*ps) -> next == *ps){ // if first and only node which is to be deleted
            free(*ps);
            *ps = NULL;
            return;
        }
        while(temp -> next != *ps){ // if first node to be deleted
            temp = temp -> next;
        }
        temp -> next = (*ps) -> next;
        free(*ps);
        *ps = temp -> next;
        return;
    }
    
    while(temp -> next != *ps && temp -> data != x){
        prev = temp;
        temp = temp -> next;
    }
    if(temp -> data == x){
        prev -> next = temp -> next;
        free(temp);
    }
    else{
        cout << "Node not found" << endl;
    }
}