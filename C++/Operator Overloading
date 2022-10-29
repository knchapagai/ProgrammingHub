//Binary operator overloading

#include<iostream>
using namespace std;
class bioverload{
	public:
		int a,b,d;
		bioverload(int x,int y)
		{
			a=x;
			b=y;
			
		}
		
		bioverload()
		{
			
		}
		
		bioverload operator +(bioverload c)
		{
			bioverload b3;
			b3.a=a+c.a; //10+20=30
			b3.b=b+c.b;	//20+30=50
			return b3;
//			
			
		}
};

int main(){
	bioverload b1(10,20);
	bioverload b2(20,30);
	bioverload b3;
	b3=b1+b2;
//	cout<<"Value of b3.a :"<<b3.a<<endl;
//	cout<<"Value of b3.b :"<<b3.b<<endl;
cout<<"Total sum of (b1.a+b2.a)+(b1.b+b2.b) is "<<b3.a+b3.b;

	return 0;
}
