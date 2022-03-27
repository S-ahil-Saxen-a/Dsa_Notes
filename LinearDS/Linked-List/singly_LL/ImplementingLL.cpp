// By using structure --->
#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};

void append(struct node**, int); // ** when change in start
void display(struct node*);      // * when no change in start
int countNodes(struct node*);
int searchNode(struct node*, int); 
// return position of element if found and 0 if list is empty, otherwise -1

void addAtBeg(struct node**, int);

int main(){
    struct node* start = NULL;
    append(&start, 10);
    append(&start, 20);
    append(&start, 30);
    append(&start, 40);
    append(&start, 50);
    append(&start, 60);
    display(start);
    cout << "No. of nodes in list = " << countNodes(start);
    cout << endl << searchNode(start,10) << endl;
    addAtBeg(&start,9);
    addAtBeg(&start,7);
    display(start);
    cout << "No. of nodes in list = " << countNodes(start);
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

int countNodes(struct node *p){
    int count = 0;
    while(p != NULL){
        count++;
        p = p -> next;
    }
    return count;
}

int searchNode(struct node* p, int x){
    int pos = 0;
    if(p == NULL){ // check if list is empty
        return 0;
    }
    while(p != NULL){
        pos++;
        if(p -> data == x){
            return pos;
        }
        p = p -> next;
    }
    return -1;
}

void addAtBeg(struct node** ps, int x){
    struct node* p;
    p = (struct node*)malloc(sizeof(struct node));
    p -> data = x;
    p -> next = *ps;
    *ps = p;
} 


// using class and objects -->
/* #include <iostream>
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
int countNodes(Node*);
int searchNode(Node*, int); 
// return position of element if found and 0 if list is empty, otherwise -1

void addAtBeg(Node* &, int);

int main(){
    Node* start = new Node(10);
    append(start, 20);
    append(start, 30);
    append(start, 40);
    append(start, 50);
    display(start);
    cout << "Total no. of nodes in list = "<< countNodes(start);
    cout << endl << searchNode(start, 50) << endl;
    addAtBeg(start,9);
    addAtBeg(start,7);
    display(start);
    cout << "No. of nodes in list = " << countNodes(start);
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

int countNodes(Node* p){
    int count = 0;
    while(p != NULL){
        count++;
        p = p -> next;        
    }
    return count;
}

int searchNode(Node* p, int x){
    int pos = 0;
    if(p == NULL){
        return 0;
    }
    while(p != NULL){
        pos++;
        if(p -> data == x){
            return pos;
        }
        p = p -> next;
    }
    return -1;
} 

void addAtBeg(Node* &ps, int x){
    Node* p = new Node(x);
    p -> next = ps;
    ps = p;
} */