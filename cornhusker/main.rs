#[allow(unused_imports)]
use std::cmp::{min,max};
use std::io::{BufWriter, stdin, stdout, Write};
const INF: i64 = 0x3f3f3f3f;
 
#[derive(Default)]
struct Scanner {
    buffer: Vec<String>
}
impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            stdin().read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}
 
fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let v: Vec<i32> = (0..10).map(|_| scan.next()).collect();

    let n: i32 = scan.next();
    let kwf: i32 = scan.next();

    let mut sum = 0;

    for i in 0..5 {
        sum += v[i<<1] * v[i<<1|1];
    }

    sum /= 5;

    sum *= n;
    sum /= kwf;

    println!("{}", sum);
}
