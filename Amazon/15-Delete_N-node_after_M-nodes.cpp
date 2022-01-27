    void linkdelete(struct Node  *head, int M, int N)
    {
        //Add code here
        Node *temp=head;
        while(temp){
            //Retaining
            for(int i=1;i<M and temp!=NULL;i++){
                temp=temp->next;
            }
            
            //Deleting
            Node *dummy=temp;
            for(int i=0;i<=N and dummy!=NULL;i++){
                dummy=dummy->next;
            }
            if(temp)
                temp->next=dummy;
            temp=dummy;
        }
    }