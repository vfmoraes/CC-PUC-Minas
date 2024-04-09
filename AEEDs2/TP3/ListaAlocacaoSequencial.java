/*
 * Nome: Victor Ferraz de Moraes
 * Matrícula: 802371
 * Curso: Ciência da Computação
 */

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.*;

/**
 * Celula (pilha, lista e fila dinamica)
 * 
 * @author Max do Val Machado
 * @version 2 01/2015
 */
class Celula {
    public JogadorBuilder elemento; // Elemento inserido na celula.
    public Celula prox; // Aponta a celula prox.

    /**
     * Construtor da classe.
     */
    public Celula() {
        this(null);
    }

    /**
     * Construtor da classe.
     * 
     * @param elemento int inserido na celula.
     */
    public Celula(JogadorBuilder elemento) {
        this.elemento = elemento;
        this.prox = null;
    }
}

class Lista {
    private JogadorBuilder[] array;
    private int n;

    /**
     * Construtor da classe.
     */
    public Lista() {
        this(6);
    }

    /**
     * Construtor da classe.
     * 
     * @param tamanho Tamanho da lista.
     */
    public Lista(int tamanho) {
        array = new JogadorBuilder[tamanho];
        n = 0;
    }

    /**
     * Insere um elemento na primeira posição da lista e move os demais elementos para
     * o fim da lista.
     * 
     * @param x JogadorBuilder elemento a ser inserido.
     * @throws Exception Se a lista estiver cheia.
     */
    public void inserirInicio(JogadorBuilder x) throws Exception {
        // validar insercao
        if (n >= array.length) {
            throw new Exception("Erro ao inserir!");
        }

        // levar elementos para o fim do array
        for (int i = n; i > 0; i--) {
            array[i] = array[i - 1];
        }

        array[0] = x;
        n++;
    }

    /**
     * Insere um elemento na última posição da lista.
     * 
     * @param x JogadorBuilder elemento a ser inserido.
     * @throws Exception Se a lista estiver cheia.
     */
    public void inserirFim(JogadorBuilder x) throws Exception {
        // validar insercao
        if (n >= array.length) {
            throw new Exception("Erro ao inserir!");
        }

        array[n] = x;
        n++;
    }

    /**
     * Insere um elemento em uma posição específica e move os demais elementos para o
     * fim da lista.
     * 
     * @param x   JogadorBuilder elemento a ser inserido.
     * @param pos Posição de inserção.
     * @throws Exception Se a lista estiver cheia ou a posição for inválida.
     */
    public void inserir(JogadorBuilder x, int pos) throws Exception {
        // validar insercao
        if (n >= array.length || pos < 0 || pos > n) {
            throw new Exception("Erro ao inserir!");
        }

        // levar elementos para o fim do array
        for (int i = n; i > pos; i--) {
            array[i] = array[i - 1];
        }

        array[pos] = x;
        n++;
    }

    /**
     * Remove um elemento da primeira posição da lista e move os demais elementos
     * para o início da mesma.
     * 
     * @return resp JogadorBuilder elemento a ser removido.
     * @throws Exception Se a lista estiver vazia.
     */
    public JogadorBuilder removerInicio() throws Exception {
        // validar remocao
        if (n == 0) {
            throw new Exception("Erro ao remover!");
        }

        JogadorBuilder resp = array[0];
        n--;

        for (int i = 0; i < n; i++) {
            array[i] = array[i + 1];
        }

        return resp;
    }

    /**
     * Remove um elemento da última posição da lista.
     * 
     * @return resp JogadorBuilder elemento a ser removido.
     * @throws Exception Se a lista estiver vazia.
     */
    public JogadorBuilder removerFim() throws Exception {
        // validar remocao
        if (n == 0) {
            throw new Exception("Erro ao remover!");
        }

        return array[--n];
    }

