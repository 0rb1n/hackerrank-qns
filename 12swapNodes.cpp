#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

struct Node{
    int data;
    Node *right;
    Node *left;
    Node *link;
    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

void inorderSwap(Node* root, int k, int depth) {
    if (root == nullptr) {
        return;
    }
    if (depth % k == 0) {
        Node* ptr = root->left;
        root->left = root->right;
        root->right = ptr;
    }
    inorderSwap(root->left, k, depth + 1);
    cout << root->data << " ";
    inorderSwap(root->right, k, depth + 1);
}

Node* createBinaryTree(const vector<pair<int, int>>& indexes) {
    Node* root = new Node(1);
    queue<Node*> q;
    q.push(root);

    for (const auto& index : indexes) {
        Node* current = q.front();
        q.pop();

        if (index.first != -1) {
            current->left = new Node(index.first);
            q.push(current->left);
        }
        if (index.second != -1) {
            current->right = new Node(index.second);
            q.push(current->right);
        }
    }

    return root;
}

int main(){
    int size; cin>>size;
    vector<pair<int,int>>indexes;
    for(int i=0; i<size; i++){
        int a=0, b=0;
        cin>>a>>b;
        indexes.push_back(make_pair(a, b));
    }
    Node* root = createBinaryTree(indexes);
    int q; cin>>q;
    while(q>0){
        int k; cin>>k;;
        inorderSwap(root, k, 1);
        cout << endl;
        q--;
    }
    return 0;
}