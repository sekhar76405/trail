import RPi.GPIO as GPIO
from gpiozero import Button, MotionSensor
from picamera import PiCamera
from time import sleep
from signal import pause
import time
import smtplib
 
GPIO.setmode(GPIO.BCM)
 
GPIO_TRIGGER = 23
GPIO_ECHO = 24
 
GPIO.setup(GPIO_TRIGGER, GPIO.OUT)
GPIO.setup(GPIO_ECHO, GPIO.IN)
 
def distance():
    GPIO.output(GPIO_TRIGGER, True)
 
    # set Trigger after 0.01ms to LOW
    time.sleep(0.00001)
    GPIO.output(GPIO_TRIGGER, False)
 
    StartTime = time.time()
    StopTime = time.time()
 
    while GPIO.input(GPIO_ECHO) == 0:
        StartTime = time.time()
 
    # save time of arrival
    while GPIO.input(GPIO_ECHO) == 1:
        StopTime = time.time()
 
    # time difference between start and arrival
    TimeElapsed = StopTime - StartTime
    # multiply with the sonic speed (34300 cm/s)
    # and divide by 2, because there and back
    distance = (TimeElapsed * 34300) / 2
 
    return distance
    time.sleep(10)
def a():
    GPIO.output(GPIO_TRIGGER, True)
 
    # set Trigger after 0.01ms to LOW
    time.sleep(0.0001)
    GPIO.output(GPIO_TRIGGER, False)
 
    StartTime = time.time()
    StopTime = time.time()
 
    while GPIO.input(GPIO_ECHO) == 0:
        StartTime = time.time()
 
    # save time of arrival
    while GPIO.input(GPIO_ECHO) == 1:
        StopTime = time.time()
 
    # time difference between start and arrival
    TimeElapsed = StopTime - StartTime
    # multiply with the sonic speed (34300 cm/s)
    # and divide by 2, because there and back
    a = (TimeElapsed * 34300) / 2
    return a
 
if __name__ == '__main__':
    try:
        while True:
            dist = distance()
            print ("Measured Distance = %.1f cm" % dist)
            a1=a()
            print ("a Distance = %.lf cm" % a1)
            
            if (dist <= a1) :
                print("")
            else:  
                #create objects that refer to a button,
                #a motion sensor and the PiCamera
                button = Button(2)
                pir = MotionSensor(4)
                camera = PiCamera()

                #start the camera
                camera.rotation = 180
                camera.start_preview()

                #image image names
                i = 0

            #stop the camera when the pushbutton is pressed
                def stop_camera():
                    camera.stop_preview()
                #exit the program
                    exit()

#take photo when motion is detected
                def take_photo():
                    global i
                i = i + 1
                camera.capture('/home/pi/Desktop/image_%s.jpg' % i)
                print('A photo has been taken')
                sleep(10)

#assign a function that runs when the button is pressed
                button.when_pressed = stop_camera
#assign a function that runs when motion is detected
                pir.when_motion = take_photo

                pause()
                
                
                # smtplib module send mail
                
                TO = 'recipient@mailservice.com'
                SUBJECT = 'TEST MAIL'
                TEXT = 'Here is a message from python.'
                
                # Gmail Sign In
                gmail_sender = 'sender@gmail.com'
                gmail_passwd = 'password'
                
                server = smtplib.SMTP('smtp.gmail.com', 587)
                server.ehlo()
                server.starttls()
                server.login(gmail_sender, gmail_passwd)
                
                BODY = '\r\n'.join(['To: %s' % TO,
                                    'From: %s' % gmail_sender,
                                    'Subject: %s' % SUBJECT,
                                    '', TEXT])
                
                try:
                    server.sendmail(gmail_sender, [TO], BODY)
                    print ('email sent')
                except:
                    print ('error sending mail')
                
                server.quit()
            time.sleep(1)
 
        # Reset by pressing CTRL + C
    except KeyboardInterrupt:
        print("Measurement stopped by User")
        GPIO.cleanup()



