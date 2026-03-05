# -*- coding: utf-8 -*-
"""
Created on Tue Dec 10 09:28:32 2024

@author: zzhang
"""

import os 
os.chdir("C:/adventofcode2024")

file = open("day10.txt").read().split("\n")

loc=[]
for i, line in enumerate(file):
    for j, char in enumerate(line):
        if char == "0":
            loc.append([i,j])
            
        #%% part 1
direct=[[-1,0],[1,0],[0,1],[0,-1]]
count = 0
for item in loc:
    loc1 = [item]
    memo=[]
    while loc1!= []:
        r,c = loc1.pop() 
        if file[r][c] == "9" and [r,c] not in memo:
            memo.append([r,c])   
        for dr,dc in direct:
            if r+dr in range(len(file)) and c+dc in range(len(file[0])):
                if int(file[r][c]) == int(file[r+dr][c+dc]) - 1:
                    loc1.append([r+dr,c+dc])    
    count += len(memo)               
             #%% part2
count = 0
while loc!= []:
    r,c = loc.pop() 
    if file[r][c] == "9" and [r,c]:
        count += 1  
    for dr,dc in direct:
        if r+dr in range(len(file)) and c+dc in range(len(file[0])):
            if int(file[r][c]) == int(file[r+dr][c+dc]) - 1:
                loc.append([r+dr,c+dc])    

