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
public class ArvoreArvorePesquisa implements Cloneable {

    public static class Jogador {
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
        public Jogador() {
            // Inicializa o objeto sem definir valores para os atributos
        }

        // Construtor com todos os atributos como argumentos
        public Jogador(int id, String nome, int altura, int peso, String universidade, int anoNascimento,
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
        public ArvoreArvorePesquisa clone() throws CloneNotSupportedException {
            return (ArvoreArvorePesquisa) super.clone();
        }

        // Método toString para representar o objeto como uma string
        @Override
        public String toString() {
            return "[" + id + " ## " + nome + " ## " + altura + " ## " + peso + " ## " + anoNascimento + " ## "
                    + universidade
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
                        this.cidadeNascimento = data.length > 6 ? (data[6].equals("") ? "nao informado" : data[6])
                                : "nao informado";
                        this.estadoNascimento = data.length > 7 ? (data[7].equals("") ? "nao informado" : data[7])
                                : "nao informado";
                        break; // Sai do loop, pois já encontrou o jogador com o ID procurado
                    }
                }
                br.close(); // Fecha o BufferedReader
            } catch (IOException e) {
                e.printStackTrace(); // Imprime o stack trace se acontecer um erro de IO
            }
        }
    }

    public static int contComparacoes = 0;

    class No1 {

        public int alturaMod15;
        public No1 esq, dir;
        public No2 raiz;

        public No1(int altura) {
            this.alturaMod15 = altura;
            this.raiz = null;
            this.esq = this.dir = null;
        }
    }

    class No2 {

        public String nome;
        public No2 esq, dir;

        public No2(Jogador jogador) {
            this.nome = jogador.getNome();
            this.esq = this.dir = null;
        }
    }

    class ArvoreArvore {

        private No1 raiz;

        public ArvoreArvore() {
            this.raiz = null;
        }

        public ArvoreArvore(int[] alturas) {
            this.Montar(alturas);
        }

        public void Montar(int[] alturas) {
            for (int altura : alturas) {
                this.raiz = this.Montar(this.raiz, altura);
            }
        }

        private No1 Montar(No1 raiz, int alturaMod15) {

            if (raiz == null) {
                raiz = new No1(alturaMod15);
            } else if (alturaMod15 < raiz.alturaMod15) {
                raiz.esq = Montar(raiz.esq, alturaMod15);
            } else if (alturaMod15 > raiz.alturaMod15) {
                raiz.dir = Montar(raiz.dir, alturaMod15);
            }

            return raiz;
        }

        public No1 getRaiz() {
            return this.raiz;
        }

        public static int CompareTo(String nome, No2 raiz) {
            ArvoreArvorePesquisa.contComparacoes++;
            return nome.compareTo(raiz.nome);
        }

        public static int CompareTo(Jogador jogador, No2 raiz) {
            ArvoreArvorePesquisa.contComparacoes++;
            return jogador.getNome().compareTo(raiz.nome);
        }

        public void Mostrar() throws Exception {

            if (this.raiz == null) {
                throw new Exception("Erro ao mostrar Árvore: Árvore vazia.");
            }

            System.out.print("{ ");
            Mostrar(this.raiz);
            System.out.println("\b\b }");
        }

        private void Mostrar(No1 raiz) {

            if (raiz != null) {
                Mostrar(raiz.esq);
                System.out.printf("%d, ", raiz.alturaMod15);
                Mostrar(raiz.dir);
            }
        }

        public void MostrarSub() throws Exception {

            if (this.raiz == null) {
                throw new Exception("Erro ao mostrar Sub Árvores: Árvore vazia.");
            }

            MostrarSub(this.raiz);
        }

        private void MostrarSub(No1 raiz) {

            if (raiz != null) {
                MostrarSub(raiz.esq);
                System.out.printf("AlturaMod15 - %d: \n", raiz.alturaMod15);
                MostrarSub(raiz.raiz);
                System.out.println("-----------------");
                MostrarSub(raiz.dir);
            }
        }

        private void MostrarSub(No2 raiz) {

            if (raiz != null) {
                MostrarSub(raiz.esq);
                System.out.println(raiz.nome);
                MostrarSub(raiz.dir);
            }
        }

        public void Inserir(Jogador jogador) {
            No1 pesquisado = Pesquisar(this.raiz, jogador.getAltura() % 15);
            pesquisado.raiz = Inserir(pesquisado.raiz, jogador);
        }

        private No1 Pesquisar(No1 raiz, int alturaMod15) {

            No1 pesquisado = raiz;

            if (alturaMod15 % 15 < raiz.alturaMod15) {
                pesquisado = Pesquisar(raiz.esq, alturaMod15);
            } else if (alturaMod15 % 15 > raiz.alturaMod15) {
                pesquisado = Pesquisar(raiz.dir, alturaMod15);
            }

            return pesquisado;
        }

        private No2 Inserir(No2 raiz, Jogador jogador) {

            if (raiz == null) {
                raiz = new No2(jogador);
            } else if (CompareTo(jogador, raiz) < 0) {
                raiz.esq = Inserir(raiz.esq, jogador);
            } else if (CompareTo(jogador, raiz) > 0) {
                raiz.dir = Inserir(raiz.dir, jogador);
            }

            return raiz;
        }
    }

        static public boolean Pesquisar(ArvoreArvore arvore, String nome) {
            System.out.printf("%s raiz ", nome);
            return Pesquisar(arvore.getRaiz(), nome);
        }

        static private boolean Pesquisar(No1 raiz, String nome) {

            boolean resultado = false;

            if (raiz != null) {

                resultado = Pesquisar(raiz.raiz, nome);

                if (!resultado) {
                    System.out.printf("esq ");
                    resultado = Pesquisar(raiz.esq, nome);
                }

                if (!resultado) {
                    System.out.printf("dir ");
                    resultado = Pesquisar(raiz.dir, nome);
                }
            }

            return resultado;
        }

        static private boolean Pesquisar(No2 raiz, String nome) {

            boolean resultado = false;

            if (raiz != null) {

                resultado = ArvoreArvore.CompareTo(nome, raiz) == 0;

                if (!resultado) {
                    System.out.printf("ESQ ");
                    resultado = Pesquisar(raiz.esq, nome);
                }

                if (!resultado) {
                    System.out.printf("DIR ");
                    resultado = Pesquisar(raiz.dir, nome);
                }
            }

            return resultado;
        }



        // Método main - ponto de entrada do programa
        public static void main(String[] args) {
            // int[] alturas = { 7, 3, 11, 1, 5, 9, 13, 0, 2, 4, 6, 8, 10, 12, 14 };
		    int[] alturas = { 7, 3, 11, 1, 5, 9, 12, 0, 2, 4, 6, 8, 10, 13, 14 };
            
            List<Jogador> jogadores = new ArrayList<>();
            ArvoreArvorePesquisa arvorePesquisa = new ArvoreArvorePesquisa();
            ArvoreArvore arvore = arvorePesquisa.new ArvoreArvore(alturas);
            Scanner input = new Scanner(System.in);
            String id;
            String matricula = "802371";
            long tempoExecucao = 0;

            // Loop para ler a entrada do usuário e adicionar jogadores à lista
            while (!(id = input.nextLine()).equals("FIM")) {
                Jogador jogador = new Jogador();
                jogador.ler(id);
                jogadores.add(jogador);
                arvore.Inserir(jogador);
            }

            // Loop para ler a entrada do usuário e pesquisar jogadores na lista
            while (!(id = input.nextLine()).equals("FIM")) {
                long startTime = System.nanoTime();
                boolean resultado = Pesquisar(arvore, id);
                long endTime = System.nanoTime();
                tempoExecucao += endTime - startTime;
                System.out.println(resultado ? "SIM" : "NAO");
            }

            // Escrever no arquivo de log
            try {
                FileWriter fileWriter = new FileWriter("802371_arvoreArvore.txt", false);
                PrintWriter printWriter = new PrintWriter(fileWriter);
                printWriter.printf("%s\t%d\t%d\n", matricula, tempoExecucao, ArvoreArvorePesquisa.contComparacoes);
                printWriter.close();
            } catch (IOException e) {
                e.printStackTrace();
            }

            input.close();
        }

    }