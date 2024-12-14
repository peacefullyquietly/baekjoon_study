// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
use std::io::{stdin, Read, stdout, Write, BufWriter};

fn dfs(start: usize, list: &Vec<Vec<usize>>) -> usize{
    if list[start].is_empty(){
        return 1;
    } else{
        
        let mut underling_call_time = vec![];

        for i in &list[start]{
            underling_call_time.push(dfs(*i, list));
        }
        underling_call_time.sort_by(|a, b| b.cmp(a));

        let mut ret = 0;
        for (i, j) in underling_call_time.iter().enumerate(){
            ret = std::cmp::max(ret, i+*j+1);
        }

        return ret;
    }
}

fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);
    
    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<i32>);

    let n = input.next().unwrap() as usize;

    let mut list = vec![vec![]; n+1];
    
    let _ = input.next();
    for i in 1..n{
        list[input.next().unwrap() as usize].push(i);
    }
    // println!("{:?}", list);

    write!(writer, "{}", dfs(0, &list) - 1).unwrap();
}