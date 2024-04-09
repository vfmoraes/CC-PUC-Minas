/*
 * Nome: Victor Ferraz de Moraes
 * Matrícula: 802371
 * Curso: Ciência da Computação
 */

import java.util.*;

public class Isrecursivo {
    // Função que verifica se a string contém apenas vogais
    public static Boolean SomenteVogal(String palavra, int index) {
        if (index == palavra.length()) {
            return true;
        }

        char currentChar = palavra.charAt(index);

        if (isVowel(currentChar)) {
            return SomenteVogal(palavra, index + 1);
        }

        return false;
    }

    // Função que verifica se a string contém apenas consoantes
    public static Boolean SomenteConsoante(String palavra, int index) {
        if (index == palavra.length()) {
            return true;
        }

        char currentChar = palavra.charAt(index);

        if (isConsonant(currentChar)) {
            return SomenteConsoante(palavra, index + 1);
        }

        return false;
    }

    // Função que verifica se a string contém apenas dígitos numéricos
    public static Boolean NumeroInteiro(String palavra, int index) {
        if (index == palavra.length()) {
            return true;
        }

        char currentChar = palavra.charAt(index);

        if (Character.isDigit(currentChar)) {
            return NumeroInteiro(palavra, index + 1);
        }

        return false;
    }

    // Função que verifica se a string é um número real válido
    public static Boolean NumeroReal(String palavra, int index, int commaCount) {
        if (index == palavra.length()) {
            return commaCount <= 1;
        }

        char currentChar = palavra.charAt(index);

        if (Character.isDigit(currentChar)) {
            return NumeroReal(palavra, index + 1, commaCount);
        } else if (currentChar == ',' || currentChar == '.') {
            return NumeroReal(palavra, index + 1, commaCount + 1);
        }

        return false;
    }

    // Função auxiliar para verificar se um caractere é uma vogal
    private static boolean isVowel(char c) {
        char lower = Character.toLowerCase(c);
        return lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u';
    }

    // Função auxiliar para verificar se um caractere é uma consoante
    private static boolean isConsonant(char c) {
        char lower = Character.toLowerCase(c);
        return lower >= 'a' && lower <= 'z' && !isVowel(c);
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String entrada = sc.nextLine();
        String resp = "";

        while (!entrada.equals("FIM")) {
            if (SomenteVogal(entrada, 0)) {
                resp += "SIM ";
            } else {
                resp += "NAO ";
            }
            if (SomenteConsoante(entrada, 0)) {
                resp += "SIM ";
            } else {
                resp += "NAO ";
            }
            if (NumeroInteiro(entrada, 0)) {
                resp += "SIM ";
            } else {
                resp += "NAO ";
            }
            if (NumeroReal(entrada, 0, 0)) {
                resp += "SIM";
            } else {
                resp += "NAO";
            }
            System.out.println(resp);
            resp = "";
            entrada = sc.nextLine();
        }
        sc.close();
    }
}

