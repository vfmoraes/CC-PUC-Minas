import java.util.ArrayList;
import java.util.Scanner;

class prova03hash {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        for (int i = 0; i < N; i++) {
            int M = scanner.nextInt();
            int C = scanner.nextInt();

            HashTable hashTable = new HashTable(M);

            for (int j = 0; j < C; j++) {
                int key = scanner.nextInt();
                hashTable.insert(key);
            }

            hashTable.printHashTable();

            // Adiciona uma linha em branco entre conjuntos de saída
            if (i < N - 1) {
                System.out.println();
            }
        }

        scanner.close();
    }
}

class HashTable {
    private ArrayList<Integer>[] table;

    public HashTable(int size) {
        table = new ArrayList[size];
        for (int i = 0; i < size; i++) {
            table[i] = new ArrayList<>();
        }
    }

    public void insert(int key) {
        int index = hashFunction(key);
        table[index].add(key);
    }

    private int hashFunction(int key) {
        return key % table.length;
    }

    public void printHashTable() {
        for (int i = 0; i < table.length; i++) {
            System.out.print(i + " -> ");
            for (int j = 0; j < table[i].size(); j++) {
                System.out.print(table[i].get(j));
                if (j < table[i].size() - 1) {
                    System.out.print(" -> ");
                }
            }
            System.out.println(" \\");
        }
    }
}
