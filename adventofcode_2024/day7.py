# -*- coding: utf-8 -*-
"""
Created on Sat Dec  7 09:14:37 2024

@author: zzhang
"""

import os 
os.chdir("C:/adventofcode2024")

file = open("day7.txt").read().split("\n")
file = [line.split(": ") for line in file]
suum = [int(line[0]) for line in file]
nums = [line[1].split(" ") for line in file]

def can_math(suum, nums):
    if suum <0:
        return False
    if len(nums) == 1:
        if suum == nums[0]:
            return True
        else:
            return False
    
    else: 
        return can_math(suum/nums[len(nums)-1], nums[0:len(nums)-1]) + can_math(suum-nums[len(nums)-1], nums[0:len(nums)-1])
    

count = 0

for i, tsum in enumerate(suum):
    numbers = [int(num) for num in nums[i]]
    if can_math(tsum,numbers):
        count +=tsum

#%% part 2

def can_math(suum, nums):
    if suum <0:
        return False
    if len(nums) == 1:
        if suum == nums[0]:
            return True
        else:
            return False
    
    else: 
        num_len = len(str(nums[len(nums)-1]))
        return can_math(suum/nums[len(nums)-1], nums[0:len(nums)-1]) + can_math(suum-nums[len(nums)-1], nums[0:len(nums)-1]) +can_math( (suum-nums[len(nums)-1])/10**num_len, nums[0:len(nums)-1]) 
    
count = 0

for i, tsum in enumerate(suum):
    numbers = [int(num) for num in nums[i]]
    if can_math(tsum,numbers):
        count +=tsum
