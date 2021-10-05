import cv2

image_folder = '../images'
video_name = '../test.mp4'

vidcap = cv2.VideoCapture(video_name)
success, image = vidcap.read()
count = 1

while success:
  cv2.imwrite(image_folder + "\\%d.jpg" % count, image)     # save frame as JPEG file      
  success, image = vidcap.read()
  print('Read a new frame: ', success)
  count += 1