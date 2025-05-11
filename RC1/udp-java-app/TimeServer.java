import java.net.*;
import java.text.SimpleDateFormat;
import java.util.Date;

public class TimeServer {
    private static final int PORT = 9876;
    private static byte[] receiveData = new byte[1024];
    private static byte[] sendData;

    public static void main(String[] args) throws Exception {
        DatagramSocket serverSocket = new DatagramSocket(PORT);
        System.out.println("Servidor de tempo aguardando requisições na porta " + PORT);

        while (true) {
            DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
            serverSocket.receive(receivePacket);
            String clientCommand = new String(receivePacket.getData(), 0, receivePacket.getLength()).trim();
            System.out.println("Recebido: " + clientCommand);

            String response;
            if ("TIME".equalsIgnoreCase(clientCommand)) {
                SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");
                response = formatter.format(new Date());
            } else {
                response = "Comando desconhecido";
            }
            sendData = response.getBytes();

            InetAddress clientAddress = receivePacket.getAddress();
            int clientPort = receivePacket.getPort();
            DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, clientAddress, clientPort);
            serverSocket.send(sendPacket);
            System.out.println("Enviado: " + response);
        }
    }
}