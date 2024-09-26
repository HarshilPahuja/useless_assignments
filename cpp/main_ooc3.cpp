#include <iostream>
#include <string>

using namespace std;

class Employee
{
    string Ename;
    int EmpID;

public:
    
	Employee() {
	Ename="";
	EmpID=0;
	}
	
	Employee(string n,int id) {
	Ename=n;
	EmpID=id;
	}
   virtual void accept()
    {
        cout << "Enter the Employee Name: ";
        cin >> Ename;
        cout << "Enter the Employee ID: ";
        cin >> EmpID;
    }

    virtual void display()
    {
        cout << "The Employee Name is: " << Ename << endl;
        cout << "The Employee ID is: " << EmpID << endl;
    }
};

class SalariedEmployee : public Employee
{
    double WeeklySalary;

public:

	SalariedEmployee() {
	WeeklySalary=0;
	}
	
	SalariedEmployee(double salary) {
	WeeklySalary=salary;
	}
    void accept()
    {
        Employee::accept();
        cout << "Enter weekly salary: ";
        cin >> WeeklySalary;
    }
    void Weekly_earnings()
    {
        cout << "The weekly salary is: " << WeeklySalary << endl;
    }
};

class HourlyEmployee : public Employee
{
    double wage;
    double hours;
    double HourlySalary;

public:
	HourlyEmployee() {
	wage=0;
	hours=0;
	HourlySalary=0;
	}
	
	HourlyEmployee(double wa,double h,double hoursal){
	wage=wa;
	hours=h;
	HourlySalary=hoursal;
	}
    void accept()
    {
        Employee::accept();
        cout << "Enter hourly wage: ";
        cin >> wage;
        cout << "Enter number of hours worked: ";
        cin >> hours;
    }
    void Hourly_earnings()
    {
        if (hours < 40)
        {
            HourlySalary = hours * wage;
        }

        else
        {
            HourlySalary = 40 * wage + ((hours - 40) * wage) * 1.5;
        }
        cout << "Hourly Earnings:" << HourlySalary << endl;
    }
};

class CommissionEmployee : public Employee
{
    double GrossSales;
    double CommissionRate;
    double CommissionSalary;

public:
    
	CommissionEmployee() {
	GrossSales=0;
	CommissionRate=0;
	CommissionSalary=0;
	}
	
	CommissionEmployee(double sales,double rate,double sal){
	GrossSales=sales;
	CommissionRate=rate;
	CommissionSalary=sal;
	}
    void accept()
    {
        Employee::accept();
        cout << "Enter gross sales: ";
        cin >> GrossSales;
        cout << "Enter commission rate: ";
        cin >> CommissionRate;
    }
    void Commission_earnings()
    {
        CommissionSalary = GrossSales * CommissionRate;
        cout << "The commission earnings is: " << CommissionSalary << endl;
    }
};

int main()
{
    SalariedEmployee ES;
    HourlyEmployee EH;
    CommissionEmployee EC;

    cout << "Enter details for Salaried Employee:" << endl;
    ES.accept();
    ES.display();
    ES.Weekly_earnings();

    cout << "\nEnter details for Hourly Employee:" << endl;
    EH.accept();
    EH.display();
    EH.Hourly_earnings();

    cout << "\nEnter details for Commission Employee:" << endl;
    EC.accept();
    EC.display();
    EC.Commission_earnings();

    return 0;
}