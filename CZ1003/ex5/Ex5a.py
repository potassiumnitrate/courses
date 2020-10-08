from sense_hat import SenseHat
sense = SenseHat()

red = (255, 0, 0)
yellow = (255, 255, 0)
blue = (0, 0, 255)
teal = (0, 255, 255)

sense.clear()

import random
from random import randint

sense.set_pixel (randint(0,7), randint(0,7), teal)
sense.set_pixel (randint(0,7), randint(0,7), blue)
sense.set_pixel (randint(0,7), randint(0,7), red)
sense.set_pixel (randint(0,7), randint(0,7), yellow)

