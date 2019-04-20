package miltithreadserverwithbancacc;

import java.io.*;
import java.net.*;
import java.util.ArrayList;
import java.util.Iterator;

public class MultiThreadClass implements Runnable{
    
    private Socket s;
    int numberOfObject = 0;
    private ArrayList<BankAcc> arrOfObject = new ArrayList<BankAcc>();
    public MultiThreadClass(Socket s){
        this.s = s;
    }
        void readAllObject(File file){
        BankAcc ob = null;
        FileInputStream fi = null;
        ObjectInputStream oi = null;
        try {
            fi = new FileInputStream(file);
            oi = new ObjectInputStream(fi);
            while(true) 
            {
                ob = (BankAcc) oi.readObject();
                arrOfObject.add(ob);
                numberOfObject++;
            }
            
        }
        catch(Exception e){
//            oi.close();
//            fi.close();
            System.out.println("number of object: " + numberOfObject);
            
        }
        
    }
    
    void writeAllObject(File file){
        FileOutputStream f = null;
        ObjectOutputStream o = null;
        try
        {
            f = new FileOutputStream(file);
            o = new ObjectOutputStream(f);
//            arrOfObject.clear();
            Iterator<BankAcc> it = arrOfObject.iterator();
            while(it.hasNext()) o.writeObject(it.next());
            
            o.close();
            f.close();
            System.out.println("successfully saved object.");
        }
        catch (IOException e)
        {
            System.out.println("Error initializing stream");
        }
        
    }
     void functionalities() throws Exception{
        
        DataInputStream din=new DataInputStream(s.getInputStream());  
	DataOutputStream dout=new DataOutputStream(s.getOutputStream());  
	String strClient,accName,accPass,accAge,accBalance;
        readAllObject(new File("myObjects.txt"));
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
        din.close();
        s.close();
        
    }
    @Override
    public void run(){
        System.out.println("welcome to server");  
	System.out.println("connected a client:");
        
        try{
            functionalities();
            s.close();
        }
        catch(Exception e){
                e.printStackTrace();
        }
        
        writeAllObject(new File("myObjects.txt"));
 
	  
	System.out.println("OK from Server");
    }
}
    
