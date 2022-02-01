int solve(Node* root,int X,int &count){
    if(!root)
        return 0;
    int total=0;
    total+=solve(root->left,X,count);
    total+=solve(root->right,X,count);
    total+=root->data;
    if(total==X)
        count++;
    return total;
}
//Function to count number of subtrees having sum equal to given sum.
int countSubtreesWithSumX(Node* root, int X)
{
	// Code here
    int count=0;
    solve(root,X,count);
    return count;
        
}