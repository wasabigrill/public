# -*- coding: utf-8 -*-
"""
Created on Wed Dec  4 17:47:47 2024

@author: zzhang
"""

import os 
os.chdir("C:/adventofcode2024")

file = [line.split(" ") for line in open("day2.txt").read().split("\n")]
inputs = [[int(x) for x in line] for line in file] 

#%%
def safe_report(list):
    if list[0] < list[1] : 
        for i in range(len(list)-1):
            if list[i] >= list[i+1] or abs(list[i]-list[i+1]) not in range(1,4):
                return False 
            
        else:
            return True
    if list[0] > list[1]:
        for i in range(len(list)-1):
            if list[i] <= list[i+1] or abs(list[i]-list[i+1]) not in range(1,4):
                return False 
        else:
            return True
            
count = 0
for line in inputs:
    if safe_report(line) is True:
        count +=1

#%%
count = 0
for line in inputs:
    if safe_report(line) is True:
        count += 1
        continue
    for i, num in enumerate(line):
        new_list = line[0:i] + line[i+1:len(line)]
        if safe_report(new_list) is True:
            count += 1
            break
        