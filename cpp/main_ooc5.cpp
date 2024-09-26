#include <iostream>
#include <string>
using namespace std;
int age_valid=0;
int income_valid=0;	
int city_valid=0;
int room_valid=0;
int count=0;
class Hotel{
	public:
		string cust_name,city,room_type;
		int cust_id, income;
		
	
	void accept(){

		cout<<"enter customer name"<<endl;
		cin>>cust_name;
		cout<<"enter customer id"<<endl;
		cin>>cust_id;
		cout<<"enter city name"<<endl;
		cin>>city;
		getcity();
		cout<<"enter room type"<<endl;
		cin>>room_type;
		getroom_type();
		cout<<"enter income"<<endl;
		cin>>income;
		getincome();
		getage();
		
	}
	
		void getage(){
			int age;

			cout<<"enter age"<<endl;
			cin>>age;
			try{
			if(age>=18 && age<=55)
				
				count++;
			else
				throw age;
				}
			catch(int age){
				cout<<"invalid age"<<endl;
					
			}}
		
		
		void getincome(){

			try{
				if (income>=50000 && income<=100000)
					
					count++;
				else
					throw income;}
			catch(int income){cout<<"not enough eheh"<<endl;}
		
		}
		
		void getcity(){
				try{if(city=="Pune" || city=="pune"|| city=="Mumbai"|| city=="mumbai")
				
				count++;
				else
					throw city;}
				catch(string city){
				cout<<"invalid city"<<endl;}}
				
		void getroom_type(){
		try{if (room_type=="deluxe" || room_type=="super_delux")
			
			count++;
			else
			throw room_type;}
		
		catch(string room ){
		cout<<"invalid room"<<endl;}
		
		}
				

		

	void display(){
		cout<<"customer name:\t"<<cust_name<<endl;
		cout<<"city name:\t"<<city<<endl;
		cout<<"room type:\t"<<room_type<<endl;
		cout<<"income:\t"<<income<<endl;
	
	}

};

int main(){

Hotel h1;
h1.accept();
if(count==4){
h1.display();}
else
cout<<"invalid input"<<endl;

return 0;
}