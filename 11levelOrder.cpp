#include<iostream>
#include<fstream>
#include<deque>
using namespace std;

struct node{
    int data;
    node *right;
    node *left;
    node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

deque<node*> levelOrder(node *root){
    deque<node*> dq1; deque<node*> dq2;
    dq1.push_back(root); dq1.push_back(root->left); dq1.push_back(root->right);
    dq2 = dq1; dq2.pop_front();
    while(!dq2.empty()){
        if(dq2.front()->left != nullptr){
            dq1.push_back(dq2.front()->left);
            dq2.push_back(dq2.front()->left);
        }
        if(dq2.front()->right != nullptr){
            dq1.push_back(dq2.front()->right);
            dq2.push_back(dq2.front()->right);
        }
        dq2.pop_front();
    }
    return dq1;
}
