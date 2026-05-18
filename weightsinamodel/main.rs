use std::io::*;

fn main() {
    let mut io = IO::new(stdin(), stdout());

    let m = 1000000007;
    let maxn = 100005;
    let mut x = vec![0 as i64; maxn];

    x[1] = io.read();
    x[2] = io.read();

    let a: i64 = io.read();
    let b: i64 = io.read();
    let c: i64 = io.read();
    let d: i64 = io.read();

    for i in 3..maxn {
        if i % 2 == 0 {
            x[i] = (a*x[i-1] % m + b * (i as i64) % m) % m;
        } else {
            x[i] = (c*x[i-1] % m + d * x[i-2] % m) % m;
        }
    }

    let q: usize = io.read();

    for _ in 0..q {
        let n: usize = io.read();
        io.write(x[n]);
        io.write('\n');
    }
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
