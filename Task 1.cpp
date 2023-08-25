#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main()
{
	//seeding to generate random number
	srand(time(0));
	int num,num2;
	int attempts=5;
	num=0+(rand()%100);
	
	do
	{
		attempts--;
		cout<<"Enter your preferred number"<<endl;
		cin>>num2;
		if(num<num2)
		{
			cout<<"Number high : Enter a smaller number"<<endl;
			cout<<"Tries left : "<<attempts<<endl;
		}
		else if(num>num2)
		{
			cout<<"Number low : Enter a bigger number"<<endl;
			cout<<"Tries left : "<<attempts<<endl;
		}
		else if(num2==num)
		{
			cout<<"Comgratulations! Number Matched"<<endl;
			cout<<"Tries left : "<<attempts<<endl;
			break;
		}
	}while(attempts>0);
	if(attempts==0)
	{
		cout<<"You could'nt guess the number "<<endl;
		cout<<"The number was "<<num<<endl;
	}
}


