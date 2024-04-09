/*
 * Nome: Victor Ferraz de Moraes
 * Matrícula: 802371
 * Curso: Ciência da Computação
 */

import java.util.Scanner;

public class PalindromoRecursivo {
    // Função recursiva que verifica se uma string é um palíndromo
    public static boolean isPalindromo(String palavra) {
        // Caso base: uma string vazia ou com um único caractere é sempre um palíndromo
        if (palavra.length() <= 1) {
            return true;
        } else {
            // Compara o primeiro e o último caractere da string
            char primeiro = palavra.charAt(0);
            char ultimo = palavra.charAt(palavra.length() - 1);
            
            // Se os caracteres forem diferentes, a string não é um palíndromo
            if (primeiro != ultimo) {
                return false;
            } else {
                // Chama a função recursivamente com a substring sem o primeiro e último caractere
                String subPalavra = palavra.substring(1, palavra.length() - 1);
                return isPalindromo(subPalavra);
            }
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String entrada = sc.nextLine();
        // Lê strings da entrada padrão até encontrar a palavra "FIM"
        while (!entrada.equals("FIM")) {
            if (isPalindromo(entrada)) {
                System.out.println("SIM"); // Se for um palíndromo, imprime "SIM"
            } else {
                System.out.println("NAO"); // Se não for um palíndromo, imprime "NAO"
            }
            entrada = sc.nextLine(); // Lê a próxima entrada
        }
        sc.close(); // Fecha o scanner quando não precisamos mais
    }
}
