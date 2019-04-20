package serverwithourip;

import java.net.*;  
import java.io.*;  
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;
class MyServer{  
	
public static void main(String args[])throws Exception{  
	System.out.println("welcome to server");
	ServerSocket ss=new ServerSocket(3333);  
	Socket s=ss.accept();  
	System.out.println("connected a client:");
	DataInputStream din=new DataInputStream(s.getInputStream());  
	DataOutputStream dout=new DataOutputStream(s.getOutputStream());  
	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));  
	  
	String myStr,strClient,accName,accPass,accAge,accBalance,hudai;
        ArrayList<BankAcc> arrOfObject = new ArrayList<>();
        FileInputStream fi = null;
        ObjectInputStream oi = null;
        BankAcc ob = null;
        try {
            fi = new FileInputStream(new File("myObjects.txt"));
            oi = new ObjectInputStream(fi);
            while(true) 
            {
                ob = (BankAcc) oi.readObject();
                arrOfObject.add(ob);
            }
            
        } 
        catch (IOException e){
            
            while(true){
                dout.writeUTF("1)login\n2)create account\n3)close connection\nchoose: ");
//		dout.flush();
		strClient=din.readUTF();  
		System.out.println("client says: "+strClient);
                if(strClient.equals("1")){   //login
                    if(arrOfObject.isEmpty()) continue;
                    dout.writeUTF("password: ");
                    strClient=din.readUTF();
                    Iterator<BankAcc> it = arrOfObject.iterator();
                    BankAcc bk = null;
                    boolean check= false;
                    while(it.hasNext()){
                        bk = it.next();
                        if(bk.isPass(strClient)) {
                                check = true;
                                break;
                            }
                            
                    }
                    while(check){
                    dout.writeUTF("1)withdraw\n2)deposit\n3)information\n4)logout\nchoose: ");
                    strClient=din.readUTF();
                    if(strClient.equals("1")) //withdraw
                    {
                        dout.writeUTF("withdraw amount: ");
                        strClient=din.readUTF();
                        boolean bl = (bk.withdraw(Double.parseDouble(strClient)));
                        if(bl==true) dout.writeUTF("sucess withdraw");
                        else  dout.writeUTF("wrong withdraw");
                        din.readUTF();
                    }
                    else if(strClient.equals("2")) //deposit
                    {
                        dout.writeUTF("deposit amount: ");
                        strClient=din.readUTF();
                        boolean bl = (bk.deposit(Double.parseDouble(strClient)));
                        if(bl==true) dout.writeUTF("sucess deposit");
                        else  dout.writeUTF("wrong deposit");
                        din.readUTF();
                    }
                    else if(strClient.equals("3")){ //information
                        dout.writeUTF(bk.toString());
                        din.readUTF();
                    }
                    
                    else break; //logout
                  }
                }
                else if(strClient.equals("2")) //create account
                {
                    dout.writeUTF("name: ");
                    accName=din.readUTF();
                    
                    dout.writeUTF("age: ");
                    accAge=din.readUTF();
                    
                    dout.writeUTF("balance: ");
                    accBalance=din.readUTF();
                    
                    dout.writeUTF("password: ");
                    accPass=din.readUTF();
                    
                    BankAcc acc = new BankAcc(accName,Integer.parseInt(accAge),Double.parseDouble(accBalance),accPass);
                    arrOfObject.add(acc);
                    
                }
                else if(strClient.equals("3")) break; //close connection
                else{
                    dout.writeUTF("wrong input!");
                    din.readUTF();
                }                
		dout.flush();      
	}
            dout.close();
            oi.close();
            fi.close();
        }
        try
        {
            FileOutputStream f = new FileOutputStream(new File("myObjects.txt"));
            ObjectOutputStream o = new ObjectOutputStream(f);
            //arrOfObject.clear();
            Iterator<BankAcc> it = arrOfObject.iterator();
            while(it.hasNext()) o.writeObject(it.next());
            
            o.close();
            f.close();
            
        }
        catch (IOException e)
        {
            System.out.println("Error initializing stream");
        }
        
	  
	din.close();  
	s.close();  
	ss.close(); 
	
	System.out.println("OK from Server");
	
	}	
} 
