// Creates hollow pyramid in console using Node.js process.stdin, process.stdout
// -------------------------------------
// Enter number of rows:3
// -> 3!
//   *    
//  * *  
// *****
// -------------------------------------

const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout
})

readline.question(`Enter number of rows:`, r => {
  console.log(`-> ${r}!`)
  var i;
  var j;
  var s;
  var lineBuffer = [];
  for(i = 1; i <= r; i++){
    //for loop to put space in pyramid
    for (s = i; s < r; s++){
      lineBuffer += " ";
    }
  //for loop to print star
  for(j = 1; j <= (2 * r - 1); j++){
    if(i == r || j == 1 || j == 2*i - 1){
      lineBuffer += "*";
    }else{
      lineBuffer += " ";
    }
  }
  lineBuffer += "\n";
  }
  console.log(lineBuffer);
  readline.close()
})
