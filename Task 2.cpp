#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
	cout<<"Welcome to my calculator"<<endl;
	int num1,num2;
	char operation;
	//looping until user wants to end
	while(1)
	{
		double x;
		cout<<"Enter the two numbers"<<endl;
		cin>>num1;
		cin>>num2;
		cout<<"Which operation do you want to perform "<<endl;
		cout<<"Enter + for addition "<<endl;
		cout<<"Enter - for subtraction "<<endl;
		cout<<"Enter * for multiplication "<<endl;
		cout<<"Enter / for division "<<endl;
		cout<<"Enter 1 to exit "<<endl;
		cin>>operation;
		if(operation=='+')
		{
			x=num1+num2;
			cout<<"Result after addition is : "<<x<<endl;
		}
		else if(operation=='-')
		{
			x=num1-num2;
			cout<<"Result after subtraction is : "<<x<<endl;	
		}
		else if(operation=='*')
		{
			x=num1*num2;
			cout<<"Result after multiplication is : "<<x<<endl;
		}
		else if(operation=='/')
		{
			x=num1/num2;
			cout<<"Result after division is : "<<x<<endl;
		}
		else if(operation=='1')
		{
			break;
		}
	}
	
}


