  var num=1234, rem, sum=0;
  while(num)
  {
    rem = num%10;
    sum = sum+rem;
    num = Math.floor(num/10);
  }
  console.log(sum);
