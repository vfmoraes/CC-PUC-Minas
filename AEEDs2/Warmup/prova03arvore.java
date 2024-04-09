import java.util.*;

public class prova03arvore {

  public static class No {
    int elemento;
    No esq, dir;

    public No(int e) {
      this.elemento = e;
      esq = null;
      dir = null;
    }

    public No() {
      this(-1);
    }
  }

  public static class ArvoreBinaria {
    private No raiz;

    public ArvoreBinaria() {
      raiz = null;
    }

    No insere(int x) {
      raiz = insere(raiz, x);
      return raiz;
    }

    No insere(No i, int x) {
      if (i == null) {
        i = new No(x);
      } else if (x < i.elemento) {
        i.esq = insere(i.esq, x);
      } else if (x > i.elemento) {
        i.dir = insere(i.dir, x);
      } else {
        System.out.println("Elemento ja existe");
      }
      return i;
    }

    public void mostraNivel() {
      mostraNivel(raiz);
    }

    void mostraNivel(No i) {
      // Cria uma LinkedList e adiciona a raiz
      Queue<No> fila = new LinkedList<No>();
      fila.add(i);
      while (!fila.isEmpty()) {
        No atual = fila.poll();
        System.out.print(atual.elemento + " ");
        if (atual.esq != null) {
          fila.add(atual.esq);
        }
        if (atual.dir != null) {
          fila.add(atual.dir);
        }
      }
      System.out.println();
    }
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int casos = sc.nextInt();

    for (int i = 0; i < casos; i++) {
      int numeros = sc.nextInt();
      ArvoreBinaria arvore = new ArvoreBinaria();
      for (int j = 0; j < numeros; j++) {
        int num = sc.nextInt();
        arvore.insere(num);
      }
      arvore.mostraNivel();
    }
  }
}