# Write a Python program that accepts a sentence and find the number
# of words, digits, uppercase letters, and lowercase letters.

user_sentence = input("Enter a sentence: ")

word_count = len(user_sentence.split())
digit_count, uppercase_count, lowercase_count = 0, 0, 0

for char in user_sentence:
    if (char.isdigit()):
        digit_count += 1
    elif (char.isupper()):
        uppercase_count += 1
    elif (char.islower()):
        lowercase_count += 1

print("Word Count: ", word_count)
print("Digit Count: ", digit_count)
print("Uppercase Count: ", uppercase_count)
print("Leowercas Count: ", lowercase_count)