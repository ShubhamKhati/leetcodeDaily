class Solution {
public:

    int solve(int i, string &s,unordered_map<string,int>&jd,vector<int>&dp)
    {

        if(i==s.size())
        {
            return 0;
        }

        if(dp[i]!=-1)
        {
            return dp[i];
        }

        string ans = "";
        int extra = 0,result = s.size();
        int total ;
        for(int idx = i; idx<s.size(); idx++)
        {

            ans+=s[idx];
            if(jd.find(ans)==jd.end())
            {
                extra = ans.size();
            }
            else
            {
                extra = 0;
            }

            int z = solve(idx+1,s,jd,dp);
            total  = z + extra;

            result  = min(total,result);


        }
        
        dp[i]=result;
        return result;
    }


    int minExtraChar(string s, vector<string>& dictionary) {
        
        unordered_map<string,int>jd;
        vector<int>dp(s.size(),-1);
        for(int i=0; i<dictionary.size(); i++)
        {
            jd[dictionary[i]]=0;
        }

        int ans  = solve(0,s,jd,dp);
        return ans;

    }
};