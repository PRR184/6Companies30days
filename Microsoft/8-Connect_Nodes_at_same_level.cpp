class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
       // Your Code Here
       queue<Node*>q;
       q.push(root);
       while(!q.empty()){
           int n=q.size();
           Node* last=NULL;
           while(n--){
               Node* node=q.front();
               q.pop();
               
               if(last){
                   last->nextRight=node;
               }
               node->nextRight=NULL;
               last=node;
               
               if(node->left)
                q.push(node->left);
               if(node->right)
                q.push(node->right);
           }
       }
    }    
      
};