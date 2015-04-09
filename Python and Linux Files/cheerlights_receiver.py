# Intel Galileo - Insper Workshop
# Cheerlights Code to Interface with Arduino

import urllib2

colors = {'red': '100,0,0',
          'green': '0,100,0',
          'blue': '0,0,100',
          'cyan': '0,100,100',
          'white': '100,100,100',
          'warmwhite': '99,96,90',
          'purple': '50,0,50',
          'magenta': '100,0,100',
          'yellow': '100,100,0',
          'orange': '100,65,0',
          'pink': '100,75,80',
          'oldlace': '99,96,90'}

url = "http://api.thingspeak.com/channels/1417/field/1/last.txt"

last_color = urllib2.urlopen(url).read()
print colors[last_color]
