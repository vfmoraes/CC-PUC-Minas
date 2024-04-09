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

public class ArvoreRubroNegra {

  public static class NoRN {
    public boolean cor;
    public String elemento;
    public NoRN esq, dir;

    public NoRN() {
      this(null);
    }

    public NoRN(String elemento) {
      this(elemento, false, null, null);
    }

    public NoRN(String elemento, boolean cor, NoRN esq, NoRN dir) {
      this.cor = cor;
      this.elemento = elemento;
      this.esq = esq;
      this.dir = dir;
    }
  }

  private NoRN raiz;

  public ArvoreRubroNegra() {
    this.raiz = null;
  }

  public void inserir(String nome) {
    NoRN no = new NoRN(nome, true, null, null);
    if (raiz == null) {
      raiz = no;
      raiz.cor = false;
    } else {
      raiz = inserir(raiz, no);
      raiz.cor = false;
    }
  }

  private NoRN inserir(NoRN h, NoRN no) {
    if (h == null)
      return no;

    if (h.elemento.compareTo(no.elemento) > 0) {
      h.esq = inserir(h.esq, no);
    } else if (h.elemento.compareTo(no.elemento) < 0) {
      h.dir = inserir(h.dir, no);
    } else {
      return h; // Não permitir elementos duplicados
    }

    if (isRed(h.dir) && !isRed(h.esq))
      h = rotacaoEsq(h);
    if (isRed(h.esq) && isRed(h.esq.esq))
      h = rotacaoDir(h);
    if (isRed(h.esq) && isRed(h.dir))
      inverterCores(h);

    return h;
  }

  private boolean isRed(NoRN no) {
    if (no == null)
      return false;
    return no.cor == true;
  }

  private NoRN rotacaoDir(NoRN h) {
    NoRN x = h.esq;
    h.esq = x.dir;
    x.dir = h;
    x.cor = h.cor;
    h.cor = true;
    return x;
  }

  private NoRN rotacaoEsq(NoRN h) {
    NoRN x = h.dir;
    h.dir = x.esq;
    x.esq = h;
    x.cor = h.cor;
    h.cor = true;
    return x;
  }

  private void inverterCores(NoRN h) {
    h.cor = !h.cor;
    h.esq.cor = !h.esq.cor;
    h.dir.cor = !h.dir.cor;
  }

  public String pesquisar(String nome) {
    StringBuilder caminho = new StringBuilder("raiz");
    String resultado = pesquisar(raiz, nome, caminho);
    return resultado;
  }

  private String pesquisar(NoRN no, String nome, StringBuilder caminho) {
    while (no != null) {
      int comp = nome.compareTo(no.elemento);

      if (comp < 0) {
        no = no.esq;
        caminho.append(" esq");
      } else if (comp > 0) {
        no = no.dir;
        caminho.append(" dir");
      } else {
        return caminho.toString() + " SIM"; // elemento encontrado
      }
    }

    return caminho.toString() + " NAO"; // elemento não encontrado
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

  // Construtor com todos os atributos como argumentos
  public ArvoreRubroNegra(int id, String nome, int altura, int peso, String universidade, int anoNascimento,
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
  public ArvoreRubroNegra clone() throws CloneNotSupportedException {
    return (ArvoreRubroNegra) super.clone();
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

  public static void main(String[] args) {
    List<ArvoreRubroNegra> jogadores = new ArrayList<>();
    ArvoreRubroNegra arvore = new ArvoreRubroNegra();
    Scanner input = new Scanner(System.in);
    String id;
    String matricula = "802371";
    long tempoExecucao = 0;

    // Loop para ler a entrada do usuário e adicionar jogadores à lista
    while (!(id = input.nextLine()).equals("FIM")) {
      ArvoreRubroNegra jogador = new ArvoreRubroNegra();
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
      printWriter.printf("%s\t%d\t%d\n", matricula, tempoExecucao, ArvoreRubroNegra.contComparacoes);
      printWriter.close();
    } catch (IOException e) {
      e.printStackTrace();
    }

    input.close();
  }
}
