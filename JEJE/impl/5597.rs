use std::io::{stdin, Read, stdout, Write, BufWriter};

fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);
    
    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);

    let mut arr = [0; 30];

    for _ in 0..28{
        let num = input.next().unwrap();
        arr[num-1] = 1;
    }

    let ans = arr.iter().enumerate().filter(|(_, &x)| x == 0).collect::<Vec<_>>();

    for i in ans{
        write!(writer, "{}\n", i.0 + 1).unwrap();
    }
}