from sense_hat import SenseHat
sense = SenseHat()

import time
import random
from random import randint

while True:
  pitch = sense.get_orientation()['pitch']
  roll = sense.get_orientation()['roll']
  print("pitch {0} roll {1}".format(round(pitch, 0), round(roll,0)))
  time.sleep(0.05)
  break

sense.clear()
b = (0,0,0)
w = (255,255,255)
g = (0,255,0)
r = (255,0,0)
board = [ [r, r, r, b, b, b, b, r],
          [r, b, b, b, b, b, b, r],
          [b, b, b, b, g, r, b, r],
          [b, r, r, b, r, r, b, r],
          [b, b, b, b, b, b, b, b],
          [b, r, b, r, r, b, b, b],
          [b, b, b, r, b, b, b, r],
          [r, r, b, b, b, r, r, r] ]




y = randint(0,7)
x = randint(0,7)
board[y][x]=w

board_1D = sum(board, [])
print(board_1D)
sense.set_pixels(board_1D)

def check_wall(x, y, new_x, new_y):
  if board[new_y][new_x] != r:
    return new_x, new_y
  elif board[new_y][x] != r:
    return x, new_y
  elif board[y][new_x] != r:
    return new_x, y
  else:
    return x,y
    
def move_marble(pitch, roll, x, y):
  new_x = x
  new_y = y
  if 1 < pitch < 179 and x != 0:
    new_x -= 1
  elif 359 > pitch > 179 and x != 7:
    new_x += 1
  if 1 < roll < 179 and y != 7:
    new_y += 1
  elif 359 > roll > 179 and y != 0:
    new_y -= 1
  
  new_x, new_y = check_wall(x, y, new_x, new_y)
  return new_x, new_y


game_over = False
while not game_over:
  pitch = sense.get_orientation()['pitch']
  roll = sense.get_orientation()['roll']
  x, y = move_marble(pitch, roll, x, y)
  if board[y][x] == g:
    sense.show_message("Yay! :-D")
    game_over = True
  board[y][x] = w
  sense.set_pixels(sum(board, []))
  time.sleep(0.05)
  board[y][x] = b
'''
game_over = False
while game_over == False:
  pitch = sense.get_orientation()['pitch']
  roll = sense.get_orientation()['roll']
  x, y = move_marble(pitch, roll, x, y)
  if board[y][x] == g:
    sense.show_message("Yay! :-D")
    game_over = True
  board[y][x] = w
  sense.set_pixels(sum(board, []))
  time.sleep(0.05)
  board[y][x] = b
'''
