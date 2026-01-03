#include <iostream>
#include <vector>
using namespace std;

vector<int> pairsum(vector<int> nums, int target)
{
    vector<int> ans;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
}

vector<int> pairSum(vector<int> nums, int target)
{
    int n = nums.size();
    vector<int> ans;
    int i = 0, j = n - 1;
    int pairsum;
    pairsum = nums[i] + nums[j];
    while (i < j)
    {
        if (pairsum < target)
        {
            i++;
        }
        else if (pairsum > target)
        {
            j--;
        }
        else
        {
            ans.push_back(i);
            ans.push_back(j);
        }
    }
    return ans;
}


int majorityel(vector<int> nums){
    int n = nums.size() ;
    sort(nums.begin() , nums.end()) ;
    int freq = 1 , ans = nums[0] ;
    for(int i=1;i<n;i++){
        if(nums[i]== nums[i-1]){
            freq++ ;

        }
        else{
            freq = 1 , ans =nums[i] ;
        }
        if(freq>n/2){
            return ans ;
        }
    }
    return ans ;
    
}


int main()
{
    vector<int> nums = {2, 1, 2, 2};
    cout<<majorityel(nums)<<endl;;

    return 0;
}
