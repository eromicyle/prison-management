#include <iostream>
#include <string>
#include <sstream> 
using namespace std;

class Person {
protected:
    string name;
    int age;
    string gender;
    string CNIC;
public:
    Person(string a, int b, string c, string d) {
        name = a;
        age = b;
        gender = c;
        CNIC = d;
    }
    void displayPersonInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Identification number: " << CNIC << endl;
        cout << endl;
    }
};

class Prisoner : public Person {
    string crimeType;
    int sentenceInput;
    int cellNumber;
    int admissionYear;
public:
    string prisonerId;

    Prisoner() : Person("", 0, "", ""), prisonerId(""), crimeType(""), sentenceInput(0), cellNumber(-1), admissionYear(0) {}

    Prisoner(string a, int b, string c, string d, string e, string f, int g, int h, int i)
        : Person(a, b, c, d), prisonerId(e), crimeType(f), sentenceInput(g), cellNumber(h), admissionYear(i) {}

    int calculateReleaseYear() {
        if (sentenceInput == -1) {
        	cout << "This prisoner is serving a life sentence.\n";
        	return -1;
    	}
    	return admissionYear + sentenceInput;
    }

    void updateRecord(int newYears) {
        sentenceInput = newYears;
    }

    int getCellNumber() {
        return cellNumber;
    }

    void assignCell(int cellNum) {
        cellNumber = cellNum;
    }

    void releaseFromCell() {
        cellNumber = -1;
        cout << "Prisoner ID " << prisonerId << " released from cell.\n";
    }

    void displayPrisonerInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Identification number: " << CNIC << endl;
        cout << "Prisoner ID: " << prisonerId << endl;
        cout << "Crime Type: " << crimeType << endl;
        cout << "Sentence year: ";
		if (sentenceInput == -1)
			cout << "Life Sentence" << endl;
		else
    		cout << sentenceInput << endl;
        cout << "Cell Number: " << cellNumber << endl;
        cout << "Admission year: " << admissionYear << endl;
        cout << endl;
    }
};

class Staff : public Person {
    string staffId;
    string designation;
    string dutyshift;
public:
    Staff() : Person("", 0, "", ""), staffId(""), designation(""), dutyshift("") {}

    Staff(string a, int b, string c, string d, string e, string f, string g)
        : Person(a, b, c, d), staffId(e), designation(f), dutyshift(g) {}

    void assignDuty(string duty) {
        designation = duty;
    }

    void updateInfo(string newdesignation) {
        designation = newdesignation;
    }

    void displayStaffInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Identification number: " << CNIC << endl;
        cout << "Staff ID: " << staffId << endl;
        cout << "Designation: " << designation << endl;
        cout << "Shift: " << dutyshift << endl;
        cout << endl;
    }
};

class Cell {
    int cellNumber;
    string occupied;
    int capacity;
    string securityLevel;
public:
    Cell() : cellNumber(0), occupied("No"), capacity(0), securityLevel("") {}

    Cell(int a, string f, int c, string d) {
        cellNumber = a;
        occupied = f;
        capacity = c;
        securityLevel = d;
    }

    void assignPrisoner(string prisonerId) {
        if (occupied == "No" || occupied == "no") {
            occupied = "Yes";
            cout << "Prisoner ID " << prisonerId << " assigned to Cell #" << cellNumber << endl;
        }
        else {
            cout << "Cell #" << cellNumber << " is already occupied." << endl;
        }
    }

    void releasePrisoner() {
        if (occupied == "Yes" || occupied == "yes") {
            occupied = "No";
            cout << "Cell #" << cellNumber << " is now available.\n";
        }
        else {
            cout << "Cell #" << cellNumber << " is already empty.\n";
        }
    }

    int getCellNumber() { return cellNumber; }
    bool isOccupied() { return occupied == "Yes"; }
};


