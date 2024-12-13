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


# Function to shown Menu
def menu():
    print("\n-------------------------MENU-------------------------")
    print("1. Unsorted data search.")
    print("2. Sorted data search.")
    print("5.To EXIT\n")


# Function to show Menu(a).
def menu1():
    print("\n-------------------------MENU-------------------------")
    print("1.Enter roll number of students:")
    print("2.Display roll number of students.")
    print("3.Use linear search to find element.")
    print("4.Use sentinel search to find element.")
    print("5.To EXIT\n")


# Function to show Menu(b).
def menu2():
    print("\n-------------------------MENU-------------------------")
    print("1.Enter roll number of students:")
    print("2.Display roll number of students.")
    print("3.Use Binary search to find element.")
    print("4.Use Fibonacci search to find element.")
    print("5.To EXIT\n")


Roll_No = []
menu()
choice = int(input("\nEnter your choice(from 1 to 3):\n"))
cont = True
if choice == 1:
    menu1()
    while cont:

        choice1 = int(input("\nEnter your choice(from 1 to 5)\nEnter 0 to see MENU: "))

        if choice1 == 1:
            Roll_No = input_roll_no()

        elif choice1 == 2:
            display_roll_no(Roll_No)

        elif choice1 == 3:
            search = int(input("Enter roll number you want to search: "))
            print(linear_search(Roll_No, search))

        elif choice1 == 4:
            search = int(input("Enter roll number you want to search: "))
            print(sentinel_search(Roll_No, search))

        elif choice1 == 5:
            print("\n\nYou terminated the program!!!")
            break

        elif choice1 == 0:
            menu1()
        else:
            print("\nINVALID CHOICE")

elif choice == 2:
    menu2()
    while cont:

        choice2 = int(input("\nEnter your choice(from 1 to 5)\nEnter 0 to see MENU: "))

        if choice2 == 1:
            Roll_No = input_roll_no()

        elif choice2 == 2:
            display_roll_no(Roll_No)

        elif choice2 == 3:
            search = int(input("Enter roll number you want to search: "))
            print("The number you want to find is", end="")
            print(binary_search(Roll_No, search, 0, len(Roll_No) - 1))

        elif choice2 == 4:
            search = int(input("Enter roll number you want to search: "))
            print("The number you want to find is", end="")
            print(fibonacci_search(Roll_No, search))

        elif choice2 == 5:
            print("\n\nYou terminated the program!!!")
            break

        elif choice2 == 0:
            menu2()
        else:
            print("\nINVALID CHOICE")

else:
    print("\n\nYou terminated the program!!!")
# <--------------------------------------- END OF PROGRAM ------------------------------------------------>

# def quicksort(arr):
#     if len(arr) <= 1:
#         return arr
#
#     pivot = arr[len(arr) // 2]
#     left = [x for x in arr if x < pivot]
#     middle = [x for x in arr if x == pivot]
#     right = [x for x in arr if x > pivot]
#
#     return quicksort(left) + middle + quicksort(right)
#
# # Example usage:
# numbers = [3, 6, 8, 10, 1, 2, 1]
# sorted_numbers = quicksort(numbers)
# print("Original list:", numbers)
# print("Sorted list:", sorted_numbers)
