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
    lngth = 0
    min_op = 0
    for i in range(2, n//2+2):
        if n % i == 0:
            min_op = i
            break

    count = min_op
    lngth = min_op

    while n != lngth:
        if n % lngth == 0:
            min_op = lngth
            lngth += min_op

            count += 2

        else:
            count += 1
            lngth += min_op

    return count
