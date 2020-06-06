//Time: O(n) and Space:O(1)

void decode_huff(node * root, string s) {  
    node *track=root;
    for(int i=0;i<s.size();i++){

        if(s[i]=='0'){
            track=track->left;
        }else{
            track=track->right;
        }

        if(track->left==NULL && track->right==NULL){
            cout<<track->data;
            track=root;
        }
    }
}
