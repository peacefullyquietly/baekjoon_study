// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
use std::io::{stdin, Read, stdout, Write, BufWriter};

#[derive(Clone)]
struct Info(Vec<usize>, usize);

fn dfs(start: usize, list: &Vec<Info>, visited: &mut Vec<bool>, dp: &mut Vec<Vec<usize>>){
    visited[start] = true;
    dp[0][start] = 0;
    dp[1][start] = list[start].1;
    for i in &list[start].0{
        if !visited[*i]{
            dfs(*i, list, visited, dp);
            dp[0][start] += std::cmp::max(dp[0][*i], dp[1][*i]);
            dp[1][start] += dp[0][*i];
        }
    }
}

fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);
    
    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);

    let n = input.next().unwrap();

    let mut list = vec![Info(Vec::new(), 0); n+1];
    let mut visited = vec![false; n+1 as usize];
    let mut dp = vec![vec![0; n+1 as usize]; 2];

    for i in 1..=n{
        let a = input.next().unwrap();
        list[i].1 = a;
    }

    for _ in 0..n-1{
        let a = input.next().unwrap();
        let b = input.next().unwrap();
        list[a].0.push(b);
        list[b].0.push(a);
    }

    dfs(1, &list, &mut visited, &mut dp);

    write!(writer, "{}", std::cmp::max(dp[1][1], dp[0][1])).unwrap();
}