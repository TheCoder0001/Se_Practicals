"""
Experiment No. 14:
                    Write a python program to store first year percentage of students in an array.
                    Write function for sorting array of floating point numbers in ascending order using:
                        a) Selection Sort
                        b) Bubble Sort and display top five scores
"""


"""
        Student Name: Rahul Mahendra Patil
        Class: FE-COMP-2
        Semester: 3
        Subject: Data Structures Laboratory
"""


# Function to enter percentage
def enter_percentage():
    percentage = []
    num = int(input("Enter number of students: "))
    print("\n---------------ENTER PERCENTAGE---------------\n")
    for value in range(num):
        perc = float(input("Enter percentage: "))
        percentage.append(perc)

    return percentage


# Function to display percentages
def print_percentage(array):
    print("\n---------------STUDENT PERCENTAGE---------------\n")
    for i in range(len(array)):
        print(f"Marks of student {i+1} : {array[i]}")


# Function for Selection sort
def selection_sort(lst):
    d = 0
    length = len(lst)
    for i in range(length):
        min_index = i
        for j in range(i+1, len(lst)):
            current_index = j
            if lst[min_index] > lst[current_index]:
                min_index = current_index
        (lst[i], lst[min_index]) = (lst[min_index], lst[i])
    return lst


# Function for Bubble sort
def bubble_sort(lst):
    for i in range(1, len(lst)):
        for j in range(len(lst) - i):
            if lst[j] > lst[j+1]:
                (lst[j], lst[j+1]) = (lst[j+1], lst[j])

    return lst


# Function to show Menu
def menu():
    print("\n--------------------MENU--------------------")
    print("1. Enter the Percentage of Students.")
    print("2. Display the Percentages of Students.")
    print("3. Sort percentage of students in ascending order.(Selection sort)")
    print("4. Sort percentage of students in ascending order.(Bubble sort)")
    print("5. Exit\n")


unsort_percentage1 = []
unsort_percentage2 = []
sort_percentage1 = []
sort_percentage2 = []


menu()
cont = True

while cont:

    ch = int(input("\nEnter your choice (from 1 to 4)\nEnter 0 to see MENU: "))

    if ch == 1:
        unsort_percentage1 = enter_percentage()
        unsort_percentage2 = unsort_percentage1

    elif ch == 2:
        print_percentage(unsort_percentage1)

    elif ch == 3:
        print("Percentages of Students after arranging them in ascending order : ")
        sort_percentage1 = selection_sort(unsort_percentage1)
        print(sort_percentage1)

    elif ch == 4:
        print("Percentages of Students after arranging them in ascending order : ")
        sort_percentage2 = bubble_sort(unsort_percentage2)
        print(sort_percentage2)
        if len(sort_percentage2) > 5:
            choice = input("Do you want to display the Top 5 Percentages of Students (yes/no) : ")
            if choice == 'yes':
                for marks in sort_percentage2[:5]:
                    print(f"Marks of student: {marks}")

    elif ch == 5:
        print("Thanks for using this program!!")
        break

    elif ch == 0:
        menu()

    else:
        print("INVALID CHOICE")

# <----------------------------------------END OF PROGRAM------------------------------------------------->
