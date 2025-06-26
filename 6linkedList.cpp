// #include <bits/stdc++.h>
#include <iostream>
#include <climits>

using namespace std;

struct node{
    int data;
    node* next;// like FILE* fptr;
};

void insertAfterNode(node* ptr, int data){
    if (ptr == nullptr) {
        cout << "Error: The given node pointer is null." << endl;
        return;
    }
    node *insert_node = new node;
    cout << "enter data"<<endl; cin>>insert_node->data;
    while (ptr->data != data)
    {
        ptr = ptr->next;
    }
    node* ptr1 = ptr->next;
    ptr->next = insert_node;
    insert_node->next = ptr1;   
}

// void insert_node_at_index(node* ptr, node* ptr1, int ind, node* insert_node){
//     printf("enter data"); scanf("%d", &insert_node->data);
//     for (int i = 0; i < ind; i++)
//     {
//         if (i == ind-1)
//         {
//             ptr->next = insert_node;
//             insert_node->next =  ptr1;
//             printf("succesfully inserted");
//         }
//         else{
//             ptr = ptr->next;
//             ptr1 = ptr1->next;
//         }
//     }   
// }

void insert_at_last(node* ptr, int data){
    node *insert_node = new node;
    insert_node->data = data;
    insert_node->next = nullptr;
    for(int i = 0; ;i++){
        if (ptr->next == NULL)
        {
            ptr->next = insert_node;
            insert_node->next = NULL;
            cout<<"succesfully inserted"<<endl;
            return;
        }
        ptr= ptr->next;
    } 
}

// void insert_at_first(node* ptr, node* insert_node){
//     printf("enter data"); scanf("%d", &insert_node->data);
//     insert_node->next = ptr;
//     printf("succesfully inserted");
// }

void traverse_ll(node* ptr){
    while (ptr != NULL){
        cout << ptr->data << endl;
        ptr = ptr->next;
    }   
}

int main(){

    node* head; node* second; node* last; node *insert_node;

    head = new node;
    second = new node;
    last = new node;
    head->data = 1;
    head-> next = second;
    second->data = 2;
    second->next = last;
    last->data = 4;
    last->next = NULL;

    int data = INT_MIN;
    insert_at_last(head, 3);
    traverse_ll(head);

    return 0;
}

