import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());

        sc.useRadix(16);

        for (int i = 0; i < n; ++i) {
            String s = sc.nextLine();
            int num = 0;
            int den = 0;

            if (isBin(s)) {
                den += 1;
                var b = new BigInteger(s, 2);
                if (b.isProbablePrime(10))num += 1;
            }
            if (isOct(s)) {
                den += 1;
                var b = new BigInteger(s, 8);
                if (b.isProbablePrime(10))num += 1;
            }
            if (isDec(s)) {
                den += 1;
                var b = new BigInteger(s, 10);
                if (b.isProbablePrime(10))num += 1;
            }
            den += 1;
            var b = new BigInteger(s, 16);
            if (b.isProbablePrime(10))num += 1;

            if (num == 2 && den == 4) {
                num = 1;
                den = 2;
            }
            if (num == 0)den = 1;
            if (num == den) {
                num = 1;
                den = 1;
            }
            System.out.println("" + num + "/" + den);
        }
        sc.close();
    }

    static boolean isBin(String s) {
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (!('0' <= c && c <= '1')) return false;
        }
        return true;
    }
    static boolean isOct(String s) {
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (!('0' <= c && c <= '7')) return false;
        }
        return true;
    }
    static boolean isDec(String s) {
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (!('0' <= c && c <= '9')) return false;
        }
        return true;
    }
}
