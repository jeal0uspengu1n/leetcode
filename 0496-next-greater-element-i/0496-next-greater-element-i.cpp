class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        stack<int> s;
        for(int i=0;i<nums2.size();i++)
        {
            if(s.empty())
                s.push(i);
            else
            {
                while(!s.empty() && nums2[i]>nums2[s.top()])
                {
                    m[nums2[s.top()]]=nums2[i];
                    s.pop();
                }
                s.push(i);
            }
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++)
            ans.push_back( m[nums1[i]] > 0 ? m[nums1[i]] : -1 );
        return ans;
    }
};