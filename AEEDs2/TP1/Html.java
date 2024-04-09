/*
 * Nome: Victor Ferraz de Moraes
 * Matrícula: 802371
 * Curso: Ciência da Computação
 */

import java.io.*;
import java.net.*;
import java.util.*;

class Html {
   // Função para obter o código HTML de uma URL dada
   public static String getHtml(String endereco){
      URL url;
      InputStream is = null;
      BufferedReader br;
      String resp = "", line;
      // Variáveis para contar caracteres acentuados e consoantes
      int a = 0, aagudo = 0, acrase = 0, acirc = 0, atil = 0, e = 0, eagudo = 0, ecrase = 0, ecirc = 0, i = 0, iagudo = 0, icrase = 0, icirc = 0, o = 0, oagudo = 0, ocrase = 0, ocirc = 0, otil = 0, u = 0, uagudo = 0, ucrase = 0, ucirc = 0, consoante = 0, quebra = 0, table = 0;

      try {
         url = new URL(endereco);
         is = url.openStream();  // Abre a conexão com a URL
         br = new BufferedReader(new InputStreamReader(is));

         while ((line = br.readLine()) != null) {
            resp += line + "\n"; // Lê o HTML linha por linha e concatena em 'resp'
         }
         // Loop para contar caracteres acentuados e consoantes na resposta HTML
         for (int j = 0; j < resp.length(); j++){
            char c = resp.charAt(j);
            if (Character.isLowerCase(c)) {
               switch (c) {
                  // Casos para caracteres acentuados
                  case 'a':
                    a++;
                    break;
                  case 225:
                    aagudo++;
                    break;
                  case 224:
                    acrase++;
                    break;
                  case 227:
                     atil++;
                     break;
                  case 226:
                     acirc++;
                     break;
                  case 'e':
                      e++;
                      break;
                  case 233:
                      eagudo++;
                      break;
                  case 232:
                      ecrase++;
                      break;
                  case 234:
                     ecirc++;
                     break;    
                  case 'i':
                      i++;
                      break;
                  case 237:
                      iagudo++;
                      break;
                  case 236:
                      icrase++;
                      break;
                  case 238:
                     icirc++;
                     break;    
                  case 'o':
                      o++;
                      break;
                  case 243:
                      oagudo++;
                      break;
                  case 242:
                      ocrase++;
                      break;
                  case 245:
                     otil++;
                     break;
                  case 244:
                     ocirc++;
                     break;
                  case 'u':
                     u++;
                     break;
                  case 250:
                     uagudo++;
                     break;
                  case 249:
                     ucrase++;
                     break;
                  case 251:
                     ucirc++;
                     break;   
                  default:
                     consoante++; // Caso padrão, conta como consoante
                     break;
               }
            }
         }
         // Conta ocorrências das tags "<br>" e "<table>" na resposta HTML
         quebra = contarOcorrencias(resp, "<br>");
         table = contarOcorrencias(resp, "<table>");
         consoante -= quebra*2;
         consoante -= table*3;
         a -= table;
         e -= table;
      } catch (MalformedURLException mue) {
         mue.printStackTrace(); // Trata erros de URL mal formada
      } catch (IOException ioe) {
         ioe.printStackTrace(); // Trata erros de I/O
      } 

      try {
         is.close(); // Fecha a stream de entrada
      } catch (IOException ioe) {
         // Ignora exceções ao fechar a stream
      }

      // Retorna uma string formatada com a contagem de caracteres
      return ("a(" + a + ") e(" + e + ") i(" + i + ") o(" + o + ") u(" + u + ") \u00E1(" + aagudo + ") \u00E9(" + eagudo + ") \u00ED(" + iagudo + ") \u00F3(" + oagudo + ") \u00FA(" + uagudo + ") \u00E0(" + acrase + ") \u00E8(" + ecrase + ") \u00EC(" + icrase + ") \u00F2(" + ocrase + ") \u00F9(" + ucrase + ") \u00E3(" + atil + ") \u00F5(" + otil + ") \u00E2(" + acirc + ") \u00EA(" + ecirc + ") \u00EE(" + icirc + ") \u00F4(" + ocirc + ") \u00FB(" + ucirc + ") consoante(" + consoante + ") <br>(" + quebra + ") <table>(" + table + ")");
   }

   // Função para contar ocorrências de uma string em outra
   public static int contarOcorrencias(String texto, String alvo) {
      int count = 0;
      int index = 0;
      while ((index = texto.indexOf(alvo, index)) != -1) {
         count++;
         index += alvo.length();
      }
      return count;
   }
   

   public static void main(String[] args) {
      String endereco, html, entrada;
      Scanner sc = new Scanner(System.in);
      entrada = sc.nextLine();
      while (!entrada.equals("FIM")) {
         endereco = sc.nextLine();
         html = getHtml(endereco);
         System.out.println(html + " " + entrada); // Imprime a contagem de caracteres acentuados, consoantes, tags e a entrada
         entrada = sc.nextLine();
      }
      sc.close();
   }
}