class Solution {
public:
      long long factorial(long long k){
        if(k==0)return 1;
        return k*factorial(k-1);
    }
    long long ncr(long long n, long long r){
        long long ans;
        if(n-r>=r){
            long long up=1;
            for(int i=n-r+1; i<=n; i++){
                  up=up*i;
            }
            ans=up/factorial(r);
        }
        else{
            long long up=1;
            for(int i=r+1; i<=n; i++){
                up=up*i;
            }
            ans=up/factorial(n-r);
        }  
        return ans;
    }
    void solve(int n,vector<int>v,vector<vector<int>>&ans){
        if(n==0){
            return;
        }
            solve(n-1,v,ans);
            for(int i=0; i<n; i++){
                v.push_back(ncr(n-1,i));
            }
            ans.push_back(v);
    }
    vector<vector<int>> generate(int numRows) {
        vector<int>v;
        vector<vector<int>>ans;
        solve(numRows,v,ans);
        return ans;
    }
};