# push_swap | 42KL

## Introduction

Push_swap is a 42 project that involves sorting a list of integers using 2 stacks(can be any data structures ie. array / linked list in C) using the least possible operations (or moves). This projects introduces the concept of Big O notation in computational algorithm efficiency. In this case, it is the time complexity which is how many operations (or moves) it will take to sort the integers as a function of its input size. 

## Operations allowed

| Code  | Instruction                         | Action                                                 |
| ----- | ----------------------------------- | ------------------------------------------------------ |
| `sa`  | swap a                              | swaps the 2 top elements of stack a                    |
| `sb`  | swap b                              | swaps the 2 top elements of stack b                    |
| `ss`  | swap a + swap b                     | both `sa` and `sb`                                     |
| `pa`  | push a                              | moves the top element of stack b at the top of stack a |
| `pb`  | push b                              | moves the top element of stack a at the top of stack b |
| `ra`  | rotate a                            | shifts all elements of stack a from bottom to top      |
| `rb`  | rotate b                            | shifts all elements of stack b from bottom to top      |
| `rr`  | rotate a + rotate b                 | both `ra` and `rb`                                     |
| `rra` | reverse rotate a                    | shifts all elements of stack a from top to bottom      |
| `rrb` | reverse rotate b                    | shifts all elements of stack b from top to bottom      |
| `rrr` | reverse rotate a + reverse rotate b | both `rra` and `rrb`                                   |

See [Subject.pdf](https://github.com/mseong123/push_swap/blob/8458567d1fc504117fc06f64fe64f30c6b35ed86/en.subject.pdf) for full project instructions.

## Algorithm used

Typical in-place sorting algorithms such as bubble sort, insertion sort and selection sorts can't be used directly in this exercise due to the limitations imposed which is 1) using 2 stacks 2) operations allowed above. Also project imposes limits on maximum operations that can be performed given certain input sizes:

- 3 number : no more than 3 operations
- 5 number : no more than 12 actions
- 100 number : no more than 700 actions
- 500 number : no more than 5,500 actions

Hence I used a 'count all sorts' algorithm which aims to iterate through stack a and for each number in stack a, I calculate beforehand the number of moves to move it across to stack b (so that the number is sorted in stack b). My algorithm will then execute the moves for the number with the least required number of operation. Once all the numbers are moved to stack b (it's already sorted), my algorithm will move it back to stack a which is the requirement of this exercise.

## Example Sorting Visualisation for 100 numbers

![push_swap.gif](https://github.com/mseong123/push_swap/blob/5355e751f5c77db8662e59306913330655c91a01/push_swap.gif)

## Status

Validated 14/6/2023. Grade: 125%. Project duration: 2 weeks.

## Clone and Compile

```
git clone https://github.com/mseong123/push_swap.git
cd push_swap
make
```

## Run

```
./push_swap <numbers to sort>
```

Example:

```
./push_swap 23 5 8 -2 1 28
```

Result (operations needed to sort stack a):
```
pb
pb
pb
rrb
pb
pb
rb
rb
pb
pa
pa
pa
pa
pa
pa
```

Feel free to test with however many numbers you want.

## Resources

To generate random numbers:
[Random number generator](https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php)

Visualizer:
[Codepen](https://codepen.io/ahkoh/full/bGWxmVz)



