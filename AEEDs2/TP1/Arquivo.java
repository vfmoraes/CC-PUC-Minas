/*
 * Nome: Victor Ferraz de Moraes
 * Matrícula: 802371
 * Curso: Ciência da Computação
 */

import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.*;

public class Arquivo {
  
  public static void main(String args[]) throws IOException {
    int n; // Variável para armazenar a quantidade de números a serem lidos
    double num; // Variável para armazenar os números lidos
    Scanner sc = new Scanner(System.in); // Cria um objeto Scanner para entrada de dados
    n = sc.nextInt(); // Lê a quantidade de números a serem lidos
    RandomAccessFile escrita = new RandomAccessFile("teste", "rw"); // Abre um arquivo para escrita

    // Loop para ler e escrever os números no arquivo
    for (int i = 0; i < n; i++) {
      num = sc.nextDouble(); // Lê um número da entrada padrão
      escrita.writeDouble(num); // Escreve o número no arquivo
    }

    escrita.close(); // Fecha o arquivo de escrita
    sc.close(); // Fecha o Scanner de entrada

    RandomAccessFile leitura = new RandomAccessFile("teste", "r"); // Abre o mesmo arquivo para leitura

    // Posiciona o cursor no último número no arquivo (n * 8 - 8 bytes antes do fim)
    leitura.seek(n * 8 - 8);

    // Loop para ler e imprimir os números do arquivo em ordem reversa
    for (int i = 1; i < n; i++) {
      num = leitura.readDouble(); // Lê um número do arquivo
      if (num % 1 == 0)
        MyIO.println((int) num); // Se o número for um número inteiro, imprime como inteiro
      else
        MyIO.println(num); // Caso contrário, imprime como número de ponto flutuante
      leitura.seek(leitura.getFilePointer() - 16); // Move o cursor 16 bytes para trás no arquivo (tamanho de um double)
    }

    MyIO.println(leitura.readDouble()); // Lê e imprime o primeiro número no arquivo (primeiro na ordem original)
    leitura.close(); // Fecha o arquivo de leitura
  }
}
