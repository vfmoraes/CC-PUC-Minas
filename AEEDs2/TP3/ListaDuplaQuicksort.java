/*
 * Nome: Victor Ferraz de Moraes
 * Matrícula: 802371
 * Curso: Ciência da Computação
 */

import java.io.*;
import java.util.*;

class CelulaDupla {
  public ListaDuplaQuicksort data;
  public CelulaDupla ant;
  public CelulaDupla prox;

  public CelulaDupla(ListaDuplaQuicksort data) {
    this.data = data;
    this.ant = null;
    this.prox = null;
  }
}

public class ListaDuplaQuicksort implements Cloneable, Comparable<ListaDuplaQuicksort> {

  private int id;
  private String nome;
  private int altura;
  private int peso;
  private String universidade;
  private int anoNascimento;
  private String cidadeNascimento;
  private String estadoNascimento;

  private CelulaDupla primeiro;
  private CelulaDupla ultimo;

  public ListaDuplaQuicksort() {
    this.primeiro = new CelulaDupla(null);
    this.ultimo = primeiro;
  }

  public ListaDuplaQuicksort(int id, String nome, int altura, int peso, String universidade, int anoNascimento,
      String cidadeNascimento, String estadoNascimento) {
    this.id = id;
    this.nome = nome;
    this.altura = altura;
    this.peso = peso;
    this.universidade = universidade;
    this.anoNascimento = anoNascimento;
    this.cidadeNascimento = cidadeNascimento;
    this.estadoNascimento = estadoNascimento;
    this.primeiro = new CelulaDupla(null);
    this.ultimo = primeiro;
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
  public ListaDuplaQuicksort clone() throws CloneNotSupportedException {
    return (ListaDuplaQuicksort) super.clone();
  }

  @Override
  public int compareTo(ListaDuplaQuicksort outro) {
    if (this.estadoNascimento == null || outro.estadoNascimento == null) {
      if (this.estadoNascimento == null && outro.estadoNascimento == null) {
        return 0;
      } else if (this.estadoNascimento == null) {
        return 1;
      } else {
        return -1;
      }
    } else if (this.estadoNascimento.equals(outro.estadoNascimento)) {
      return this.nome.compareTo(outro.nome);
    } else {
      return this.estadoNascimento.compareTo(outro.estadoNascimento);
    }
  }

  @Override
  public String toString() {
    return "[" + id + " ## " + nome + " ## " + altura + " ## " + peso + " ## " + anoNascimento + " ## " + universidade
        + " ## " + cidadeNascimento + " ## " + estadoNascimento + "]";
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
          this.cidadeNascimento = data.length > 6 ? (data[6].equals("") ? "nao informado" : data[6]) : "nao informado";
          this.estadoNascimento = data.length > 7 ? (data[7].equals("") ? "nao informado" : data[7]) : "nao informado";
          break;
        }
      }
      br.close();
    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  public void adicionarJogador(ListaDuplaQuicksort jogador) {
    CelulaDupla novaCelula = new CelulaDupla(jogador);
    novaCelula.ant = ultimo;
    ultimo.prox = novaCelula;
    ultimo = novaCelula;
  }

  public static void ordenarPorQuicksort(ListaDuplaQuicksort lista, CelulaDupla esq, CelulaDupla dir) {
    if (esq != null && dir != null && esq != dir && esq.ant != dir) {
      CelulaDupla j = partition(lista, esq, dir);
      ordenarPorQuicksort(lista, esq, j.ant);
      ordenarPorQuicksort(lista, j.prox, dir);
    }
  }

  public static CelulaDupla partition(ListaDuplaQuicksort lista, CelulaDupla esq, CelulaDupla dir) {
    ListaDuplaQuicksort pivo = dir.data;
    CelulaDupla i = esq.ant;

    for (CelulaDupla j = esq; j != null && j != dir.prox; j = j.prox) {
      if (j.data.compareTo(pivo) <= 0) {
        i = (i == null) ? esq : i.prox;
        troca(lista, i, j);
      }
    }

    return i;
  }

  public static void troca(ListaDuplaQuicksort lista, CelulaDupla i, CelulaDupla j) {
    ListaDuplaQuicksort temp = i.data;
    i.data = j.data;
    j.data = temp;
  }

  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    ListaDuplaQuicksort jogadores = new ListaDuplaQuicksort();

    String id;

    while (!(id = input.nextLine()).equals("FIM")) {
      ListaDuplaQuicksort jogador = new ListaDuplaQuicksort();
      jogador.ler(id);
      jogadores.adicionarJogador(jogador);
    }

    CelulaDupla ultimaCelula = jogadores.ultimo;
    ordenarPorQuicksort(jogadores, jogadores.primeiro.prox, ultimaCelula);

    for (CelulaDupla atual = jogadores.primeiro.prox; atual != null; atual = atual.prox) {
      System.out.println(atual.data.toString());
    }

    input.close();
  }
}
