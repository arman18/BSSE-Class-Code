package clientserverwithoutip;

import java.net.*;  
import java.io.*;  
class MyClient{  
public static void main(String args[])throws Exception{ 
	System.out.println("Welcome to client. Write stop for close");
	
	Socket s=new Socket("localhost",3333);  
	
	DataInputStream din=new DataInputStream(s.getInputStream());  
	DataOutputStream dout=new DataOutputStream(s.getOutputStream());  
	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));  
	  
	String str,str2;  
	while(true){
                try {
                    str2=din.readUTF(); //after server calling dout.close()
                                        //client attemp to using din.readUTF()
                                        //will throws EOFException
                }
                catch (EOFException e) {
                    break;
                }
                System.out.println(str2);  
		str=br.readLine();  
		dout.writeUTF(str);  
		dout.flush();  
	}  
	  
	dout.close();  
	s.close();  
	
	System.out.println("Thank you.");

	}
}  
