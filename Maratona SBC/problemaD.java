import java.util.Scanner;

public class problemaD {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tempobaseHoras = 19;
        
        while (sc.hasNext()) {
            int E = sc.nextInt();
            int V = sc.nextInt();
            double tempohoras = (double) E / V;
            int horas = (int) tempohoras;
            int minutos = (int) Math.round((tempohoras - horas) * 60);
            int horaFinal = (tempobaseHoras + horas) % 24;
            int minutoFinal = minutos;
            if (minutoFinal >= 60) {
                horaFinal = (horaFinal + minutoFinal / 60) % 24;
                minutoFinal = minutoFinal % 60;
            }
            System.out.printf("%02d:%02d\n", horaFinal, minutoFinal);
        }

        sc.close();
    }
}