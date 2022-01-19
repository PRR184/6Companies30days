//Problem:-https://practice.geeksforgeeks.org/problems/run-length-encoding/1/
string encode(string src)
{     
  //Your code here 
  char c;
  int count=0;
  int i=0,n=src.length();
  string ans="";
  while(i<n){
      if(src[i]==c){
          count++;
      }else{
          if(i!=0){
            ans+=c;
            ans+=to_string(count);
          }
          c=src[i];
          count=1;
      }
      i++;
  }
    ans+=c;
    ans+=to_string(count);
  return ans;
  
} 