# -*- coding: utf-8 -*-
"""
Created on Sun Dec 15 09:28:05 2024

@author: zzhang
"""


import os 
os.chdir("C:/adventofcode2024")

maps, motions= open("day15_test2.txt").read().split("\n\n")

maps = maps.split("\n")
maps = [list(line) for line in maps]
#%% part1
for i, line in enumerate(maps):
    for j, item in enumerate(line):
        if item == "@":
            r = i
            c =j

for i, direct in enumerate(motions): 
    if direct == "<":
        push = maps[r][:c]
        idx_wall = len(push) - push[::-1].index("#") 
        if "." not in push[idx_wall:]:
            continue
        else: 
            idx = push[::-1].index(".") + 1
            maps[r][c-idx:c] = maps[r][c-idx+1:c+1]
            maps[r][c] = "."
            c = c-1
    if direct == ">":
        push = maps[r][c:len(maps[r])]
        idx_wall = push.index("#")
        if "." not in push[:idx_wall]:
            continue
        else: 
            idx = push.index(".")
            maps[r][c+1:c+idx+1] = maps[r][c:c+idx]
            maps[r][c] = "."
            c = c+1
    if direct == "^":
        push = [line[c] for x, line in enumerate(maps) if x <r]
        idx_wall = len(push) - push[::-1].index("#") 
        if "." not in push[idx_wall:]:
            continue
        else: 
            idx = push[::-1].index(".") +1
            push[r-idx:len(push)-1] = push[r-idx+1:]
            push[len(push)-1] = "@"
            for i, item in enumerate(push):
                maps[i][c]=item
            maps[r][c] = "."
            r = r-1
    if direct == "v": 
        push = [line[c] for x, line in enumerate(maps) if x >= r]
        idx_wall = push.index("#")
        if "." not in push[:idx_wall]:
            continue
        else: 
            idx = push.index(".") 
            push[1:idx+1] = push[:idx]
            for i, item in enumerate(push):
                maps[r+i][c]=item
            maps[r][c] = "."
            r = r + 1
            
total = 0
for i, line in enumerate(maps):
    for j, item in enumerate(line):
        if item == "O":
            total += i*100 + j
print(total)

#%% part2 
map2= [[0 for _ in range(2*len(maps[0]))] for _ in range(len(maps))]
for i, line in enumerate(maps):
    for j in range(0,len(line)):
        item = line[j]
        if item == "#":
            map2[i][2*j]="#"
            map2[i][2*j+1]="#"
        if item =="O":
            map2[i][2*j]='['
            map2[i][2*j+1] ="]"
        if item == ".":
            map2[i][2*j]='.'
            map2[i][2*j+1] ="."
        if item == "@":
            map2[i][2*j]='@'
            map2[i][2*j+1] ="."

for i, line in enumerate(maps):
    for j, item in enumerate(line):
        if item == "@":
            r = i
            c =j
            


for i, direct in enumerate(motions): 
    if direct == "<":
        push = maps[r][:c]
        idx_wall = len(push) - push[::-1].index("#") 
        if "." not in push[idx_wall:]:
            continue
        else: 
            idx = push[::-1].index(".") + 1
            maps[r][c-idx:c] = maps[r][c-idx+1:c+1]
            maps[r][c] = "."
            c = c-1
    if direct == ">":
        push = maps[r][c:len(maps[r])]
        idx_wall = push.index("#")
        if "." not in push[:idx_wall]:
            continue
        else: 
            idx = push.index(".")
            maps[r][c+1:c+idx+1] = maps[r][c:c+idx]
            maps[r][c] = "."
            c = c+1
    if direct == "^":
        push = [line[c] for x, line in enumerate(maps) if x <r]
        idx_wall1 = 0
        idx_wall2 = 0
        if "]" in push:
            push1 = [line[c-1] for x, line in enumerate(maps) if x <r]
            idx_wall1 = len(push) - push[::-1].index("#") 
        if "[" in push:
            push2 = [line[c+1] for x, line in enumerate(maps) if x <r]
            idx_wall2 = len(push) - push[::-1].index("#")            
        idx_wall0 = len(push) - push[::-1].index("#") 
        idx_wall = max(idx_wall0,idx_wall1,idx_wall2)
        if "." not in push[idx_wall:]:
            continue
        else: 
            idx = push[::-1].index(".") +1
            push[r-idx:len(push)-1] = push[r-idx+1:]
            push[len(push)-1] = "@"
            for i, item in enumerate(push):
                maps[i][c]=item
            maps[r][c] = "."
            r = r-1
    if direct == "v": 
        push = [line[c] for x, line in enumerate(maps) if x >= r]
        idx_wall = push.index("#")
        if "." not in push[:idx_wall]:
            continue
        else: 
            idx = push.index(".") 
            push[1:idx+1] = push[:idx]
            for i, item in enumerate(push):
                maps[r+i][c]=item
            maps[r][c] = "."
            r = r + 1