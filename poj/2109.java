import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        BigInteger TWO = new BigInteger("2");
        while (sc.hasNext()) {
            int n = sc.nextInt();
            BigInteger p = sc.nextBigInteger();
            BigInteger left = BigInteger.ONE;
            BigInteger right = p;
            boolean flag = false;
            while (left.compareTo(right) <= 0) {
                BigInteger mid = left.add(right).divide(TWO);
                int cmp = mid.pow(n).compareTo(p);
                if (cmp == -1) {
                    left = mid.add(BigInteger.ONE);
                } else if (cmp == 1) {
                    right = mid.subtract(BigInteger.ONE);
                } else {
                    System.out.println(mid);
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                System.out.println(right);
            }
        }
        sc.close();
    }
}
