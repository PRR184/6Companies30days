//Time:O(N),space:O(N);
//Using BFS
class Solution {
    void findParents(map<Node*,Node*> &parent, Node *root, Node *p){
        if(!root)
            return;
        parent[root]=p;
        findParents(parent,root->left,root);
        findParents(parent,root->right,root);
    }
  public:
    Node* find(int target,Node* root){
        if(!root)
            return NULL;
        if(root->data==target)
            return root;
        Node *left=find(target,root->left);
        if(left)
            return left;
        return find(target,root->right);
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node*,Node*> parent;
        Node* p=NULL;
        findParents(parent,root,p);
        
        Node *node=find(target,root);
        set<Node*>vis;
        queue<Node*>q;
        q.push(node);
        vis.insert(node);
        
        int timer=0;
        while(!q.empty()){
            int n=q.size();
            bool flag=false;
            while(n--){
                Node* n=q.front();
                q.pop();
                
                if(n->left and vis.find(n->left)==vis.end()){
                    vis.insert(n->left);
                    flag=true;
                    q.push(n->left);
                }
                if(n->right and vis.find(n->right)==vis.end()){
                    vis.insert(n->right);
                    flag=true;
                    q.push(n->right);
                }
                if(parent[n] and vis.find(parent[n])==vis.end()){
                    vis.insert(parent[n]);
                    flag=true;
                    q.push(parent[n]);
                }
            }
            if(flag)
                timer++;
        }
        return timer;
    }
};