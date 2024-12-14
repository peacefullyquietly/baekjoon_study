use std::io::{stdin, Read, stdout, Write, BufWriter};

fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);
    
    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);

    let mut arr = [0; 10];
    arr[0] = input.next().unwrap();
    for i in 1..10{
        arr[i] = input.next().unwrap()+arr[i-1];
    }

    let mut flag = 101;
    let mut ans = 0;
    for i in 0..arr.len(){
        if (arr[i] - 100) <= flag{
            flag = (arr[i] - 100).abs();
            ans = arr[i];
        }
    }

    write!(writer, "{}", ans).unwrap();
}