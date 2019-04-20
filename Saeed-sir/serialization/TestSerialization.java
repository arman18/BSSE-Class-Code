package serialization;

import java.io.EOFException;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import static java.nio.file.Files.delete;
import java.util.logging.Level;
import java.util.logging.Logger;

public class TestSerialization {


    public static void main(String[] args) {
        
        Student s1 =  new Student("arman" , 19, "BSSE-1029");
        Student s3 = new Student("sadi", 20, "BSSE-1003");
        File file = new File("info.txt");  //if there is no file it will create new one
        
        
        try (ObjectOutputStream outputStream = new ObjectOutputStream(new FileOutputStream(file,true))) 
        {
            
            outputStream.writeObject(s1);
            outputStream.writeObject(s3);
            outputStream.flush();
            outputStream.close();
            
        } catch (IOException e) {
            e.printStackTrace();
        }
        
        Student s2 = null; //without null it is getting an err!!
        
        try(ObjectInputStream inputStream = new ObjectInputStream(new FileInputStream(file)))
        {
            
            try 
            {
                s2 =  (Student) inputStream.readObject();
                while(s2!=null)
                {
                    System.out.println(s2);
                    s2 =  (Student) inputStream.readObject();
                }
                inputStream.close();
            } 
            catch (Exception ex) 
            {
                ex.printStackTrace();
            }
            
            
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
        
    }
    
}
