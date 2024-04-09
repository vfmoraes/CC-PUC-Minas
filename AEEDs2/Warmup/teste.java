import java.util.Arrays;

public class teste {
    public static void main(String[] args) {
        int[] vetA = {12, 10, 8, 6, 4, 2};
        int[] vetB = {11, 9, 7, 5, 3, 1};
        
        int[] resultado = vetorOrdenado(vetA, vetB);

        System.out.println("Array Resultante:");
        for (int num : resultado) {
            System.out.print(num + " ");
        }
    }

    public static int[] vetorOrdenado(int[] vetA, int[] vetB) {
        int m = vetA.length;
        int n = vetB.length;
        int[] resultado = new int[m + n];

        // Copia os elementos para o array resultado
        System.arraycopy(vetA, 0, resultado, 0, m);
        System.arraycopy(vetB, 0, resultado, m, n);

        // Ordena o array resultado em ordem crescente
        Arrays.sort(resultado);

        return resultado;
    }
}
