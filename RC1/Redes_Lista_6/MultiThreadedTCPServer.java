import java.io.*;
import java.net.*;

public class MultiThreadedTCPServer {
    private static final int PORT = 7000;

    public static void main(String[] args) throws IOException {
        ServerSocket serverSocket = new ServerSocket(PORT);
        System.out.println("Servidor multi-thread iniciado na porta " + PORT);

        while (true) {
            Socket clientSocket = serverSocket.accept();
            System.out.println("Nova conexão de " + clientSocket.getInetAddress().getHostAddress());
            new Thread(new ClientHandler(clientSocket)).start();
        }
    }
}

class ClientHandler implements Runnable {
    private Socket socket;

    public ClientHandler(Socket socket) {
        this.socket = socket;
    }

    @Override
    public void run() {
        try (
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            DataOutputStream out = new DataOutputStream(socket.getOutputStream());
        ) {
            String message;
            while ((message = in.readLine()) != null) {
                System.out.println("Mensagem recebida: " + message);
                if (message.equalsIgnoreCase("bye")) {
                    out.writeBytes("Adeus!\n");
                    break;
                }
                // Reverte a mensagem recebida e envia de volta
                String reversed = new StringBuilder(message).reverse().toString();
                out.writeBytes("Reverso: " + reversed + "\n");
            }
        } catch (IOException e) {
            System.err.println("Erro na conexão: " + e.getMessage());
        } finally {
            try {
                socket.close();
            } catch (IOException e) {
                // Ignora exceção ao fechar
            }
            System.out.println("Conexão encerrada.");
        }
    }
}