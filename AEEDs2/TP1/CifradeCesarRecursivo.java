/*
 * Nome: Victor Ferraz de Moraes
 * Matrícula: 802371
 * Curso: Ciência da Computação
 */

import java.util.*;

public class CifradeCesarRecursivo {
    // Função recursiva para aplicar a cifra de César a uma palavra
    public static String CifraDeCesar(String palavra, int index) {
        if (index == palavra.length()) {
            return ""; // Caso base: a palavra foi completamente cifrada
        }
        
        char caractere = palavra.charAt(index);
        int codigoASCII = (int) caractere;
        codigoASCII += 3; // Desloca o caractere 3 posições no código ASCII
        char caractereCifrado = (char) codigoASCII;
        
        return caractereCifrado + CifraDeCesar(palavra, index + 1);
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String entrada = MyIO.readLine(); // Lê a entrada da linha de comando
        String saida;
        while(!entrada.equals("FIM")){
            saida = CifraDeCesar(entrada, 0); // Aplica a cifra de César à entrada
            MyIO.println(saida); // Imprime a palavra cifrada
            entrada = MyIO.readLine(); // Lê a próxima entrada
        }
        sc.close(); // Fecha o scanner quando não precisamos mais
    }
}
