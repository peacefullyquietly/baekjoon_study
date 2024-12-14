use std::io::{Write, stdin, Read, stdout, BufWriter};
use std::collections::BTreeMap;
use std::cmp::Reverse;

fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace();

    let N = input.next().unwrap().parse::<usize>().unwrap();
    let mut list = BTreeMap::new();
    for _ in 0..N{
        let name = input.next().unwrap();
        let status = input.next().unwrap();
        if status == "enter"{
            list.insert(Reverse(name), true);
        }else{
            list.entry(Reverse(name)).and_modify(|e| *e = false);
        }
    }
    for (name, status) in list.iter(){
        if *status{
            write!(writer, "{}\n", name.0).unwrap();
        }
    }    
}