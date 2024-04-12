#!/usr/bin/python3
import sys
import re
import signal

log_pattern = re.compile(
    r'(?P<ip>\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}) - \[(?P<date>.+?)\] '
    r'"GET /projects/260 HTTP/1\.1" (?P<status>\d{3}) (?P<size>\d+)'
)

total_size = 0
status_codes = {str(code): 0 for code in [200, 301, 400, 401, 403, 404, 405, 500]}

def print_stats(signum, frame):
    print(f"File size: {total_size}")
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print(f"{code}: {status_codes[code]}")
    if signum is not None:
        sys.exit()

signal.signal(signal.SIGINT, print_stats)

line_count = 0
try:
    for line in sys.stdin:
        match = log_pattern.match(line)
        if match:
            data = match.groupdict()
            total_size += int(data['size'])
            if data['status'] in status_codes:
                status_codes[data['status']] += 1
        line_count += 1
        if line_count % 10 == 0:
            print_stats(None, None)
except KeyboardInterrupt:
    pass
finally:
    print_stats(None, None)
