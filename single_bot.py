# 30 august friday

import cv2
import cv2.aruco
import numpy as np
import sys
import time
import serial
ser1 = serial.Serial('/dev/ttyACM0', 9600)

# direction- current facing
# send_radio- send data
# orientaion- manager of all function calls
# orient_north- align north towards north


def send_radio(data):
    if data == 'for':
        print("forward")
        ser1.write('w'.encode())
    if data == 'lt':
        print("left")
        ser1.write('a'.encode())
    if data == 'rev':
        print("reverse")
        ser1.write('s'.encode())
    if data == 'rt':
        print("right")
        ser1.write('d'.encode())
    if data == 'z':
        sys.exit()
    if data == 'c':
        print("not pressed")
        ser1.write('q'.encode())
    time.sleep(0.1)


# this function tells the current direction in which the bot is facing
def direction(img, top_left, top_right, centre):
    dictionary = cv2.aruco.getPredefinedDictionary(cv2.aruco.DICT_6X6_250)
    while True:
    	ret, frame = cap.read()
    	corners, ids, rejected = cv2.aruco.detectMarkers(frame, dictionary)
        cv2.aruco.drawDetectedMarkers(frame, corners, ids)
        top_left = corners[0][0][0]
        top_right = corners[0][0][1]
        
        top_left_x = top_left[0]
	    top_left_y = top_left[1]
	    top_right_x = top_right[0]
	    top_right_y = top_right[1]

	    if abs(top_right_x - top_left_x) <= 15:
	        if top_left_y > top_right_y:
	            orient = "west"
	        elif top_right_y > top_left_y:
	            orient = "east"
	    elif (top_right_x - top_left_x) > 0:     # upright
	        if abs(top_right_y - top_left_y) <= 15:
	            orient = "north"
	        elif (top_right_y > top_left_y):
	            orient = "ne"
	        elif (top_left_y > top_right_y):
	            orient = "nw"
	    elif (top_right_x - top_left_x) < 0:
	        if abs(top_right_y - top_left_y) <= 15:
	            orient = "south"
	        elif (top_left_y > top_right_y):
	            orient = "sw"
	        elif (top_right_y > top_left_y):
	            orient = "se"
	    return orient


# def movement(img, top_left, top_right, centre, ids):
#     dictionary = cv2.aruco.getPredefinedDictionary(cv2.aruco.DICT_6X6_250)
#     while True:
#         ret, frame = cap.read()
#         # getting all the values in different variables
#         corners, ids, rejected = cv2.aruco.detectMarkers(frame, dictionary)
#         cv2.aruco.drawDetectedMarkers(frame, corners, ids)
#         cv2.circle(frame,(250,250), 5, [255,255,255])
#         cv2.imshow('out', frame)
#         if cv2.waitKey(1) & 0xFF == ord('q'):
#             break
#         if len(corners) > 0:
#             # draw only if aruco detected
#             i = 0

#             # nested loop only for centre coordinates
#             while i < len(corners):
#                 # corners contains 4 coordinates of the aruco (2d array)
#                 j = 0
#                 flag = 0
#                 while j < len(corners[i]):
#                     # first taking sum of all x coord, then divide by 4. Then y
#                     pos = np.sum(corners[i], axis=1) / 4
#                     j = j + 1
#                     orientation(frame, corners[0][0][0], corners[0][0][1], pos, ids[i], flag)
#                     flag = flag + 1
#                 i = i + 1
#             print("\n")

    # gives directions to the bot for destination
