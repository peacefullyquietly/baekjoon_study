// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
use std::io::{stdin, Read, stdout, Write, BufWriter};
use std::collections::VecDeque;

fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);
    
    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);

    let n = input.next().unwrap();
    let k = input.next().unwrap();

    let mut v = (1..=n).collect::<VecDeque<usize>>();
    let mut cnt = 1;

    write!(writer, "<").unwrap();
    while !v.is_empty(){
        if cnt%k == 0{
            write!(writer, "{}", v.pop_front().unwrap()).unwrap();
            if !v.is_empty() { write!(writer, ", ").unwrap(); }
        } else {
            let tmp = v.pop_front().unwrap();
            v.push_back(tmp);
        }
        cnt += 1;
    }
    write!(writer, ">").unwrap();
}