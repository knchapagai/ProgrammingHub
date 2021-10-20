void main() {   
/*List data structure  
Stores collection of items. Different types is accepted.
Indexed from 0.

*/
var fruits=["apple","mango","kiwi",10];
  
  //popular methods on List 
  fruits.add("Watermelon");  
  fruits.remove("kiwi");
  fruits.removeAt(0);
  fruits.addAll(["banana","jackfruit"]);
  
for(int i=0;i<fruits.length;i++){
  print(fruits[i]);
}
  
  /*Map data structure  
 Stores Key-value pairs as items in it.
 Keys are unique.
 Values are accessed using keys.
*/
 var prices=new Map();
  prices['apple']=140;
  prices['mango']=100;
  prices['kiwi']=220;
  
  //popular methods on Maps
  print(prices.keys); //returns the keys present.
  print(prices.values); //returns the values present.
  print(prices.isEmpty); //returns bool
  print(prices['apple']); //accessing an value using key 
  prices.remove('kiwi');  //removes an key value pair
  
/* Set data structure
stores collection of unique elements

*/
  
var uniqueCollection=<int>{1,2,3,3,4,5};
print(uniqueCollection); // {1,2,3,4,5};
  
//popular methods on Set
print(uniqueCollection.first); // 1
print(uniqueCollection.last); //5
uniqueCollection.add(6);  
uniqueCollection.add(7);  
uniqueCollection.add(6);
print(uniqueCollection); //{1,2,3,4,5,6,7}
print(uniqueCollection.isEmpty); //false
  
}  