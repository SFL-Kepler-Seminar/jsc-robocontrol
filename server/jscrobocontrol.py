#!/usr/bin/env python2
# -*- coding: utf-8 -*-
import pygame
import serial
import argparse

argparser = argparse.ArgumentParser(description="Ein Werkzeug zur Kontrolle eines Roboters über Tastatureingaben.")
argparser.add_argument("serial", help="Der pfad zur seriellen Konsole.", default="/dev/ttyUSB0",  nargs='?')
args = argparser.parse_args()
pygame.init()
pygame.display.set_mode()
screen = pygame.display.get_surface()
pygame.key.set_repeat(200, 200)
myfont = pygame.font.SysFont("monospace", 22)

label = myfont.render("Benutze W - A - S - D und Leertaste um deinen Roboter zu steuern.", 1, (255,255,255))

screen.blit(label, (screen.get_width()/2-label.get_width()/2, screen.get_height()/2-label.get_height()/2))
pygame.display.update()
with serial.Serial(args.serial, 115200, timeout=1) as ser:
	while 1:
    		for event in pygame.event.get():
        		if event.type == pygame.KEYDOWN:
				if event.key == pygame.K_ESCAPE:
					pygame.quit()
            			if event.key == pygame.K_w:
					ser.write('w')
            			if event.key == pygame.K_a:
                			ser.write('a')
				if event.key == pygame.K_s:
                                        ser.write('s')
				if event.key == pygame.K_d:
                                        ser.write('d')
				if event.key == pygame.K_SPACE:
                                        ser.write('x')
        		if event.type == pygame.KEYUP:
                                if event.key == pygame.K_w:
                                        ser.write('1')
                                if event.key == pygame.K_a:
                                        ser.write('2')
                                if event.key == pygame.K_s:
                                        ser.write('3')
                                if event.key == pygame.K_d:
                                        ser.write('4')
                                if event.key == pygame.K_SPACE:
                                        ser.write('0')
