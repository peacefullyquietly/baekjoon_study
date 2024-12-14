// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
use std::io::{Write, stdin, Read, stdout, BufWriter};
use std::convert::TryInto;
use std::collections::VecDeque;

fn dfs(start: usize, list: &Vec<usize>, visited: &mut Vec<bool>, looped: &mut Vec<i32>, looped_n: &mut i32, cnt: &mut i32) {
    let mut stack = VecDeque::new();
    stack.push_back(start);
    visited[start] = true;
    looped[start] = *looped_n;

    while !stack.is_empty(){
        let cur = stack.pop_back().unwrap();
        let next = list[cur];

        if !visited[next]{
            stack.push_back(next);
            visited[next] = true;
            looped[next] = *looped_n;
        }else{
            if looped[next] == *looped_n{
                *cnt = *cnt + 1;
                let mut i = list[next];
                while i != next{
                    *cnt = *cnt + 1;
                    i = list[i];
                }
            }
        }
    }
    *looped_n += 1;
}

fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);

    let tc = input.next().unwrap();
    for _ in 0..tc{
        let mut visited = vec![false; 100001];
        let mut list:Vec<usize> = vec![0; 100001];
        let mut looped = vec![-1; 100001];
        let mut looped_n = 1;
        let mut cnt = 0;

        let n = input.next().unwrap();
        for i in 1..=n{
            list[i as usize] = input.next().unwrap();
        }

        for i in 1..=n{
            if !visited[i]{
                dfs(i, &list, &mut visited, &mut looped, &mut looped_n, &mut cnt);
            }
        }

        // write!(writer, "{}\n", n-cnt).unwrap();
        println!("{}", n-(cnt as usize));
    }

}