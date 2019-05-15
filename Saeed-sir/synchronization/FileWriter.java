package serializationunderstanding;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

public class FileWriter {
    File file = new File("info1.txt");
    FileOutputStream fo = null;
    public void Write(){
        try {
            fo = new FileOutputStream(file,true);
        } catch (FileNotFoundException ex) {
            System.out.println("err while fileOutputstream");
        }
    
        String s = "arman";
        //synchronized(this){ //parameter is this object
            for(int i=0; i<5000; i++){
            s = Integer.toString(i);
            s+="\n";
            byte b[] = s.getBytes();
                    try {
                        fo.write(b);
                    } catch (IOException ex) {
                        System.out.println("err while writing");
                    }
            }
        //}
    }     
}
