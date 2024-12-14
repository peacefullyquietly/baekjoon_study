// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
use std::io::{Write, stdin, Read, stdout, BufWriter};

fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let N = buf.split_ascii_whitespace().flat_map(str::parse::<usize>).next().unwrap();

    let mut stack = Vec::new();
    for i in 0..N{
        let mut layer = String::new();
        
        for _ in 0..N-i-1{
            layer.push(' ');
        }
        
        for _ in 0..2*i+1{
            layer.push('*');
        }
        
        layer.push('\n');
        write!(writer, "{}", layer).unwrap();
        stack.push(layer);
    }

    stack.pop();
    while !stack.is_empty(){
        write!(writer, "{}", stack.pop().unwrap()).unwrap();
    }
}