'''
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
'''


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        neg = 0
        ln = len(nums)
        for i in nums:
            if i < 0:
                neg += 1
        if neg == ln:
            return max(nums)
        ix = -10**9
        mx = 0
        for i in range(ln):
            mx = mx + nums[i]
            if mx > ix:
                ix = mx
            if mx < 0:
                mx = 0
        return ix
