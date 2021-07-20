# Stock Market Problem

| Problem                                                                                           |         Code          |     Algorithm      |
| ------------------------------------------------------------------------------------------------- | :-------------------: | :----------------: |
| [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | [C++20](solution.cpp) | Divide and Conquer |

## Algorithm Design

We divide the problem into two subproblem until it reaches into a subproblem of size one. From each subproblem, we return its minimum and maximum values. At our combine step, we calculate (right maximum - left minimum) and keep track of the maximum value.

Also, this problem can be solved without using a divide-and-conquer method.

## Complexity Analysis

Each divide, conquer, and combine step takes constant time. We divide each problem into two subproblems. Thus, T(n) = 2T(n/2) + O(1). If we use the Master Method, we get T(n) = O(n).
