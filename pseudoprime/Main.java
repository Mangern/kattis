import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            long p = sc.nextInt();
            long a = sc.nextInt();
            if (p == 0 && a == 0) break;

            boolean is_prime = BigInteger.valueOf(p).isProbablePrime(10);
            boolean is_pseudo = modpow(a, p, p) == a;

            if (is_pseudo && !is_prime) {
                System.out.println("yes");
            } else {
                System.out.println("no");
            }
        }
        sc.close();
    }

    public static long modpow(long a, long b, long p) {
        if (b == 0) return 1;
        long r = modpow(a, b >> 1, p);
        r = (r * r) % p;
        if (b % 2 == 1) {
            r = (r * a) % p;
        }
        return r;
    }
}
