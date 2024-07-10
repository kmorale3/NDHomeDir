#!/usr/bin/env python3

#cat /etc/passwd | cut -d : -f 4 | sort | uniq -c | sort -rns | head -n 1 | awk '{print $2}'

results = {}
for line in open('/etc/passwd'):
    data = line.split(':')[3]
    results[data] = results.get(data, 0) + 1 

results = sorted(results.items(), key = lambda r: r)
print(results[0][0])