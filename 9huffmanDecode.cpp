void decode_huff(node * root, string s) {
    node *ptr = root;
    for (int i=0; i<s.length(); i++){
        if(s[i] == '0'){
            ptr = ptr->left;
            if(ptr->left == nullptr && ptr->right == nullptr){  
                cout<<ptr->data;
                ptr = root;
            }                                                                           
        }
        else{
            ptr = ptr->right;
            if(ptr->left == nullptr && ptr->right == nullptr){  
                cout<<ptr->data;
                ptr = root;
            }                        
        }
    }
}