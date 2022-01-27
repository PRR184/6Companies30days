    void serializeUtil(Node *root,vector<int> &ans){
       if(!root){
           ans.push_back(-1);
           return;
       }
       ans.push_back(root->data);
       serializeUtil(root->left,ans);
       serializeUtil(root->right,ans);
    }
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        //Your code here
        vector<int>ans;
        serializeUtil(root,ans);
        return ans;
    }
    Node* deSerializeUtil(vector<int> &ans,int &start,int n){
        if(ans[start]==-1){
            start++;
            return NULL;
        }
        Node* root=new Node(ans[start++]);
        root->left=deSerializeUtil(ans,start,n);
        root->right=deSerializeUtil(ans,start,n);
        return root;
    }
    //Function to deserialize a list and construct the tree.
    Node* deSerialize(vector<int> &A)
    {
       //Your code here
       int n=A.size();
       int start=0;
       return deSerializeUtil(A,start,n);
    }