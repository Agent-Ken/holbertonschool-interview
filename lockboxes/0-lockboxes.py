#!/usr/bin/python3

''' Documentation part:
The main function determines if all the boxes can be opened.
`boxes (List[List[int]]):` - list of lists where each inner list represents a box and contains keys to other boxes.
Returns either true or false depending on whether all the boxes can be opened or not
The first box is unlocked by default.

"Depth-first search (DFS) is an algorithm for traversing or searching tree or graph data structures". It is better than "breadth-first search".
We use it to explore reachable boxes. In it the `box_index (int)` is the index of the current box. At all we check if all boxes were visited or not.
'''

def canUnlockAll(boxes):
    box_amount = len(boxes)
    visited = [False] * box_amount
    visited[0] = True  

    def depth_first_search(box_index):
        for key in boxes[box_index]:
            if not visited[key]:
                visited[key] = True
                depth_first_search(key)

    depth_first_search(0)
    return all(visited)
