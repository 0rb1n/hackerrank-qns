#include <iostream>
#include <vector>

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

bool searchNode(Node* root, int value, vector<int>&arr){
    if (root == nullptr) return false;
    arr.push_back(root->data);
    if (root->data == value) return true;

    if(searchNode(root->left, value, arr)) return true;
    if(searchNode(root->right, value, arr)) return true;
    arr.pop_back();
    return false;
}

int lowestCommonAncestor(vector<int> arr1, vector<int> arr2){
    int size = min(arr1.size(), arr2.size());
    for(int i=size-1; i>=0; i--){
        if(arr1[i] == arr2[i]){
            return arr1[i];
        }
    }
    return 0;
}

int dist(vector<int> arr1, vector<int> arr2){
    int size = min(arr1.size(), arr2.size());   int count=0;
    for(int i=0; ; i++){
        if(arr1[i] == arr2[i]){
            continue;
        }
        else{
            if(i < arr1.size()) count++;
            if(i < arr2.size()) count++;
            else{
                return count;
            }
        }
    }
}


int main() {
    // Create a sample binary tree
    Node* root = new Node(1);           //1
    root->left = new Node(2);         //2   3
    root->right = new Node(3);      //4   5
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> path1; vector<int> path2; int targetValue1=4, targetValue2=3;
    bool found1 = searchNode(root, targetValue1, path1);
    bool found2 = searchNode(root, targetValue2, path2);
    if (found1) {
        cout << "Node with value " << targetValue1 << " found." << endl;
        cout << "Path: ";
        for (size_t i = 0; i < path1.size(); ++i) {
            cout << path1[i];
            if (i < path1.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
    } else {
        cout << "Node with value " << targetValue1 << " not found." << endl;
    }

    if (found2) {
        cout << "Node with value " << targetValue2<< " found." << endl;
        cout << "Path: ";
        for (size_t i = 0; i < path2.size(); ++i) {
            cout << path2[i];
            if (i < path2.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
    } else {
        cout << "Node with value " << targetValue2<< " not found." << endl;
    }
    if(found1 && found2){
        int lca = lowestCommonAncestor(path1, path2);
        cout<<"lca "<<lca<<endl;
    }

    int distance = dist(path1, path2);
    cout<<"distance "<<distance<<endl;
    return 0;
}