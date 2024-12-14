use std::io::{self, Read, Write};

struct Stack{
    stack: Vec<i32>
} impl Stack{
    fn new() -> Stack
    {
        Stack{stack: vec![]}
    }
    
    fn is_empty(&self) -> bool
    {
        self.stack.is_empty()
    }
    
    fn push(&mut self, value: i32)
    {
        self.stack.push(value);
    }
    
    fn pop(&mut self) -> i32
    {
        match self.stack.pop()
        {
            None => -1,
            Some(val) => val as i32,
        }
    }
    
    fn size(&self) -> usize
    {
        self.stack.len()
    }
    
    fn empty(&self) -> u8
    {
        match self.is_empty()
        {
            true => 1,
            false => 0,
        }
    }
    
    fn top(&self) -> i32
    {
        match self.is_empty()
        {
            true => -1,
            false => self.stack[self.stack.len()-1] as i32,
        }
    }
}

fn input() -> String
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    input
}

fn main()
{
    let mut stack = Stack::new();
    let tc:i32 = input().trim().parse().unwrap();
    for _ in 0..tc
    {
        let order = input();
        match &order[..=1]
        {
            "pu" =>
            {
                let a = order.split_whitespace().skip(1).next().unwrap();
                let a:i32 = a.parse().unwrap();
                stack.push(a);
            },
            "po" => println!("{}", stack.pop()),
            "si" => println!("{}", stack.size()),
            "em" => println!("{}", stack.empty()),
            "to" => println!("{}", stack.top()),
            _ => {},
        }
    }
}

//https://www.acmicpc.net/source/21889790