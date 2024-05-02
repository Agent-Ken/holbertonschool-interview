#!/usr/bin/python3
"""
UTF-8 Validation
"""


def validUTF8(data):
    """Validation function"""
    n_bytes = 0
    msb_1 = 1 << 7
    msb_2 = 1 << 6
    for num in data:
        bin_rep = format(num, '#010b')[-8:]
        if n_bytes == 0:
            for bit in bin_rep:
                if bit == '0':
                    break
                n_bytes += 1
            if n_bytes == 0:
                continue
            if n_bytes == 1 or n_bytes > 4:
                return False
        else:
            if not (num & msb_1 and not (num & msb_2)):
                return False
        n_bytes -= 1
    return n_bytes == 0
