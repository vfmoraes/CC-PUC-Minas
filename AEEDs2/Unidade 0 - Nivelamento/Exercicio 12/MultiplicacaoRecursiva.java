import java.util.Scanner;

public class MultiplicacaoRecursiva {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Digite o primeiro número: ");
        int num1 = scanner.nextInt();
        
        System.out.print("Digite o segundo número: ");
        int num2 = scanner.nextInt();
        
        int resultado = multiplicacaoRecursiva(num1, num2);
        
        System.out.println(num1 + " * " + num2 + " = " + resultado);
        
        scanner.close();
    }
    
    public static int multiplicacaoRecursiva(int a, int b) {
        if (b == 0) {
            return 0;
        }
        
        return a + multiplicacaoRecursiva(a, b - 1);
    }
}
