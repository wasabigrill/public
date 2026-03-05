# -*- coding: utf-8 -*-
"""
Created on Wed Dec  4 19:15:47 2024

@author: zzhang
"""

import os 
os.chdir("C:/adventofcode2024")

file = open("day4_test.txt").read().split("\n")


def is_xmas(idx,idy,lst):
    count = 0
    char = lst[idx][idy]
    if char == "X":
        x = 0
    if char == "M":
        x = 1
    if char == "A":
        x = 2
    if char == "S":
        x = 3
        
    if idy + 3-x  < len(lst[idx]) and idy - x >= 0 and lst[idx][idy-x:idy+4-x] == "XMAS":
        count += 1
    if idy - (3-x) >= 0 and idy + x  < len(lst[idx]) and lst[idx][idy-3+x:idy+x+1] == "SAMX":
        count += 1
        
    if idy+3-x < len(lst[idx]) and idx+3-x < len(lst):
        string = "".join(lst[idx-x][idy-x] + lst[idx-x+1][idy-x+1] + lst[idx-x+2][idy-x+2] + lst[idx-x+3][idy-x+3])
        if string == "XMAS":
            count +=1
    if idy + 3 - x < len(lst[idx]) and idx+x <len(lst) and idx-3+x >=0 and idy-x >=0:
        string = "".join(lst[idx-3+x][idy-x] + lst[idx-2+x][idy-x+1] + lst[idx-1+x][idy-x+2]+ lst[idx+x][idy-x+3])
        if string == "XMAS":
            count += 1
    
    if idy -(3- x) >= 0 and idx -(3-x) >=0 and idy + x < len(lst[idx]) and idx + x < len(lst) : 
        string = "".join(lst[idx-3+x][idy-3+x] + lst[idx-2+x][idy-2+x] + lst[idx-1+x][idy-1+x] + lst[idx+x][idy+x])
        if string == "SAMX":
            count += 1
    if idx -x >= 0 and idy-x+3 >=0 and idx-x+3 < len(lst) and idy+x < len(lst[idx]):
        string = "".join(lst[idx-x][idy-3+x]+lst[idx-x+1][idy-2+x]+lst[idx-x+2][idy-1+x]+lst[idx-x+3][idy+x])
        if string == "SAMX":
            count += 1
    if idx + 3 - x < len(lst) and idx -x >=0 :
        string = "".join(lst[idx-x][idy]+lst[idx-x+1][idy]+lst[idx-x+2][idy]+lst[idx-x+3][idy])
        if string == "XMAS":
            count += 1
    if idx-3+x >= 0 and idx + x < len(lst):
        string = "".join(lst[idx-3+x][idy] + lst[idx-2+x][idy] + lst[idx-1+x][idy]+ lst[idx+x][idy])
        if string == "SAMX":
            count += 1
    return count 

count = 0
mat = [[0 for _ in range(len(file[0]))] for _ in range(len(file))]

for i, line in enumerate(file):
    for j in range(0,len(line)):
        count += is_xmas(i,j,file)
        mat[i][j] = is_xmas(i,j,file)
print(count/4)

#%%
for i, line in enumerate(file):
    if "XMAS" in line: 
        count += 1
        remain_line=line[line.index("XMAS"):]
        while "XMAS" in remain_line:
            remain_line = remain_line[remain_line.index("XMAS"):]   
            count += 1
    if "SAMX" in line: 
        count += 1
        remain_line=line[line.index("SAMX"):]
        while "SAMX" in remain_line:
            remain_line = remain_line[remain_line.index("SAMX"):]   
            count += 1
    