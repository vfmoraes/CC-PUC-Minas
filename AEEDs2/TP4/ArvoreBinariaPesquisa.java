/*
 * Nome: Victor Ferraz de Moraes
 * Matrícula: 802371
 * Curso: Ciência da Computação
 */

// Importação das classes necessárias
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Classe Jogador que implementa a interface Cloneable (necessária para o método clone)
public class ArvoreBinariaPesquisa implements Cloneable {

  public static class Jogador {
    private String nome;
    private Jogador esquerda;
    private Jogador direita;

    public Jogador(String nome) {
      this.nome = nome;
    }

    public String getNome() {
      return nome;
    }

    public Jogador getEsquerda() {
      return esquerda;
    }

    public Jogador getDireita() {
      return direita;
    }

    public void setEsquerda(Jogador esquerda) {
      this.esquerda = esquerda;
    }

    public void setDireita(Jogador direita) {
      this.direita = direita;
    }
  }

  public static class ArvoreBinaria {
    private Jogador raiz;

    public ArvoreBinaria() {
      this.raiz = null;
    }

    public void inserir(String nome) {
      Jogador jogador = new Jogador(nome);
      if (raiz == null) {
        raiz = jogador;
      } else {
        Jogador atual = raiz;
        Jogador pai;
        while (true) {
          pai = atual;
          int comp = nome.compareTo(atual.getNome());
          if (comp < 0) {
            atual = atual.getEsquerda();
            if (atual == null) {
              pai.setEsquerda(jogador);
              return;
            }
          } else if (comp > 0) {
            atual = atual.getDireita();
            if (atual == null) {
              pai.setDireita(jogador);
              return;
            }
          } else {
            // Elemento já existe, não inserir
            return;
          }
        }
      }
    }

    public String pesquisar(String nome) {
      Jogador atual = raiz;
      StringBuilder caminho = new StringBuilder("raiz");
      while (atual != null) {
        ArvoreBinariaPesquisa.contComparacoes++;
        int comp = nome.compareTo(atual.getNome());
        if (comp < 0) {
          atual = atual.getEsquerda();
          caminho.append(" esq");
        } else if (comp > 0) {
          atual = atual.getDireita();
          caminho.append(" dir");
        } else {
          return caminho.toString() + " SIM"; // elemento encontrado
        }
      }
      return caminho.toString() + " NAO"; // elemento não encontrado
    }
  }

  public static int contComparacoes = 0;

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
  public ArvoreBinariaPesquisa() {
    // Inicializa o objeto sem definir valores para os atributos
  }

  // Construtor com todos os atributos como argumentos
  public ArvoreBinariaPesquisa(int id, String nome, int altura, int peso, String universidade, int anoNascimento,
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
  public ArvoreBinariaPesquisa clone() throws CloneNotSupportedException {
    return (ArvoreBinariaPesquisa) super.clone();
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

  // Método main - ponto de entrada do programa
  public static void main(String[] args) {
    List<ArvoreBinariaPesquisa> jogadores = new ArrayList<>();
    ArvoreBinaria arvore = new ArvoreBinaria();
    Scanner input = new Scanner(System.in);
    String id;
    String matricula = "802371";
    long tempoExecucao = 0;

    // Loop para ler a entrada do usuário e adicionar jogadores à lista
    while (!(id = input.nextLine()).equals("FIM")) {
      ArvoreBinariaPesquisa jogador = new ArvoreBinariaPesquisa();
      jogador.ler(id);
      jogadores.add(jogador);
      arvore.inserir(jogador.getNome());
    }

    // Loop para ler a entrada do usuário e pesquisar jogadores na lista
    while (!(id = input.nextLine()).equals("FIM")) {
      long startTime = System.nanoTime();
      String resultado = arvore.pesquisar(id);
      long endTime = System.nanoTime();
      tempoExecucao += endTime - startTime;
      System.out.println(id + " " + resultado);
    }

    // Escrever no arquivo de log
    try {
      FileWriter fileWriter = new FileWriter("802371_arvoreBinaria.txt", false);
      PrintWriter printWriter = new PrintWriter(fileWriter);
      printWriter.printf("%s\t%d\t%d\n", matricula, tempoExecucao, ArvoreBinariaPesquisa.contComparacoes);
      printWriter.close();
    } catch (IOException e) {
      e.printStackTrace();
    }

    input.close();
  }

}