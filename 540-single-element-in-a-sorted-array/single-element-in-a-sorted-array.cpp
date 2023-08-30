class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int s=0; int e=nums.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
             cout<<s<<" "<<e<<" "<<",mid = "<<mid<<endl;
            if(s==e)return nums[s];
            else if(mid-1>=0 && mid+1<nums.size() && nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]){
                return nums[mid];
            }
            else if((nums[mid]==nums[mid+1] && mid%2!=0) || nums[mid]!=nums[mid+1] && mid%2==0){
                e=mid-1;
            }
            else if((nums[mid]==nums[mid+1] && mid%2==0)  || nums[mid]!=nums[mid+1] && mid%2!=0){
                s=mid+1;
            }
          
        }
      return nums[s];
    }
};