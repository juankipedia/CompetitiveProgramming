# Create Contest script.
# call this script like:
#   python3 create_contest.py <template path> <destination directory> <number of problems>
#
# Example:
#   python3 create_contest.py ./template.cpp ~/Desktop/exercises 7

import sys
import os.path
from string import ascii_uppercase

if len(sys.argv) != 4:
    raise Exception("Wrong number of arguments")

n = int(sys.argv[3])

if n > 26:
    raise Exception("Number of problems cannot be greater than 26")
elif n <= 0:
    raise Exception("Number of problems has to be greater than 1")

if not os.path.isfile(sys.argv[1]):
    raise Exception("Template not found")

if not os.path.isdir(sys.argv[2]):
    raise Exception("Destination directory not found")

template_file = open(sys.argv[1], "r")
template = template_file.read()

destination = ""
if sys.argv[2][-1] == '/':
    destination = sys.argv[2]
else:
    destination = sys.argv[2] + '/'

for c in ascii_uppercase:
    f = open(destination + c + '.cpp', 'w')
    f.write(template)
    n -= 1
    if n == 0:
        break
