/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array/#/description
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.


*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int i = 0;
        for (int j = 1; j < nums.size(); j++)
        {
            if (nums[i] != nums[j])
            {
                nums[i + 1] = nums[j];
                i++;
            }
        }
        nums.erase(nums.begin() + i + 1, nums.end());
        return nums.size();
    }
};


int main()
{
    Solution s;
    int data[3] = {1, 1, 2};
    vector<int> nums(data, data + sizeof(data) / sizeof(int));
    int ret = s.removeDuplicates(nums);
    cout<<"ret = "<<ret<<endl;
    return 0;
}


