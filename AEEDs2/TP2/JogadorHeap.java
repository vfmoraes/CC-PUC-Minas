/*
 * Nome: Victor Ferraz de Moraes
 * Matrícula: 802371
 * Curso: Ciência da Computação
 */

// Importação das classes necessárias
import java.io.*;
import java.util.*;

// Classe Jogador que implementa a interface Cloneable (necessária para o método clone) e Comparable (necessária para ordenação)
public class JogadorHeap implements Cloneable, Comparable<JogadorHeap> {

  // Declaração dos atributos privados da classe
  private int id;
  private String nome;
  private int altura;
  private int peso;
  private String universidade;
  private int anoNascimento;
  private String cidadeNascimento;
  private String estadoNascimento;

  // Construtor padrão (sem argumentos)
  public JogadorHeap() {
    // Inicializa o objeto sem definir valores para os atributos
  }

  // Construtor com todos os atributos como argumentos
  public JogadorHeap(int id, String nome, int altura, int peso, String universidade, int anoNascimento,
      String cidadeNascimento, String estadoNascimento) {
    // Inicializa o objeto com os valores passados como argumentos
    this.id = id;
    this.nome = nome;
    this.altura = altura;
    this.peso = peso;
    this.universidade = universidade;
    this.anoNascimento = anoNascimento;
    this.cidadeNascimento = cidadeNascimento;
    this.estadoNascimento = estadoNascimento;
  }

  // Getters (métodos para obter os valores dos atributos)
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

  // Setters (métodos para definir os valores dos atributos)
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

  // Método clone para criar uma cópia do objeto
  @Override
  public JogadorHeap clone() throws CloneNotSupportedException {
    return (JogadorHeap) super.clone();
  }

  // Método que permite a comparação entre dois Jogadores pela altura, necessário
  // para a ordenação
  @Override
  public int compareTo(JogadorHeap outro) {
    if (this.altura == outro.altura) { //Se a altura for igual, compara o nome
      return this.nome.compareTo(outro.nome);
    }
    return this.altura - outro.altura;
  }

  // Método toString para representar o objeto como uma string
  @Override
  public String toString() {
    return "[" + id + " ## " + nome + " ## " + altura + " ## " + peso + " ## " + anoNascimento + " ## " + universidade
        + " ## " + cidadeNascimento + " ## " + estadoNascimento + "]";
  }

  // Método para ler os atributos de um jogador a partir de um arquivo CSV
  public void ler(String id) {
    try {
      // Cria um BufferedReader para ler o arquivo
      BufferedReader br = new BufferedReader(new FileReader("/tmp/players.csv"));
      String line;
      // Lê cada linha do arquivo
      while ((line = br.readLine()) != null) {
        // Divide a linha em colunas
        String[] data = line.split(",");
        // Se a linha tem o ID procurado
        if (data[0].equals(id)) {
          // Atribui os valores das colunas aos atributos do objeto
          this.id = Integer.parseInt(data[0]);
          this.nome = data[1];
          this.altura = Integer.parseInt(data[2]);
          this.peso = Integer.parseInt(data[3]);
          this.universidade = data[4].equals("") ? "nao informado" : data[4];
          // Verifica se a linha tem colunas suficientes antes de tentar acessá-las
          this.anoNascimento = data.length > 5 ? Integer.parseInt(data[5]) : 0;
          this.cidadeNascimento = data.length > 6 ? (data[6].equals("") ? "nao informado" : data[6]) : "nao informado";
          this.estadoNascimento = data.length > 7 ? (data[7].equals("") ? "nao informado" : data[7]) : "nao informado";
          break; // Sai do loop, pois já encontrou o jogador com o ID procurado
        }
      }
      br.close(); // Fecha o BufferedReader
    } catch (IOException e) {
      e.printStackTrace(); // Imprime o stack trace se acontecer um erro de IO
    }
  }

  private static void troca(JogadorHeap[] jogadores, int i, int j) {
    JogadorHeap temp = jogadores[i];
    jogadores[i] = jogadores[j];
    jogadores[j] = temp;
  }

  private static void peneira(int tamanhoDoHeap, JogadorHeap[] jogadores, int i, int[] numComparacoes,
      int[] numMovimentacoes) {
    int max = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    numComparacoes[0]++;
    if (esquerda < tamanhoDoHeap && jogadores[esquerda].compareTo(jogadores[max]) > 0) {
      max = esquerda;
    }

    numComparacoes[0]++;
    if (direita < tamanhoDoHeap && jogadores[direita].compareTo(jogadores[max]) > 0) {
      max = direita;
    }

    if (max != i) {
      troca(jogadores, i, max);
      numMovimentacoes[0]++;
      peneira(tamanhoDoHeap, jogadores, max, numComparacoes, numMovimentacoes);
    }
  }

  private static void constroiHeap(JogadorHeap[] jogadores, int tamanhoHeap, int[] numComparacoes,
      int[] numMovimentacoes) {
    for (int i = tamanhoHeap / 2 - 1; i >= 0; i--)
      peneira(tamanhoHeap, jogadores, i, numComparacoes, numMovimentacoes);
  }

  // Método de ordenação por Heapsort
  public static void ordenarPorHeapsort(JogadorHeap[] jogadores, String matricula) {
    int[] numComparacoes = { 0 };
    int[] numMovimentacoes = { 0 };
    long tempoInicial = System.nanoTime();

    int tamanhoDoHeap = jogadores.length;
    constroiHeap(jogadores, tamanhoDoHeap, numComparacoes, numMovimentacoes);

    for (int i = tamanhoDoHeap - 1; i > 0; i--) {
      troca(jogadores, 0, i);
      numMovimentacoes[0]++;
      peneira(i, jogadores, 0, numComparacoes, numMovimentacoes);
    }

    long tempoFinal = System.nanoTime();
    long tempoExecucao = tempoFinal - tempoInicial;

    // Salva as informações de log em um arquivo
    salvarLog(matricula, numComparacoes[0], numMovimentacoes[0], tempoExecucao);
  }

  // Método para salvar as informações de log (número de comparações e
  // movimentações, tempo de execução) em um arquivo
  public static void salvarLog(String matricula, int numComparacoes, int numMovimentacoes, long tempoExecucao) {
    try {
      PrintWriter pw = new PrintWriter(new FileWriter("matricula_heapsort.txt"));
      pw.println(matricula + "\t" + numComparacoes + "\t" + numMovimentacoes + "\t" + tempoExecucao);
      pw.close();
    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  // Método main - ponto de entrada do programa
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    ArrayList<JogadorHeap> jogadores = new ArrayList<>();
    String id;

    // Loop que continua lendo a entrada do usuário até que a palavra "FIM" seja
    // inserida
    while (!(id = input.nextLine()).equals("FIM")) {
      JogadorHeap jogador = new JogadorHeap(); // Cria um novo objeto Jogador
      jogador.ler(id); // Lê os atributos do jogador a partir do arquivo CSV
      jogadores.add(jogador); // Adiciona o jogador ao ArrayList
    }

    JogadorHeap[] arrayJogadores = jogadores.toArray(new JogadorHeap[0]);
    ordenarPorHeapsort(arrayJogadores, "802371");

    for (JogadorHeap jogador : arrayJogadores) {
      System.out.println(jogador.toString());
    }

    input.close(); // Fecha o Scanner
  }
}