#include <iostream>
#include <string>
#include <cstdlib>  // For the system function
const int MAX_STUDENTS = 100;
int studentCount = 0;
using namespace std;

class Person {
	
	public:
	    int id;
	    string name;
	    string gender;
	    
}; 

class Student : public Person {
	
	public:
		
	    string studentClass;
	    string section;
	    float fee;
	    
};

Student students[MAX_STUDENTS];

class Management : public Person {
public:
	    
	void printBorder() {
	    cout << "+--------------------------------------------------+\n";
	}
		
	void program_name(){
		
		printBorder();
	    cout << "|                School Management System          |\n";
	    printBorder();
	    	
	}
	
	void printMenu() {
		
		program_name();
		cout<<endl; 
		printBorder(); 
		cout << "|                       HOME                       |\n";
	    	printBorder();
		
		cout << "| Select An Operation to Perform with Data:        |\n";
	    cout << "| 1. Add                                           |\n";
	    cout << "| 2. Read                                          |\n";
	    cout << "| 3. Edit                                          |\n";
	    cout << "| 4. Delete                                        |\n";
	    cout << "| 5. Search                                        |\n";
	   
	    printBorder();
		cout << "| 6. Exit Program                                  |\n";
		printBorder();
		cout<<endl; 
		
	}
	
	void addData() {
		
		system("cls"); 
		program_name(); 
		
		cout<<endl; 
			printBorder(); 
		cout << "|                   Adding Data                    |\n";
	    	printBorder();
	    	
	    if (studentCount >= MAX_STUDENTS) {
	    	
	        cout << "Array is full. Cannot add more students.\n";
	        return;
	        
	    }
	    
	    int id;
	    cout << "Enter Student ID: ";
	    
		cin >> id;
	    for (int i = 0; i < studentCount; ++i) {
	        
			if (students[i].id == id) {
	            cout << "Data with this ID already exists.\n";
	            return;
	        }
	    }
	    
		students[studentCount].id = id;
		cout << "Enter Name: ";
		cin.ignore(50, '\n');
		getline(cin, students[studentCount].name);
	    cout << "Enter Class: ";
	    cin >> students[studentCount].studentClass;
	    cout << "Enter Section: ";
	    cin >> students[studentCount].section;
	    cout << "Enter Fee(Integers): ";
	    cin >> students[studentCount].fee;
	    cout << "Enter Gender: ";
	    cin >> students[studentCount].gender;
	    studentCount++;
	    cout << "Student added successfully.\n";
	    
	}
	
	void readData() {
		
		system("cls");
		program_name(); 
			cout<<endl; 
			printBorder(); 
		cout << "|                   Reading Data                    |\n";
	    	printBorder();
	    printBorder();
	    for (int i = 0; i < studentCount; ++i) {
	        cout << "| ID: " << students[i].id << " | Name: " << students[i].name 
	             << " | Class: " << students[i].studentClass << " | Section: " << students[i].section
	             << " | Fee: " << students[i].fee << " | Gender: " << students[i].gender << " |\n";
	   
	    }
	    
	    printBorder();
	    
	}
	
	void updateData() {
		
		system("cls");
		program_name(); 
			cout<<endl; 
			printBorder(); 
		cout << "|                   Updating Data                    |\n";
	    	printBorder();
	    int id;
	    cout << "Enter ID to update: ";
	    cin >> id;
	    for (int i = 0; i < studentCount; ++i) {
	        if (students[i].id == id) {
	            cout << "Enter new Name: ";
	            cin.ignore(50, '\n');
					getline(cin, students[studentCount].name);
	            cout << "Enter new Class: ";
	            cin >> students[i].studentClass;
	            cout << "Enter new Section: ";
	            cin >> students[i].section;
	            cout << "Enter new Fee: ";
	            cin >> students[i].fee;
	            cout << "Enter new Gender: ";
	            cin >> students[i].gender;
	            cout << "Data updated successfully.\n";
	            return;
	        }
	    }
	    
	    cout << "No data found with the given ID.\n";
	    
	}
	
	
	void deleteData() {
		
		system("cls");
		program_name(); 
		
			cout<<endl; 
			printBorder(); 
		cout << "|                  Deleting Data                   |\n";
	    	printBorder();
	    	
		cout << "Stored Data: " << endl; 
		readData(); 
		
	    int id;
	    cout << "Enter ID to delete: ";
	    cin >> id;
	    
	    bool found = false;
	    
	    for (int i = 0; i < studentCount; ++i) {
	        
			if (students[i].id == id) {
	            
				for (int j = i; j < studentCount - 1; ++j) {
					
	                students[j] = students[j + 1];
	                
	            }
	            
	            studentCount--;
	            found = true;
	            cout << "Data deleted successfully.\n";
	            break;
	        }
	    }
	    
	    if (!found) {
	        cout << "No data found with the given ID.\n";
	    }
	    
	}
	
	void searchData() {
		
		system("cls");
		program_name(); 
			cout<<endl; 
			printBorder(); 
		cout << "|                 Searching Data                   |\n";
	    	printBorder();
	    	
	    int choice;
	    cout << "Search by: 1. ID 2. Name\n";
	    cin >> choice;
	    
	    if (choice == 1) {
	        int id;
	        cout << "Enter ID to search: ";
	        cin >> id;
	        
	        bool found = false;
	        
	        for (int i = 0; i < studentCount; ++i) {
	        	
	            if (students[i].id == id) {
	                cout << "ID: " << students[i].id << " | Name: " << students[i].name 
	                     << " | Class: " << students[i].studentClass << " | Section: " << students[i].section
	                     << " | Fee: " << students[i].fee << " | Gender: " << students[i].gender << "\n";
	                found = true;
	                break;
	            }
	            
	        }
	        
	        if (!found) {
	            cout << "No data found with the given ID.\n";
	        }
	    } 
			
			else if (choice == 2) {
	    	
	        string name;
	        cout << "Enter Name to search: ";
	        	cin.ignore(50, '\n');
				getline(cin, students[studentCount].name);
				
	        bool found = false;
	        
	        for (int i = 0; i < studentCount; ++i) {
	        	
	            if (students[i].name == name) {
	               
				    cout << "ID: " << students[i].id << " | Name: " << students[i].name 
	                     << " | Class: " << students[i].studentClass << " | Section: " << students[i].section
	                     << " | Fee: " << students[i].fee << " | Gender: " << students[i].gender << "\n";
	                found = true;
	                break;
	                
	            }
	        }
	        if (!found) {
	        	
	            cout << "No data found with the given name.\n";
	            
	        }
	    } 
		else {
			
	        cout << "Invalid choice.\n";
	        
	    }
	}
};


int main() {
	
    int choice;
    Management management; 
    while (true) {
    	
		management.printMenu(); 
        cin >> choice;
        
        switch (choice) {
        	
            case 1: management.addData(); break;
            case 2: management.readData(); break;
            case 3: management.updateData(); break;
            case 4: management.deleteData(); break;
            case 5: management.searchData(); break;
            case 6: cout << "Exiting program...\n"; return 0;
            default: cout << "Invalid choice. Please try again.\n";
            
        }
    }
    
    return 0;
    
}