fn main() {
    let correct = "hello world";
    let mut string = String::new();
    let characters = "abcdefghijklmnopqrstuvwxyz ";
    for i in 0..correct.len() {
        for j in characters.chars() {
            if j.to_string() == &correct[i..(i+1)] {
                string.push_str(&j.to_string());
                println!("{}", string);
            }
        }
    }
}
