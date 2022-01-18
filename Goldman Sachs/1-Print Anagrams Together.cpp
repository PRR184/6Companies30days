//Q - https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/#
//Time : O(N x (length of all Strings)) [Assuming unordered_map(O(1))]
class Solution{
  public:
    vector<vector<string>> Anagrams(vector<string>& string_list) {
        vector<vector<string>>ans;
        //code here
        set<string>s;
        int n=string_list.size();
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i])
                continue;
            unordered_map<char,int>mp;
            for(auto l:string_list[i])
                mp[l]++;
            vector<string>temp;
            temp.push_back(string_list[i]);
            for(int j=i+1;j<n;j++){
                if(visited[i])
                    continue;
                unordered_map<char,int>mp1;
                for(auto l:string_list[j])
                    mp1[l]++;
                int countJ=0;
                for(auto x:mp){
                    if(mp1[x.first]!=x.second)
                        break;
                    else
                        countJ++;
                }
                if(countJ==mp.size()){
                    temp.push_back(string_list[j]);
                    visited[j]=1;
                }
                
            }
            visited[i]=1;
            ans.push_back(temp);
        }
        return ans;
    }
};