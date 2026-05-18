#include <iostream>
#include <string>
#include <fstream>
 
#include"BST.h"
using namespace std;

BST appointments; 

void Schedule_an_appointment()
{
	string name, dept;
	int priority;
	cout << "Enter Patient Name :";
	cin.ignore();
	getline(cin, name);
	cout << "\nEnter Piriorty Level :";
	cin >> priority;
	cout << "\nEnter Depertament :";
	cin >> dept;
	appointments.insert(Appointment(name,priority,dept));
	cout << "Appointment scheduled" << endl;
}
void Display_all_appointments()
{
	appointments.displayinorder();
}
void Search_for_an_appointment()
{
	int priority;
	cout << "Enter The Priority Level : ";
	cin >> priority;
	appointments.Search(priority);
}
void Cancel_an_appointment()
{
	int priority;
	cout << "Enter The Priority Level : ";
	cin >> priority;
	appointments.Delete(priority);
}
void Display_more_urgent_than()
{
	int priority;
	cout << "Display More Urent Than : ";
	cin >> priority;
	appointments.displayMoreUrgent(priority);
}
void Display_less_urgent_than()
{
	int priority;
	cout << "Display Less Urent Than : ";
	cin >> priority;
	appointments.displayLessUrgent(priority);
}




int main()
{
	

	ifstream file("input.txt");
	int n;
	file >> n;
	file.ignore();
	for (int i = 0; i < n; i++)
	{
		string name, dept;
		int Priority;

		getline(file, name);     
		file >> Priority;
		file.ignore();           
		getline(file, dept);

		Appointment app(name, Priority, dept);
		appointments.insert(app);
	}
	
	
	
	int choice = -1;
	while (true)
	{
		cout << "1) Schedule an appointment (using BST Class) \n";
		cout << "2) Display all appointments (using BST Class)\n";
		cout << "3) Search for an appointment (using BST Class)\n";
		cout << "4) Cancel an appointment (using BST Class) \n";
		cout << "5) Display more urgent than (using BST Class) \n";
		cout << "6) Display less urgent than (using BST Class) \n";
		cout << "Please Enter Your Choice [1-6]: \n";
		cin >> choice;

		if (!(choice >= 1 && choice <= 6))
		{
			cout << "Invalid Input Please Try Agin\n";
			continue;
		}
		
		if (choice == 1)
			Schedule_an_appointment();
		else if (choice == 2)
			Display_all_appointments();
		else if (choice == 3)
			Search_for_an_appointment();
		else if (choice == 4)
			Cancel_an_appointment();
		else if (choice == 5)
			Display_more_urgent_than();
		else if (choice == 6)
			Display_less_urgent_than();
		else
			break;
	}
	
	
}




