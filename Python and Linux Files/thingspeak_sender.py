# Intel Galileo - Insper Workshop
# Python script to publish data to Thingspeak channel

import httplib, urllib
import sys

API_KEY = 'YOUR API KEY HERE'

voltage = float(sys.argv[1])

print "Updating Thingspeak with:", voltage
params = urllib.urlencode({'field1':voltage,'key':API_KEY})
headers = {"Content-type": "application/x-www-form-urlencoded","Accept": "text/plain"}
conn = httplib.HTTPConnection("api.thingspeak.com:80")
conn.request("POST", "/update", params, headers)
ts_response = conn.getresponse()
print "Thingspeak Response:", ts_response.status, ts_response.reason
conn.close