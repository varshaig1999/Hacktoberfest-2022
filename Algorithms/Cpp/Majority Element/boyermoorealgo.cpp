#include<bits/stdc++.h>
using namespace std;
//Intuition:
//When the elements are same as the candidate element we increment votes and decrement when
//the element is not same. We know that candidate that is majority occurs more than n/2 times
//and the remaining elements are less than n/2.

int findMajority(vector<int> &nums)
{
    //To find a candidate
    int res = 0, count = 1;
    for(int i=1; i<nums.size();i++){
        if(nums[res]==nums[i])
            count++;
        else
                count--;
        if(count==0){
            res=i;
            count=1;
        }
    }

    //To check if the candidate is actually a majority
    count = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[res]==nums[i])
            count++;
    }
    if(count<=(nums.size()/2))
        return -1;
    return nums[res];
}