fn main() {
  let fNum = 5;
  let sNum: i32 = 25;
 
  let sum = return_sum(fNum,  sNum);
  println!("The sum of fNum &  sNum is = {}", sum);
}
 
fn return_sum(i: i32, j: i32) -> i32 {
  i + j
}
