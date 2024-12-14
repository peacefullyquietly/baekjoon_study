// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
use std::io::{stdin, Read, stdout, Write, BufWriter};

fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);
    
    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);

    let n = input.next().unwrap();
    let mut cards: Vec<i32> = vec![0; n as usize];
    for i in cards.iter_mut(){
        *i = input.next().unwrap();
    }
    cards.sort_unstable();

    let find_cnt = input.next().unwrap();
    for _ in 0..find_cnt{
        let find = input.next().unwrap();
        match cards.binary_search(&find){
            Ok(_) => write!(writer, "1 "),
            Err(_) => write!(writer, "0 "),
        }.unwrap();
    }
}