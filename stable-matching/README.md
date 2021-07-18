# [Stable Marriage Problem](stable-marriage-problem.pdf)

| Problem                                                             |         Code          |       Algorithm        |
| ------------------------------------------------------------------- | :-------------------: | :--------------------: |
| [The Stable Marriage Problem](https://www.acmicpc.net/problem/3761) | [C++20](solution.cpp) | Gale-Shapley Algorithm |

## Algorithm Design

We will use the [Gale-Shapely Algorithm](https://en.wikipedia.org/wiki/Gale%E2%80%93Shapley_algorithm) to solve this problem.

```text
Initialize all men and women as free
While there is a men m who is free and hasn't proposed to every women
    w = the highest-ranked woman in m's preference list to whom m has not yet proposed
    If w is free then
        (m, w) become engaged
    Else w is currently engaged to m'
        If W preferes m' to m then
            m remains free
        Else w preferes m to m'
            (m, w) become engaged
            m' becomes free
        Endif
    Enfif
Endwhile
Return the set S of engaged pairs
```

> The side that does the proposing ends up with the "best possible partner" (from their perspective), while the side that receives a proposal correspondingly ends up with the "worst possible partner."

## Complexity Analysis

1. Indentify a free man: O(1)
2. For a man m, identify the highest ranked woman to whom he has not yet proposed: O(1)
3. For a woman w, decide if w is engaged, and if so to whom: O(1)
4. For a woman w and two man m and m', decide which man is prefered by w: O(1)
5. Place a man back in the list of free man: O(1)

Thus, the algorithm terminates after at most n^2 iterations of the While loop.
