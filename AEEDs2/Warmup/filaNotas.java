import java.util.*;

public class filaNotas{
    public static int naoMudou(ArrayList <Integer> notas){
        int cont = 0;        
        ArrayList <Integer> notasOrdenadas = new ArrayList<Integer>();
        notasOrdenadas.addAll(notas);
        Collections.sort(notasOrdenadas);
        Collections.reverse(notasOrdenadas);
        for(int i = 0; i < notas.size(); i++){
            if(notas.get(i) == notasOrdenadas.get(i)){
                cont++;
            }
        }
        return cont;
    }
    public static void main (String args[]){
        Scanner sc = new Scanner(System.in);
        int casos = sc.nextInt();
        int numAlunos = 0;
        for(int i = 0; i < casos; i++){
        ArrayList <Integer> notas = new ArrayList <Integer>();
        numAlunos = sc.nextInt();
        for(int j = 0; j < numAlunos; j++){
            notas.add(sc.nextInt());
        }
        System.out.println(naoMudou(notas));
    }
    sc.close();
}
}