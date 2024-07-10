#!/usr/bin/env python3

comics = {
    "marvel": ["spider-man", "deadpool", "wolverine"],
    "dc"    : ["batman boy", "superman", "iron-man"]
}


primary =  sorted(str.join(',', comics['marvel']))
print(primary)