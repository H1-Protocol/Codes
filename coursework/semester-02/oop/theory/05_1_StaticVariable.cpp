#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;

int getAutoValue()
{
	int val = 0;
	return ++val;
}

int getStaticValue1()
{
	static int val = 0; //retain it previous value for method "getStaticValue1()"
	return ++val;
}

int getStaticValue2()
{
	static int val = 0; //retain it previous value for method "getStaticValue2()"
	return ++val;
}

int main() 
{ 
	cout<<endl<<"Value: "<<getAutoValue(); 
	cout<<endl<<"Value: "<<getAutoValue();
	cout<<endl<<"Value: "<<getAutoValue();

	cout<<"\n-------------------------------\n";
	cout<<endl<<"Value Static-1: "<<getStaticValue1(); 
	cout<<endl<<"Value Static-1: "<<getStaticValue1(); 
	cout<<endl<<"Value Static-1: "<<getStaticValue1(); 

	cout<<"\n-------------------------------\n";
	cout<<endl<<"Value Static-2: "<<getStaticValue2(); 
	cout<<endl<<"Value Static-2: "<<getStaticValue2(); 
	cout<<endl<<"Value Static-2: "<<getStaticValue2(); 
	
	return 0; 
} 