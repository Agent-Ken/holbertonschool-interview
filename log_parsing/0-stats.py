#!/usr/bin/python3


"""Input stats"""


import sys
import re


logs = 0
total_size = 0
status_codes = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
}


def print_statistics(statuses, total):
    print("File size: {}".format(total))
    for key, value in sorted(statuses.items()):
        if value != 0:
            print("{}: {}".format(key, value))


try:
    for line in sys.stdin:
        new_line = line.rstrip().split(" ")
        if len(new_line) == 9 or len(new_line) == 7:
            try:
                logs += 1
                total_size += int(new_line[-1])
                status_codes[new_line[-2]] += 1
                if logs % 10 == 0 and logs != 0:
                    print_statistics(status_codes, total_size)
            except BaseException:
                pass
finally:
    print_statistics(status_codes, total_size)
