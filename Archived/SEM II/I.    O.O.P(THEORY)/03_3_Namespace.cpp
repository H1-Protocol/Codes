#include"iostream"
using namespace std;
//using std::cout; 	// Professional Way of Using Namespace, minimizes name conflicts
					// namespace is not used with individual items

void swap(int &a, int &b);
int main()
{
    int a=10, b=20;

	std::swap(a, b); // Enforces std::swap, as local/global functions have higher priority than namespace imports
    cout<<a<<" "<<b<<endl;

	swap(a, b);
    cout<<"Hello World!"<<endl<<a<<" "<<b;
}

void swap(int &a, int &b)
{
	cout<<"Custom Swap Function Called"<<endl;
	int temp = a;
	a = b;
	b = temp;
}
