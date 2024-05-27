import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
 

public class Main {
 
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);

        int total = sc.nextInt();
        sc.nextLine();

        String[] dormir = sc.nextLine().split(" ");
        String[] irritando = sc.nextLine().split(" ");

        Map<String, Integer> mapa = new HashMap<>();

        for (int i = 0; i < total; i++)  mapa.put(irritando[i], i);

        int index = 0;
        StringBuilder saida = new StringBuilder();
        for ( int i = 0; i < total; i++ ){
            while ( irritando[index] == "0" ) index++;
            saida.append(irritando[index]).append(" ");

            irritando[mapa.get(dormir[i])] = "0";
        }

        System.out.println(saida);
 
        sc.close();
    }
 
}