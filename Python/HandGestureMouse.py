import cv2
import mediapipe as mp
import pyautogui
from time import sleep
hand_detect = mp.solutions.hands.Hands()
cap = cv2.VideoCapture(0)
while True:
    ret, frame = cap.read()
    frame = cv2.flip(frame, 1)
    frame_height, frame_width, _ = frame.shape
    rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    results = hand_detect.process(rgb_frame)
    hands = results.multi_hand_landmarks
    if hands:
        for hand in hands:
            landmark = hand.landmark
            for id, landmark in enumerate(landmark):
                x = int(landmark.x*frame_width)
                if id == 8:
                    if x > 300:
                        pyautogui.keyDown('left')
                        pyautogui.keyUp('left')
                        sleep(1)
                    elif x < 100:
                        pyautogui.keyDown('right')
                        pyautogui.keyUp('right')
                        sleep(1)
    cv2.waitKey(1)
