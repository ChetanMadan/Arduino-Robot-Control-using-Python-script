import sys,pygame
from time import sleep
from pygame.locals import *
import serial

ser1 = serial.Serial('/dev/cu.usbmodem143101',9600)

size = width,height = 600,400
black = 0,0,0

pygame.init()
screen = pygame.display.set_mode(size)
while 1:
    for event in pygame.event.get():
        if event.type == KEYDOWN and event.key == K_w:
            print("forward")
            ser1.write('w'.encode())
        if event.type == KEYDOWN and event.key == K_a:
            print("left")
            ser1.write('a'.encode())
        if event.type == KEYDOWN and event.key == K_s:
            print("reverse")
            ser1.write('s'.encode())
        if event.type == KEYDOWN and event.key == K_d:
            print("right")
            ser1.write('d'.encode())
        if event.type == KEYDOWN and event.key == K_ESCAPE:
            sys.exit();
        if event.type == KEYUP:
            print("not pressed")
            ser1.write('q'.encode())
        sleep(0.1)
