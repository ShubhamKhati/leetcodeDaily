class Solution {
public:
    void merge(int low, int mid, int high, vector<int>&nums){
        int indone=low; 
        int indtwo=mid+1;
        vector<int>temp;
        while(indone<=mid && indtwo<=high){
            if(nums[indone]<=nums[indtwo]){
                temp.push_back(nums[indone++]);
            }
            else{
                temp.push_back(nums[indtwo++]);
            }
        }
        while(indone<=mid){
            temp.push_back(nums[indone++]);
        }
        while(indtwo<=high){
            temp.push_back(nums[indtwo++]);
        }
        int k=0;
        for(int i=low; i<=high; i++){
            nums[i]=temp[k++];
        }
    }
    void merge_sort(vector<int>&nums,int low,int high){
        if(low>=high)return;
        int mid=(low+high)/2;
        merge_sort(nums,low,mid);
        merge_sort(nums,mid+1,high);
        merge(low,mid,high,nums);
    }
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums,0,nums.size()-1);
        return nums;
    }
};