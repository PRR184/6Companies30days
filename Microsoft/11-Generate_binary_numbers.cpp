vector<string> generate(int N)
{
	// Your code here
	vector<string>ans;
	queue<string>q;
	q.push("1");
	for(int i=0;i<N;i++)
	{
	    string curr = q.front();
	    q.pop();
	    ans.push_back(curr);
	    q.push(curr+"0");
	    q.push(curr+"1");
	}
	return ans;
}
