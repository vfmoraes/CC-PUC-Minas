/*
 * Nome: Victor Ferraz de Moraes
 * Matrícula: 802371
 * Curso: Ciência da Computação
 */

import java.util.*;

public class Is {
    // Função que verifica se a string contém apenas vogais
    public static Boolean SomenteVogal(String palavra){
        for(int i = 0; i < palavra.length(); i++){
            // Verifica se o caractere atual não é uma vogal minúscula ou maiúscula
            if(palavra.charAt(i) != 'a' && palavra.charAt(i) != 'A' && palavra.charAt(i) !=  'e' && palavra.charAt(i) !=  'E' && palavra.charAt(i) !=  'i' && palavra.charAt(i) !=  'I' && palavra.charAt(i) !=  'o' && palavra.charAt(i) !=  'O' && palavra.charAt(i) !=  'u' && palavra.charAt(i) !=  'U'){
                return false; // Se não for uma vogal, retorna falso
            }
        }
        return true; // Se todas as letras forem vogais, retorna verdadeiro
    }

    // Função que verifica se a string contém apenas consoantes
    public static Boolean SomenteConsoante(String palavra){
        char lower;
        for(int i = 0; i < palavra.length(); i++){
            lower = Character.toLowerCase(palavra.charAt(i));
            // Verifica se o caractere atual é uma letra minúscula do alfabeto
            if(lower >= 'a' && palavra.charAt(i) <= 'z'){
                // Verifica se o caractere atual não é uma vogal minúscula ou maiúscula
                if(palavra.charAt(i) == 'a' || palavra.charAt(i) == 'A' || palavra.charAt(i) ==  'e' || palavra.charAt(i) ==  'E' || palavra.charAt(i) ==  'i' || palavra.charAt(i) ==  'I' || palavra.charAt(i) ==  'o' || palavra.charAt(i) ==  'O' || palavra.charAt(i) ==  'u' || palavra.charAt(i) ==  'U'){
                    return false; // Se for uma vogal, retorna falso
                }
            } else {
                return false; // Se não for uma letra do alfabeto, retorna falso
            }
        }
        return true; // Se todas as letras forem consoantes, retorna verdadeiro
    }

    // Função que verifica se a string contém apenas dígitos numéricos
    public static Boolean NumeroInteiro(String palavra){
        for(int i = 0; i < palavra.length(); i++){
            // Verifica se o caractere atual não é um dígito
            if(!Character.isDigit(palavra.charAt(i))){
                return false; // Se não for um dígito, retorna falso
            }
        }
        return true; // Se todos os caracteres forem dígitos, retorna verdadeiro
    }

    // Função que verifica se a string é um número real válido
    public static Boolean NumeroReal(String palavra){
        int check = 0;
        for(int i = 0; i < palavra.length(); i++){
            // Verifica se o caractere atual não é um dígito, vírgula ou ponto decimal
            if(!Character.isDigit(palavra.charAt(i)) && palavra.charAt(i) != ',' && palavra.charAt(i) != '.'){
                return false; // Se não for um caractere válido em um número real, retorna falso
            }
            // Verifica se o caractere atual é vírgula ou ponto decimal e se não ocorreram mais de uma vez
            if(palavra.charAt(i) == ',' || palavra.charAt(i) == '.'){
                check++;
                if(check > 1){
                    return false; // Se ocorrer mais de uma vírgula ou ponto, retorna falso
                }
            }
        }
        return true; // Se a string for um número real válido, retorna verdadeiro
    }    
    
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String entrada = sc.nextLine();
        String resp = "";
        while(!entrada.equals("FIM")){
            // Chama as funções de verificação e acumula as respostas na variável 'resp'
            if (SomenteVogal(entrada)){
                resp += "SIM ";
            } else {
                resp += "NAO ";
            }
            if (SomenteConsoante(entrada)) {
                resp += "SIM ";                
            } else {
                resp += "NAO ";
            }
            if (NumeroInteiro(entrada)){
                resp += "SIM ";                
            } else {
                resp += "NAO ";
            }
            if (NumeroReal(entrada)){
                resp += "SIM";      
            } else {
                resp += "NAO";
            }
            System.out.println(resp); // Imprime a resposta acumulada
            resp = ""; // Limpa a variável 'resp' para a próxima entrada
            entrada = sc.nextLine(); // Lê a próxima entrada
        }
        sc.close(); // Fecha o scanner quando não precisamos mais
    }
}
