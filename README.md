[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/hMNYkiY_)
# Implementing Longest Common Subsequence (LCS) Algorithm for Gene Sequence Analysis
[![Points badge](../../blob/badges/.github/badges/points.svg)](../../actions)

## Overview

The Longest Common Subsequence (LCS) problem is crucial in bioinformatics,
particularly for understanding genetic similarities. This project will
implement the LCS algorithm to compare gene sequences.

Skills to be developed and applied include:

+ Dynamic programming for LCS computation
+ Reconstructing a sequence from the dynamic programming table
+ File I/O for reading sequences

## Project Description

This project will implement the dynamic programming version of the LCS
algorithm for gene sequence comparison in two separate parts.

Dynamic Programming Approach
----------------------------

The DP approach breaks down a complex problem into simpler subproblems and
solves each subproblem just once, storing its solution. The algorithm
constructs a matrix where the cell at the intersection of the $i^{th}$ row
and $j^{th}$ column contains the length of the LCS between the first $i$
characters of the first sequence and the first $j$ characters of the second
sequence.

To compute the values in this matrix, the following rules are applied:

- If the characters at position $i$ in the first sequence and $j$ in the
  second sequence match, the value is 1 plus the value of the LCS up to
  positions $i-1$ and $j-1$.
- If there is no match, the value is the maximum of the two possible LCS values:
  one up to positions $i-1$ and $j$, and the other up to positions $i$
  and $j-1$.

Backtracing to Reconstruct the LCS
-----------------------------------
Once the dynamic programming matrix is filled, the LCS can be reconstructed by
backtracing from the bottom-right corner of the matrix to the top-left. This
process involves the following steps:

1. Start from the cell at the bottom-right of the matrix, which contains the
   length of the LCS. Let i be the row number and j be the column number.
2. Move to the next cell according to the following rules:

   - If the characters at the current positions in the sequences matches. The
     corresponding character is part of the LCS, and the next cell to consider
     is the diagonal one (i-1, j-1).
   - If the characters at the current positions in the sequences do not match,
     choose the cell with the maximum value out of the left $j-1$ or the above
     cell $i-1$. **If the values are the same, go up $i-1$**

3. Continue this process until the top-left cell of the matrix is reached or
   one of the sequences is exhausted (i.e., reaching the first row or column of
   the matrix).
4. The characters chosen during this process form the LCS, and they are
   collected in reverse order. Reverse the collected characters to obtain the
   LCS in correct order.

Space Optimization
------------------
The conventional dynamic programming approach to LCS uses a two-dimensional
matrix of size $m \times n$ (where $m$ and $n$ are the lengths of the two
sequences), which can be space-intensive. However, it is possible to optimize
this algorithm to use less space. Instead of maintaining the entire matrix, we
can retain just two rows (or columns) at any one time. This optimization
leverages the fact that to calculate the current row (or column), only the
previous row (or column) is necessary.

Backtracing not possible using this method!

### Part 1: LCS Computation and Reconstruction

- **Input**: Read two gene sequences from command line arguments.
- **LCS Algorithm**: Use dynamic programming to compute the LCS.
- **Output**: Display the length and the LCS.

```
./lcs ACTGATTCA ACGGATGCA
LCS: 7 ACGATCA
```

### Part 2: Gene Sequence Similarity Analysis
- **Input**: Read a file name from command line argument.
- **File**: Contains an integer count in the first line and several sequences.
- **A different LCS Algorithm**:

  - Storage space optimization: rather than the standard `(m+1) x (n+1)` table.
    Use a table with only 2 rows `2 x (n+1)` to memorize the result.
  - This version can only find the length! The backtrace will not work!

- **Similarity Table**: Output a table indicating similarity measures between
  sequence pairs.
- **Similarity Measurement**: the ratio of the LCS to the strings

  - **(H)igh**:  `min(n, m)/max(n, m) > 90%` and `LCS/min(m, n) > 90%`
  - **(M)edium** `min(n, m)/max(n, m) > 80%` and `LCS/min(m, n) > 80%`
  - **(L)ow** `min(n, m)/max(n, m) > 50%` and `LCS/min(m, n) > 50%`
  - **(D)issimilar** Everything else

- **Output**: Display the similarities of sequences processed

```
./sim seqs.txt
     1  2  3  4  5  6  7  8
 1   -  L  D  D  L  D  M  L
 2   -  -  D  D  L  D  L  H
 3   -  -  -  M  D  M  D  D
 4   -  -  -  -  D  H  D  D
 5   -  -  -  -  -  D  M  L
 6   -  -  -  -  -  -  D  D
 7   -  -  -  -  -  -  -  L
 8   -  -  -  -  -  -  -  -
```

### Documentation

Produce a `user_guide.md/docx/pdf` detailing how to compile and run the
program.

## Requirements
- **lcs driver**:
  * Read from command line arguments.
  * Find one LCS.
  * Output the LCS.

- **sim driver**:
  * Read from command line arguments.
  * Read contents from the file.
  * Find the length of LCS.
  * Output the similarity table.

- **Documentation**:
  * A user guide named `user_guide.md/docx/pdf`.

- **Modular Design**:
  * Organize the program into logical modules for readability and maintenance.
  * Classes or functions are both reasonable according to your design.

- **Makefile**:
  * Include a makefile for compiling the program in a Linux environment.
  * It should create two executable targets named `lcs` and `sim`.
  * The commands `make lcs` and `make sim` should make them respectively.

- **Compliance**:
  * Do not modify any provided files unless explicitly instructed.

## Grade Breakdown

+ [10 pts] Compilable code `make -f test.mk make-all`
+ [30 pts] Correct LCS computation `make -f test.mk test-lcs`
+ [30 pts] Correct similarity analysis and table formatting `make -f test.mk
  test-sim`
+ [10 pts] Storage optimization
+ [10 pts] Documentation quality
+ [5 pts] Submission compliance
+ [5 pts] Code quality and modularity

## Instruction for TA

+ Autograding [70 pts]
+ Manual Review [30 pts]

  * Read the LCS function for similarity search to make sure that the table for
    storage has only two rows.
  * Assess documentation for clarity and accuracy.
  * Verify code modularity and readability.
  * Ensure no provided files are altered.
