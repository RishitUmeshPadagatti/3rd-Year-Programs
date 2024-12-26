# Program to generate a Random Password

import random
import string

def generate_password(length):
    characters = string.ascii_letters + string.digits + string.punctuation
    password = "".join(random.choice(characters) for i in range(length))
    return password

password_length = 12
random_password = generate_password(password_length)
print("Random Password: ", random_password)