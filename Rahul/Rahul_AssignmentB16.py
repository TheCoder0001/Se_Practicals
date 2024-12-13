"""
Experiment No. 16 :
Write a python program to store first year percentage of students in array.Write function for
sorting array of floating point numbers in ascending order using quick sort and display top five scores.
"""

"""
        Student Name: Rahul Mahendra Patil
        Class: FE-COMP-2
        Semester: 3
        Subject: Data Structures Laboratory
"""


# Function to enter percentage.
def enter_percentage():
    percentage = []
    num = int(input("Enter number of students: "))
    print("\n---------------ENTER PERCENTAGE---------------\n")
    for value in range(num):
        perc = float(input("Enter percentage: "))
        percentage.append(perc)

    return percentage


# Function to display percentage.
def print_percentage(array):
    print("\n---------------STUDENT PERCENTAGE---------------\n")
    for j in range(len(array)):
        print(f"Marks of student {j+1} : {array[j]}")


# Function for data partition.
def partition(array, low, high):
    # choose the rightmost element as pivot
    pivot = array[high]

    # pointer for greater element
    i = low - 1

    # traverse through all elements
    # compare each element with pivot
    for j in range(low, high):
        if array[j] <= pivot:

            # If element smaller than pivot is found
            # swap it with the greater element pointed by i
            i = i + 1

            # Swapping element at i with element at j
            (array[i], array[j]) = (array[j], array[i])

    # Swap the pivot element with the greater element specified by i
    (array[i + 1], array[high]) = (array[high], array[i + 1])

    # Return the position from where partition is done
    return i + 1


# Function to perform quicksort
def quicksort(array, low, high):
    if low < high:

        # Find pivot element such that
        # element smaller than pivot are on the left
        # element greater than pivot are on the right
        pi = partition(array, low, high)

        # Recursive call on the left of pivot
        quicksort(array, low, pi - 1)

        # Recursive call on the right of pivot
        quicksort(array, pi + 1, high)

    return array


# Function to show Menu.
def menu():
    print("\n--------------------MENU--------------------")
    print("1. Enter the Percentage of Students.")
    print("2. Display the Percentages of Students.")
    print("3. Sort percentage of students in ascending order.")
    print("4. Exit")


unsort_percentage = []
sort_percentage = []

menu()
cont = 1

while cont == 1:

    ch = int(input("Enter your choice (from 1 to 4)\nEnter 0 to see MENU: "))

    if ch == 1:
        unsort_percentage = enter_percentage()

    elif ch == 2:
        print_percentage(unsort_percentage)

    elif ch == 3:
        print("Percentages of Students after arranging them in ascending order : ")
        sort_percentage = quicksort(unsort_percentage, 0, len(unsort_percentage)-1)
        print_percentage(sort_percentage)
        if len(sort_percentage) > 5:
            choice = input("Do you want to display the Top 5 Percentages of Students (Y/N) : ")
            if choice == "Y":
                start = len(sort_percentage)-1
                end = len(sort_percentage) - 6
                # for i in range(start, end, -1):
                #     print(f"Marks of student {i}: {sort_percentage[i]}")
                print(sort_percentage[start:end:-1])

    elif ch == 4:
        print("Thanks for using this program!!")
        break

    elif ch == 0:
        menu()

    else:
        print("INVALID CHOICE!!!")

# <----------------------------------------END OF PROGRAM------------------------------------------------->
