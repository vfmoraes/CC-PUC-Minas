import java.util.Scanner;

public class MediaNotasAlunos {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int contador = 1;
        double somaNotas = 0.0;
        
        while (contador <= 5) {
            System.out.print("Digite a nota do aluno " + contador + ": ");
            double nota = scanner.nextDouble();
            
            somaNotas += nota;
            contador++;
        }
        
        double media = somaNotas / 5;
        System.out.println("A média das notas dos alunos é: " + media);
        
        scanner.close();
    }
}
