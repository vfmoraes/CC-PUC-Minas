/*
 * Nome: Victor Ferraz de Moraes
 * Matrícula: 802371
 * Curso: Ciência da Computação
 */

import java.util.*;

public class Tpex1 {
    // Função que verifica se uma string é um palíndromo
    public static boolean isPalindromo(String palavra) {
        int tam = palavra.length();
        for (int i = 0; i < tam; i++) {
            // Compara o caractere atual com o caractere correspondente no final da string
            if (palavra.charAt(i) != palavra.charAt(tam - i - 1)) {
                return false; // Se não forem iguais, a string não é um palíndromo
            }
        }
        return true; // Se chegarmos aqui, a string é um palíndromo
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
