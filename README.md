# Goldbach's Conjecture Implementation

A C program implementing Goldbach's Conjecture, which states that every even integer greater than 2 can be expressed as the sum of two prime numbers.

## Table of Contents

* [Overview](#overview)
* [Features](#features)
* [Installation](#installation)
* [Usage](#usage)
* [Implementation Details](#implementation-details)
* [Example Output](#example-output)

## Overview

This implementation provides a practical demonstration of Goldbach's Conjecture, allowing users to verify the conjecture for any even number greater than 2. The program uses efficient prime number checking algorithms to find pairs of primes that sum to the target even number.

## Features

* Efficient prime number verification using trial division
* Multiple prime pair finding for larger numbers
* Clear console output showing the decomposition
* Error handling for invalid inputs
* Optimized performance for reasonable input ranges

## Installation

To compile and run the program locally:

```bash
gcc main.c -o goldbach
./goldbach <even_number>
```

Replace `<even_number>` with any even number greater than 2.

## Usage

The program takes a single argument - an even number. For example:

```bash
./goldbach 100
```

This will output all prime number pairs that sum to 100.

## Implementation Details

The program consists of two main functions:

1. `is_prime(n)` - Checks if a number is prime using trial division
2. `find_goldbach_pairs(n)` - Finds all prime pairs that sum to n

The algorithm uses an iterative approach to check potential prime pairs, ensuring efficiency for reasonable input values.
