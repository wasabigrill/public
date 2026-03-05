# -*- coding: utf-8 -*-
"""
Created on Sun Dec  8 10:24:11 2024

@author: zzhang
"""


import os 
os.chdir("C:/adventofcode2024")

file = open("day8.txt").read().split("\n")


node = {}

for i, line in enumerate(file): 
    for j, item in enumerate(line): 
        if item != ".":
            if item not in node:
                node[item] = [[i,j]]
            else:
                node[item].append([i,j])

antinode=[]
for key in node:
    for i, item1 in enumerate(node[key][:len(node[key])-1]):
        for item2 in node[key][i+1:]:
            r1 = min(item1[0],item2[0]) - abs( item1[0] - item2[0])
            r2 = max(item1[0],item2[0]) + abs( item1[0] - item2[0])
            c1 = min(item1[1],item2[1]) - abs( item1[1] - item2[1])
            c2 = max(item1[1],item2[1]) + abs( item1[1] - item2[1])
            if (item1[0]-item2[0])*(item1[1]-item2[1]) >=0:    
                if r1 in range(0,len(file)) and c1 in range(0,len(file[0])) and [r1,c1] not in antinode : 
                   antinode.append([r1,c1])
                if r2 in range(0,len(file)) and c2 in range(0,len(file[0])) and [r2,c2] not in antinode : 
                   antinode.append([r2,c2])
            else: 
                if r1 in range(0,len(file)) and c2 in range(0,len(file[0])) and [r1,c2] not in antinode : 
                   antinode.append([r1,c1])
                if r2 in range(0,len(file)) and c1 in range(0,len(file[0])) and [r2,c1] not in antinode : 
                   antinode.append([r2,c2])
