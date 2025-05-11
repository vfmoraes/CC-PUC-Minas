import java.io.*;
import java.net.*;

public class TCPClient {
    private static final String SERVER_IP = "192.168.100.2";
    private static final int SERVER_PORT = 7000;

    public static void main(String[] args) throws Exception {
        Socket socket = new Socket(SERVER_IP, SERVER_PORT);
        System.out.println("Conectado com o servidor " + SERVER_IP + " na porta " + SERVER_PORT);

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        DataOutputStream out = new DataOutputStream(socket.getOutputStream());
        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));

        String inputLine;
        while (true) {
            System.out.print("Digite uma mensagem (ou 'bye' para sair): ");
            inputLine = reader.readLine();
            out.writeBytes(inputLine + "\n");

            String response = in.readLine();
            System.out.println("Resposta do servidor: " + response);

            if (inputLine.equalsIgnoreCase("bye")) {
                break;
            }
        }
        
        socket.close();
        System.out.println("Conexão encerrada.");
    }
}