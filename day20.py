# -*- coding: utf-8 -*-
"""
Created on Fri Dec 20 09:25:28 2024

@author: zzhang
"""

import os 
os.chdir("C:/adventofcode2024")

maps = open("day20.txt").read().split("\n")

for i, line in enumerate(maps):
    for j, char in enumerate(line):
        if char == "S":
            r0 = i; c0 = j
        if char == "E":
            re = i; ce =j
            
direct = [(-1,0),(1,0),(0,1),(0,-1)]

r = r0
c = c0
seen = []
while (r,c)  != (re,ce):
    seen.append([r,c])
    for dr, dc in direct: 
        if maps[r+dr][c+dc] in "E." and [r+dr,c+dc] not in seen:
            r += dr; c+=dc
            break
seen.append([re,ce])
        
direct1 = [(-2,0),(2,0),(0,2),(0,-2)]

count=0
for idx0, [r,c] in enumerate(seen):
    for dr,dc in direct1:
        if [r+dr,c+dc] in seen[idx0:]:
            idx1 = seen.index([r+dr,c+dc])
            if idx1-idx0-2 >= 100 :
                count+=1
#%% part2 
