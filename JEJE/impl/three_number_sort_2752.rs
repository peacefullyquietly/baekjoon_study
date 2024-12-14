use std::io::{stdin, Read, stdout, Write, BufWriter};

fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);
    
    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);

    let mut arr = [0; 3];
    for i in 0..3{
        arr[i] = input.next().unwrap();
    }
    arr.sort_unstable();

    for i in 0..3{
        write!(writer, "{} ", arr[i]).unwrap();
    }
}