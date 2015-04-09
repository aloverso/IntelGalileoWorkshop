# Intel Galileo - Insper Workshop
# Cheerlights Display Code

import urllib2

url = "http://api.thingspeak.com/channels/1417/field/1/last.txt"

while 1:
 	last_color = urllib2.urlopen(url).read()
 	print "Latest color: " + last_color
