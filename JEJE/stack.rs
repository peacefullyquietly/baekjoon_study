use std::io;

fn main()
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let tc:i32 = input.trim().parse().unwrap();
    for i in 0..tc
    {
        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        let tc:i32 = input.trim().parse().unwrap();
    }
}