"""
Experiment Number 2 :
Write a python program to store marks stored in subject "Fundamentals of Data Structure" by N
students in the class. Write functions to compute following:
						1. The average score of the class.
						2. Highest score and lowest score of the class.
						3. Count of students who were absent for the test.
						4. Display marks with the highest frequency.
"""

"""
		Student Name: Rahul Mahendra Patil
		Class: FE-COMP-2
		Semester: 3
		Subject: Data Structures Laboratory
"""


# Function for average score of the class
def avg(lst):
	total_marks = 0
	appeared = 0
	for marks in lst:
		if marks != "A":
			total_marks += marks
			appeared += 1

	avg_marks = total_marks/appeared
	return avg_marks


# Function for Highest score in the test for the class
def highest(lst):
	mx = 0
	for marks in lst:
		if marks == "A":
			continue
		elif marks > mx:
			mx = marks

	roll_no = lst.index(mx) + 1
	return f"Highest score is {mx} by roll number {roll_no}"


# Function for Lowest score in the test for the class
def lowest(lst):
	mn = 100
	for marks in lst:
		if marks != "A":
			if marks < mn:
				mn = marks

	roll_no = lst.index(mn) + 1
	return f"Lowest score is {mn} by roll number {roll_no}"


# Function for counting the number of students absent for the test
def abst(lst):
	absent = 0
	for marks in lst:
		if marks == "A":
			absent += 1

	return f"Number of students absent are {absent}"


# Function for displaying marks with the highest frequency
def high_frq(lst):
	frequency = {}
	high = 0
	for item in lst:
		if item != "A":	
			if item in frequency:
				frequency[item] += 1
			else:
				frequency[item] = 1

	for value in frequency.values():
		if value > high:
			high = value

	if high == 1:
		return f"Frequency of marks is {frequency}."
	else:
		marks = [k for k, v in frequency.items() if v == high]
		return f"{marks} is the score with highest frequency of {high}"


# Function to create list of students for test
def create_list():
	list_of_marks = []
	strength = int(input("Enter number of students who appeared for FDS test: "))

	for i in range(strength):
		marks = (input(f"Enter marks of student no. {i+1}: "))
		if marks != "A":
			list_of_marks.append(int(marks))
		else:
			list_of_marks.append(marks)

	return list_of_marks


# Function to show Menu
def menu():
	print("\n<--------------------------- MENU --------------------------->")
	print("1. Avg score of class.\n2. Highest and lowest score of class.\n3. Number of absent students.")
	print("4. Score with highest frequency.\n5. To Exit\n")


list_marks = create_list()
menu()
check = True


while check:
	choice = int(input("\nWhat do you want to check? (Enter value from 1 to 5)\nEnter 0 to see MENU: "))

	if choice == 1:
		print(f"Average score of class is {avg(list_marks)}.")

	elif choice == 2:
		print(f"{highest(list_marks)}\n{lowest(list_marks)}")

	elif choice == 3:
		print(abst(list_marks))

	elif choice == 4:
		print(high_frq(list_marks))

	elif choice == 0:
		menu()

	else:
		check = False

# <---------------------------------------------END OF PROGRAM--------------------------------------->
