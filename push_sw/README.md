*This project has been created as part of the 42 curriculum by aunoguei and ppousser.*

# PUSH SWAP

## Description

The Push swap project sorted in ascending order a set of integer values, using only  2 stacks and a set of operations to manipulate both stacks

The algorithm calculates and displays on the standard output the "Push swap language operations", that sorts the integers received as arguments.

The goal of this project is to discover algorithmic complexity (time and space), and understand that the choice of algorithm can make the difference between a quick win and an endless scroll of operations.

Implementation :

division trabajo
ppousser -> input validation + Makefile
aunoguei -> stack init + normalization input + rules/operations (ra, pb etc)

trabajo juntos :
arquitectura del proyecto, esqueltero del programa que llama a los algoritmos y creacion de los algoritmos de ordenation.


if no parameters are specified, the program must not display anything and give the
prompt back.

## Instructions

Make
Make re
Make clean
Make fclean

An optional strategy selector:
--simple Forces the use of your O(n2) algorithm.
--medium Forces the use of your O(n√n) algorithm.
--complex Forces the use of your O(n log n) algorithm.
--adaptive Forces the use of your adaptive algorithm based on disorder.
This is the default behavior if no selector is given

The optional benchmark mode (--bench) must display, after sorting:
◦ The computed disorder (% with two decimals).
◦ The name of the strategy used and its theoretical complexity class.
◦ The total number of operations.
◦ The count of each operation type (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb,
rrr).
The benchmark output must be sent to stderr and only appear when the flag is
present.

if no parameters are specified, the program must not display anything and give the
prompt back.

In case of error, it must display "Error" followed by a \n on the standard error.
Errors include, for example: arguments that are not integers, integers outside the
valid range, or duplicate values.

## Resources
https://www.bigocheatsheet.com/
https://www.w3schools.com/dsa/dsa_algo_insertionsort.php
https://www.geeksforgeeks.org/dsa/radix-sort/
https://www.geeksforgeeks.org/dsa/implement-quicksort-with-first-element-as-pivot/
linked list allows efficient insertion and deletion operations compared to arrays.

## Explanation and justification of the algorithms

**Insertion Sort:**
Insertion sort is used in situations when the list is nearly sorted. if disorder < 0.2 el número de inversiones es O(n).

**Bucket sort**

**Radix Sort LSD (Least Significant Digit)**

**Custom adaptive algorithm**

Disorder Metric

We define disorder as the number of inversions:
disorder = (# of inversions) / (n(n−1)/2)
This value is between 0 and 1, where:
- 0 means already sorted
- 1 means reverse sorted

Threshold Rationale

We use the following thresholds:
Low disorder: < 0.2
Medium disorder: 0.2 ≤ disorder < 0.5
High disorder: ≥ 0.5

When disorder < 0.2, the array is nearly sorted. An insertion-sort strategy performs close to linear time because only a small fraction of elements are misplaced.

Between 0.2 and 0.5, disorder is moderate, so we use a bucket-sort strategy to limit cross-stack movements.

When disorder ≥ 0.5, the list behaves like a random permutation, so we use a radix-based algorithm to guarantee O(n log n) operations.

IMPLEMENTATION

**Low Disorder** – Insertion Strategy

if disorder < 0.2 && nums == 3
sort_three(hardcodeado les 6 possibilites) complexity O(1)?
if nums == 5 () pasamos a b index 0 y despues index 1 y llamamos a sort_three. complex O(n)?

We iteratively place misplaced elements into their correct position using minimal rotations.
Because the number of misplaced elements is small, the total number of operations is bounded by O(n).

**Medium Disorder** – Bucket sort Strategy
We divide the index range into √n buckets and push elements to stack B bucket per bucket
 if 0.2 ≤ disorder < 0.5, bucket sort adaptations with √n buckets
push to B by blocks and when A is empty, push each elements in his correct position
Each element may move between stacks at most O(√n) times.
Total operations: O(n√n).

**High Disorder** – Radix Sort on Indices
We normalize values to indices and perform a binary radix sort.
For each bit (log n bits), we process all n elements.
Total operations: O(n log n).
