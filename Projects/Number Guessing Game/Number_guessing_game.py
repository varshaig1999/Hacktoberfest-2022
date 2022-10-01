import random

random_number = random.randint(1,100)
print(random_number)
tries = 0
guess=0

name = input("Hello, What's your Name")

print("HELLO", name.upper(),"!")

question = input("Would you Like To Play A Game ? [Y/N] ").lower()

if question == "n":
    print("oh..okay")

if question == "y":
    print("I'm Thinking Of A Number Between 1 & 100")
    while guess != random_number:
        guess = int(input("Have a Guess :"))
        tries+=1
        if guess > random_number:
            print("Guess Lower...")
        elif guess < random_number:
            print("Guess Higher...")
        elif guess==random_number:
            print("You're Right! you win! The Number Was", random_number, "and you only took", tries, "tries to guess it")
        
