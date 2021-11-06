##################################################################################################################################
#                                                       Adarsh , Aadithya                                                               #
##################################################################################################################################

import serial 
import sys
import os

ser = serial.Serial('/dev/rfcomm1',9600) 

path='/sys/class/backlight/intel_backlight/brightness' 



while(1):
	try:
		#value  = ser.readline().split()
		value  = str(ser.readline())
		value = value.split()
		print (value) 
		#val = int(value[0][2:])
		val = int(value[0])
		print(val)
		
		if(val <= 70):
			os.system('xrandr --output eDP-1 --brightness 0.5')
		if(val >=70 and val <= 88):
			os.system('xrandr --output eDP-1 --brightness 1.0')
		if(val > 88):
			os.system('xrandr --output eDP-1 --brightness 1.5')
		if(int(value[1])==1):
			os.system("amixer set 'Master' 5%+")
		if(int(value[1])==-1):
			os.system("amixer set 'Master' 5%-")
	except KeyboardInterrupt:
		print('Interrupted')
		break
	#finally:
		#ser.close()
		# Just to take care of initial garbage values

		
############################################################# END ##################################################################
