#!/usr/bin/env python3

#cat /etc/passwd | cut -d: -f 1 | grep d$| wc -l

count = 0
for line in open('/etc/passwd'):
    data = line.split(':')[0]
    if data.endswith('d'):
        count += 1
print(count)

print(sum(1 for line in open('/etc/passwd') if line.split(':')[0].endswith('d')))