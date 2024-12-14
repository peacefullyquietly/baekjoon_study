// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
use std::io::{stdin, Read, stdout, Write, BufWriter};

fn group_word(s: &str) -> bool{
    let mut arr = [false; 26];
    let mut last: usize = s.bytes().nth(0).unwrap() as usize - 97;
    arr[last] = true;
    for c in s.bytes(){
        let idx = c as usize - 97;
        if last != idx{
            if arr[idx] { return false; }
            arr[idx] = true;
            last = idx;
        }
    }
    true
}

fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);
    
    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace();

    let n = input.next().unwrap().parse::<usize>().unwrap();
    let mut cnt = 0;

    for _ in 0..n{
        let s = input.next().unwrap();
        if group_word(s) { cnt += 1; }
    }

    write!(writer, "{}", cnt).unwrap();
}