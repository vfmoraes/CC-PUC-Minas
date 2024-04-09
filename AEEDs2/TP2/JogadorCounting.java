/*
 * Nome: Victor Ferraz de Moraes
 * Matrícula: 802371
 * Curso: Ciência da Computação
 */

// Importação das classes necessárias
import java.io.*;
import java.util.*;

// Classe Jogador que implementa a interface Cloneable (necessária para o método clone) e Comparable (necessária para ordenação)
public class JogadorCounting implements Cloneable, Comparable<JogadorCounting> {

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
  public JogadorCounting() {
    // Inicializa o objeto sem definir valores para os atributos
  }

  // Construtor com todos os atributos como argumentos
  public JogadorCounting(int id, String nome, int altura, int peso, String universidade, int anoNascimento,
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
  public JogadorCounting clone() throws CloneNotSupportedException {
    return (JogadorCounting) super.clone();
  }

  // Método que permite a comparação entre dois Jogadores pela altura, necessário
  // para a ordenação
  @Override
  public int compareTo(JogadorCounting outro) {
    if (this.altura == outro.altura) { // Se a altura for igual, compara o nome
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

  private static int[] contarElementos(JogadorCounting[] jogadores) {
    int k = 0;
    for (JogadorCounting jogador : jogadores) {
      k = Math.max(k, jogador.getAltura());
    }

    int[] c = new int[k + 1];
    Arrays.fill(c, 0);

    for (JogadorCounting jogador : jogadores) {
      c[jogador.getAltura()] += 1;
    }

    for (int i = 1; i < c.length; i++) {
      c[i] += c[i - 1];
    }

    return c;
  }

  public static void ordenarPorCountingSort(JogadorCounting[] jogadores, String matricula) {
    int[] numComparacoes = { 0 };
    int[] numMovimentacoes = { 0 };
    long tempoInicial = System.nanoTime();

    int[] c = contarElementos(jogadores);
    JogadorCounting[] ordenados = new JogadorCounting[jogadores.length];

    for (int i = jogadores.length - 1; i >= 0; i--) {
      numMovimentacoes[0]++;
      ordenados[c[jogadores[i].getAltura()] - 1] = jogadores[i];
      c[jogadores[i].getAltura()]--;
    }

    for (int i = 0; i < jogadores.length; i++) {
      jogadores[i] = ordenados[i];
    }

    for (int i = 1; i < jogadores.length; i++) {
      JogadorCounting chave = jogadores[i];
      int j = i - 1;

      while (j >= 0 && jogadores[j].getAltura() == chave.getAltura()
          && jogadores[j].getNome().compareTo(chave.getNome()) > 0) {
        jogadores[j + 1] = jogadores[j];
        j = j - 1;
      }

      jogadores[j + 1] = chave;
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
      PrintWriter pw = new PrintWriter(new FileWriter("matricula_countingsort.txt"));
      pw.println(matricula + "\t" + numComparacoes + "\t" + numMovimentacoes + "\t" + tempoExecucao);
      pw.close();
    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  // Método main - ponto de entrada do programa
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    ArrayList<JogadorCounting> jogadores = new ArrayList<>();
    String id;

    // Loop que continua lendo a entrada do usuário até que a palavra "FIM" seja
    // inserida
    while (!(id = input.nextLine()).equals("FIM")) {
      JogadorCounting jogador = new JogadorCounting(); // Cria um novo objeto Jogador
      jogador.ler(id); // Lê os atributos do jogador a partir do arquivo CSV
      jogadores.add(jogador); // Adiciona o jogador ao ArrayList
    }

    JogadorCounting[] arrayJogadores = jogadores.toArray(new JogadorCounting[0]);
    ordenarPorCountingSort(arrayJogadores, "802371");

    for (JogadorCounting jogador : arrayJogadores) {
      System.out.println(jogador.toString());
    }

    input.close(); // Fecha o Scanner
  }
}