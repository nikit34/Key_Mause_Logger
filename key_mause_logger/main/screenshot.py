import numpy as np
import pyautogui
import imutils
import cv2
import sys

file = open("buffer.txt", "r+", encoding="utf-8") 
i = int(file.read())

image = pyautogui.screenshot()
image = cv2.cvtColor(np.array(image), cv2.COLOR_RGB2BGR)
cv2.imwrite("../data/screenshots/screen_{}.png".format(i), image)

i += 1
file.seek(0)
file.write(str(i))
file.close()
del i
del image