    /**
     * Remove um elemento de uma posição específica da lista e move os demais
     * elementos para o início da mesma.
     * 
     * @param pos Posição de remoção.
     * @return resp JogadorBuilder elemento a ser removido.
     * @throws Exception Se a lista estiver vazia ou a posição for inválida.
     */
    public JogadorBuilder remover(int pos) throws Exception {
        // validar remocao
        if (n == 0 || pos < 0 || pos >= n) {
            throw new Exception("Erro ao remover!");
        }

        JogadorBuilder resp = array[pos];
        n--;

        for (int i = pos; i < n; i++) {
            array[i] = array[i + 1];
        }

        return resp;
    }

    /**
     * Mostra os elementos da lista separados por espaços.
     */
    public void mostrar() {
        int contador = 0;
        for (int i = 0; i < n; i++) {
            System.out.print("["+contador+"] ");
            array[i].mostrar();
            contador++;
        }
    }

    /**
     * Procura um elemento e retorna se ele existe.
     * 
     * @param x JogadorBuilder elemento a ser pesquisado.
     * @return <code>true</code> se o array existir, <code>false</code> em caso
     *         contrário.
     */
    public boolean pesquisar(JogadorBuilder x) {
        boolean retorno = false;
        for (int i = 0; i < n && !retorno; i++) {
            retorno = (array[i] == x);
        }
        return retorno;
    }
}

class JogadorBuilder {
    private Integer id;
    private String nome;
    private Integer altura;
    private Integer peso;
    private String universidade;
    private Integer anoNascimento;
    private String cidadeNascimento;
    private String estadoNascimento;

    public JogadorBuilder() {
        this.id = null;
        this.nome = null;
        this.altura = null;
        this.peso = null;
        this.universidade = null;
        this.anoNascimento = null;
        this.cidadeNascimento = null;
        this.estadoNascimento = null;
    }

    public JogadorBuilder(Integer id, String nome, Integer altura, Integer peso, String universidade,
            Integer anoNascimento,
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

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Integer getPeso() {
        return peso;
    }

    public void setPeso(Integer peso) {
        this.peso = peso;
    }

    public Integer getAltura() {
        return peso;
    }

    public void setAltura(Integer altura) {
        this.altura = altura;
    }

    public String getUniversidade() {
        return universidade;
    }

    public void setUniversidade(String universidade) {
        this.universidade = universidade;
    }

    public Integer getAnoNascimento() {
        return anoNascimento;
    }

    public void setAnoNascimento(Integer anoNascimento) {
        this.anoNascimento = anoNascimento;
    }

    public String getcidadeNascimento() {
        return cidadeNascimento;
    }

    public void setcidadeNascimento(String cidadeNascimento) {
        this.cidadeNascimento = cidadeNascimento;
    }

    public String getEstadoNascimento() {
        return estadoNascimento;
    }

    public void setEstadoNascimento(String estadoNascimento) {
        this.estadoNascimento = estadoNascimento;
    }

    public void mostrar() {
        System.out.println("## " + (this.nome == null ? "nao informado" : this.nome) + " ## "
                + (this.altura == null ? "nao informado" : this.altura) + " ## "
                + (this.peso == null ? "nao informado" : this.peso) + " ## "
                + (this.anoNascimento == null ? "nao informado" : this.anoNascimento) + " ## "
                + (this.universidade == null ? "nao informado" : this.universidade) + " ## "
                + (this.cidadeNascimento == null ? "nao informado" : this.cidadeNascimento) + " ## "
                + (this.estadoNascimento == null ? "nao informado" : this.estadoNascimento) + " ##");

    }
}

public class ListaAlocacaoSequencial {
    public static void main(String[] args) throws Exception {
        long begin = System.nanoTime();
        Scanner sc = new Scanner(System.in);
        String entrada;
        FileReader file = new FileReader("/tmp/players.csv");
        BufferedReader buffer = new BufferedReader(file);
        int i = 0;
        Lista listaJogador = new Lista(3921);
        JogadorBuilder[] jogador = new JogadorBuilder[3921];
        String read = buffer.readLine();
        read = buffer.readLine();
        while (i < 3921) {
            jogador[i] = build(read);
            i++;
            read = buffer.readLine();
        }
        buffer.close(); // terminou de ler todos para um array de objetos
        entrada = sc.nextLine();
        while (!entrada.equals("FIM")) {
            for (int j = 0; j < jogador.length; j++) {
                if (Integer.parseInt(entrada) > jogador.length) { // se for maior que o limite de jogadores
                    throw new Exception("ERROR! Out of bounds");
                }
                if (jogador[j].getId().toString().equals(entrada)) {
                    listaJogador.inserirFim(jogador[j]);
                    // jogador[j].mostrar(); -> teste
                    break;
                }
            }
            entrada = sc.nextLine();
        }
        entrada = sc.nextLine();
        int limite = Integer.parseInt(entrada);
        String instrucao;
        int idAdd;
        int pos;
        for(int j = 0; j < limite; j++){
            entrada = sc.nextLine();
            instrucao = entrada.substring(0, 2);
            switch(instrucao){
                case "II":
                    idAdd = Integer.parseInt(entrada.substring(3));
                    listaJogador.inserirInicio(retornaBuildado(idAdd, jogador));
                    break;
                case "IF":
                    idAdd = Integer.parseInt(entrada.substring(3));
                    listaJogador.inserirFim(retornaBuildado(idAdd, jogador));
                    break;
                case "I*":
                    pos = Integer.parseInt(entrada.split(" ")[1]);
                    idAdd = Integer.parseInt(entrada.split(" ")[2]);
                    listaJogador.inserir(retornaBuildado(idAdd, jogador), pos);
                    break;
                case "RI":
                    System.out.println("(R) " + listaJogador.removerInicio().getNome());
                    break;
                case "RF":
                    System.out.println("(R) " + listaJogador.removerFim().getNome());
                    break;
                case "R*":
                    pos = Integer.parseInt(entrada.split(" ")[1]);
                    System.out.println("(R) " + listaJogador.remover(pos).getNome());
                    break;
                default:
                System.out.println("Nao existe");
                break;
            }
        }
        // --------------------------------------------------------------------//
        listaJogador.mostrar();
        // --------------------------------------------------------------------//
        sc.close();
        long end = System.nanoTime(); // finaliza contagem de tempo
        long time = end - begin; // calcula o tempo
        // --------------------------Arquivo Log--------------------------------//
        FileWriter writer = new FileWriter("802371.txt");
        writer.write(802371 + "\t" + time + "\t");
        writer.close();
        // --------------------------------------------------------------------//
    }

