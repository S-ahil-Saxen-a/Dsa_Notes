#include <iostream>
using namespace std;

struct doubly{
    struct doubly* prev;
    int data;
    struct doubly* next;
};

void append(struct doubly**, int);
void del_first(struct doubly**);
void del_last(struct doubly**);
void del_any(struct doubly**, int);
void show(struct doubly*);

int main(){
    struct doubly* start = NULL;
    append(&start,10);
    append(&start,20);
    append(&start,30);
    append(&start,40);
    append(&start,50);
    append(&start,60);
    show(start);
    del_first(&start);
    cout << "After deleting one node from begning: " << endl;
    show(start);
    del_last(&start);
    cout << "After deleting one node from the end: " << endl;
    show(start);
    del_any(&start,50);
    cout << "After deleting 50 from the list: " << endl;
    show(start);
    return 0;
}

void append(struct doubly** ps, int x){
    struct doubly* p, * temp;
    p = (struct doubly*)malloc(sizeof(struct doubly));
    if(p == NULL){
        cout << "Insufficient Memory";
        return;
    }
    p -> data = x;
    p -> next = NULL;
    if(*ps == NULL){
        *ps = p;
        p -> prev = NULL;
        return;
    }
    temp = *ps;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = p;
    p -> prev = temp;
}

void show(struct doubly* p){
    if(p == NULL){
        cout << "List is empty";
        return;
    }
    while(p != NULL){
        cout << p -> data << endl;
        p = p -> next;
    }
}

void del_first(struct doubly** ps){
    struct doubly *temp;
    if(*ps == NULL){
        cout << "List is empty";
        return;
    }
    if((*ps) -> next == NULL){
        free(*ps);
        *ps = NULL;
        return;
    }
    temp = *ps;
    *ps = temp -> next;
    free(temp);
    (*ps) -> prev = NULL;

    // skip line 65 - 73
 /* temp = *ps;
    *ps = temp -> next;
    free(temp);
    if(*ps != NULL)
        (*ps) -> prev = NULL;
 */
}

void del_last(struct doubly** ps){
    if(*ps == NULL){
        cout << "List is empty";
        return;
    }

    if((*ps) -> next == NULL){
        free(*ps);
        *ps == NULL;
        return;
    }

    struct doubly* temp = *ps, *prev;
    while(temp -> next != NULL){
        prev = temp;
        temp = temp -> next;
    }
    prev -> next = temp -> next; // prev = NULL
    free(temp);
}

void del_any(struct doubly** ps, int x){
    if(*ps == NULL){ // list is empty
        cout << "List is empty";
        return;
    }

    if(((*ps) -> data == x) && ((*ps) -> next == NULL)){   // if first node to be deleted                                                                                                
        free(*ps);                                        // iff fitst node is present
        *ps = NULL;
        return;
    }

    struct doubly* temp = *ps;
    while(temp -> next && temp -> data != x){
        temp = temp -> next;
    }

    if(temp -> data == x){
        if(temp == *ps){  // first node to be deleted
            *ps = temp -> next;
            temp -> next -> prev = temp -> prev;
            free(temp);
            return;
        }

        if(temp -> next == NULL){ // last node to be deleted
            temp -> prev -> next = temp -> next;
            free(temp);
            return;
        }

        temp -> next -> prev = temp -> prev;
        temp -> prev -> next = temp -> next;
        free(temp);
    }
    else{
        cout << "Node not found!" << endl;
    }
    
}

