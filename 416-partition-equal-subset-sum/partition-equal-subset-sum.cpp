class Solution {
public:
   
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        long b=sum(nums); 
        if(b%2 !=0){
            return false;
        }
        else{
            return subsetsum(nums,b/2);
        }
      }

     int sum(vector<int>& nums){
        int k=0;
        for(int i=0;i<nums.size();i++){
            k=k+nums[i];
        }
        return k;
    }

    bool subsetsum(vector<int>& nums,int s){
       int n=nums.size();
       bool dp[n+1][s+1];
       for(int i=0;i<=n;i++){
        for(int j=0;j<=s;j++){
            if(j==0){
                dp[i][j]=true;
            }
            else if(i==0){
                dp[i][j]=false;
            }
        }
       }

       for(int i=1;i<=n;i++){
        for(int j=1;j<=s;j++){
            if(nums[i-1]<=j){
                dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
            }
            else if(nums[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
        }
       }
       return dp[n][s];
    }
};