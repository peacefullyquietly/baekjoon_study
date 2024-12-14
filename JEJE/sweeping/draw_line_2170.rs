// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
use std::io::{stdin, Read, stdout, Write, BufWriter};
type Point = (i32, i32);

fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);
    
    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);

    let n = input.next().unwrap();
    let mut v: Vec<Point> = Vec::new();
    for _ in 0..n{
        let x = input.next().unwrap();
        let y = input.next().unwrap();
        v.push((x, y));
    }
    v.sort_by(|a, b| a.0.cmp(&b.0));

    let mut ans = 0;
    let mut s = v[0].0;
    let mut e = v[0].1;
    for i in 1..n as usize{
        if v[i].0 <= e{
            e = e.max(v[i].1);
        }else{
            ans += e - s;
            s = v[i].0;
            e = v[i].1;
        }
    }
    ans += e - s;
    
    write!(writer, "{ans}").unwrap();
}