/*
 * Nome: Victor Ferraz de Moraes
 * Matrícula: 802371
 * Curso: Ciência da Computação
 */

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class tabelaHashReserva implements Cloneable {

  public static class Jogador {
    private int id;
    private String nome;
    private int altura;
    private int peso;
    private String universidade;
    private int anoNascimento;
    private String cidadeNascimento;
    private String estadoNascimento;

    public Jogador() {
    }

    public Jogador(int id, String nome, int altura, int peso, String universidade, int anoNascimento,
        String cidadeNascimento, String estadoNascimento) {
      this.id = id;
      this.nome = nome;
      this.altura = altura;
      this.peso = peso;
      this.universidade = universidade;
      this.anoNascimento = anoNascimento;
      this.cidadeNascimento = cidadeNascimento;
      this.estadoNascimento = estadoNascimento;
    }

    public int getId() {
      return id;
    }

    public String getNome() {
      return nome;
    }

    public int getAltura() {
      return altura;
    }

    public int getPeso() {
      return peso;
    }

    public String getUniversidade() {
      return universidade;
    }

    public int getAnoNascimento() {
      return anoNascimento;
    }

    public String getCidadeNascimento() {
      return cidadeNascimento;
    }

    public String getEstadoNascimento() {
      return estadoNascimento;
    }

    public void setId(int id) {
      this.id = id;
    }

    public void setNome(String nome) {
      this.nome = nome;
    }

    public void setAltura(int altura) {
      this.altura = altura;
    }

    public void setPeso(int peso) {
      this.peso = peso;
    }

    public void setUniversidade(String universidade) {
      this.universidade = universidade;
    }

    public void setAnoNascimento(int anoNascimento) {
      this.anoNascimento = anoNascimento;
    }

    public void setCidadeNascimento(String cidadeNascimento) {
      this.cidadeNascimento = cidadeNascimento;
    }

    public void setEstadoNascimento(String estadoNascimento) {
      this.estadoNascimento = estadoNascimento;
    }

    @Override
    public Jogador clone() throws CloneNotSupportedException {
      return (Jogador) super.clone();
    }

    @Override
    public String toString() {
      return "[" + id + " ## " + nome + " ## " + altura + " ## " + peso + " ## " + anoNascimento + " ## "
          + universidade + " ## " + cidadeNascimento + " ## " + estadoNascimento + "]";
    }

    public void ler(String id) {
      try {
        BufferedReader br = new BufferedReader(new FileReader("/tmp/players.csv"));
        String line;
        while ((line = br.readLine()) != null) {
          String[] data = line.split(",");
          if (data[0].equals(id)) {
            this.id = Integer.parseInt(data[0]);
            this.nome = data[1];
            this.altura = Integer.parseInt(data[2]);
            this.peso = Integer.parseInt(data[3]);
            this.universidade = data[4].equals("") ? "nao informado" : data[4];
            this.anoNascimento = data.length > 5 ? Integer.parseInt(data[5]) : 0;
            this.cidadeNascimento = data.length > 6 ? (data[6].equals("") ? "nao informado" : data[6])
                : "nao informado";
            this.estadoNascimento = data.length > 7 ? (data[7].equals("") ? "nao informado" : data[7])
                : "nao informado";
            break;
          }
        }
        br.close();
      } catch (IOException e) {
        e.printStackTrace();
      }
    }
  }

  public static class TabelaHash {
    public static final int TAMANHO_TABELA = 21;
    public static final int TAMANHO_RESERVA = 9;

    public Jogador[] tabela;
    public Jogador[] reserva;

    public TabelaHash() {
      tabela = new Jogador[TAMANHO_TABELA];
      reserva = new Jogador[TAMANHO_RESERVA];
    }

    public void inserir(Jogador jogador) {
      int hash = calcularHash(jogador.getAltura());
      if (tabela[hash] == null) {
        tabela[hash] = jogador;
      } else {
        int posicaoReserva = buscarPosicaoReserva(hash);
        if (posicaoReserva != -1) {
          reserva[posicaoReserva] = jogador;
        }
      }
    }

    public int buscar(Jogador jogador) {
      int hash = calcularHash(jogador.getAltura());

      if (tabela[hash] != null && tabela[hash].getNome().equals(jogador.getNome())) {
        return hash;
      } else {
        int posicaoReserva = buscarPosicaoReserva(hash);
        if (posicaoReserva != -1 && reserva[posicaoReserva] != null
            && reserva[posicaoReserva].getNome().equals(jogador.getNome())) {
          return posicaoReserva + TabelaHash.TAMANHO_TABELA;
        }
      }

      return -1;
    }

    private int calcularHash(int altura) {
      return altura % TAMANHO_TABELA;
    }

    private int buscarPosicaoReserva(int hash) {
      for (int i = 0; i < TAMANHO_RESERVA; i++) {
        int posicaoReserva = (hash + i) % TAMANHO_RESERVA;
        if (reserva[posicaoReserva] == null) {
          return posicaoReserva;
        }
      }
      return -1;
    }
  }

  public static int contComparacoes = 0;

  public static void main(String[] args) {
    List<Jogador> jogadores = new ArrayList<>();
    Scanner input = new Scanner(System.in);
    String id;
    String matricula = "802371";
    long tempoExecucao = 0;

    TabelaHash tabelaHash = new TabelaHash();

    while (!(id = input.nextLine()).equals("FIM")) {
      Jogador jogador = new Jogador();
      jogador.ler(id);
      jogadores.add(jogador);
      tabelaHash.inserir(jogador);
    }

    while (!(id = input.nextLine()).equals("FIM")) {
      Jogador jogador = new Jogador();
      // Procura o jogador com mesmo nome na lista de jogadores
      for (Jogador j : jogadores) {
        if (j.getNome().equals(id)) {
          jogador = j;
          break;
        }
      }
      long startTime = System.nanoTime();
      int posicao = tabelaHash.buscar(jogador);
      long endTime = System.nanoTime();
      tempoExecucao += endTime - startTime;
      if (posicao != -1) {
        if (posicao < TabelaHash.TAMANHO_TABELA) {
          System.out.println(tabelaHash.tabela[posicao].getNome() + " SIM");
        } else {
          System.out.println(tabelaHash.reserva[posicao - TabelaHash.TAMANHO_TABELA].getNome() + " SIM");
        }
      } else {
        System.out.println(id + " NAO");
      }
    }

    try {
      FileWriter fileWriter = new FileWriter(matricula + "_hashReserva.txt", false);
      PrintWriter printWriter = new PrintWriter(fileWriter);
      printWriter.printf("%s\t%d\t%d\n", matricula, tempoExecucao, contComparacoes);
      printWriter.close();
    } catch (IOException e) {
      e.printStackTrace();
    }

    input.close();
  }

}
