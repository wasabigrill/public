# -*- coding: utf-8 -*-
"""
Created on Wed Dec 11 09:50:58 2024

@author: zzhang
"""

import os 
os.chdir("C:/adventofcode2024")

inputs= open("day11.txt").read().split(" ")
#inputs = ["125","17"]

blink = 25
skip = False
for i in range(blink):
    for j, stone in enumerate(inputs): 
        if skip == True:
            skip = False
            continue
        if stone == "0":
            inputs[j] = "1"
        elif len(stone)%2 == 0:
            inputs[j] = stone[:int(len(stone)/2)]
            sh = stone[int(len(stone)/2):]
            if set(sh) == {"0"}:
                inputs.insert(j+1,"0")
            elif sh[0] == "0":
                inputs.insert(j+1,"".join(sh.split("0")))
            else:
                inputs.insert(j+1,sh)
            skip = True
        else:
            stone = int(stone)*2024
            inputs[j] = str(stone)
