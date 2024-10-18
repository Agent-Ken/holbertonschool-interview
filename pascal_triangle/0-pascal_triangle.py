#!/usr/bin/python3
"""
Module for generating Pascal's Triangle.
"""


def pascal_triangle(n):
    """
    Generate Pascal's Triangle up to n rows.

    Args:
        n (int): The number of rows to generate

    Returns:
        list: A list of lists representing Pascal's triangle
              Returns empty list if n <= 0
    """
    if n <= 0:
        return []

    triangle = [[1]]

    for i in range(1, n):
        prev_row = triangle[-1]
        new_row = [1]

        for j in range(len(prev_row) - 1):
            new_row.append(prev_row[j] + prev_row[j + 1])

        new_row.append(1)
        triangle.append(new_row)

    return triangle
