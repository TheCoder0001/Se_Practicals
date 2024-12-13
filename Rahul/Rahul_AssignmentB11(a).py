"""
EXPERIMENT NO. 11(a):
Write a Python program to store roll numbers of student in array who attended training program in random
order. Write function for searching whether particular student attended training program or not, using
Linear Search and Sentinel search.
"""

"""
        Student Name: Rahul Mahendra Patil
        Class: FE-COMP-2
        Semester: 3
        Subject: Data Structures Laboratory
"""


# Function to take input of roll numbers from user.
def input_roll_no():
    roll_no = []
    num = int(input("Enter number of students:"))
    print("\n-------------------------ENTER ROLL NUMBER-------------------------\n")
    for value in range(num):
        roll = int(input("Enter roll number: "))
        roll_no.append(roll)
    return roll_no


# Function to display roll numbers.
def display_roll_no(lst):
    print("\n-------------------------DISPLAY OF ROLL NUMBER-------------------------\n")
    for roll_no in lst[:-1]:
        print(roll_no, end=", ")
    print(lst[-1])


# Function for Linear Search.
def linear_search(lst, srch):
    print("\n-------------------------LINEAR SEARCH-------------------------\n")
    pos = 0
    for roll_no in lst:
        pos += 1
        if roll_no == srch:
            return f"Search found at position {pos}."
    return f"No such roll number present."


# Function for Sentinel Search.
def sentinel_search(lst, srch):
    print("\n-------------------------SENTINEL SEARCH-------------------------\n")
    lst1 = lst
    last = lst1[-1]
    lst1[-1] = srch
    pos = 0
    if last == srch:
        return f"Search found at position {len(lst)}"
    else:
        for roll_no in lst1[:-1]:
            pos += 1
            if roll_no == srch:
                return f"Search found at position {pos}."
        return f"No such roll number present."


# Function to show Menu.
def menu():
    print("\n-------------------------MENU-------------------------")
    print("1.Enter roll number of students:")
    print("2.Display roll number of students.")
    print("3.Use linear search to find element.")
    print("4.Use sentinel search to find element.")
    print("5.To EXIT\n")


Roll_No = []
menu()
cont = True
while cont:

    choice = int(input("\nEnter your choice(from 1 to 5)\nEnter 0 to see MENU: "))

    if choice == 1:
        Roll_No = input_roll_no()

    elif choice == 2:
        display_roll_no(Roll_No)

    elif choice == 3:
        search = int(input("Enter roll number you want to search: "))
        print(linear_search(Roll_No, search))

    elif choice == 4:
        search = int(input("Enter roll number you want to search: "))
        print(sentinel_search(Roll_No, search))

    elif choice == 5:
        break

    elif choice == 0:
        menu()
    else:
        print("INVALID CHOICE")

# <--------------------------------------- END OF PROGRAM ------------------------------------------------>
