#!/usr/bin/env python3

import collections

Person = collections.namedtuple(
    'Person',
    'first_name last_name'
)

People = [
    Person('Peter', 'Bui'),
    Person('Joshua', 'Cepeda'),
    Person('Tanner', 'Waltz'),
    Person('Nicole', 'Lee'),
    Person('Caleb', 'Bui')
]

SortedPeople = sorted(People, key=lambda p: (p.last_name, p.first_name))

for person in SortedPeople:
    print(person.last_name, person.first_name)