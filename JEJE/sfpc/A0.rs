// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
use std::io::{stdin, Read, stdout, Write, BufWriter};

fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);
    
    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);

    let n = input.next().unwrap();
    let k = input.next().unwrap();

    let mut arr = [0; 11];

    while let Some(num) = input.next(){
        arr[num] += 1;
    }

    let mut ans = 0;
    let cost = [0, 1000, 1000, 2000, 3000, 3000, 6000, 6000];
    println!("{:?}", arr);
    // println!("{}", k);
    for i in 1..=7{
        if arr[i] == 0{
            continue;
        }
        if arr[i] >= k{
            ans += cost[i];
            println!("{} {}\n", i, cost[i]);
        }
    }

    write!(writer, "{}\n", ans*n).unwrap();
}