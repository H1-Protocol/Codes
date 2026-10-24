#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;

namespace A
{
	int x = 10;
}

namespace B
{
	int x = 30;
}

int main()
{
	cout<<A::x<<endl;
}

// A namespace is a container allowing to group identifiers 
// such as variables, functions, and classes under a name to avoid 
// name conflicts. Organize code and makes it easier to manage