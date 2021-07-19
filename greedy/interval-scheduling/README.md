| Problem                                             |         Code          |   Algorithm   |
| --------------------------------------------------- | :-------------------: | :-----------: |
| [회의실 배정](https://www.acmicpc.net/problem/1931) | [C++20](solution.cpp) | Greedy Method |

## Algorithm Design

Sort requests in order of finish time and select requests that are compatible with each other starting from the first.

## Complexity Analysis

Sorting the requests would take O(nlogn) and selecting compatible requests would take O(n). Thus, the overall time complexity would be O(nlogn).
