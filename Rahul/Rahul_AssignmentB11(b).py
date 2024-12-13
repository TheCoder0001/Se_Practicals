
"""
        Student Name: Rahul Mahendra Patil
        Class: FE-COMP-2
        Semester: 3
        Subject: Data Structures Laboratory
"""


# Function to take input of roll numbers from user.
def input_roll_no():
    roll_no = []
    num = int(input("Enter number of students: "))
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


# Function to perform Fibonacci search.
def binary_search(array, x, low, high):
    lst = array
    while low <= high:
        mid = low + (high - low)//2
        if lst[mid] == x:
            return f" found at position {mid + 1}."
        elif lst[mid] < x:
            low = mid + 1
        else:
            high = mid - 1

    return f" nowhere to be found."


# Function to perform Fibonacci search.
def fibonacci_search(lst, target):
    size = len(lst)

    start = -1

    f0 = 0
    f1 = 1
    f2 = 1
    while f2 < size:
        f0 = f1
        f1 = f2
        f2 = f1 + f0

    while f2 > 1:
        index = min(start + f0, size - 1)
        if lst[index] < target:
            f2 = f1
            f1 = f0
            f0 = f2 - f1
            start = index
        elif lst[index] > target:
            f2 = f0
            f1 = f1 - f0
            f0 = f2 - f1
        else:
            return f" found at position {index + 1}"
    if f1 and (lst[size - 1] == target):
        return f" found at position {size}"
    return f" nowhere to be found."


# Function to show Menu.
def menu():
    print("\n-------------------------MENU-------------------------")
    print("1.Enter roll number of students:")
    print("2.Display roll number of students.")
    print("3.Use Binary search to find element.")
    print("4.Use Fibonacci search to find element.")
    print("5.To EXIT\n")


Roll_No = []
Roll_No_duplicate = []
menu()
cont = True
while cont:

    choice = int(input("\nEnter your choice(from 1 to 5)\nEnter 0 to see MENU: "))

    if choice == 1:
        Roll_No = input_roll_no()
        Roll_No_duplicate = Roll_No

    elif choice == 2:
        display_roll_no(Roll_No_duplicate)

    elif choice == 3:
        search = int(input("Enter roll number you want to search: "))
        print("The number you want to find is", end="")
        print(binary_search(Roll_No, search, 0, len(Roll_No) - 1))

    elif choice == 4:
        search = int(input("Enter roll number you want to search: "))
        print("The number you want to find is", end="")
        print(fibonacci_search(Roll_No, search))

    elif choice == 5:
        break

    elif choice == 0:
        menu()
    else:
        print("INVALID CHOICE")

# <--------------------------------------- END OF PROGRAM ------------------------------------------------>
