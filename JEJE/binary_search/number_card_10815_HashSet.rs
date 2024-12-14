use std::io::{stdin, Read, stdout, Write, BufWriter};
use std::collections::HashSet;

fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);
    
    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);

    let n = input.next().unwrap();
    let mut cards: HashSet<i32> = HashSet::new();
    for _ in 0..n{
        cards.insert(input.next().unwrap());
    }

    let find_cnt = input.next().unwrap();
    for _ in 0..find_cnt{
        match cards.contains(&input.next().unwrap()){
            true => write!(writer, "1 "),
            false => write!(writer, "0 "),
        }.unwrap();
    }
}