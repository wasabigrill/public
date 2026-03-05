# -*- coding: utf-8 -*-
"""
Created on Wed Dec  4 18:33:43 2024

@author: zzhang
"""

import os 
os.chdir("C:/adventofcode2024")

file = open("day3.txt").read().split("mul(")
inputs = [line[0:line.index(")")].split(",") for line in file if "," and ")" in line]

#%%
def is_integer(s):
    return s.isdigit()

sum = 0
for line in inputs:
    if len(line) == 2:
        if is_integer(line[0]) and is_integer(line[1]) is True:
            sum += int(line[0])*int(line[1])
            
#%% part2

file =  open("day3.txt").read().split("don't()")

for i,line in enumerate(file): 
    if i == 0:
        continue
    else: 
        if "do()" in line:
            file[i] = line[line.index("do()"):]
        else:
            file[i] = ""
        
file = "".join(file).split("mul(")
    
inputs = [line[0:line.index(")")].split(",") for line in file if "," and ")" in line]

sum = 0
for line in inputs:
    if len(line) == 2:
        if is_integer(line[0]) and is_integer(line[1]) is True:
            sum += int(line[0])*int(line[1])
            