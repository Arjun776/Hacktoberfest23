#include <iostream>
#include <vector>

using namespace std;

class Employee {
public:
    Employee(int id, string name, double hourlyRate) : id(id), name(name), hourlyRate(hourlyRate) {
        totalHoursWorked = 0.0;
    }

    void addHoursWorked(double hours) {
        totalHoursWorked += hours;
    }

    double calculatePay() const {
        return totalHoursWorked * hourlyRate;
    }

    void displayInfo() const {
        cout << "Employee ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Total Hours Worked: " << totalHoursWorked << " hours" << endl;
        cout << "Hourly Rate: $" << hourlyRate << "/hour" << endl;
        cout << "Total Pay: $" << calculatePay() << endl;
    }

private:
    int id;
    string name;
    double hourlyRate;
    double totalHoursWorked;
};

int main() {
    vector<Employee> employees;

    while (true) {
        cout << "\nEmployee Payroll System" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Record Hours Worked" << endl;
        cout << "3. Calculate and Display Pay" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                string name;
                double hourlyRate;

                cout << "Enter employee ID: ";
                cin >> id;
                cout << "Enter employee name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter hourly rate: $";
                cin >> hourlyRate;

                employees.push_back(Employee(id, name, hourlyRate));
                cout << "Employee added successfully." << endl;
                break;
            }
            case 2: {
                int id;
                double hoursWorked;

                cout << "Enter employee ID: ";
                cin >> id;
                cout << "Enter hours worked: ";
                cin >> hoursWorked;

                for (Employee &employee : employees) {
                    if (employee.getId() == id) {
                        employee.addHoursWorked(hoursWorked);
                        cout << "Hours recorded successfully." << endl;
                        break;
                    }
                }
                break;
            }
            case 3: {
                int id;

                cout << "Enter employee ID: ";
                cin >> id;

                for (const Employee &employee : employees) {
                    if (employee.getId() == id) {
                        employee.displayInfo();
                        break;
                    }
                }
                break;
            }
            case 4:
                cout << "Exiting the Employee Payroll System." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
