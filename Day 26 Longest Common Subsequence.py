'''
Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.



If there is no common subsequence, return 0.



Example 1:

Input: text1 = "abcde", text2 = "ace"
Output: 3
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.


Constraints:

1 <= text1.length <= 1000
1 <= text2.length <= 1000
The input strings consist of lowercase English characters only.
'''

class Solution:
    def longestCommonSubsequence(self, t1: str, t2: str) -> int:
        dik = [-1]*(len(t1)+1)
        ln = len(t2)+1
        for i in range(len(t1)+1):
            dik[i] = [-1]*ln
        print(dik)

        def helper(s1, s2, a, b):
            if a == 0 or b == 0:
                return 0

            if dik[a][b] != -1:
                return dik[a][b]

            if s1[0] == s2[0]:
                temp = 1 + helper(s1[1:], s2[1:], a-1, b-1)
                dik[a][b] = temp
                return temp

            xx = helper(s1[1:], s2, a-1, b)
            yy = helper(s1, s2[1:], a, b-1)

            dik[a][b] = max(xx, yy)

            return max(xx, yy)
        helper(t1, t2, len(t1), len(t2))
        return dik[-1][-1]
