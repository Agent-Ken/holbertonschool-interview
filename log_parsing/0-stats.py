#!/usr/bin/python3

"""
Log parsing algorithm

This script reads standard input line by line and computes metrics based on the input format:
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>

It prints the following statistics after every 10 lines or a keyboard interruption (CTRL + C):
- Total file size: File size: <total size>
- Number of lines by status code: <status code>: <number>

If the input line does not match the expected format, it is skipped.
"""

import sys
from collections import defaultdict

total_size = 0
status_counts = defaultdict(int)
line_count = 0


def print_stats():
    """Print the total file size and number of lines by status code."""
    global total_size
    print(f"File size: {total_size}")
    for status_code in sorted(status_counts.keys()):
        count = status_counts[status_code]
        if count > 0:
            print(f"{status_code}: {count}")


try:
    for line in sys.stdin:
        line_count += 1
        line_parts = line.rstrip().split(" ")

        if len(line_parts) == 9 or len(line_parts) == 7:
            try:
                ip_address = line_parts[0]
                date_time = line_parts[3].strip('[]')
                request = line_parts[5].strip('"')
                status_code = int(line_parts[-2])
                file_size = int(line_parts[-1])

                if request == "GET /projects/260 HTTP/1.1":
                    total_size += file_size
                    status_counts[status_code] += 1
            except (IndexError, ValueError):
                pass

        if line_count % 10 == 0:
            print_stats()

except KeyboardInterrupt:
    print_stats()
