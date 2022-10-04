# Contributed by - RajatRathore123-github
# Date - 4-10-2022

# Ask user if they want to generate a password or not
# If yes , ask for password length
# Generate password
# Print password
# If initial response is no , exit program

import string
import random

characters = list(string.ascii_letters + string.digits + "@#$%&*")
def generate_password():
    password_length = int(input("How long would you like your password to be? "))

    random.shuffle(characters)

    password = []

    for x in range(password_length):
        password.append(random.choice(characters))

    random.shuffle(password)

    password = "".join(password) 

    print(password) 

option = input("Do you want to generate the password? (Yes/No): ")

if option == "Yes":
    generate_password()
else:
    print("Program ended")
      
