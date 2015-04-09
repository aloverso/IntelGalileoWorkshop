# -*- coding: utf-8 -*
# Intel Galileo - Insper Workshop
# Python script to write current date and time to a text file

from datetime import datetime
 
n=datetime.now()
res=n.strftime("%d/%m/%y %H:%M:%S")
 
#Append time to log file located in home directory of Intel Galileo Gen 2
f=open("/home/root/button_log.txt","a+")
 
f.write(res+"\n")
f.close()
