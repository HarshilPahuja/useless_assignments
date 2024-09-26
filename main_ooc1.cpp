#include<iostream>
#include<string>
using namespace std;

class Student{
  private:
    float marks;
  public:
    static int count;
    string name;
    int roll;
    int classes;
    string division;
    int dob;
    int adhar;
    string bloodgrp;
    string add;
    int tel;

  void setData(){
    cout << "Enter the marks:"<<endl;
    cin >> marks;
    cout << "name:" <<endl;
    cin >> name;
    cout << "roll:" <<endl;
    cin >> roll;
    cout << "class:" <<endl;
    cin >> classes;
    cout << "division:" <<endl;
    cin >> division;
    cout << "dob:" <<endl;
    cin >> dob;
    cout << "adhar:" <<endl;
    cin >> adhar;
    cout << "bloodgrp:" <<endl;
    cin >> bloodgrp;
    cout << "add:" <<endl;
    cin >> add;
    cout << "tel:" <<endl;
    cin >> tel;
    count=count+1;
  }
  void getData(){
    cout << "name:" <<endl;
    cout << name <<endl;
    cout << "roll:" <<endl;
    cout << roll <<endl;
    cout << "class:" <<endl;
    cout << classes <<endl;
    cout << "division:" <<endl;
    cout << division <<endl;
    cout << "dob:" <<endl;
    cout << dob <<endl;
    cout << "bloodgrp:" <<endl;
    cout << bloodgrp <<"+" <<endl;
    cout << "adhar:" <<endl;
    cout << adhar <<endl;
    cout << "add" <<endl;
    cout << add <<endl;
    cout << "tel" <<endl;
    cout << tel <<endl;
  }
  friend void percentage_marks(Student);
  static void total(){
    cout <<endl <<"Total Students=" <<count <<endl;}

}; 

void percentage_marks(Student s)
{
cout << "Marks:" <<(s.marks/100)*100 << "%" <<endl;
}

int Student::count;

int main(){
  
  int i;
  int num;
  cout <<endl <<"Enter the number of students=" <<endl;
  cin >> num;
  Student s[num];
  for(i=0;i<num;i++){
  cout <<endl <<"Student:" << i+1 <<endl;
  s[i].setData();
  s[i].getData();
  percentage_marks(s[i]);
    
  }
  
  Student::total();
}