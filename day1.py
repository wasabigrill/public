# -*- coding: utf-8 -*-
"""
Created on Wed Dec  4 17:23:57 2024

@author: zzhang
"""

import os 
os.chdir("C:/adventofcode2024")

file=open("day1.txt").read().split("\n")

inputs = [ line.split("   ") for line in file]

list1 = [int(line[0]) for line in inputs] 
list2 = [int(line[1]) for line in inputs] 

#%%
sum = 0;
while list1 != []:
    sum += abs( min(list1) - min(list2))
    list1.remove(min(list1)) 
    list2.remove(min(list2))

#%%    
sum1=0
for num1 in list1:
    indices = [];
    indices = [ i for i, num2 in enumerate(list2) if num2 == num1 ] 
    if indices != []:
        sum1 += num1*len(indices)

