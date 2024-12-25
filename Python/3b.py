# Write a Python program to find the string similarity between two
# given strings.

str1 = input("Enter the string1: ")
str2 = input("Enter the string2: ")

if (len(str1) < len(str2)):
    short = len(str1)
    long = len(str2)
else:
    short = len(str2)
    long = len(str1)

matchCount = 0
for i in range (short):
    if (str1[i] == str2[i]):
        matchCount += 1
print("Similarity between two strings: ", matchCount/long)