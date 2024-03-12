#!/usr/bin/python3

"""
Approach: based on tracking reachable boxes using a set and
verifying that all boxes are accessible from the initial box.
"""


def canUnlockAll(boxes):
    openBoxes = set()
    for i, key in enumerate(boxes):
        for box in key:
            if box < len(boxes) and box != i:
                openBoxes.add(box)
    openBoxes.add(0)

    for index, openBox in enumerate(openBoxes):
        if index != openBox:
            return False
    return True
