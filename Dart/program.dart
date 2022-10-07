void main(){
  int a = 2, b = 3, result;
  result =product(a, b);
  print('$result');
}

// calculate multiplication and return the result
int product(int a,int b){
  int temp =0;
  while(b != 0){
    temp += a;
    b--;
  }
  return temp;
}
