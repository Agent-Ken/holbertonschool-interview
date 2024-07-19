#!/usr/bin/python3
"""
This module contains the count_words function that recursively queries
the Reddit API, parses the titles of hot articles, and prints a sorted
count of given keywords.
"""
import requests


def count_words(subreddit, word_list, after='', counts=None):
    """
    Recursively queries the Reddit API, parses the titles of hot articles,
    and prints a sorted count of given keywords.

    Args:
        subreddit (str): The name of the subreddit to query.
        word_list (list): A list of keywords to count in the titles.
        after (str): The 'after' parameter for pagination (default: '').
        counts (dict): A dictionary to keep track of keyword counts (default: None).
    """
    if counts is None:
        counts = {}

    headers = {'User-Agent': 'Mozilla/5.0'}
    url = f'https://www.reddit.com/r/{subreddit}/hot.json'
    params = {'after': after, 'limit': 100}

    response = requests.get(url, headers=headers, params=params, allow_redirects=False)
    
    if response.status_code != 200:
        return

    data = response.json().get('data')
    after = data.get('after')

    for post in data.get('children'):
        title = post.get('data').get('title').lower().split()
        for word in word_list:
            word_lower = word.lower()
            counts[word_lower] = counts.get(word_lower, 0) + title.count(word_lower)

    if after:
        count_words(subreddit, word_list, after, counts)
    else:
        sorted_counts = sorted(counts.items(), key=lambda kv: (-kv[1], kv[0]))
        for key, val in sorted_counts:
            if val > 0:
                print(f'{key}: {val}')
