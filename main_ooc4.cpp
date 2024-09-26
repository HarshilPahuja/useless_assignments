#include <iostream>
using namespace std;
class Complex
{

  private:
     float real;
     float imag;
     
  public:
  
     Complex(): real(0), imag(0){}

     void readComplex()
         {
         cout<<"\n\nEnter the REAL PART : ";
         cin>> real;
         cout<<"\n\nEnter the IMAGINARY PART : ";
         cin>>imag;
         }
     void printComplex()
         {
         cout<<"\n\nComplex Number";
         cout<< real;
         cout<<"+";
         cout<<imag<<"i";
         
         }
         
         Complex operator + (Complex c2)
         {
            Complex temp;
            temp.real = real + c2.real;
            temp.imag = imag + c2.imag;
            
            return temp;
         }
         
         Complex operator - (Complex c2)
         {
         	Complex temp;
         	temp.real=real - c2.real;
         	temp.imag=imag-c2.imag;
         	return temp;
         }
         
      friend Complex operator *(Complex c1,Complex c2);
      friend Complex operator /(Complex c1, Complex c2);
        };  
        Complex operator * (Complex c1,Complex c2){
       	Complex temp;
		temp.real = c1.real * c2.real - c1.imag * c2.imag;
		temp.imag = c1.real * c2.imag + c1.imag * c2.real; 
		return temp;
        
       
        
        }
        Complex operator / (Complex c1,Complex c2){
       Complex temp;
    	float denominator = c2.real * c2.real + c2.imag * c2.imag;

    	if (denominator == 0) {
        cout << "\nError: Division by zero.";
        return temp; 
    }

    temp.real = (c1.real * c2.real + c1.imag * c2.imag) / denominator;
    temp.imag = (c1.imag * c2.real - c1.real * c2.imag) / denominator;

    return temp;
        }
        
        
int main()
 { 
    Complex c1,c2,c3;
    int choice=0,cont;
    do
    {
    cout<<"hello";
    cout<<"\t\tCOMPLEXNUMBERS\n\n 1.ADDITION\n\n 2.SUBTRACTION\n\n 3.MULTIPLICATION\n\n 4.DIVISION";

    cout<<"In\nEnter your choice : ";
    cin>>choice;
  
    if (choice==1||choice==2||choice==3||choice==4){
        cout<<"\n\nEnter the First Complex Number:";
        c1.readComplex();
        cout<<"\n\nEnter the Second Complex Number:";
        c2.readComplex();
}
    switch(choice) {
        case 1:
            c3 = c1 + c2;
            cout<< "\n\nSum = ";
            c3.printComplex();
            break;
            
         case 2 : 
         	c3=c1-c2;

 			cout<<"\n\nSub="; 
 			c3.printComplex(); 
 			break;
             
		
        case 3:
         c3 = c1 * c2;
                cout << "\nProduct = ";
                c3.printComplex();
                break;
                
        case 4:
         c3=c1/c2; 
         cout<<"\n\nDIv="; 
         c3.printComplex(); 
         break;
        
        	
        	
        default:
         cout<<"\n\nUndefined Choice";}
         cout<<"\n\nDo you want to continue?(1-Y,0-N)";
         cin>>cont;
         }while(cont==1);
         return 0;
 }