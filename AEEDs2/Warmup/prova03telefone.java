import java.util.Scanner;

public class prova03telefone {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNext()) {
            int N = sc.nextInt();
            sc.nextLine();

            String[] telefones = new String[N];
            for (int i = 0; i < N; i++) {
                telefones[i] = sc.nextLine();
            }

            int economia = calcularEconomia(telefones);
            System.out.println(economia);
        }
    }

    public static int calcularEconomia(String[] telefones) {
        int economia = 0;

        for (int i = 1; i < telefones.length; i++) {
            String atual = telefones[i];
            String anterior = telefones[i - 1];

            int j = 0;
            while (j < atual.length() && j < anterior.length() && atual.charAt(j) == anterior.charAt(j)) {
                j++;
            }

            economia += j;
        }

        return economia;
    }
}
