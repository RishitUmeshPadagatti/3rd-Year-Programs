# Develop a python program to convert binary to decimal, octal to
# hexadecimal using functions.

def binaryToDecimal(binary):
    power = 0
    decimal = 0
    while (binary != 0):
        last_digit = binary % 10
        decimal += last_digit * (2 ** power)
        power += 1
        binary = binary // 10
    return decimal

def octalToHexadecimal(octal):
    power = 0
    decimal = 0
    while (octal != 0):
        last_digit = octal % 10
        decimal += last_digit * (8 ** power)
        power += 1
        octal = octal // 10
    
    hexadecimal = ""
    hex = "0123456789ABCDEF"
    while(decimal != 0):
        remainder = decimal % 16
        hexadecimal = hex[remainder] + hexadecimal
        decimal = decimal // 16
    return hexadecimal

binary = int(input("Enter the binary number: "))
print("Decimal Equivalent: ", binaryToDecimal(binary))

octal = int(input("Enter the octal number: "))
print("Hexadecimal Equivalent: ", octalToHexadecimal(octal))