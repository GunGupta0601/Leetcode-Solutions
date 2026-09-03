class Solution {
    bool isPossible(vector<int>& nums, int mid, int k){
        int sum=0, count=1;
        for(int i=0; i<nums.size();){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
                i++;
            }
            else{
                count++;
                sum=0;
            }
            if(count>k){
                return false;
            }
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int max=INT_MIN, sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if(nums[i]>max){
                max=nums[i];
            }
        }
        int s=max, e=sum, ans;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isPossible(nums, mid, k)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }

        }
        return ans;
    }
};