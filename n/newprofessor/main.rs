use std::io::*;
use std::collections::*;

fn main() {
    let mut io = IO::new(stdin(), stdout());
    let n: usize = io.read();

    let mut heap = BinaryHeap::<i64>::new();

    for _ in 0..n {
        let x: i64 = io.read();
        heap.push(x);
    }

    let mut ans = 0;

    while heap.len() > 0 {
        let count = std::cmp::min(5, heap.len());
        ans += count;

        if count < 5 {
            break;
        }

        let mut els = Vec::<i64>::new();
        for _ in 0..count {
            let x = heap.pop().unwrap();
            if x > 1 {
                els.push(x - 1);
            }
        }

        for x in els {
            heap.push(x);
        }
    }

    println!("{ans}");
}

pub struct IO<R, W: std::io::Write>(R, std::io::BufWriter<W>);

impl<R: std::io::Read, W: std::io::Write> IO<R, W> {
    pub fn new(r: R, w: W) -> IO<R, W> {
        IO(r, std::io::BufWriter::new(w))
    }
    pub fn write<S: ToString>(&mut self, s: S) {
        use std::io::Write;
        self.1.write_all(s.to_string().as_bytes()).unwrap();
    }
    pub fn read<T: std::str::FromStr>(&mut self) -> T {
        use std::io::Read;
        let buf = self
            .0
            .by_ref()
            .bytes()
            .map(|b| b.unwrap())
            .skip_while(|&b| b == b' ' || b == b'\n' || b == b'\r' || b == b'\t')
            .take_while(|&b| b != b' ' && b != b'\n' && b != b'\r' && b != b'\t')
            .collect::<Vec<_>>();
        unsafe { std::str::from_utf8_unchecked(&buf) }
            .parse()
            .ok()
            .expect("Parse error.")
    }

    pub fn vec<T: std::str::FromStr>(&mut self, n: usize) -> Vec<T> {
        (0..n).map(|_| self.read()).collect()
    }
    pub fn chars(&mut self) -> Vec<char> {
        self.read::<String>().chars().collect()
    }
    pub fn line(&mut self) -> Vec<char> {
        use std::io::Read;
        let buf = self
            .0
            .by_ref()
            .bytes()
            .map(|b| b.unwrap())
            .skip_while(|&b| b == b'\n' || b == b'\r')
            .take_while(|&b| b != b'\n' && b != b'\r')
            .collect::<Vec<_>>();
        unsafe { std::str::from_utf8_unchecked(&buf) }.to_string()
            .chars()
            .collect()
    }
}
