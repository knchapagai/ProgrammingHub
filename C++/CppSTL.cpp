#include<iostream>
using namespace std;
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
int main(){
/***************************************************************************************************
/*vector - Vector is an dynamic array ie auto grows or shrink the size
		 Headerfile - #include <vector>
		 Elements begin from 0 indexing*/
vector<int> vec={1,2,3};
cout<<"Element at index 1: "<<vec[1]<<endl; //2
cout<<"Contents in vector:"<<endl;
for (auto x: vec)
cout<<x<<" ";  //1 2 3

vec.push_back(4); //1 2 3 4

cout<<"\nSize : " <<vec.size(); //4
vec.pop_back();
cout<<"\nSize : "<<vec.size()<<endl; //3

//****************************************************************************************************
/*Set - Set is an collection of unique items 
       Headerfile - #include<set> */
     
set<int> setelem={1,2,3,3};
for(auto x: setelem)
cout<<x<<" ";
setelem.insert(-1); //-1 1 2 3
setelem.erase(2);   //-1 1 3
cout<<"\nSize : "<<setelem.size()<<endl;

//***************************************************************************************************
/*Map - Map is an collection of key value pair of items
       Headerfile - #include<map> */
map<string,int>mapelem;
mapelem["Apple"]=100;
mapelem["Mango"]=120;
mapelem["Kiwi"]=200;
mapelem["Apple"]=50;
cout<<"\nContents in Map \n";
for(auto x: mapelem){
    cout<<x.first<<" -> "<<x.second<<endl;
}
//**************************************************************************************************
/*Stack - Stack follows LIFO ordering of elements
       Headerfile - #include<stack> */
stack<int> st;
st.push(10); // 10
st.push(20); // 20 10
st.pop();    //10
cout<<"\nTop of the stack \n"<<st.top();    //10

//**************************************************************************************************
/*Queue - Queue follows FIFO ordering of elements
       Headerfile - #include<queue> */
queue<int> qu;
qu.push(10); // 10
qu.push(20); // 10 20
qu.pop();    //20
cout<<"\nFront of the queue \n"<<qu.front();  //20

//*************************************************************************************************
//algorithms
vector<int> elems={4,3,-1,30};
sort(elems.begin(),elems.end()); //-1,3,4,30
cout<<endl<<binary_search(elems.begin(),elems.end(),4); //1 - returns 1 if found else returns 0 


return 0;

}