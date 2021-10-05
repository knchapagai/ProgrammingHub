
print(" *** Welcome To The iContacts ***")

myContacts = {}

# creating function, which will check the key value and returns the corressponding value of the searched key value
def keyVal(dict, key):
	if key in dict.keys():
		print(f"Phone number of {key} is : {dict[key]}.\n")
	else:
		print("Not present!")

# if we restart our programme then also we are able to search the contacts
with open("contacts.txt", "r") as file:

	saved_contacts = file.read()

	if(len(saved_contacts)==0):
		saved_contacts = {}
	else:
		# to convert our string into a valid dictionary
		myContacts = eval(saved_contacts)

while True:
	print("What you wanna to do?\n")
	choice = int(input("1. Add contact\n2. Search Contact\n3. To exit the program\n"))

	if(choice==1):
		print("Add a new Contact")
		number = int(input("Enter the Number\n"))
		strNumber = str(number) # typecasting number to string

		if(len(strNumber)<10 or len(strNumber)>10):
			print(" ** Please enter a valid number !\n")
		else:
			name = input("Enter the name of this contact\n")
			myContacts[name] = number
	
			with open("contacts.txt", "w") as f:
				f.write(f"{myContacts}")
			print(" --- Successfully added this contact!\n")

	elif(choice==2):
		print("Search Contact")
		search_name = input("Enter the name of the contact\n")

		try:
			if(search_name in myContacts ):
				keyVal(myContacts, search_name)

			else:
				print("\nSorry, this contact is not in your list!\n")

		except Exception as e:
			print("Your contact list is empty!")
	
	elif(choice==3):
		break
