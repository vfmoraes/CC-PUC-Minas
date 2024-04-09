/*
 * Nome: Victor Ferraz de Moraes
 * Matrícula: 802371
 * Curso: Ciência da Computação
 */

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.*;

class Pilha {
    private JogadorBuilder[] array;
    private int topo;
    private int contador = 0;

    public Pilha(int tamanhoMaximo) {
        array = new JogadorBuilder[tamanhoMaximo];
        topo = -1;
    }

    public void inserir(JogadorBuilder x) {
        if (topo < array.length - 1) {
            topo++;
            array[topo] = x;
            contador++;
        } else {
            System.out.println("Erro: Pilha cheia.");
        }
    }

    public JogadorBuilder remover() throws Exception {
        if (topo >= 0) {
            JogadorBuilder resp = array[topo];
            topo--;
            contador--;
            return resp;
        } else {
            throw new Exception("Erro ao remover: Pilha vazia.");
        }
    }

    public void mostrar() {
        int contador = 0;
        for (int i = 0; i <= topo; i++) {
            System.out.print("[" + contador + "] ");
            array[i].mostrar();
            contador++;
        }
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

public class PilhaAlocacaoSequencial {
    public static void main(String[] args) throws Exception {
        long begin = System.nanoTime();
        Scanner sc = new Scanner(System.in);
        String entrada;
        FileReader file = new FileReader("/tmp/players.csv");
        BufferedReader buffer = new BufferedReader(file);
        int i = 0;
        Pilha pilhaJogador = new Pilha(3921);
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
                    pilhaJogador.inserir(jogador[j]);
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
        for(int j = 0; j < limite; j++){
            entrada = sc.nextLine();
            instrucao = entrada.split(" ")[0];
            switch(instrucao){
                case "I":
                    idAdd = Integer.parseInt(entrada.split(" ")[1]);
                    pilhaJogador.inserir(retornaBuildado(idAdd, jogador));
                    break;
                case "R":
                    System.out.println("(R) " + pilhaJogador.remover().getNome());
                    break;
                default:
                System.out.println("Nao existe");
                break;
            }
        }
        // --------------------------------------------------------------------//
        pilhaJogador.mostrar();
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
