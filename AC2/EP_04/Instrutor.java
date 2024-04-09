/*
EP_04 - Leitura de instruções de um arquivo .ula e geração de um arquivo hexadecimal
Membros do grupo:
- Luís Augusto Lima de Oliveira
- Samuel Horta de Faria
- Victor Ferraz de Moraes

Criação: 09/04/2024
 */ 
import java.util.*;
import java.io.*;

public class Instrutor {
  public static void main(String[] args) {

    //Limpa o arquivo testeula.hex antes da execução
    try{
      RandomAccessFile rf = new RandomAccessFile("testeula.hex", "rw");
      rf.setLength(0);
      rf.close();
    } catch(Exception e){
      e.printStackTrace();
    }

    //Variáveis para armazenar os valores de X, Y e W
    String x = " ", y = " ", w = " ";

    try {
      //Lendo do arquivo testeula.ula
      File arquivo = new File("testeula.ula");
      FileWriter escreverArquivo = new FileWriter("testeula.hex", true);
      Scanner sc = new Scanner(arquivo);
      //Enquanto houver linhas no arquivo, lê a linha
      while (sc.hasNextLine()) {
        String linha = sc.nextLine();
        //Ler a linha, se for X, Y ou W, atribui a variável correspondente
        if(linha.contains("X=")){
          x = linha.substring(2, 3);
          System.out.println("X = " + x);
        }
        if(linha.contains("Y=")){
          y = linha.substring(2, 3);
          System.out.println("Y = " + y);
        }
        if(linha.contains("W=")){
          w = linha.substring(2, 3);
          System.out.println("W = " + linha.substring(2));
          //Dependendo do Mnemônico, atribui a W a instrução correspondente, que vai de 0 a F
          if(linha.contains("nB")){
            w = "0";
          }
          else if(linha.contains("nAeBn")){
            w = "1";
          }
          else if(linha.contains("nAeB")){
            w = "2";
          }
          else if(linha.contains("Lzero")){
            w = "3";
          }
          else if(linha.contains("AeBn")){
            w = "4";
          }
          else if(linha.contains("nA")){
            w = "5";
          }
          else if(linha.contains("AxB")){
            w = "6";
          }
          else if(linha.contains("AenB")){
            w = "7";
          }
          else if(linha.contains("nAonB")){
            w = "8";
          }
          else if(linha.contains("nAxnB")){
            w = "9";
          }
          else if(linha.contains("Bcopia")){
            w = "A";
          }
          else if(linha.contains("AeB")){
            w = "B";
          }
          else if(linha.contains("Lum")){
            w = "C";
          }
          else if(linha.contains("AonB")){
            w = "D";
          }
          else if(linha.contains("AoB")){
            w = "E";
          }
          else if(linha.contains("Acopia")){
            w = "F";
          }
          else {
            //Nenhuma instrução encontrada
            System.out.println("Instrução inválida");
          }
          //Imprime o valor de W e a instrução
          System.out.println("W = " + w);
          System.out.println("Instrução: " + x + y + w);
          //Escreve no arquivo testeula.hex uma linha contendo X, Y e W, formando a instrução
          escreverArquivo.write(x + y + w + "\n");
        }
      }
      //Escreve o fim do arquivo .hex
      escreverArquivo.write("fim");
      //Fecha o Scanner e Arquivo de escrita
      escreverArquivo.close();
      sc.close();
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    } catch (IOException e) {
      e.printStackTrace();
    }
  
  
  }
}