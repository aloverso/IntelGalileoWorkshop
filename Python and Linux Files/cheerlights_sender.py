# Intel Galileo - Insper Workshop
# Python script to send tweets to change cheerlights color

import sys
import random
from twython import Twython

# only uncomment these lines if it does not work
# before uncommenting, you will need to install urllib3
# install it with the command "pip install urllib3"

#import urllib3
#urllib3.disable_warnings()

# API ACCESS TOKENS
API_KEY = 'LyJSQNCHZgdjqONbs280TK1Or'
API_SECRET = 'DdioxOLnhix5KUz81DLTzAKVa1BdiiaisvDVD3mmVX9heeScvE'
ACCESS_TOKEN = '3153951443-H2Kf0iK3qghZx2vfYhfIaBbEVE8bzQ7y8JN98LR'
ACCESS_TOKEN_SECRET = 'UyKFksP9RkBm3MNExAWO30Y2ctb23lXKxshkAbhJSewMM'

api = Twython(API_KEY,API_SECRET,ACCESS_TOKEN,ACCESS_TOKEN_SECRET) 

extra_words = ['please', 'thank you', 'now please', 'instead', 'this time', 'for fun', 'thanks', 'very much', 'thank you so much', 'much obliged']
random_word = random.choice(extra_words)

name = "Anne"

api.update_status(status='@cheerlights %(name)s Galileo wants %(color)s, %(word)s' % {"color": sys.argv[1],"name": name, "word":random_word})