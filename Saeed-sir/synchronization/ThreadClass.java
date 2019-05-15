package serializationunderstanding;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ThreadClass implements Runnable{
    private FileWriter fw;
    public ThreadClass(FileWriter fw){
        this.fw = fw;
    }
    @Override
    public void run() {
        
     fw.Write();
    }
    
}
