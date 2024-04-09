/*
 * Nome: Victor Ferraz de Moraes
 * Matrícula: 802371
 * Curso: Ciência da Computação
 */

// Importação das classes necessárias
import java.io.*;
import java.util.*;

// Classe Jogador que implementa a interface Cloneable (necessária para o método clone) e Comparable (necessária para ordenação)
public class JogadorQuickSortParcial implements Cloneable, Comparable<JogadorQuickSortParcial> {

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
  public JogadorQuickSortParcial() {
    // Inicializa o objeto sem definir valores para os atributos
  }

  // Construtor com todos os atributos como argumentos
  public JogadorQuickSortParcial(int id, String nome, int altura, int peso, String universidade, int anoNascimento,
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
  public JogadorQuickSortParcial clone() throws CloneNotSupportedException {
    return (JogadorQuickSortParcial) super.clone();
  }

  // Método que permite a comparação entre dois Jogadores pelo ano de nascimento,
  // necessário
  // para a ordenação
  @Override
  public int compareTo(JogadorQuickSortParcial outro) {
    if (this.estadoNascimento == null || outro.estadoNascimento == null) {
      if (this.estadoNascimento == null && outro.estadoNascimento == null) {
        // Ambos são nulos, portanto, são considerados iguais
        return 0;
      } else if (this.estadoNascimento == null) {
        // this.estadoNascimento é nulo, então é considerado "maior"
        return 1;
      } else {
        // outro.estadoNascimento é nulo, então this é considerado "menor"
        return -1;
      }
    } else if (this.estadoNascimento.equals(outro.estadoNascimento)) {
      // Se o estadoNascimento for igual, compara pelo nome
      return this.nome.compareTo(outro.nome);
    } else {
      return this.estadoNascimento.compareTo(outro.estadoNascimento);
    }
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

  // Método de ordenação por Quicksort
  public static void ordenarPorQuicksort(JogadorQuickSortParcial[] jogadores, int esq, int dir) {
    if (esq < dir) {
      int j = partition(jogadores, esq, dir);
      ordenarPorQuicksort(jogadores, esq, j - 1);
      ordenarPorQuicksort(jogadores, j + 1, dir);
    }
  }

  public static int partition(JogadorQuickSortParcial[] jogadores, int esq, int dir) {
    JogadorQuickSortParcial pivo = jogadores[dir];
    int i = esq - 1;
    for (int j = esq; j < dir; j++) {
      if (jogadores[j].compareTo(pivo) <= 0) {
        i++;
        troca(jogadores, i, j);
      }
    }
    troca(jogadores, i + 1, dir);
    return i + 1;
  }

  public static void troca(JogadorQuickSortParcial[] jogadores, int i, int j) {
    JogadorQuickSortParcial temp = jogadores[i];
    jogadores[i] = jogadores[j];
    jogadores[j] = temp;
  }

  // Método main - ponto de entrada do programa
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    ArrayList<JogadorQuickSortParcial> jogadores = new ArrayList<>();
    String id;

    // Loop que continua lendo a entrada do usuário até que a palavra "FIM" seja
    // inserida
    while (!(id = input.nextLine()).equals("FIM")) {
      JogadorQuickSortParcial jogador = new JogadorQuickSortParcial(); // Cria um novo objeto Jogador
      jogador.ler(id); // Lê os atributos do jogador a partir do arquivo CSV
      jogadores.add(jogador); // Adiciona o jogador ao ArrayList
    }

    JogadorQuickSortParcial[] arrayJogadores = jogadores.toArray(new JogadorQuickSortParcial[0]);
    ordenarPorQuicksort(arrayJogadores, 0, arrayJogadores.length - 1);

    for (int i = 0; i < 10; i++) {
      System.out.println(arrayJogadores[i].toString());
    }

    input.close(); // Fecha o Scanner
  }
}