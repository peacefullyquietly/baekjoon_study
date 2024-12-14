use std::io::{stdin, Read, stdout, Write, BufWriter};
use std::convert::TryInto;

fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace();

    let mut arr = ["0";5];
    for i in 0..5{
        arr[i] = input.next().unwrap();
    }

    let mut ans = String::new();

    for j in 0..15{
        for i in 0..5{
            if j < arr[i].len(){
                ans += &arr[i][j..j+1];
            }
        }
    }

    write!(writer, "{ans}").unwrap();
}