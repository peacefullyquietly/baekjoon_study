use std::io;
fn main()
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let num = input.trim().parse::<i32>().unwrap();
    for i in 1..10
    {
        println!("{} * {} = {}", num, i, i*num);
    }
}