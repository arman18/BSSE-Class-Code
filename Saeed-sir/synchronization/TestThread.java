package serializationunderstanding;

import java.io.File;

public class TestThread {
    public static void main(String[] args) {
        ThreadClass th = null;
        FileWriter fw = new FileWriter();
        new Thread(new ThreadClass(fw)).start();
        new Thread(new ThreadClass(fw)).start();
    }
    
}
