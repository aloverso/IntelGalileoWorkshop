# Intel Galileo - Insper Workshop
# Python script to send email

import smtplib

from_address = 'engenhariainsper@gmail.com'
password = 'insper2015'

to_address  = 'aelv13@gmail.com'

body = 'YOUR MESSAGE HERE'

# The actual mail send
server = smtplib.SMTP('smtp.gmail.com', 587)
server.starttls()
server.login(from_address,password)
server.sendmail(from_address, to_address, body)
server.quit()