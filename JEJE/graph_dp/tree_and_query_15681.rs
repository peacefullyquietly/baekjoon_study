// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
use std::io::{stdin, Read, stdout, Write, BufWriter};

fn find(start: usize, list: &Vec<Vec<usize>>, visited: &mut Vec<bool>, dp: &mut Vec<usize>) -> usize{
    if dp[start] != 1{
        return dp[start];
    }
    visited[start] = true;
    for i in &list[start]{
        if !visited[*i]{
            dp[start] += find(*i, list, visited, dp);
        }
    }
    return dp[start];
}

fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);
    
    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);

    let n = input.next().unwrap();
    let r = input.next().unwrap();
    let q = input.next().unwrap();

    let mut list = vec![vec![]; n+1 as usize];
    let mut visited = vec![false; n+1 as usize];
    let mut dp = vec![1; n+1 as usize];

    for _ in 0..n-1{
        let a = input.next().unwrap();
        let b = input.next().unwrap();
        list[a].push(b);
        list[b].push(a);
    }

    find(r, &list, &mut visited, &mut dp);

    for _ in 0..q{
        let u = input.next().unwrap();
        write!(writer, "{}\n", dp[u]).unwrap();
    }
}