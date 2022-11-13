class Solution {
public:
    vector<vector<bool> > solve(string &s)
    {
        int n = s.size();
        // cout<<s<<" "<<n<<endl;
        vector<vector<bool> > dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
            if (i < n && s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
            }
        }
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                if (s[i] == s[i + (len - 1)]
                    && dp[i + 1][i + (len - 1) - 1]) {
                    dp[i][i + (len - 1)] = true;
                }
            }
        }
        // vector<int> kmp(n, 0);
        // for (int i = 0; i < n; i++) {
        //     int j = 0, k = 1;
        //     while (k + i < n) {
        //         if (s[j + i] == s[k + i]) {
        //             dp[k + i - j][k + i] = false;
        //             kmp[k++] = ++j;
        //         }
        //         else if (j > 0) {
        //             j = kmp[j - 1];
        //         }
        //         else {
        //             kmp[k++] = 0;
        //         }
        //     }
        // }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=i;j<n;j++)
        //     {
        //         if(dp[i][j])
        //             cout<<i<<" "<<j<<endl;
        //     }
        // }
        return dp;
    }
    
    
    int jaadu(string &s,int curr,int last,int k,vector<vector<int>> &dp,vector<vector<bool> > &check)
    {
        if(curr<0)
            return 0;
        if(dp[curr][last]!=-1)
            return dp[curr][last];
        int ans=0;
        if(check[curr][last-1]==true && last-curr>=k)
        {
            // cout<<check<<" "<<last<<" "<<curr<<endl;
            ans=max(ans,1+jaadu(s,curr-1,curr,k,dp,check));
        }
        ans=max(ans,jaadu(s,curr-1,last,k,dp,check));
        ans=max(ans,jaadu(s,curr-1,curr,k,dp,check));
        return dp[curr][last]=ans;
    }
    
    
    int maxPalindromes(string s, int k) {
        int n=s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        vector<vector<bool> > check=solve(s);
        int count=0;
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=i;j<n;j++)
        //     {
        //         if(check[i][j])
        //         {
        //             count++;
        //             cout<<i<<" "<<j<<endl;
        //         }
        //     }
        // }
        // cout<<count<<endl;
        return jaadu(s,n-1,n,k,dp,check);
    }
};