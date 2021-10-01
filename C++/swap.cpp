#include<iostream>
using namespace std;
class SwapNumbers
{ 
	private:
		int x,y;
	public:
	void getdata()
	{ 
		cin>>x>>y;
	}
	void showdata()
	{
	 cout<<"X="<<x<<"Y="<<y;
	}
	friend void swap(SwapNumbers&s);
};


void swap(SwapNumbers&s)
{ 
	int temp;
	temp=s.x;
	s.x=s.y;
	s.y=temp;
}
int main()
{
	SwapNumbers s;
	cout<<"Input two numbers to swap:"<<endl;
	s.getdata();
	cout<<endl<<"Before swapping:"<<endl;
	s.showdata();
	swap(s);
	cout<<endl<<"After swapping:"<<endl;
	s.showdata();
	return 0;
}