# Write a Python program to find the best of two test average marks out of three test marks accepted by the user.

m1 = int(input("Enter marks for test 1: "))
m2 = int(input("Enter marks for test 2: "))
m3 = int(input("Enter marks for test 3: "))
if (m1<=m2 and m1<=m3):
    avgMarks = (m2+m3)/2
elif (m2<=m3 and m2<=m1):
    avgMarks = (m3+m1)/2
else:
    avgMarks = (m1+m2)/2
print("Average of best of two marks is: ", avgMarks)