# -*- coding: utf-8 -*-
"""
Created on Wed Apr 22 10:54:19 2026

@author: zzhang
"""

"""
ENWS, right-up-left-down
"""


import random as rand
import pygame
        

def next_blocks(r: int, c: int, width: int, height: int, visited: list) -> list:
    next_blocks = []
    if r > 0 and (r - 1, c) not in visited:
        next_blocks.append((r - 1, c))
    if r < height - 1 and (r + 1, c) not in visited:
        next_blocks.append((r + 1, c))
    if c > 0 and (r, c - 1) not in visited:
        next_blocks.append((r, c - 1))
    if c < width - 1 and (r, c + 1) not in visited:
        next_blocks.append((r, c + 1))
    return (next_blocks)

class Maze:
    def __init__(self, width, height):
        self.width = width
        self.height = height
        self.visited = []
        self.count = 0
        self.grid = [[15 for _ in range(self.width)] for _ in range(self.height)]
        self. r = rand.randint(0, self.height - 1)
        self. c = rand.randint(0, self.width - 1)
        self.start = (0,0)
        self.end = (self.height - 1, self.width - 1)
        
    def generate_maze(self):
        if (self.r, self.c) not in self.visited:
            self.visited.append((self.r, self.c))
            self.count += 1

        if self.count is self.height * self.width:
            return      
        if not next_blocks(self.r, self.c, self.width, self.height, self.visited):
            i = len(self.visited) - 1
            while (i > 0):
                self.r, self.c = self.visited[i]
                next_grids = next_blocks(self.r, self.c, self.width, self.height, self.visited)
                i -= 1
                if next_grids:
                    return self.generate_maze()
        else:
            next_grids = next_blocks(self.r, self.c, self.width, self.height, self.visited)
            new_r, new_c = next_grids[rand.randint(0, len(next_grids) - 1)]
            dr = new_r - self.r
            dc = new_c - self.c
            if dc == 1: 
                self.grid[self.r][self.c] -= 8
                self.grid[new_r][new_c] -= 2
            elif dc == -1:
                self.grid[self.r][self.c] -= 2
                self.grid[new_r][new_c] -= 8
            if dr == 1:
                self.grid[self.r][self.c] -= 1
                self.grid[new_r][new_c] -= 4
            elif dr == -1:
                self.grid[self.r][self.c] -= 4
                self.grid[new_r][new_c] -= 1
            self.r, self.c = new_r, new_c
            return self.generate_maze()


def draw_maze(maze, start, end):
    maze_layer = pygame.Surface((WIDTH, HEIGHT), pygame.SRCALPHA)
    for r, row in enumerate(maze):
        for c, value in enumerate(row):
            x, y = c * TILE_SIZE + OFFSET, r * TILE_SIZE + OFFSET
            # Check bits using the bitwise AND operator (&)
            if value & 4: # Top wall
                pygame.draw.line(maze_layer, WALL_COLOR, (x, y), (x + TILE_SIZE, y), 2)
            if value & 8: # Right wall
                pygame.draw.line(maze_layer, WALL_COLOR, (x + TILE_SIZE, y), (x + TILE_SIZE, y + TILE_SIZE), 2)
            if value & 1: # Bottom wall
                pygame.draw.line(maze_layer, WALL_COLOR, (x + TILE_SIZE, y + TILE_SIZE), (x, y + TILE_SIZE), 2)
            if value & 2: # Left wall
                pygame.draw.line(maze_layer, WALL_COLOR, (x, y + TILE_SIZE), (x, y), 2)
            if start == (r, c):
                pygame.draw.circle(maze_layer, (255, 0, 0), (x + TILE_SIZE/2, y + TILE_SIZE/2), TILE_SIZE/4)
            if end == (r, c):
                pygame.draw.circle(maze_layer, (0, 255, 0), (x + TILE_SIZE/2, y + TILE_SIZE/2), TILE_SIZE/4)
    return maze_layer


w = int(input("Width of the maze:"))
h = int(input("Height of the maze:"))
maze = Maze(w, h)
maze.generate_maze()

WIDTH = 500
OFFSET = 50
TILE_SIZE = (WIDTH - 2* OFFSET)/ w
HEIGHT = TILE_SIZE * h + 2 * OFFSET
WALL_COLOR = (255, 192, 203) # Light Gray
BG_COLOR = (255, 255, 255)
PATH_COLOR = (255, 255, 0)
# Pygame Boilerplate
pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("A-Maze-ing")
maze_layer = draw_maze(maze.grid, maze.start, maze.end)
path = set()

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        if event.type == pygame.MOUSEBUTTONDOWN:
            if event.button == 3:
                path.clear()
                
    if pygame.mouse.get_pressed()[0]:
        mx, my = pygame.mouse.get_pos()
        c = int((mx - OFFSET) // TILE_SIZE)
        r = int((my - OFFSET) // TILE_SIZE)
        if 0 <= c <= w and 0 <= r <= h:
            path.add((r, c))

        
    screen.fill(BG_COLOR)
    
    for r, c in path:
        x, y = c * TILE_SIZE + OFFSET, r * TILE_SIZE + OFFSET
        pygame.draw.rect(screen, PATH_COLOR, (x, y, TILE_SIZE, TILE_SIZE))
    
    screen.blit(maze_layer, (0, 0))
    pygame.display.flip()
    
pygame.quit()
