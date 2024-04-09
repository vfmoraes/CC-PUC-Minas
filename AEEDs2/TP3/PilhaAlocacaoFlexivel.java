import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.*;

/**
 * Celula Dupla (lista dupla dinamica)
 * @author Max do Val Machado
 * @version 2 01/2015
 */
class CelulaDupla {
	public JogadorBuilder elemento;
	public CelulaDupla ant;
	public CelulaDupla prox;

	/**
	 * Construtor da classe.
	 */
	public CelulaDupla() {
		this(null);
	}


	/**
	 * Construtor da classe.
	 * @param elemento int inserido na celula.
	 */
	public CelulaDupla(JogadorBuilder elemento) {
		this.elemento = elemento;
		this.ant = this.prox = null;
	}
}


/**
 * Lista dupla dinamica
 * @author Max do Val Machado
 * @version 2 01/2015
 */
class ListaDupla {
	private CelulaDupla primeiro;
	private CelulaDupla ultimo;


	/**
	 * Construtor da classe que cria uma lista dupla sem elementos (somente no cabeca).
	 */
	public ListaDupla() {
		primeiro = new CelulaDupla();
		ultimo = primeiro;
	}


	/**
	 * Insere um elemento na primeira posicao da lista.
    * @param x int elemento a ser inserido.
	 */
	public void inserirInicio(JogadorBuilder x) {
		CelulaDupla tmp = new CelulaDupla(x);

      tmp.ant = primeiro;
      tmp.prox = primeiro.prox;
      primeiro.prox = tmp;
      if(primeiro == ultimo){
         ultimo = tmp;
      }else{
         tmp.prox.ant = tmp;
      }
      tmp = null;
	}


	/**
	 * Insere um elemento na ultima posicao da lista.
    * @param x int elemento a ser inserido.
	 */
	public void inserirFim(JogadorBuilder x) {
		ultimo.prox = new CelulaDupla(x);
      ultimo.prox.ant = ultimo;
		ultimo = ultimo.prox;
	}


	/**
	 * Remove um elemento da primeira posicao da lista.
    * @return resp int elemento a ser removido.
	 * @throws Exception Se a lista nao contiver elementos.
	 */
	public JogadorBuilder removerInicio() throws Exception {
		if (primeiro == ultimo) {
			throw new Exception("Erro ao remover (vazia)!");
		}

      CelulaDupla tmp = primeiro;
		primeiro = primeiro.prox;
		JogadorBuilder resp = primeiro.elemento;
      tmp.prox = primeiro.ant = null;
      tmp = null;
		return resp;
	}


	/**
	 * Remove um elemento da ultima posicao da lista.
    * @return resp int elemento a ser removido.
	 * @throws Exception Se a lista nao contiver elementos.
	 */
	public JogadorBuilder removerFim() throws Exception {
		if (primeiro == ultimo) {
			throw new Exception("Erro ao remover (vazia)!");
		} 
      JogadorBuilder resp = ultimo.elemento;
      ultimo = ultimo.ant;
      ultimo.prox.ant = null;
      ultimo.prox = null;
		return resp;
	}


	/**
    * Insere um elemento em uma posicao especifica considerando que o 
    * primeiro elemento valido esta na posicao 0.
    * @param x int elemento a ser inserido.
	 * @param pos int posicao da insercao.
	 * @throws Exception Se <code>posicao</code> invalida.
	 */
   public void inserir(JogadorBuilder x, int pos) throws Exception {

      int tamanho = tamanho();

      if(pos < 0 || pos > tamanho){
			throw new Exception("Erro ao inserir posicao (" + pos + " / tamanho = " + tamanho + ") invalida!");
      } else if (pos == 0){
         inserirInicio(x);
      } else if (pos == tamanho){
         inserirFim(x);
      } else {
		   // Caminhar ate a posicao anterior a insercao
         CelulaDupla i = primeiro;
         for(int j = 0; j < pos; j++, i = i.prox);
		
         CelulaDupla tmp = new CelulaDupla(x);
         tmp.ant = i;
         tmp.prox = i.prox;
         tmp.ant.prox = tmp.prox.ant = tmp;
         tmp = i = null;
      }
   }


	/**
    * Remove um elemento de uma posicao especifica da lista
    * considerando que o primeiro elemento valido esta na posicao 0.
	 * @param posicao Meio da remocao.
    * @return resp int elemento a ser removido.
	 * @throws Exception Se <code>posicao</code> invalida.
	 */
	public JogadorBuilder remover(int pos) throws Exception {
      JogadorBuilder resp;
      int tamanho = tamanho();

		if (primeiro == ultimo){
			throw new Exception("Erro ao remover (vazia)!");

      } else if(pos < 0 || pos >= tamanho){
			throw new Exception("Erro ao remover (posicao " + pos + " / " + tamanho + " invalida!");
      } else if (pos == 0){
         resp = removerInicio();
      } else if (pos == tamanho - 1){
         resp = removerFim();
      } else {
		   // Caminhar ate a posicao anterior a insercao
         CelulaDupla i = primeiro.prox;
         for(int j = 0; j < pos; j++, i = i.prox);
		
         i.ant.prox = i.prox;
         i.prox.ant = i.ant;
         resp = i.elemento;
         i.prox = i.ant = null;
         i = null;
      }

		return resp;
	}


	/**
	 * Mostra os elementos da lista separados por espacos.
	 */
	public void mostrar() {
		int contador = 0;
        for (CelulaDupla i = primeiro.prox; i != null; i = i.prox) {
            System.out.print("["+contador+"] ");
            i.elemento.mostrar();
            contador++;
        }
	}

	/**
	 * Calcula e retorna o tamanho, em numero de elementos, da lista.
	 * @return resp int tamanho
	 */
   public int tamanho() {
      int tamanho = 0; 
      for(CelulaDupla i = primeiro; i != ultimo; i = i.prox, tamanho++);
      return tamanho;
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

public class PilhaAlocacaoFlexivel {
    public static void main(String[] args) throws Exception {
        long begin = System.nanoTime();
        Scanner sc = new Scanner(System.in);
        String entrada;
        FileReader file = new FileReader("/tmp/players.csv");
        BufferedReader buffer = new BufferedReader(file);
        int i = 0;
        ListaDupla pilhaFlexJogador = new ListaDupla();
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
                    pilhaFlexJogador.inserirFim(jogador[j]);
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
                    pilhaFlexJogador.inserirFim(retornaBuildado(idAdd, jogador));
                    break;
                case "R":
                    System.out.println("(R) " + pilhaFlexJogador.removerFim().getNome());
                    break;
                default:
                System.out.println("Nao existe");
                break;
            }
        }
        // --------------------------------------------------------------------//
        pilhaFlexJogador.mostrar();
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