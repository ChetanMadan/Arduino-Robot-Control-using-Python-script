import sys,pygame
from time import sleep
from pygame.locals import *
import serial

ser1 = serial.Serial('/dev/cu.usbmodem143201',9600) # serial.Serial(COM Port,BAUD Rate)

size = width,height = 600,400 # width and height of the window
black = 0,0,0

pygame.init()
screen = pygame.display.set_mode(size)
while 1:
    for event in pygame.event.get():

        if event.type == KEYDOWN and event.key == K_w:
            print("forward")
            ser1.write('w'.encode())
        if event.type == KEYUP and event.key == K_w:
            #print("not pressed")
            ser1.write('y'.encode())

        if event.type == KEYDOWN and event.key == K_a:
            print("left")
            ser1.write('a'.encode())
        if event.type == KEYUP and event.key == K_a:
            #print("not pressed")
            ser1.write('g'.encode())

        if event.type == KEYDOWN and event.key == K_s:
            print("reverse")
            ser1.write('s'.encode())
        if event.type == KEYUP and event.key == K_s:
            #print("not pressed")
            ser1.write('h'.encode())

        if event.type == KEYDOWN and event.key == K_d:
            print("right")
            ser1.write('d'.encode())
        if event.type == KEYUP and event.key == K_d:
            #print("not pressed")
            ser1.write('j'.encode())
                    
        sleep(0.1)
