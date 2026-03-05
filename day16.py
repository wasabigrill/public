# -*- coding: utf-8 -*-
"""
Created on Mon Dec 16 10:56:08 2024

@author: zzhang
"""

import os 
import heapq
os.chdir("C:/adventofcode2024")

file= open("day16_test1.txt").read().split("\n")


for i, line in enumerate(file):
    if "S" in line:
        r0 = i
        c0 = line.index("S")
    if "E" in line:
        re = i
        ce = line.index("E")


direct = {"r":[0,1],"d":[1,0],"l":[0,-1],"u":[-1,0]}

def get_score(r0,c0,re,ce,move,file):
    r= r0
    c=c0
    direct = {0:[0,1],1:[1,0],2:[0,-1],3:[-1,0]}
    
    dr, dc = direct[move]
    
    if r == re and c == ce:
        return score
    
    # going forward
    if file[r+dr][c+dc] != "#":
        score += 1
        return get_score(r+dr,c+dc,re,ce,move,file)
    # rotating
    else:
    
    #%%
q =[]
heapq.heappush(q, (0, [r0,c0,0, 0]))
direct = {0:[0,1],1:[1,0],2:[0,-1],3:[-1,0]}

r=0;c=0
while r!= re and c!= ce:
    (priority, [r,c,score,direction]) = heapq.heappop(q)
    dr,dc = direct[direction]
    if file[r+dr][c+dc] != "#":
        heapq.heappush(q, (score+1, [r,c,score+1, direction]))
    heapq.heappush(q, (score+1000, [r,c,score+1000, (direction-1)%4]) )
    heapq.heappush(q, (score+1000, [r,c,score+1000, (direction+1)%4]) )

