#!usr/bin/env python3

# Author observations 
# Requires a .env file in the same directory with this application with your telegram bot token that you can acquire
# the token using the bot father, the format required is TELEGRAM_TOKEN=token_goes_here 
# Is also required the python requirements.txt file with the libs PyTelegramBotAPI==2.2.3 and python-telegram-bot


import os
from telegram.ext import Updater, CommandHandler

# This is the method structure for commands. When a person uses the command start that you can
# config in bot father, the follwing method wil be called 
def start_bot(update):
  message_people = 'Hi {}, \n Welcome to my bot.'.format(update.message.from_user.first_name)
  update.message.reply_text(message_people)

# In the main you have the updater to get what's going on you bot chat
# and you can always check the documentation of telegram.ext lib to see the options that you can use.
# In the add_handler you can use it as a model to create new commands and to put the method that will be called.   
def main():
    updater = Updater(os.getenv('TELEGRAM_TOKEN'), use_context=True)
    dp = updater.dispatcher
    dp.add_handler(CommandHandler('start', start_bot))
    updater.start_polling()
    updater.idle()

if __name__ == '__main__':
    main()
