//Probelm:-https://practice.geeksforgeeks.org/problems/decode-the-string2444/1

//Thinking similar to balanced paranthesis problem.
// Time:O(|S|) nad Space:O(|S|)
class Solution{
public:
    string decodedString(string s){
        // code here
        stack<string>s1;
        int len=s.length();
        for(int j=0;j<len;j++){
            if(isdigit(s[j])){
                string temp="";
                while(isdigit(s[j])){
                    temp+=s[j];
                    j++;
                }
                s1.push(temp);
                j--;
            }
            else if(s[j]==']'){
                string temp="";
                while(!s1.empty() and s1.top()!="["){
                    temp=s1.top()+temp;
                    s1.pop();
                }
                s1.pop();
                int n=stoi(s1.top());
                string temp1="";
                for(int i=0;i<n;i++)
                    temp1+=temp;
                s1.pop();    
                s1.push(temp1);
            }else{
                string temp="";
                temp+=s[j];
                s1.push(temp);
                // cout<<x<<"-"<<s1.top()<<"\n";
            }
        }
        return s1.top();
    }
};