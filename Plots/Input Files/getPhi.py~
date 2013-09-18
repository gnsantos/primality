#!/usr/bin/python
import sys, getopt

def gdc(a,b):
    if(a > b):
        aux = b
        b = a
        a = aux
    if b%a == 0:
        return a
    return gdc(b%a, a)

def phi(n):
    return len([i for i in range(1,n) if gdc(i,n) == 1]);
        
f = open(sys.argv[1], 'w')
n = int(sys.argv[2])
for i in range(1, n):
    p = phi(i)
    values = str(p)+"\n"
    f.write(values)
