"""
Experiment Number 5 :
Write a python program to compute following operations on String:
                    a) To display word with the longest length.
                    b) To determine the frequency of occurrence of a particular character in the string.
                    c) To check whether given string is palindrome or not.
                    d) To display index of first appearance of substring.
                    e) To count occurrences of each word in a given string.
"""


"""
        Student Name: Rahul Mahendra Patil
        Class: FE-COMP-2
        Semester: 3
        Subject: Data Structures Laboratory
"""


# Function to display word with the longest length from string.
def longest(string):
    empty = {}

    string += " "

    substring = ""
    count = 0
    for letter in string:
        if letter == " ":
            empty[count] = substring
            substring = ""
            count = 0
        else:
            substring += letter
            count += 1

    maxvalue = 0
    for value in empty.keys():
        if value > maxvalue:
            maxvalue = value

    return f"Word with longest length is {empty[maxvalue]}"


# Function to find frequency of occurrence of a particular character from string.
def frq(char_actor, string):
    freq = 0
    for letter in string:
        if letter == char_actor:
            freq += 1

    return f"Frequency of character {char_actor} is {freq}"


# Function to check if given string is palindrome or not.
def palindrome(string):
    r_string = ""
    for letter in string:
        r_string = letter + r_string

    if string == r_string:
        return "It is a Palindrome."
    else:
        return "It is not a Palindrome."


# Function to display index of first appearance of substring.
def firstapp(substring, string):
    try:
        string.index(substring)
    except ValueError:
        return "Does not exist"
    else:
        return f"First appearance of substring {substring} is at index {string.index(substring)}"


# Function to count occurrences of each word in a given string.
def occur_word(string):
    frequency = {}
    word = ""
    string += " "
    for letter in string:
        if letter == " ":
            if word in frequency:
                frequency[word] += 1
            else:
                frequency[word] = 1
            word = ""
        else:
            word += letter
    return f"Occurrence of each letter is {frequency}."


# Function to display menu.
def menu():
    print("\n<--------------------------- MENU --------------------------->")
    print("1. Enter the string.\n"
          "2. Display word with longest length.\n"
          "3. Frequency of occurrence of a particular character.\n"
          "4. Check if given string is palindrome or not.\n"
          "5. Display index of first appearance of substring.\n"
          "6. Count occurrences of each word in a given string.")
    print("7. EXIT\n")


menu()
check = True
sting = ""


while check:
    choice = int(input("\nWhat do you want to perform? (Enter value from 1 to 7)\nEnter 0 to see MENU: "))

    if choice == 1:
        sting = input("Enter your string: ")

    elif choice == 2:
        print(longest(sting))

    elif choice == 3:
        character = input("Enter the character to be found: ")
        print(frq(character, sting))

    elif choice == 4:
        print(palindrome(sting))

    elif choice == 5:
        sub_str = input("Enter the substring to be found: ")
        print(firstapp(sub_str, sting))

    elif choice == 6:
        print(occur_word(sting))

    elif choice == 0:
        menu()

    else:
        break


# <---------------------------------------------END OF PROGRAM--------------------------------------->
