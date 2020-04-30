'''
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?
'''

class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        a = []
        b = []
        la = 0
        lb = 0
        for i in s:
            if la > 0 and i == '#':
                del a[-1]
                la-=1
            elif la == 0 and i == '#':
                continue
            elif i != '#':
                a.append(i)
                la += 1
        for i in t:
            if lb > 0 and i == '#':
                del b[-1]
                lb-=1
            elif lb == 0 and i == '#':
                continue
            elif i != '#':
                b.append(i)
                lb += 1
        print(a, b)
        return a == b
