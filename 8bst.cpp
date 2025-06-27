#include <iostream>
#include <fstream>


using namespace std;

struct Node{
    int data;
    Node *left; Node *right;
    Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

Node *insert(Node *root, int data){ //insertion
    if (root == nullptr){
        return new Node(data);
    }
    if(root->data == data)
        return root;
    if(root->data < data)
        root->right = insert(root->right,data);
    else
        root->left = insert(root->left, data);
    return root;
}

int height(Node* root) {//height of bst
    if (root == nullptr){
        return 0;
    }
        
    int leftCount = height(root->left);
    int rightCount = height(root->right);

    return 1+max(leftCount, rightCount);  
}

void printCurrentLevel(Node *root, int level){
    if(root == nullptr){
        return;
    }if(level == 1){
        cout<<root->data<<" ";
        return;
    }else {
        printCurrentLevel(root->left, level-1);
        printCurrentLevel(root->right, level-1);
    }
}

void levelOrder(Node * root) {// level order traversal
    int h = height(root);
    for (int i=1; i<=h; i++){
        printCurrentLevel(root, i);
    }
    return;
}

Node *lca(Node *root, int v1,int v2) {// lowest common ancestor of two elements
    
    while(root != nullptr){
		if(v1 > root->data && v2 > root->data)
            root = root->right;
        if(v1 < root->data && v2 < root->data)
            root = root->left;      
        else
            return root;
    }
    return nullptr;
}

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

int main() {
    Node *root = nullptr;
    ifstream infile;
    infile.open("input.txt");
    if(!infile){ 
        cout<<"error in opening input file"<<endl;return 1;
    }int i,data; infile>>i;
    while(i-- > 0){
        infile>>data; root = insert(root, data);
    }
    cout<<"insertion succesfull"<<endl
        <<"height of tree"
        <<height(root)<<endl
        <<"levelOrder";
    levelOrder(root); cout <<endl;
    int v1, v2; infile>>v1>>v2;
    Node *ptr = lca(root, v1, v2); cout<<ptr->data<<endl;
    return 0;
}
