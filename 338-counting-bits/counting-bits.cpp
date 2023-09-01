class Solution {
public:
    int countSetBits(int number){
        int count=0;
        while(number){
           count+=number&1;
           number>>=1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int>ans;
         for(int i=0; i<=n; i++){
             ans.push_back(countSetBits(i));
         }
         return ans;
    }

};