import java.util.*;

public class Main {

  static boolean isPrimo(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
      if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
  }

  static boolean isNotPrimo(int n) {
    return !isPrimo(n);
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int perguntas = sc.nextInt();

    for (int i = 0; i < perguntas; i++) {
      int numero = sc.nextInt();
      int x = -1, y = -1;
      int mindiff = Integer.MAX_VALUE;

      for (int j = 1; j <= numero / 2; j++) {
        if (isNotPrimo(j) && isNotPrimo(numero - j)) {
          int k = numero - j;
          int diff = Math.abs(j - k);
          if (diff < mindiff) {
            mindiff = diff;
            x = j;
            y = k;
          }
        }
      }

      if (x != -1 && y != -1) {
        System.out.println(x + " " + y);
      } else {
        System.out.println("-1");
      }
    }

    sc.close();
  }
}