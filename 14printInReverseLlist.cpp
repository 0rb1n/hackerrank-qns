#include <iostream>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

SinglyLinkedListNode *llist(SinglyLinkedListNode *head, int n){
    if(head == nullptr){
        int num; cin>>num;
        head = new SinglyLinkedListNode(num);    
    }
    SinglyLinkedListNode *curr = head;
    for(int i=0; i<n-1; i++){
        int num; cin>>num;
        SinglyLinkedListNode *temp = new SinglyLinkedListNode(num);
        curr->next = temp;
        curr = temp;
    }
    return head;
}

SinglyLinkedListNode *reversellist(SinglyLinkedListNode *head){
    SinglyLinkedListNode *curr = head;
    SinglyLinkedListNode *next = head->next;
    SinglyLinkedListNode *temp = head;
    
    while(temp!=nullptr){
        temp = next->next;
        next->next = curr;
        curr = next;
        next = temp;
    }
    head->next = nullptr;
    head = curr;
    return head;
}

void printllist(SinglyLinkedListNode *ptr){
    while(ptr!=nullptr){
        cout<<ptr->data<<endl;
        ptr = ptr->next;
    }
}

int main(){
    int t; cin>>t;
    SinglyLinkedListNode *head = nullptr;
    for(int i=0; i<t; i++){
        head = nullptr;
        int n; cin>>n;
        head = llist(head, n);
        printllist(head);
        head = reversellist(head);
        printllist(head);
    }
    return 0;
}

