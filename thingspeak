import urllib.request
import requests
import serial
import time
import json


ser = serial.Serial('COM3', baudrate = 9600, timeout = 1)


API_KEY = 'MN3CJT4FQOWJGRU8'
channelID = '1648141'

writeURL = 'https://api.thingspeak.com/update?api_key=' + API_KEY + '&field1='
readURL = 'https://api.thingspeak.com/channels/' + channelID + '/feeds.json'
entries = requests.get(readURL).json()


n = entries["channel"]["last_entry_id"]

if n is None:
        data = urllib.request.urlopen(writeURL + str(35.00))
        entries = requests.get(readURL).json()
        n = entries["channel"]["last_entry_id"]

for x in range(n): 
	lastTemp = entries["feeds"][int(x)]["field1"]
	print ("[" + str(x+1) + "] " + lastTemp)

while True:

	arduinoData = ser.readline().decode('ascii')
	if (str(arduinoData) != ""):
		arduinoData = arduinoData.replace(" ", "")
		arduinoData = arduinoData.replace("\n", " ").replace("\r", " ")
		print ("["+ str(n+1) + "] " + str(arduinoData))
		data = urllib.request.urlopen(writeURL + str(arduinoData))
		n += 1
