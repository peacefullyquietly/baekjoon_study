use std::io::{stdin, Read, stdout, Write, BufWriter};

fn dfs(start: usize, list: &Vec<Vec<usize>>, visited: &mut Vec<bool>, dp: &mut Vec<Vec<usize>>){
    visited[start] = true;
    dp[0][start] = 0;
    dp[1][start] = 1;
    for i in &list[start]{
        if !visited[*i]{
            dfs(*i, list, visited, dp);
            dp[0][start] += dp[1][*i];
            dp[1][start] += std::cmp::min(dp[0][*i], dp[1][*i]);
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

    let mut list = vec![vec![]; n+1 as usize];
    let mut visited = vec![false; n+1 as usize];
    let mut dp = vec![vec![0; n+1 as usize]; 2];

    for _ in 0..n-1{
        let a = input.next().unwrap();
        let b = input.next().unwrap();
        list[a].push(b);
        list[b].push(a);
    }

    dfs(1, &list, &mut visited, &mut dp);

    write!(writer, "{}", std::cmp::min(dp[1][1], dp[0][1])).unwrap();
}