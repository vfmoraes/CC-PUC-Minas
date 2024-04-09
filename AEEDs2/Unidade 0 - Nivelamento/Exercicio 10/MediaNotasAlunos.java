import java.util.Scanner;

public class MediaNotasAlunos {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        double somaNotas = 0.0;
        
        for (int contador = 1; contador <= 5; contador++) {
            System.out.print("Digite a nota do aluno " + contador + ": ");
            double nota = scanner.nextDouble();
            
            somaNotas += nota;
        }
        
        double media = somaNotas / 5;
        System.out.println("A média das notas dos alunos é: " + media);
        
        scanner.close();
    }
}
