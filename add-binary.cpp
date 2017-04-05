/*
https://leetcode.com/problems/add-binary/#/description
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".


*/

/*
294 / 294 test cases passed.
Status: Accepted
Runtime: 6 ms
*/

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string s1, s2, result;
        int len1 = a.length(), len2 = b.length();
        s1 = (len1 < len2) ? b : a;
        s2 = (len1 < len2) ? a : b;
        len1 = s1.length(), len2 = s2.length();

        result.reserve(s1.length() + 2);

        int carry = 0;
        for (int i = 1; i <= len2; i++)
        {
            int tmp = (s1[len1 - i] - '0') + (s2[len2 - i] - '0') + carry;
            result = ((tmp % 2 == 0) ? '0' : '1') + result;
            carry = (tmp / 2 == 0) ? 0 : 1;
        }

        for (int i = len2 + 1; i <= len1; i++)
        {
            int tmp = (s1[len1 - i] - '0') + carry;
            result = ((tmp % 2 == 0) ? '0' : '1') + result;
            carry = (tmp / 2 == 0) ? 0 : 1;
        }
        if (carry == 1)
            result = '1' + result;

        return result;
    }
};

int main()
{
    Solution s;
    string a = "100", b = "110010";
    string ret = s.addBinary(a, b);
    cout<<"result: "<<ret<<endl;
    return 0;
}