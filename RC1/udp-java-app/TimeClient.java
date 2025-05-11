import java.io.*;
import java.net.*;

public class TimeClient {
    private static final int SERVER_PORT = 9876;
    private static byte[] sendData;
    private static byte[] receiveData = new byte[1024];

    public static void main(String[] args) throws Exception {
        DatagramSocket clientSocket = new DatagramSocket();
        InetAddress serverAddress = InetAddress.getByName("192.168.100.2"); // altere para o IP do servidor, se necessário

        // Envia o comando "TIME"
        String command = "TIME";
        sendData = command.getBytes();
        DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, serverAddress, SERVER_PORT);
        clientSocket.send(sendPacket);
        System.out.println("Comando enviado: " + command);

        // Recebe a resposta do servidor
        DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
        clientSocket.receive(receivePacket);
        String response = new String(receivePacket.getData(), 0, receivePacket.getLength());
        System.out.println("Resposta do servidor: " + response);

        clientSocket.close();
    }
}