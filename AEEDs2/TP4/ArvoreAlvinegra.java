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
public class ArvoreAlvinegra implements Cloneable {

  public static class Jogador {
    private String nome;
    private Jogador esquerda;
    private Jogador direita;
    private Jogador pai;
    private boolean cor;

    public Jogador(String nome) {
      this.nome = nome;
      this.cor = true; // true para vermelho, false para preto
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

    public Jogador getPai() {
      return pai;
    }

    public boolean getCor() {
      return cor;
    }

    public void setEsquerda(Jogador esquerda) {
      this.esquerda = esquerda;
    }

    public void setDireita(Jogador direita) {
      this.direita = direita;
    }

    public void setPai(Jogador pai) {
      this.pai = pai;
    }

    public void setCor(boolean cor) {
      this.cor = cor;
    }
  }

  private Jogador raiz;

  public ArvoreAlvinegra() {
    this.raiz = null;
  }

  public void rotacaoEsquerda(Jogador nodo) {
    Jogador direita = nodo.getDireita();
    nodo.setDireita(direita.getEsquerda());
    if (nodo.getDireita() != null) {
      nodo.getDireita().setPai(nodo);
    }
    direita.setPai(nodo.getPai());
    if (nodo.getPai() == null) {
      this.raiz = direita;
    } else if (nodo == nodo.getPai().getEsquerda()) {
      nodo.getPai().setEsquerda(direita);
    } else {
      nodo.getPai().setDireita(direita);
    }
    direita.setEsquerda(nodo);
    nodo.setPai(direita);
  }

  public void rotacaoDireita(Jogador nodo) {
    Jogador esquerda = nodo.getEsquerda();
    nodo.setEsquerda(esquerda.getDireita());
    if (nodo.getEsquerda() != null) {
      nodo.getEsquerda().setPai(nodo);
    }
    esquerda.setPai(nodo.getPai());
    if (nodo.getPai() == null) {
      this.raiz = esquerda;
    } else if (nodo == nodo.getPai().getEsquerda()) {
      nodo.getPai().setEsquerda(esquerda);
    } else {
      nodo.getPai().setDireita(esquerda);
    }
    esquerda.setDireita(nodo);
    nodo.setPai(esquerda);
  }

  public void inserir(String nome) {
    Jogador jogador = new Jogador(nome);
    if (raiz == null) {
      raiz = jogador;
      raiz.setCor(false);
    } else {
      Jogador atual = raiz;
      Jogador pai = null;
      while (true) {
        pai = atual;
        int comp = nome.compareTo(atual.getNome());
        if (comp < 0) {
          atual = atual.getEsquerda();
          if (atual == null) {
            pai.setEsquerda(jogador);
            jogador.setPai(pai);
            break;
          }
        } else if (comp > 0) {
          atual = atual.getDireita();
          if (atual == null) {
            pai.setDireita(jogador);
            jogador.setPai(pai);
            break;
          }
        } else {
          // Elemento já existe, não inserir
          return;
        }
      }
      ajustarAposInsercao(jogador);
    }
  }

  public String pesquisar(String nome) {
    Jogador atual = raiz;
    StringBuilder caminho = new StringBuilder("raiz");
    while (atual != null) {
      ArvoreAlvinegra.contComparacoes++;
      int comp = nome.compareTo(atual.getNome());
      if (comp < 0) {
        caminho.append(" esq");
        atual = atual.getEsquerda();
      } else if (comp > 0) {
        caminho.append(" dir");
        atual = atual.getDireita();
      } else {
        return caminho.toString() + " SIM"; // elemento encontrado
      }
    }
    return caminho.toString() + " NAO"; // elemento não encontrado
  }

  public void ajustarAposInsercao(Jogador nodo) {
    while (nodo != raiz && nodo.getPai().getCor() == true) {
      if (nodo.getPai() == nodo.getPai().getPai().getEsquerda()) {
        Jogador tio = nodo.getPai().getPai().getDireita();
        if (tio != null && tio.getCor() == true) {
          nodo.getPai().setCor(false);
          tio.setCor(false);
          nodo.getPai().getPai().setCor(true);
          nodo = nodo.getPai().getPai();
        } else {
          if (nodo == nodo.getPai().getDireita()) {
            nodo = nodo.getPai();
            rotacaoEsquerda(nodo);
          }
          nodo.getPai().setCor(false);
          nodo.getPai().getPai().setCor(true);
          rotacaoDireita(nodo.getPai().getPai());
        }
      } else {
        Jogador tio = nodo.getPai().getPai().getEsquerda();
        if (tio != null && tio.getCor() == true) {
          nodo.getPai().setCor(false);
          tio.setCor(false);
          nodo.getPai().getPai().setCor(true);
          nodo = nodo.getPai().getPai();
        } else {
          if (nodo == nodo.getPai().getEsquerda()) {
            nodo = nodo.getPai();
            rotacaoDireita(nodo);
          }
          nodo.getPai().setCor(false);
          nodo.getPai().getPai().setCor(true);
          rotacaoEsquerda(nodo.getPai().getPai());
        }
      }
    }
    raiz.setCor(false);
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
  public ArvoreAlvinegra(int id, String nome, int altura, int peso, String universidade, int anoNascimento,
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
  public ArvoreAlvinegra clone() throws CloneNotSupportedException {
    return (ArvoreAlvinegra) super.clone();
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
    List<ArvoreAlvinegra> jogadores = new ArrayList<>();
    ArvoreAlvinegra arvore = new ArvoreAlvinegra();
    Scanner input = new Scanner(System.in);
    String id;
    String matricula = "802371";
    long tempoExecucao = 0;

    // Loop para ler a entrada do usuário e adicionar jogadores à lista
    while (!(id = input.nextLine()).equals("FIM")) {
      ArvoreAlvinegra jogador = new ArvoreAlvinegra();
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
      FileWriter fileWriter = new FileWriter("802371_alvinegra.txt", false);
      PrintWriter printWriter = new PrintWriter(fileWriter);
      printWriter.printf("%s\t%d\t%d\n", matricula, tempoExecucao, ArvoreAlvinegra.contComparacoes);
      printWriter.close();
    } catch (IOException e) {
      e.printStackTrace();
    }

    input.close();
  }

}