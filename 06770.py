import sys
import collections


n = int(sys.stdin.readline())
readings = []
for _ in range(n):
    reading = int(sys.stdin.readline())
    readings.append(reading)
tally = collections.Counter(readings)
frequencies = {}
for key, val in tally.items():
    if val in frequencies:
        frequencies[val].append(key)
    else:
        frequencies[val] = [key]
sorted_frequencies = sorted(frequencies.items(), key=lambda x: x[0], reverse=True)
if len(sorted_frequencies[0][1]) > 1:
    print(max(sorted_frequencies[0][1]) - min(sorted_frequencies[0][1]))
else:
    print(max(sorted_frequencies[0][1][0] - min(sorted_frequencies[1][1]),
              max(sorted_frequencies[1][1]) - sorted_frequencies[0][1][0]))
