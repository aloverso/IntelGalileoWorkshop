# Intel Galileo - Insper Workshop
# Python script to send a random color to cheerlights
# Fill in the parts indicated by TODO

import sys
import random
from twython import Twython

import urllib3
urllib3.disable_warnings()

API_KEY = 'T6UThSFsXlZvR0XYF0OwOGhgO'
API_SECRET = 'AUyG7egvxWrp1ElN60nHumVsR8DRPrac9OU8Y9kWILUsMyRPHA'
ACCESS_TOKEN = '1712969251-gLnf5nU5FEGW3ob2kCWVd4r52iWB9GY6NTKtoL4'
ACCESS_TOKEN_SECRET = 'tCvOaKAAe0tumqUADrPJTsQ5hWMbzhnSpo13z2A8b47wm'

api = Twython(API_KEY,API_SECRET,ACCESS_TOKEN,ACCESS_TOKEN_SECRET) 

# TODO: choose a random color from a list of possible color strings

extra_words = ['please', 'thank you', 'now please', 'instead', 'this time', 'for fun', 'thanks', 'very much', 'thank you so much', 'much obliged']
random_word = random.choice(extra_words)

name = "Anne"

# TODO: Replace sys.argv[1] with the appropriate variable for the random color selection

api.update_status(status='@cheerlights %(name)s Galileo wants %(color)s, %(word)s' % {"color": sys.argv[1],"name": name, "word":random_word})