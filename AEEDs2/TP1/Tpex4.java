/*
 * Nome: Victor Ferraz de Moraes
 * Matrícula: 802371
 * Curso: Ciência da Computação
 */

import java.util.*;

public class Tpex4 {
    // Função que substitui aleatoriamente uma letra em uma palavra
    public static String TrocaLetra(String palavra, Random gerador){
        // Gera duas letras aleatórias do alfabeto minúsculas
        char letraA = (char)('a' + (Math.abs(gerador.nextInt()) % 26));
        char letraB = (char)('a' + (Math.abs(gerador.nextInt()) % 26));
        String resp = "";
        int tam = palavra.length();
        // Itera sobre cada caractere da palavra
        for (int i = 0; i < tam; i++){
            // Se o caractere atual for igual a letraA, substitui pela letraB
            if(palavra.charAt(i) == letraA){
                resp += letraB;
            } else {
                // Caso contrário, mantém o caractere original
                resp += palavra.charAt(i);
            }
        }
        return resp; // Retorna a palavra modificada
    }
    
    public static void main(String args[]){
        String palavra = MyIO.readLine(); // Lê uma palavra da entrada padrão
        Random gerador = new Random(); // Cria um gerador de números aleatórios
        gerador.setSeed(4); // Define uma semente fixa para o gerador (para repetibilidade)
        while(!palavra.equals("FIM")){ // Continua até a palavra "FIM" ser lida
            MyIO.println(TrocaLetra(palavra, gerador)); // Chama a função TrocaLetra e imprime o resultado
            palavra = MyIO.readLine(); // Lê a próxima palavra
        }
    }
}
