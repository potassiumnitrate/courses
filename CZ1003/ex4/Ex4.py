from sense_hat import SenseHat
sense = SenseHat()

print("Input Q to quit") 



#choose text colour.

while True:                                                                                    #program repeats (until user issues command to quit)
    
    count = 0                                                                                  #initiate counter 
    while count <= 3:                                                                          #maximum trial for same error = 3 times
        
        while True:                                                                       
            red_msg = input("Enter red for text: ")                                         
            if red_msg == "Q":                                                                 #(program repeats) until user issues command to quit                                                          
                exit("ended")
            green_msg = input("Enter green for text: ")
            if green_msg == "Q":
                exit("ended")
            blue_msg = input("Enter blue for text: ")
            if blue_msg == "Q":
                exit("ended")
              
            try:                                                                            
                red_msg, green_msg, blue_msg = int(red_msg), int(green_msg), int(blue_msg)     #change red, green, blue_msg to int
            except ValueError:                                                                 #to correct ValueError (out of range)
                print("Try again for value between 0 and 255.")
                count = count + 1
                continue
        
            if (0 <= red_msg <= 255) and (0 <= green_msg <= 255) and (0 <= blue_msg <= 255):   #if data is in range
                break
            else:                                                                              #if data is out of range
                count = count + 1                                                              #increase counter    
                if count <= 2:
                    print("Try again for value between 0 and 255.")
                    continue
                if count == 3:
                    print("Number of tries exceeded.")
                    exit("ended")
        
            break
        break
 
#choose background colour.
    
    count = 0                                                                                  #initiate counter
    while count <= 3:                                                                          #maximum trial for same error = 3 times
        
        while True:
            red_bg = input("Enter red for bg: ")
            if red_bg == "Q":                                                                  #(program repeats) until user issues command to quit
                exit("ended")
            green_bg = input("Enter green for bg: ")
            if green_bg == "Q":
                exit("ended")
            blue_bg = input("Enter blue for bg: ")
            if blue_bg == "Q":
                exit("ended")

            try:
                red_bg, green_bg, blue_bg = int(red_bg), int(green_bg), int(blue_bg)           #change red, green, blue_bg to int
            except ValueError:                                                                 #to correct ValueError (out of range)
                print("Try again for value between 0 and 255.") 
                continue
              
            if (0 <= red_bg <= 255) and (0 <= green_bg <= 255) and (0 <= blue_bg <= 255):      #if data is in range
                break
            else:                                                                              #if data is out of range
                count = count + 1                                                              #increase counter
                if count <= 2:
                    print("Try again for value between 0 and 255")
                    continue
                if count == 3:
                    print("Number of tries exceeded.")
                    exit("ended")
                       
            #if both msg and bg same       
            if red_msg != red_bg and green_msg != green_bg and blue_msg != blue_bg:            #if msg and bg diff
              break
            else:                                                                              #if msg and bg same
              count = count + 1                                                                #increase counter
              if count <= 2:
                print("Try again for 2 different colours.")
                continue
              if count == 3:
                print("Number of tries exceeded.")
                exit("ended")

            break
        break
    break  

'''
################## based on int for scroll speed instead of str ###########################################
#choose scroll speed.

while True:
  scroll_speed1 = input("Enter scroll speed: ")
  try:
    scroll_speed1 = float(scroll_speed1)                                                       #change scroll_speed1 to float
    break
  except ValueError:                                                                           #to correct ValueError ("fast" is not a float)
    print("Try again with a value between 0 and 1.")
    continue

#end

text_colour = (red_msg, green_msg, blue_msg)
back_colour = (red_bg, green_bg, blue_bg)

sense.show_message("This is fun!", text_colour = text_colour, \
                                   back_colour = back_colour, \
                                   scroll_speed = scroll_speed1)
'''

#choose scroll speed.

while True:
  scroll_speed1 = input("Enter scroll speed: ")
  try:
    scroll_speed1 = str(scroll_speed1)                                                       #change scroll_speed1 to float
    speed1 = 0
    break
  except ValueError:                                                                           #to correct ValueError ("fast" is not a float)
    print("Try again with a value between 0 and 1.")
    continue
  if scroll_speed1 == 'slow':
    speed1 = 0.5
    break
  elif scroll_speed1 == 'moderate':
    speed1 = 0.4
    break
  elif scroll_speed1 == 'fast':
    speed1 = 0.3
    break
  break

#end

text_colour = (red_msg, green_msg, blue_msg)
back_colour = (red_bg, green_bg, blue_bg)

sense.show_message("This is fun!", text_colour = text_colour, \
                                   back_colour = back_colour, \
                                   scroll_speed = speed1)
