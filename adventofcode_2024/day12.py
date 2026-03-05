# -*- coding: utf-8 -*-
"""
Created on Thu Dec 12 09:09:20 2024

@author: zzhang
"""

import os 
os.chdir("C:/adventofcode2024")

file= open("day12_test.txt").read().split("\n")



    
garden = {}
direct = [[1,0],[0,1],[-1,0],[0,-1]]
for r, line in enumerate(file):
    for c, char in enumerate(line):
        count = 0
        for dr,dc in direct:
            if r+dr in range(len(file)) and c+dc in range(len(file[0])) and file[r+dr][c+dc] == char:
                count += 1
        edge = 4-count
        if char not in garden:
            garden[char] = [[r,c,edge]]
        else: 
            garden[char].append([r,c,edge])
 
    
 
price = 0
area = 0
fence = 0
for pot in garden:
    coord = []
    while garden[pot] != []:
        r,c,edge = garden[pot].pop(0)
        if coord == []:
            coord.append([r,c])
            area += 1
            fence += edge
        elif [r,c] in coord
            
        for dr, dc in direct:
            if [r+dr,c+dc] not in coord:
               coord.append([r+dr,c+dr])
            
            
            area += 1
            fence += edge
            price += area*fence
            print(pot)
            print(area)
            print(fence)
            area = 0
            fence = 0
            

        