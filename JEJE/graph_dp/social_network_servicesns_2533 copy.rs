// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
use std::io::{stdin, Read, stdout, Write, BufWriter};
use std::collections::HashMap;
use std::convert::TryInto;

struct AdjacencyList<T> {
    nodes: HashMap<T, Vec<T>>,
}

impl<T> AdjacencyList<T> {
    fn new() -> Self {
        AdjacencyList {
            nodes: HashMap::new(),
        }
    }

    fn add_edge(&mut self, from: T, to: T) {
        self.nodes.entry(from).or_default().push(to);
    }

    fn get_neighbors(&self, node: T) -> &Vec<T> {
        self.nodes.get(&node).unwrap()
    }

    fn get_nodes(&self) -> Vec<T> {
        self.nodes.keys().map(|x| *x).collect()
    }

    fn size(&self) -> usize {
        self.nodes.len()
    }
}

fn bfs(list: &mut AdjacencyList<usize>){
    let mut dp = vec![vec![0; list.size()]; 2];
    let mut visited = HashMap::new();
    let mut q = Deque::new();
    q.push_back(1);
    visited.insert(1, true);

    while !q.is_empty(){
        let node = q.pop_front().unwrap();
        for i in list.get_neighbors(node){
            if !visited.contains_key(i){
                visited.insert(i, true);
                q.push_back(*i);
            }
        }
    }
}

fn main(){
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);
    
    let mut buf = String::new();
    stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);

    let mut list = AdjacencyList::new();

    let n = input.next().unwrap();
    for _ in 0..n{
        let a = input.next().unwrap();
        let b = input.next().unwrap();
        list.add_edge(a, b);
    }


    write!(writer, "{ans}").unwrap();
}