// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
use std::io::{stdin, Read, stdout, Write, BufWriter};
//use std::convert::TryInto;

fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace();

    let mut arr: Vec<Vec<_>> = (0..5).map(|_| Vec::new()).collect();
    for i in arr.iter_mut(){
        *i = input.next().unwrap().chars().collect();
    }

    let mut ans = [&'-'; 76];
    for i in 0..5{
        for j in 0..arr[i].len(){
            ans[j*5+i] = &arr[i][j];
        }
    }

    for i in ans{
        if i == &'-'{
            continue;
        }
        write!(writer, "{i}").unwrap();
    }
}