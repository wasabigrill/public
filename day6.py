# -*- coding: utf-8 -*-
"""
Created on Fri Dec  6 09:40:04 2024

@author: zzhang
"""

import os 
os.chdir("C:/adventofcode2024")

file = open("day6.txt").read().split("\n")

for r, line in enumerate(file):
    if "^" in line: 
        c0 = line.index("^")
        r0 = r

dic = {0:(-1,0),1:(0,1),2:(1,0),3:(0,-1)}

count = 0
r=r0
c=c0
route=[]
dc=0
dr=0
while r in range(0, len(file)) and c in range(0,len(file[0])): 
    if file[r][c] == "#":
        count += 1
        r = r-dr
        c = c-dc
    if [r,c] not in route:
        route.append([r,c])
    count = count%4
    dr, dc = dic[count] 
    r += dr
    c += dc

    
    