int main() {
    const int MAX = 100;

    Prisoner prisoners[MAX];
    int prisonerCount = 0;

    Staff staffMembers[MAX];
    int staffCount = 0;

    Cell cells[MAX];
    int cellCount = 0;

    int choice;
    bool running = true;
    int f = 1234;
    int d = 0;
    cout << "\nEnter the password to login to the system (you only got one try)" << endl;
    
    cin >> d;
    if (d == f) {
        cout << "Welcome" << endl;
        while (running) {
            cout << "\n\t\t\t Prison Management System \n";
            cout << "-----------------------------------------------------------------------------------" << endl;
            cout << "1. Add Prisoner\n";
            cout << "2. Add Staff\n";
            cout << "3. Add Cell\n";
            cout << "4. Assign Prisoner to Cell\n";
            cout << "5. Release Prisoner from Cell\n";
            cout << "6. Display All Prisoners\n";
            cout << "7. Display All Staff\n";
            cout << "8. Find Release Year of Prisoner\n";
            cout << "9. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;
            cout << endl;

            switch (choice) {
            case 1:
                if (prisonerCount >= MAX) {
                    cout << "Max prisoners reached.\n";
                    break;
                }
                {
                    string name, gender, crimeType;
                    int age, admissionYear, sentenceYears;
                    string cnic, prisonerId;
                    cout << "Enter prisoner details:\n";
                    cout << "Name: "; cin >> ws; getline(cin, name);
                    cout << "Age: "; cin >> age;
                    cout << "Gender: "; cin >> ws; getline(cin, gender);
                    cout << "CNIC: "; cin >> ws; getline(cin, cnic);
                    cout << "Prisoner ID: "; cin >> ws; getline(cin, prisonerId);
                    cout << "Crime Type: "; cin >> ws; getline(cin, crimeType);
                    string sentenceInput;
					cout << "Sentence Years (or type 'life'): ";
					cin >> ws;
					getline(cin, sentenceInput);

					if (sentenceInput == "life" || sentenceInput == "Life") {
    					sentenceYears = -1;  // special flag for life sentence
					} else {
    					stringstream ss(sentenceInput);
    					ss >> sentenceYears;
    				if (ss.fail()) {
        				cout << "Invalid sentence input. Setting sentence to 0.\n";
        				sentenceYears = 0;
    				}
					}
                    cout << "Admission Year: "; cin >> admissionYear;
                    

                    prisoners[prisonerCount++] = Prisoner(name, age, gender, cnic, prisonerId, crimeType, sentenceYears, -1, admissionYear);
                    cout << "Prisoner added.\n";
                }
                break;

            case 2:
                if (staffCount >= MAX) {
                    cout << "Max staff reached.\n";
                    break;
                }
                {
                    string name, gender, designation, shift;
                    int age;
                    string cnic, staffId;
                    cout << "Enter staff details:\n";
                    cout << "Name: "; cin >> ws; getline(cin, name);
                    cout << "Age: "; cin >> age;
                    cout << "Gender: "; cin >> ws; getline(cin, gender);
                    cout << "CNIC: "; cin >> ws; getline(cin, cnic);
                    cout << "Staff ID: "; cin >> ws; getline(cin, staffId);
                    cout << "Designation: "; cin >> ws; getline(cin, designation);
                    cout << "Duty Shift: "; cin >> ws; getline(cin, shift);

                    staffMembers[staffCount++] = Staff(name, age, gender, cnic, staffId, designation, shift);
                    cout << "Staff added.\n";
                }
                break;

            case 3:
                if (cellCount >= MAX) {
                    cout << "Max cells reached.\n";
                    break;
                }
                {
                    int cellNumber, capacity;
                    string level, occupied = "No";
                    cout << "Enter cell details:\n";
                    cout << "Cell Number: "; cin >> cellNumber;
                    cout << "Capacity: "; cin >> capacity;
                    cout << "Security Level: "; cin >> ws; getline(cin, level);

                    cells[cellCount++] = Cell(cellNumber, occupied, capacity, level);
                    cout << "Cell added.\n";
                }
                break;

            case 4: {
                if (prisonerCount == 0) {
                    cout << "No prisoners to assign.\n";
                    break;
                }
                string pid;
                int cellNum;
                cout << "Enter prisoner ID to assign: "; cin >> ws; getline(cin, pid);
                cout << "Enter cell number: "; cin >> cellNum;

                int pIndex = -1, cIndex = -1;

                for (int i = 0; i < prisonerCount; ++i) {
                    if (prisoners[i].prisonerId == pid) {
                        pIndex = i;
                        break;
                    }
                }
                if (pIndex == -1) {
                    cout << "Prisoner not found.\n";
                    break;
                }

                for (int i = 0; i < cellCount; ++i) {
                    if (cells[i].getCellNumber() == cellNum) {
                        cIndex = i;
                        break;
                    }
                }

                if (cIndex == -1) {
                    if (cellCount >= MAX) {
                        cout << "Cannot create new cell, max limit reached.\n";
                        break;
                    }
                    int defaultCapacity = 1;
                    string defaultSecurityLevel = "Medium";
                    cells[cellCount++] = Cell(cellNum, "No", defaultCapacity, defaultSecurityLevel);
                    cIndex = cellCount - 1;
                    cout << "Created new cell #" << cellNum << " with capacity " << defaultCapacity
                        << " and security level " << defaultSecurityLevel << ".\n";
                }

                if (cells[cIndex].isOccupied()) {
                    cout << "Cell #" << cellNum << " is already occupied.\n";
                }
                else {
                    cells[cIndex].assignPrisoner(pid);
                    prisoners[pIndex].assignCell(cellNum);
                    cout << "Prisoner assigned successfully.\n";
                }
                break;
            }

            case 5: {
                if (prisonerCount == 0 || cellCount == 0) {
                    cout << "No prisoners or cells to release.\n";
                    break;
                }
                string pid;
                cout << "Enter prisoner ID to release: "; cin >> ws; getline(cin, pid);
                int pIndex = -1;
                for (int i = 0; i < prisonerCount; ++i) {
                    if (prisoners[i].prisonerId == pid) {
                        pIndex = i;
                        break;
                    }
                }
                if (pIndex == -1) {
                    cout << "Prisoner not found.\n";
                    break;
                }
                int assignedCell = prisoners[pIndex].getCellNumber();
                int cIndex = -1;
                for (int i = 0; i < cellCount; ++i) {
                    if (cells[i].getCellNumber() == assignedCell) {
                        cIndex = i;
                        break;
                    }
                }
                if (cIndex != -1) cells[cIndex].releasePrisoner();
                prisoners[pIndex].releaseFromCell();
                break;
            }

            case 6:
                if (prisonerCount == 0) {
                    cout << "No prisoners to display.\n";
                }
                else {
                    for (int i = 0; i < prisonerCount; ++i) {
                        prisoners[i].displayPrisonerInfo();
                        cout << "------------------\n";
                    }
                }
                break;

            case 7:
                if (staffCount == 0) {
                    cout << "No staff to display.\n";
                }
                else {
                    for (int i = 0; i < staffCount; ++i) {
                        staffMembers[i].displayStaffInfo();
                        cout << "------------------\n";
                    }
                }
                break;



            case 8: {
                if (prisonerCount == 0) {
                    cout << "No prisoners in the system.\n";
                    break;
                }
                string pid;
                cout << "Enter prisoner ID: "; cin >> ws; getline(cin, pid);
                int pIndex = -1;
                for (int i = 0; i < prisonerCount; ++i) {
                    if (prisoners[i].prisonerId == pid) {
                        pIndex = i;
                        break;
                    }
                }
                if (pIndex == -1) {
                    cout << "Prisoner not found.\n";
                }
                else {
                    int releaseYear = prisoners[pIndex].calculateReleaseYear();
    				if (releaseYear == -1) {
       					cout << "Prisoner " << pid << " is serving a life sentence.\n";
    				} else {
        				cout << "Prisoner " << pid << " will be released in year: " << releaseYear << endl;
    				}
                }
                break;
            }
            case 9:
                running = false;
                cout << "Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice, try again.\n";
                break;
            }
        }
    }
    else {
        cout << "Incorrect password" << endl;
    }

    return 0;
}
