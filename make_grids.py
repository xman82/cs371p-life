#!/usr/bin/env python
from random import *
sparseness = 12
fredkinness = 10


def random_conway_cell():
    if (randint(0,sparseness)==1):
        return '*'
    else:
        return '.'

def random_fredkin_cell():
    age = randint(0,9)
    if (randint(0,sparseness) == 1):
        return age
    else:
        return '-'

def random_hetero_cell():
    if (randint(0,100) >= fredkinness):
        return random_conway_cell()
    else:
        return random_fredkin_cell()

funs = [ random_fredkin_cell,
        random_conway_cell,
        random_hetero_cell ]

for grid_num in range(4):
    r = randint(0,100)
    c = randint(0,150)
    print r
    print c
    for i in range(r):
        for j in range(c):
            print random_hetero_cell(),
        print '\n',
    print '\n',
