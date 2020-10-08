from sense_hat import SenseHat
sense = SenseHat()


msg_red = (255,0,0)
msg_green = (0,255,0)
msg_blue = (0,0,255)
print("For text colour, choose msg_red, msg_green, or msg_blue.")
color_msg = input("Enter colour of message: ")
while True:
  if color_msg == 'msg_red':
    color_msg = (255,0,0)
    break
  elif color_msg == 'msg_green':
    color_msg = (0,255,0)
    break
  elif color_msg == 'msg_blue':
    color_msg = (0,0,255)
    break
  break

back_red = (255,0,0)
back_green = (0,255,0)
back_blue = (0,0,255)
print("For background colour, choose back_red, back_green, back_blue.")
color_bg = input("Enter colour of background: ")
while True:
  if color_bg == 'back_red':
    color_bg = (255,0,0)
    break
  elif color_bg == 'back_green':
    color_bg = (0,255,0)
    break
  elif color_bg == 'back_blue':
    color_bg = (0,0,255)
    break
  break

slow = 0.5
moderate = 0.4
fast = 0.3
print("For speed, choose slow, moderate, fast.")
speed = input("Enter speed: ")
while True:
  if speed == 'slow':
    speed = 0.5
    break
  elif speed == 'moderate':
    speed = 0.4
    break
  elif speed == 'fast':
    speed = 0.3
    break
  break


sense.show_message("I got it!", text_colour = color_msg,  \
                                back_colour = color_bg,   \
                                scroll_speed = speed)
