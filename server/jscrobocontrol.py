import pygame
import serial

pygame.init()
pygame.display.set_mode()
pygame.key.set_repeat(1000, 1000)

with serial.Serial('/dev/ttyUSB0', 115200, timeout=1) as ser:
	while 1:
    		for event in pygame.event.get():
        		if event.type == pygame.KEYDOWN:
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
