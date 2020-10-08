from sense_hat import SenseHat

sense = SenseHat()
sense.set_rotation(180)

def get_color(color):
    keep_looping = True
    no_of_try = 1
    while keep_looping:
        color_str = input("Enter the value of the " + color + \
                          " color for message (0 to 255):")
        
        try:
            color_str = int(color_str) 
        except ValueError:
            print("Please try again for value between 0 and 255.")
            continue
            
        if (0<=color_str<=255):
            return color_str
        else:
            if no_of_try < 3:
                no_of_try = no_of_try + 1
                print("Please try again for value between 0 and 255.")
                continue
            elif no_of_try == 3:
                return 0
            break
        break
        
r_int = get_color("red")
g_int = get_color("green")
b_int = get_color("blue")
msg_color = (r_int, g_int, b_int)
sense.show_message("I got it!", text_colour = msg_color)
