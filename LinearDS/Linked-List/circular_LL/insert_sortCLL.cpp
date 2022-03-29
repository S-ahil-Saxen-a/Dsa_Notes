#include <iostream>
using namespace std;

struct cnode{
    int data;
    struct cnode* next;
};

void insert(struct cnode**, int);
void display(struct cnode*);

int main(){
    struct cnode* start = NULL;
    insert(&start, 60);
    insert(&start, 40);
    insert(&start, 20);
    insert(&start, 90);
    insert(&start, 5);
    insert(&start, 10);
    display(start);
    return 0;
}

void insert(struct cnode** ps, int x){
    struct cnode* p, * temp, * prev;
    p = (struct cnode*)malloc(sizeof(struct cnode));
    if(p == NULL){
        cout << "Insufficient Memory";
        return;
    }
    p -> data = x;
    if(*ps == NULL){
        *ps = p;
        p -> next = p;
        return;
    }
    temp = *ps;

    if(x < (*ps) -> data){
        p -> next = *ps;
        while(temp -> next != *ps){
            temp = temp -> next;
        }
        temp -> next = p;
        *ps = p;
        return;
    }

    while(temp -> next != *ps && temp -> data < x){
        prev = temp;
        temp = temp -> next;
    }
    if(temp -> next == *ps){
        temp -> next = p;
        p -> next = *ps;
    }
    else{
        prev -> next = p;
        p -> next = temp;
    }
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