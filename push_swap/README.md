*This project has been created as part of the 42 curriculum by `<glicciar>`.*

# push_swap

> Sorting a stack of integers with a limited set of operations, using as few moves as possible.

## Description

push_swap takes a list of integers and prints the shortest sequence it can find of stack operations that sorts them. There are two stacks, `a` (filled with the numbers) and `b` (empty). The goal is to explore sorting algorithms and complexity, and to choose the best approach for each input size.

**Allowed operations**

| Operation | Effect |
|---|---|
| `sa` `sb` `ss` | swap the top two elements of a, b, or both |
| `pa` `pb` | push the top of one stack onto the other |
| `ra` `rb` `rr` | rotate a stack up (first element becomes last) |
| `rra` `rrb` `rrr` | reverse rotate a stack (last element becomes first) |


Bonus (checker program): not implemented.

## Instructions

**Requirements:** `cc` and `make`.

```bash
make
./push_swap 2 1 3 6 5 8
```
It prints one operation per line. Invalid input (non-integers, duplicates, values out of range) prints `Error`.

## Resources
- Articles on sorting algorithms and their complexity
- Visualisers for push_swap operations

**Use of AI**
- Code assistence and debugging