def movement(img, top_left, top_right, centre):
    x1 = top_left[0]
    y1 = top_left[1]
    x2 = top_right[0]
    y2 = top_right[1]

    # s1 and s2 are coordinates of the centre of the line
    # joining top left and top right
    s1 = (x1 + x2) / 2
    s2 = (y1 + y2) / 2

    # destination
    d1 = 250.0
    d2 = 250.0
    # get the current direction of aruco
    # then send signals according to the relative positions
    # of the source (aruco) and the destination
    orient = direction(img, top_left, top_right, centre)
    # first checking if final destination reached
    if abs(s1 - d1) <= 15 and abs(s2 - d2) <= 15:
        send_radio('c', ids)
    # check for all four directions and give the command
    elif orient == "north":
        if abs(s1 - d1) <= 30:
            if s2 > d2:
                send_radio('for', ids)
            else:
                send_radio('rev', ids)
        elif s1 < d1:
            send_radio('rt', ids)
        elif s1 > d1:
            send_radio('lt', ids)
    elif orient == "south":
        if abs(s1 - d1) <= 30:
            if s2 > d2:
                send_radio('rev', ids)
            else:
                send_radio('for', ids)
        elif s1 < d1:
            send_radio('lt', ids)
        elif s1 > d1:
            send_radio('rt', ids)
    elif orient == "east":
        if abs(s2 - d2) <= 30:
            if s1 < d1:
                send_radio('for', ids)
            else:
                send_radio('rev', ids)
        elif s2 > d2:
            send_radio('lt', ids)
        elif s2 < d2:
            send_radio('rt', ids)
    elif orient == "west":
        if abs(s2 - d2) <= 30:
            if s1 < d1:
                send_radio('for', ids)
            else:
                send_radio('rev', ids)
        elif s2 < d2:
            send_radio('lt', ids)
        elif s2 > d2:
            send_radio('rt', ids)


# this function orients the bot in the north direction
def orient_north(img, top_left, top_right, centre):

    # turn the bot until faces north
    if direction(img, top_left, top_right, centre, ids) == "north":
        send_radio('c', ids)
        return
    else:
        direc = direction(img, top_left, top_right, centre, ids)
        while direc != 'north':
            print("Stuck in loop")
            send_radio('rt', ids)
            send_radio('c', ids)
            direc = direction(img, top_left, top_right, centre, ids)
            break
        send_radio('c', ids)


def orientation(img, top_left, top_right, centre):
    # this function basically manages execution of all other functions
    top_left_x = top_left[0]
    top_left_y = top_left[1]
    top_right_x = top_right[0]
    top_right_y = top_right[1]
    # source/current aruco coordinates
    s1 = (top_left_x + top_right_x) / 2
    s2 = (top_left_y + top_right_y) / 2
    # destination coord
    d1 = 250.0
    d2 = 250.0
    orient_north(img, top_left, top_right, centre)

    '''if abs(s1 - d1) <= 15 and abs(s2 - d2) <= 15:
                    send_radio('c', ids)
                else:
                	orient_north(img, top_left, top_right, centre, ids)
                	movement(img,top_left,top_right, centre, ids)'''
    while abs(s1 - d1) > 15 or abs(s2 - d2) > 15:
    	direction(img, top_left, top_right, centre)


if __name__ == '__main__':
    cap = cv2.VideoCapture(2)
    dictionary = cv2.aruco.getPredefinedDictionary(cv2.aruco.DICT_6X6_250)
    while True:
        ret, frame = cap.read()
        # getting all the values in different variables
        corners, ids, rejected = cv2.aruco.detectMarkers(frame, dictionary)
        cv2.aruco.drawDetectedMarkers(frame, corners, ids)
        # cv2.circle(frame,(250,250), 5, [255,255,255])
        cv2.imshow('out', frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
        if len(corners) > 0:
            # draw only if aruco detected
            i = 0

            # nested loop only for centre coordinates
            while i < len(corners):
                # corners contains 4 coordinates of the aruco (2d array)
                j = 0
                flag = 0
                while j < len(corners[i]):
                    # first taking sum of all x coord, then divide by 4. Then y
                    pos = np.sum(corners[i], axis=1) / 4
                    j = j + 1
                    orientation(frame, corners[0][0][0], corners[0][0][1], pos)
                    flag = flag + 1
                i = i + 1
            print("\n")

    cap.release()
    cv2.destroyAllWindows()
