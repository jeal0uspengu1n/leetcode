class Solution {
public:
    bool dfs1(int node,int parent,vector<int> &bobTime,vector<int> &bobPath,vector<int> adj[])
    {
        bool f=false;
        for(auto it: adj[node])
        {
            if(it!=parent)
            {
                bobTime[it]=bobTime[node]+1;
                if(dfs1(it,node,bobTime,bobPath,adj)==true)
                {
                    f=true;
                    bobPath[it]=1;
                }
            }
        }
        if(node==0)
            f=true;
        return f;
    }
    
    // dfs(0,0,adj,bobPath,bobTime,time,amount)
    int dfs(int node,int parent,vector<int> adj[],vector<int> &bobPath,vector<int> &bobTime,int time,vector<int> &amount)
    {
        int temp=-1e9;
        int ans=0;
        if(bobPath[node]==1 && bobTime[node]==time)
        {
            ans+=(amount[node]/2);
            // cout<<node<<"=="<<parent<<endl;
        }
        else if(bobPath[node]==1 && bobTime[node]<time)
        {
            // sab changa sii
            // cout<<node<<"<"<<parent<<endl;
        }
        else
        {
            ans+=amount[node];
            // cout<<node<<"!"<<parent<<endl;
        }
        for(auto it: adj[node])
        {
            if(it!=parent)
            {
                temp=max(temp,dfs(it,node,adj,bobPath,bobTime,time+1,amount));
            }
        }
        if(temp!=-1e9)
            ans+=temp;
        return ans;
    }
    
    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=amount.size();
        vector<int> adj[n];
        for(int i=0;i<n-1;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> bobTime(n,INT_MAX);
        vector<int> bobPath(n,0);
        bobTime[bob]=0;
        bobPath[bob]=1;
        dfs1(bob,bob,bobTime,bobPath,adj);
        // for(auto it: bobTime)
        // {
        //     cout<<it<<endl;
        // }
        // Alice will move to different paths and let's see the answer
        int ans=dfs(0,0,adj,bobPath,bobTime,0,amount);
        // cout<<endl;
        return ans;
    }
};