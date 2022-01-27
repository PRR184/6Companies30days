//Problem:-https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#

//Time:O(N),Space:O(26);
struct Node{
        char data;
        Node* next;
        Node* prev;
    };
	public:
		string FirstNonRepeating(string A){
		    // Code here
            int hash[26]={0};
            Node* mp[26]={NULL};
            Node *head=NULL,*tail=NULL;
            string ans="";
            for(auto c:A){
                if(hash[c-97]){
                    if(head==NULL)
                        ans+='#';
                    else
                        ans+=head->data;
                    continue;
                }
                else if(mp[c-97]==NULL){
                 
                    Node *temp = new Node;
                    temp->data = c;
                    temp->next=NULL;
                    if(head==NULL){
                        temp->prev=NULL;
                        head=tail=temp;
                    }else{
                        tail->next=temp;
                        temp->prev=tail;
                        tail=temp;
                    }
                    mp[c-97]=temp;
                }else{
                    Node* temp=mp[c-97];
                    if(temp==head){
                        head=temp->next;
                        if(temp->next!=NULL)
                            temp->next->prev=NULL;
                        if(temp==tail)
                            tail=temp->prev;
                    }else{
                        temp->prev->next=temp->next;
                        if(temp->next)
                            temp->next->prev=temp->prev;
                        if(temp==tail)
                            tail=temp->prev;
                    }
                    delete temp;
                    mp[c-97]=NULL;
                    hash[c-97]=1;
                    
                }
                if(head==NULL)
                    ans+='#';
                else
                    ans+=head->data;
            }

            return ans;
		}