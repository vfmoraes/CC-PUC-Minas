
/*
EP_04 - Leitura de instruções de um arquivo .ula e geração de um arquivo hexadecimal
Membros do grupo:
- Luís Augusto Lima de Oliveira (805413)
- Samuel Horta de Faria (801528)
- Victor Ferraz de Moraes (802371)

Criação: 09/04/2024
 */
import java.util.*;
import java.io.*;

public class Instrutor {
  public static void main(String[] args) {

    // Limpa o arquivo testeula.hex antes da execução
    try {
      RandomAccessFile rf = new RandomAccessFile("testeula.hex", "rw");
      rf.setLength(0);
      rf.close();
    } catch (Exception e) {
      e.printStackTrace();
    }

    // Variáveis para armazenar os valores de X, Y e W
    String x = " ", y = " ", w = " ";

    try {
      // Lendo do arquivo testeula.ula
      File arquivo = new File("testeula.ula");
      FileWriter escreverArquivo = new FileWriter("testeula.hex", true);
      Scanner sc = new Scanner(arquivo);
      // Enquanto houver linhas no arquivo, lê a linha
      while (sc.hasNextLine()) {
        String linha = sc.nextLine();
        // Ler a linha, se for X, Y ou W, atribui a variável correspondente
        if (linha.contains("X=")) {
          x = linha.substring(2, 3);
          System.out.println("X = " + x);
        }
        if (linha.contains("Y=")) {
          y = linha.substring(2, 3);
          System.out.println("Y = " + y);
        }
        if (linha.contains("W=")) {
          // Obtém a parte da linha após "W="
          String instrucao = linha.substring(2, linha.length()-1).trim(); // Utilizando trim() para remover espaços em branco antes e depois, além de não armazenar o ;
          System.out.println("W = " + instrucao);

          // Comparando instrucao diretamente com os mnemônicos

          if (instrucao.equals("nB")) {
            w = "0";
          } else if (instrucao.equals("nAeBn")) {
            w = "1";
          } else if (instrucao.equals("nAeB")) {
            w = "2";
          } else if (instrucao.equals("Lzero")) {
            w = "3";
          } else if (instrucao.equals("AeBn")) {
            w = "4";
          } else if (instrucao.equals("nA")) {
            w = "5";
          } else if (instrucao.equals("AXB")) {
            w = "6";
          } else if (instrucao.equals("AenB")) {
            w = "7";
          } else if (instrucao.equals("nAonB")) {
            w = "8";
          } else if (instrucao.equals("nAXnB")) {
            w = "9";
          } else if (instrucao.equals("Bcopia")) {
            w = "A";
          } else if (instrucao.equals("AeB")) {
            w = "B";
          } else if (instrucao.equals("Lum")) {
            w = "C";
          } else if (instrucao.equals("AonB")) {
            w = "D";
          } else if (instrucao.equals("AoB")) {
            w = "E";
          } else if (instrucao.equals("Acopia")) {
            w = "F";
          } else {
            // Nenhuma instrução encontrada
            System.out.println("Instrução inválida");
          }

          // Imprime o valor de W e a instrução
          System.out.println("W = " + w);
          System.out.println("Instrução: " + x + y + w);
          // Escreve no arquivo testeula.hex uma linha contendo X, Y e W, formando a
          // instrução
          escreverArquivo.write(x + y + w + "\n");
        }
      }
      // Escreve o fim do arquivo .hex
      escreverArquivo.write("fim");
      // Fecha o Scanner e Arquivo de escrita
      escreverArquivo.close();
      sc.close();
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    } catch (IOException e) {
      e.printStackTrace();
    }

  }
}