    public static JogadorBuilder retornaBuildado(int id, JogadorBuilder[] arr){
        for(int i = 0; i < arr.length; i++){
            if(arr[i].getId() == id){
                return arr[i];
            }
        }
        return null;
    }

    /*
     * Itera pela String concatenando os caracteres em uma posição "aux" de um array
     * de Strings, quando encontra uma virgula ele para a concatenação e faz isso
     * para o próximo atributo, até que a String acabe.
     */
    public static JogadorBuilder build(String s) {
        Integer idAux; // converter o id de String para Integer
        Integer alturaAux; // converter a altura de String para Integer
        Integer pesoAux; // converter o peso de String para Integer
        Integer anoNascimentoAux; // converter o ano de nascimento de String para Integer
        int atual = 0; // posição atual da String
        int aux = 0; // posição do array de Strings
        String sArray[] = new String[8];
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != ',') {
                if (sArray[aux] == null) { // inicialia propiamente a String do atributo
                    sArray[aux] = "";
                }
                sArray[aux] += s.charAt(i);
                atual++;
            } else {
                i = atual;
                atual++;
                aux++;
            }
        }

        if (sArray[0] != null) {
            idAux = Integer.parseInt(sArray[0]);
        } else {
            idAux = null;
        }
        if (sArray[2] != null) {
            alturaAux = Integer.parseInt(sArray[2]);
        } else {
            alturaAux = null;
        }
        if (sArray[3] != null) {
            pesoAux = Integer.parseInt(sArray[3]);
        } else {
            pesoAux = null;
        }
        if (sArray[5] != null) {
            anoNascimentoAux = Integer.parseInt(sArray[5]);
        } else {
            anoNascimentoAux = null;
        }

        JogadorBuilder j = new JogadorBuilder(idAux, sArray[1], alturaAux, pesoAux, sArray[4], anoNascimentoAux,
                sArray[6], sArray[7]);
        return j;
    }

}
