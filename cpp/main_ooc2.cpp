#include <iostream>
#include <string>
using namespace std;
class Student
{

    

  public:
  string name, blood, div, address, dob, phone;
    int rno, Class, aad;
    Student()
    {
      name = "harvey specter";
      blood = "O+.";
      div = "A-4.";
      address = "new york.";
      dob = "July 4th. 1986.";
      phone = "100";
      rno = 1;
      Class = 1;
      aad = 0077;
    }

    Student (Student &Copy)
    {
      name = Copy.name;
      blood = Copy.blood;
      div = Copy.div;
      address = Copy.address;
      dob = Copy.dob;
      phone = Copy.phone;
      rno = Copy.rno;
      Class = Copy.Class;
      aad = Copy.aad;	
    }
    Student(string n, string b, string d, string a, string db, string ph, int r, int C, int aa)
    {
      name = n;
      blood = b;
      div = d;
      address = a;
      dob = db;
      phone = ph;
      rno = r;
      Class = C;
      aad = aa;
    }

~Student() {
  cout << "Student object destroyed.\n";
}

    void Output()
      {
        cout << "Name: " << name << endl;
        cout << "Blood Group: " << blood << endl;
        cout << "Address: " << address << endl;
        cout << "Roll Number: " << rno << endl;
        cout << "Class: " << Class << endl;
        cout << "Division: " << div << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Aadhar Number: " << aad << endl;
        cout << "Contact Number: " << phone << endl;
        cout << endl;
      }
};
int main()
{
  Student S1;
  string name, blood, div, address, dob, phone;
  int rno, Class, aad;
  cout<<"enter name"<<endl;
  cin>>name;
  cout << "Blood Group: " << endl;
  cin>>blood;
  cout << "enter division: " << endl;
  cin>>div;
  cout << "enter address: " << endl;
  cin>>address;
  cout << "enter dob: " << endl;
  cin>>dob;
  cout << "enter phone: " << endl;
  cin>>phone;
  cout << "enter rno " << endl;
  cin>>rno;
  cout << "enter class: " << endl;
  cin>>Class;
  cout << "enter aad: ";
  cin>>aad;
  Student S2(name, blood, div, address, dob, phone, rno, Class, aad);

  cout<<"Default Constructor:"<<endl;
  S1.Output();
  cout<<"Parameterized Constructor:"<<endl;
  S2.Output();
  Student S3=S2;
  cout<<"Copy Constructor:"<<endl;
  S3.Output();

  return 0;

}
