# -*- coding: utf-8 -*-
"""
Created on Thu Dec 19 09:03:11 2024

@author: zzhang
"""


import os 
os.chdir("C:/adventofcode2024")

ts, file= open("day19_test.txt").read().split("\n\n")

design = file.split("\n")
ts = ts.split(", ")

def can_design(design,t,memo={}):
    if design in memo:
        return memo[design]
    if design == "":
        return 1
    for t in ts:
        if t == design[0:len(t)]:           
            if can_design(design[len(t):],ts):
                memo[design] = 1
                return memo[design]
    else:
        memo[design]=0
        return memo[design]
    
    #%% part2
def how_design(design,t,count,memo={}):
    if design in memo:
        return memo[design]
    if design == "":
        return count
    for t in ts:
        if t == design[0:len(t)]:
            count+=1
            if  can_design(design[len(t):],t,count):
                count += 1
    else:
        count = 0
        memo[design]= 0
        return memo[design]
        
count=0 
for item in design:
    count += how_design(item,ts)
how_design("gbbr",ts)
    
