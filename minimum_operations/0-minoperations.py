#!/usr/bin/python3

"""
Main file for testing
"""


def minOperations(n):
    """
    Calculates the minimum number of operations to reach 'n' from 0.
    :param n: Target number
    :return: Minimum number of operations
    """
    if n == 1 or n <= 0:
        return 0

    min_op = 0
    for i in range(2, n // 2 + 1):
        if n % i == 0:
            min_op = i
            break

    count = min_op

    while n != count:
        if n % count == 0:
            min_op = count
            count += 2
        else:
            count += 1

    return count
