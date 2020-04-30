'''
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
'''

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dik= {}
        for i in strs:
            tp = ''.join(sorted(i))
            if tp not in dik:
                dik[tp] = [i]
            else:
                dik[tp].append(i)
        res = []
        for i in list(dik.values()):
            res.append(i)
        print(res)
        return res
