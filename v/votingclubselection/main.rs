use std::io::*;
use std::ops;

fn gcd(a: i64, b: i64) -> i64 {
    if b == 0 {
        a
    } else {
        gcd(b, a%b)
    }
}

#[derive(Clone, Copy)]
struct Fraction {
    numerator: i64,
    denominator: i64
}

impl Fraction {
    fn from_i64(n: i64) -> Fraction {
        Fraction {numerator: n, denominator: 1}
    }

    fn reduce(&mut self) {
        let g = gcd(self.numerator, self.denominator);
        self.numerator /= g;
        self.denominator /= g;
    }
}

impl ops::Add<Fraction> for Fraction {
    type Output = Fraction;
    fn add(self: Fraction, rhs: Fraction) -> Fraction {
        // a/b + c/d -> (ad+bc)/(bd)
        let a = self.numerator;
        let b = self.denominator;
        let c = rhs.numerator;
        let d = rhs.denominator;
        let mut result = Fraction { numerator: a * d + b * c, denominator: b * d };
        result.reduce();
        result
    }
}

impl PartialOrd for Fraction {
    fn partial_cmp(&self, rhs: &Fraction) -> Option<std::cmp::Ordering> {
        let a = self.numerator;
        let b = self.denominator;
        let c = rhs.numerator;
        let d = rhs.denominator;

        if a * d < c * b {
            Some(std::cmp::Ordering::Less)
        } else if a * d == c * b {
            Some(std::cmp::Ordering::Equal)
        } else {
            Some(std::cmp::Ordering::Greater)
        }
    }
}

impl PartialEq for Fraction {
    fn eq(&self, rhs: &Fraction) -> bool {
        self.numerator * rhs.denominator == rhs.numerator * self.denominator
    }
}

fn main() {
    let mut io = IO::new(stdin(), stdout());

    let num_ballots: usize = io.read();
    let num_candidates: usize = io.read();

    let mut candidates = Vec::<String>::new();

    for _ in 0..num_candidates {
        let candidate: String = io.read();
        candidates.push(candidate);
    }

    let mut ballots = vec![vec![Fraction::from_i64(0); num_candidates]; num_ballots];

    let mut total_votes = Fraction::from_i64(0);

    for i in 0..num_ballots {
        for j in 0..num_candidates {
            let inp: String = io.read();
            let count_str = &inp[1..];
            let count: i64 = count_str.parse().unwrap();
            ballots[i][j].numerator = count;
            total_votes.numerator += count;
        }
    }

    let mut eliminated = vec![false; num_candidates];

    loop {
        let mut totals = vec![Fraction::from_i64(0); num_candidates];

        for i in 0..num_ballots {
            for j in 0..num_candidates {
                if eliminated[j] {
                    continue;
                }
                totals[j] = totals[j] + ballots[i][j];
            }
        }

        let mut min_count = Fraction::from_i64(i64::MAX / 8);
        let mut max_count = Fraction::from_i64(0);
        let mut losers = Vec::<usize>::new();
        let mut num_remaining = 0;
        let mut max_index = 0;

        for i in 0..num_candidates {
            if eliminated[i] {
                continue;
            }
            num_remaining += 1;

            if totals[i] > max_count {
                max_count = totals[i];
                max_index = i;
            }
            if totals[i] < min_count {
                min_count = totals[i];
                losers.clear();
                losers.push(i);
            } else if totals[i] == min_count {
                losers.push(i);
            }
        }

        if max_count + max_count > total_votes {
            println!("{}", candidates[max_index]);
            return;
        }

        if losers.len() == num_remaining {
            println!("VOID");
            return;
        }

        // Eliminate losers by redistributing ballots
        for j in &losers {
            eliminated[*j] = true;
        }

        for i in 0..num_ballots {
            let mut winners = Vec::<usize>::new();
            let mut losers_tally = Fraction::from_i64(0);

            for j in &losers {
                losers_tally = losers_tally + ballots[i][*j];
            }

            let mut big = Fraction::from_i64(0);

            for j in 0..num_candidates {
                if eliminated[j] {
                    continue;
                }

                if ballots[i][j] > big {
                    big = ballots[i][j];
                    winners.clear();
                }
                if ballots[i][j] >= big {
                    winners.push(j);
                }
            }
            losers_tally.denominator *= winners.len() as i64;
            losers_tally.reduce();

            for j in winners {
                ballots[i][j] = ballots[i][j] + losers_tally;
            }
        }
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
