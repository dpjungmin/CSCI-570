# Weighted Interval Scheduling Problem

| Problem                                                |                                 Code                                 |             Algorithm              |
| ------------------------------------------------------ | :------------------------------------------------------------------: | :--------------------------------: |
| [회의실 배정 4](https://www.acmicpc.net/problem/19623) | [C++20 top-bottom](solution-1.cpp) [C++20 bottom-up](solution-2.cpp) | Dynamic Programming, Binary Search |

## Algorithm Design

First, sort requests in order of non-decreasing finish time.

Define `P(i)` for an interval `i` to be the longest index `i` (`i` < `j`) such that inveral `i` and `j` are disjoint.

Let `O(i)` denote the optimal solution to the problem of consisting requests `{1..i}`, and let `OPT(i)` denote the value of `O(i)`.

The recurrence formula will be,

- if `i` is included -> `OPT(i) = OPT(P(i)) + w_i`
- if `i` is not included -> `OPT(i) = OPT(i - 1)`

Thus, `OPT(i) = max(OPT(i - 1), OPT(P(i)) + w_i)`.

Also, we must initialize `OPT(0) = 0`.

## Complexity Analysis

- sorting: `O(nlogn)`
- building P: `O(nlogn)` using binary search
- compute optimal solution: `O(n)

Thus, the overall time complexity is `O(nlogn)`
