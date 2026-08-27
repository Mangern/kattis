import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        var n = new BigInteger(sc.nextLine(), 10);
        sc.close();

        if (!n.isProbablePrime(10)) {
            System.out.println("Nei");
            return;
        }

        var up = n.add(new BigInteger("2"));
        var down = n.add(new BigInteger("-2"));

        if (up.isProbablePrime(10) || down.isProbablePrime(10)) {
            System.out.println("Ja");
        } else {
            System.out.println("Nei");
        }
    }
}
