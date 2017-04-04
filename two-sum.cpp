/*
https://leetcode.com/problems/two-sum/
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/

/*
10 / 10 test cases passed.
Status: Accepted
Runtime: 3 ms
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        typedef map<int, int> NumMap;
        NumMap numMap;
        vector<int> result;

        for (vector<int>::const_iterator itor = nums.begin(); itor != nums.end(); itor++)
        {
            int count = numMap.find(*itor) == numMap.end() ? 0 : numMap.at(*itor);
            numMap[*itor] = ++count;
        }

        int num1, num2;
        bool found = false;
        for (int i = 0; i < nums.size(); i++)
        {
            num1 = nums[i];
            num2 = target - num1;

            bool found1 = numMap.find(num1) != numMap.end() && numMap.at(num1) > (num1 == num2 ? 1 : 0);
            bool found2 = numMap.find(num2) != numMap.end() && numMap.at(num2) > (num1 == num2 ? 1 : 0);
            if (found1 && found2)
            {
                int next = num1, total = 0;
                for (int j = 0; j < nums.size(); j++)
                {
                    if (nums[j] == next)
                    {
                        result.push_back(j);
                        total++;
                        if (total == 1)
                            next = num2;
                        else
                            break;
                    }
                }
                break;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    int n[2] = {3,3};
    vector<int> nums(n, n + 2);
    int target = 6;
    vector<int> ret = s.twoSum(nums, target);
    cout<<ret[0]<<" "<<ret[1]<<endl;
    return 0;
}