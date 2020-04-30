=begin
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: [5,7]
Output: 4
Example 2:

Input: [0,1]
Output: 0
=end

# @param {Integer} m
# @param {Integer} n
# @return {Integer}
def range_bitwise_and(m, n)
    if m == n
        return m
    end
    delta = n - m+1
    res = 0
    bits = Integer(Math.log(n, 2)) + 1
    (0...bits).each do |i|
        mask = 1<<i
        if delta <= mask
            if (m & mask) != 0 and (n & mask) != 0
                res |= mask
            end
        end
    end
    return res
end
