*This project has been created as part of the 42 curriculum by aunoguei and ppousser.*

# PUSH SWAP

## Description

Push_swap is a sorting project that arranges a list of integers in ascending order using:

Only two stacks (A and B)

A restricted set of allowed operations

The program outputs to standard output the sequence of Push_swap operations required to sort the integers passed as arguments.

The main objective of this project is to explore:

Algorithmic time and space complexity

How algorithm choice dramatically impacts performance

The trade-off between simplicity and efficiency

A good algorithm can mean the difference between a short sequence of operations and an endless scroll of instructions.

Implementation
Team Work Distribution

ppousser

Input validation

Makefile

aunoguei

Stack initialization

Input normalization

Rules / operations implementation (ra, pb, etc.)

Joint Work

Project architecture

Program skeleton (algorithm dispatcher)

Design and implementation of sorting algorithms



Program Behavior

If no parameters are provided, the program must display nothing and return the prompt.

In case of error, the program must print:
Error
to standard error, followed by a newline.

Errors include:

Non-integer arguments

Integers outside the valid range

Duplicate values

Compilation
make
make re
make clean
make fclean


Strategy Selection

The program includes optional strategy selectors:

--simple → Forces the use of the O(n²) algorithm.

--medium → Forces the use of the O(n√n) algorithm.

--complex → Forces the use of the O(n log n) algorithm.

--adaptive → Uses the adaptive strategy based on disorder (default behavior).

If no selector is provided, the program automatically uses --adaptive.

Benchmark Mode

When the --bench flag is enabled, the program must display (to stderr, not stdout):

The computed disorder (percentage with two decimals)

The selected strategy and its theoretical complexity class

The total number of operations

The count of each operation:
sa, sb, ss
pa, pb
ra, rb, rr
rra, rrb, rrr

Benchmark output must only appear when --bench is explicitly provided.


Disorder Metric

We define disorder as the number of inversions:
disorder = (# of inversions) / (n(n − 1) / 2)
This produces a value between 0 and 1, where:
0 → Already sorted
1 → Reverse sorted

Threshold Rationale

We use the following thresholds:

Low disorder: < 0.2

Medium disorder: 0.2 ≤ disorder < 0.5

High disorder: ≥ 0.5

Why these thresholds?

When disorder < 0.2, the list is nearly sorted.
In this case, insertion-based strategies approach O(n) performance.

Between 0.2 and 0.5, disorder is moderate.
A bucket-based strategy reduces cross-stack movements.

When disorder ≥ 0.5, the list behaves similarly to a random permutation.
A radix-based strategy guarantees O(n log n) operations.

mplemented Strategies
1️⃣ Low Disorder – Insertion Strategy

Special cases:

3 numbers → Hardcoded sorting (6 possible permutations) → O(1)

5 numbers → Push smallest elements to stack B, sort remaining 3, then restore → approximately O(n)

General approach:

We iteratively move misplaced elements into their correct position using minimal rotations.

Because only a small number of elements are out of place, the total number of operations is bounded by:
O(n)


2️⃣ Medium Disorder – Bucket Strategy

If 0.2 ≤ disorder < 0.5:

Divide the normalized index range into √n buckets

Push elements from stack A to stack B bucket by bucket

Once A is empty, push elements back to A in sorted order

Each element moves between stacks at most O(√n) times.

Total complexity:
O(n√n)

3️⃣ High Disorder – Radix Sort (Binary LSD)

If disorder ≥ 0.5:

Normalize values into indices

Perform binary radix sort (Least Significant Bit first)

For each bit (≈ log n bits), process all n elements

Total complexity:
3️⃣ High Disorder – Radix Sort (Binary LSD)

If disorder ≥ 0.5:

Normalize values into indices

Perform binary radix sort (Least Significant Bit first)

For each bit (≈ log n bits), process all n elements

Total complexity:
O(n log n)
This guarantees predictable performance even for highly disordered inputs.

Data Structures

A linked list is used to represent stacks, allowing:

Efficient insertion

Efficient deletion

Constant-time stack operations

Compared to arrays, linked lists are better suited for frequent push/pop operations.








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
