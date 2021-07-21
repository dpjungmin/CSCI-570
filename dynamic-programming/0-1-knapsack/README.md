# 0-1 Knapsack Problem

| Problem                                              |         Code          |      Algorithm      |
| ---------------------------------------------------- | :-------------------: | :-----------------: |
| [평범한 배낭](https://www.acmicpc.net/problem/12865) | [C++20](solution.cpp) | Dynamic Programming |

## Algorithm Design

Let `OPT(i, w)` denote the value of the optimal solution using items `{1..i}` with the maximum capacity of `w`.

The recurrence formula is,

- if `i` is not in the knapsack -> `OPT(i, w) = OPT(i - 1, w)`
- if `i` is in the knapsack -> `OPT(i, w) = OPT(i - 1, w - w_i) + v_i`

```text
if w < w_i then
    OPT(i, w) = OPT(i - 1, w)
else
    OPT(i, w) = max(OPT(i - 1, w), OPT(i - 1, w - w_i) + v_i)
```

For the initialization step, we must set `OPT(0, w) = 0` for each `w` from `0` to the capacity of the knapsack.

> If we only need the optimal value, we could reduce the two-dimensional array into a one-dimensional array, which would reduce a great amount of memory usage.

## Complexity Analysis

For `n` items, we check every `w`. Thus, the overall time complexity is `O(nw)`. Since the the running time is a polynomial by a numeric value of the input, this algorithm runs in **pseudo-polynomial** time.
