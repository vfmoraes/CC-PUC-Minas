/*
 * Nome: Victor Ferraz de Moraes
 * Matrícula: 802371
 * Curso: Ciência da Computação
 */

import java.util.*;

public class Tpex3 {
    // Função para aplicar a cifra de César a uma palavra
    public static String CifradeCesar(String palavra){
        int tam = palavra.length();
        String cesar = "";
        int aux;
        for (int i = 0; i < tam; i++){
            aux = (int)palavra.charAt(i);
            aux += 3; // Desloca cada caractere 3 posições no código ASCII
            cesar += (char)aux;
        }
        return cesar; // Retorna a palavra cifrada
    }
    
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String entrada = MyIO.readLine(); // Lê a entrada da linha de comando
        String saida;
        while(!entrada.equals("FIM")){
            saida = CifradeCesar(entrada); // Aplica a cifra de César à entrada
            MyIO.println(saida); // Imprime a palavra cifrada
            entrada = MyIO.readLine(); // Lê a próxima entrada
        }
        sc.close(); // Fecha o scanner quando não precisamos mais
    }
}
