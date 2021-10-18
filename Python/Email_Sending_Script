import smtplib, ssl

port = 587  # For starttls
smtp_server = "smtp.gmail.com"
sender_email = input("Enter Your Email : ")
receiver_email = input("Enter reciever email : ")
password = input("Type your password and press enter:")
content = input("Enter the body of the mail : ")
message = f'"""\
Subject: Hi there
{content}
This message is sent from Python."""'

context = ssl.create_default_context()
with smtplib.SMTP(smtp_server, port) as server:
    server.ehlo()  # Can be omitted
    server.starttls(context=context)
    server.ehlo()  # Can be omitted
    server.login(sender_email, password)
    server.sendmail(sender_email, receiver_email, message)
