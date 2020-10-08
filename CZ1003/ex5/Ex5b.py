from sense_hat import SenseHat
sense = SenseHat()

import time
import random
from random import randint

r = (255, 0, 0)         #red
p = (255, 80, 180)     #pink
g = (0, 255, 0)         #green
y = (255, 255, 0)       #yellow
b = (0, 0, 255)         #blue
t = (0, 255, 255)       #teal
w = (255,255,255)       #white
n = (0,0,0)             #nothing

def image_pixels1():
  image_pixels = [w, w, w, w, w, w, w, w,
                  w, w, r, r, w, r, r, w,
                  w, r, r, r, r, r, r, r, 
                  w, r, r, r, r, r, r, r, 
                  w, r, r, r, r, r, r, r, 
                  w, w, r, r, r, r, r, w, 
                  w, w, w, r, r, r, w, w, 
                  w, w, w, w, r, w, w, w]
  return image_pixels  
 
def image_pixels2():
  image_pixels = [w, w, w, w, w, w, w, w,
                  w, w, b, b, w, b, b, w,
                  w, b, b, b, b, b, b, b, 
                  w, b, b, b, b, b, b, b, 
                  w, b, b, b, b, b, b, b, 
                  w, w, b, b, b, b, b, w, 
                  w, w, w, b, b, b, w, w, 
                  w, w, w, w, b, w, w, w]
  return image_pixels

images = [image_pixels1, image_pixels2]
#functions:
#images[0] = image_pixels1, images[1] = images_pixels2

import random
image_pixel = random.choice(images)

####### stop #########################################
count = 0
while True: 
  if count <= 5:
    sense.set_pixels(images[count % len(images)]())
    #len(images)= 2 -the list called images
    sense.set_rotation(90*randint(0,3))
    time.sleep(1)
    count += 1
    continue
  elif count == 5:
    break
  break
sense.clear(100, 100, 100)
