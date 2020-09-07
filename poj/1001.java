import java.math.BigDecimal;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            BigDecimal r = new BigDecimal(sc.next());
            String res = r.pow(sc.nextInt())
                    .stripTrailingZeros().toPlainString();
            if (res.charAt(0) == '0') {
                res = res.substring(1);
            }
            System.out.println(res);
        }
        sc.close();
    }
}