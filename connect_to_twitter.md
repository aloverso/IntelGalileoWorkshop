How to Connect to Your Own Twitter
==================================

In this workshop, the code comes with a Twitter account set up just for this workshop, and the API Access Tokens have already been set up for you.

But if you want to use the Twitter API with your own Twitter account for future Galileo projects, here's the steps for setting upp Twitter app permissions and finding your API keys:

1. Log on to your Twitter account
2. Go to https://apps.twitter.com/
3. Click Create a New App
4. Make up a descriptive name based on the purpose.
5. Add a short description of what you'll do with the Twitter access
6. Use something official for the website, maybe http://www.insper.edu.br/
7. Agree to the terms and create the app

Now that you have the app set up:

1. Go to the Keys and Access Tokens tab on your app page
2. Make note of your API Key and API Secret
3. Click Get Access Tokens
4. Make note of your Access Token and Access Token Secret

These four strings are necessary to tweet from Python using the Twython package, as shown in the cheerlights_sender.py code.
