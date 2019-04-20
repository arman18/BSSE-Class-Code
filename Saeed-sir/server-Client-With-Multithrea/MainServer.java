package miltithreadserverwithbancacc;

import java.net.ServerSocket;
import java.net.Socket;

public class MainServer {
    public static void main(String[] args) throws Exception{
        ServerSocket serverSocket = null;
        try{
            serverSocket = new ServerSocket(10000);
        }
        catch(Exception e){
            System.out.println("try with differet port: ");
        }
        Socket socket = null;
        MultiThreadClass  mtc = null;
        while(true){
            socket = serverSocket.accept(); 
            mtc = new MultiThreadClass(socket);
            new Thread(mtc).start();
        }
    }
    
}
