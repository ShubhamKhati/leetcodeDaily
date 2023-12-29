class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s=0; int e=nums.size()-1;
        int firstindex=-1; int secondindex=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]>=target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            if(nums[mid]==target)firstindex=mid;
        }
        s=0; e=nums.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]<=target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            if(nums[mid]==target){
                secondindex=mid;
            }
        }
        if(firstindex!=-1 && secondindex!=-1) return {firstindex,secondindex};
        return {-1,-1};
    }
};