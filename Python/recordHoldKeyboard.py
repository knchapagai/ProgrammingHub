import time 
import keyboard
#if import error pip install keyboard

print("Starting App")
print("[INFO] Test Hold and Release Keyboard X")
print("[ESC]  To Break App")

while True:
	if(keyboard.is_pressed('x')):
		print("Start Reading Time Keyboard Hold and Release X")
		
		start=time.time()
		while(keyboard.is_pressed('x')):
			print("Button X is hold")
		end=time.time()
		
		print("Hold Time : ",end-start)
	if(keyboard.is_pressed('esc')):
		break
