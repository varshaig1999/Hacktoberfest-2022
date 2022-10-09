#Name:Ashish Ramesh
#Github ID : AshishRamesh

import cv2 as cv

video = cv.VideoCapture(0)
face_cascade = cv.CascadeClassifier('haarcascade_frontalface_default.xml')
print('Press q to exit')
while True :
    check,frame = video.read()
    face = face_cascade.detectMultiScale(frame,
    scaleFactor = 2,
    minNeighbors = 5)
    for x,y,w,h in face:
        frame = cv.rectangle(frame,(x,y),(x+w,y+h),(0,255,0),3)
    cv.imshow('Video',frame)
    key = cv.waitKey(1)
    if key == ord('q'):
        break

video.release()
cv.destroyAllWindows()