import cv2
import serial

arduino = serial.Serial("COM3", 9600)

cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    lower = (40, 70, 70)
    upper = (80, 255, 255)

    mask = cv2.inRange(hsv, lower, upper)
    moments = cv2.moments(mask)

    if moments["m00"] > 0:
        cx = int(moments["m10"]/moments["m00"])
        cy = int(moments["m01"]/moments["m00"])

        pan = int((cx / frame.shape[1]) * 180)
        tilt = int((cy / frame.shape[0]) * 180)

        arduino.write(f"M {pan} {tilt}\n".encode())

    cv2.imshow("mask", mask)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
