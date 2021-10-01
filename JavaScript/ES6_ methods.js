
/*Below methods were Introduced in ES6. Understanding them makes our code cleaner and efficient.Explained with examples:

1.filter()
2.map()
3.reduce()
4.sort()
5.reverse()
6.find()
7.slice()
8.splice()
9.Destructuring Objects and Array
10.Spread operator
11.Rest operator


*/

/* ************************************************************************ */

/*filter() = filter() returns the array which consists of the elements that satisfy the condition.
           = Accepts function as its parameter.
*/
//Example 1:
let arr1=[1,2,3,4,5];
let resArr1=arr1.filter((element)=>(element%2==0)); //2,4 satisfies the condition so it is returned in an array.
console.log(resArr1); //[2,4]

//Example 2:
let arr2=[{"name":"Apple","price":100},{"name":"kiwi","price":40},{"name":"watermelon","price":56},{"name":"orange","price":20}]
let resArr2=arr2.filter((elem)=>(elem.price>50)); //[ { name: 'Apple', price: 100 }, { name: 'watermelon', price: 56 } ]
console.log(resArr2); 

/* ************************************************************************ */
/* map() = map() for each and every element the function is called. Used to do some operations
           = Accepts function as its parameter.
*/
//Example 1:
let arr3=[1,2,3,4,5];
let resArr3=arr3.map((element)=>(element/2)); 
console.log(resArr3); //[ 0.5, 1, 1.5, 2, 2.5 ]

//Example 2:
let arr4=[{"name":"Apple","price":100},{"name":"kiwi","price":40},{"name":"watermelon","price":56},{"name":"orange","price":20}]
let resArr4=arr4.map((elem)=>(elem.price+=100));
console.log(resArr4); //[ 200, 140, 156, 120 ]

/* ************************************************************************ */
/* reduce() = reduce() returns a single value. Has accumulator and current.
           = Accepts function as its parameter.
*/
//Example 1:
let arr5=[1,2,3,4,5];
let resReduce=arr5.reduce((accum,curr)=>accum+=curr); 
console.log(resReduce); // 15


/* ************************************************************************ */

/* sort() = sort() sorts the array in accending order.
*/
//Example 1:
let arr6=[5,1,6,0,-1];
arr6.sort(); 
console.log(arr6);  //[-1,0,1,5,6]

/* ************************************************************************ */

/* reverse() = reverses the array.*/
//Example 1:
let arr7=[1,2,3,4,5];
arr7.reverse(); 
console.log(arr7);  //[5,4,3,2,1]

/* ************************************************************************ */

/* find() = returns the first occurence of item if item is present.Else returns undefined*/
//Example 1:
let arr8=[10,50,50,20];
let res8=arr8.find((e)=>(e==50)); 
console.log(res8);  //[5,4,3,2,1]

/* ************************************************************************ */

/* slice(startindex,endindex) = used to get a subpart of the array
                              = endindex is not included in the result
*/
//Example 1:
const fruits = ["Banana", "Orange", "Lemon", "Apple", "Mango"];
const citrus=fruits.slice(1,3);
console.log(citrus);  //["Orange","Lemon"]

/* ************************************************************************ */
/* splice(index,howmaytoremove,items...) = splice() is used to add/remove items in the array.) */
//Example 1: Adding elements
const devices = ["PC","TV","Mobile","Laptop"];
devices.splice(2,0,"Tablets","Keyboard","Mouse");
console.log(devices); //["PC","TV","Tablets","Keyboard","Mouse","Mobile","Laptop"]

//Example 2: Removing elements
const devices2 = ["PC","TV","Mobile","Laptop"];
devices2.splice(2,2);
console.log(devices2); //["PC","TV"]


/* ************************************************************************ */
/* Detructuring Objects and arrays = modern way to access each element in clean code */

//Example 1 : Array detructuring 
let prices=[100,200,300];
let [f,s,t]=prices;
console.log(f); // f = 100, s = 200, t = 300

//Example 2 : Object detructuring 
let AppleProduct={"fname":"Apple","price":100,"count":14};
let {fname,price,count}=AppleProduct;
console.log(fname,price,count); // fname=Apple, price=100, count = 14


/* ************************************************************************ */
/* Spread Operator ...  = used to select elements and spread the elements*/
//Example 1:
let less5=[0,1,2,3,4,5];
let less10=[...less5,6,7,8,9,10];
console.log(less10) //[0,1,2,3,4,5,6,7,8,9,10]

/* ************************************************************************ */
/* rest Operator ...  = used to have variable number of parameters in functions.*/
//Example 1:
let sum=(...a)=>{
    return a.reduce((acc,cur)=>acc+=cur,0)
}

console.log(sum(10)); //10
console.log(sum(10,20,30)); //60
console.log(sum(1,2,3,4,5,6)); //21


