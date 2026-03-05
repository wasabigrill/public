# -*- coding: utf-8 -*-
"""
Created on Sat Dec 14 09:18:51 2024

@author: zzhang
"""


import os 
os.chdir("C:/adventofcode2024")

file= open("day14.txt").read().split("\n")

loc = [line.split(" ")[0] for line in file]
loc = [ item.split("=")[1] for item in loc]

speed = [line.split(" ")[1] for line in file]
speed = [item.split("=")[1] for item in speed]



m = 103
n = 101
t = 100 
mat = [[0 for _ in range(n)] for _ in range(m)]

for i in range(len(loc)):
    x, y = loc[i].split(",")
    vx, vy = speed[i].split(",")
    new_x = (int(x) + int(vx)*t)%n
    new_y = (int(y) + int(vy)*t)%m
    mat[new_y][new_x] += 1

a=0;b=0;c=0;d=0;   
for i, line in enumerate(mat):
    for j, item in enumerate(line):
        if i < m//2 and j < n//2 :
            a += item
        if i < m//2 and j > n//2 :
            b += item
        if i > m//2 and j < n//2 :
            c += item
        if i > m//2 and j > n//2 :
            d += item

total = a*b*c*d
print(total)