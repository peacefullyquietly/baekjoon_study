use std::io::{stdin, Read, stdout, Write, BufWriter};
// use std::convert::TryInto;

type ListT = Vec<(Vec<usize>, usize)>;
type DpT = Vec<(usize, usize)>;

fn dfs_dp(idx: usize, list: &ListT, dp: &mut DpT, visited: &mut Vec<bool>){
    visited[idx] = true;
    dp[idx].0 = 0;
    dp[idx].1 = list[idx].1;
    for i in &list[idx].0{
        if !visited[*i]{
            dfs_dp(*i, list, dp, visited);
            dp[idx].0 += std::cmp::max(dp[*i].0, dp[*i].1);
            dp[idx].1 += dp[*i].0;
        }
    }
}

fn make_list(atoms: &mut Vec<usize>, energy: &Vec<usize>, list: &mut ListT){
    
    atoms.sort_unstable();
    for i in atoms.iter(){
        list.push((vec![], *i));
    }

    for i in 0..atoms.len(){
        for j in energy{

            let mut atom_energy: usize = atoms[i] + *j;
            match atoms.binary_search(&atom_energy){
                Ok(idx) => list[i].0.push(idx),
                Err(_) => (),
            }
            
            if atoms[i] > *j {
                atom_energy = atoms[i] - *j;
                match atoms.binary_search(&atom_energy){
                    Ok(idx) => list[i].0.push(idx),
                    Err(_) => (),
                }
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

    let atom_cnt = input.next().unwrap();
    let mut atoms: Vec<usize> = vec![0; atom_cnt];
    let energy_cnt = input.next().unwrap();
    let mut energy: Vec<usize> = vec![0; energy_cnt];

    for i in atoms.iter_mut(){
        *i = input.next().unwrap();
    }
    
    for i in energy.iter_mut(){
        *i = input.next().unwrap();
    }

    let mut list: ListT = vec![];
    make_list(&mut atoms, &energy, &mut list);

    // println!("{:?}", list);
    let mut dp: DpT = vec![(0, 0); atom_cnt];
    let mut visited = vec![false; atom_cnt];
    dfs_dp(0, &list, &mut dp, &mut visited);
    // println!("{:?}", dp);
    write!(writer, "{}", std::cmp::max(dp[0].0, dp[0].1)).unwrap();
}