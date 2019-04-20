package regularex;
import java.util.Scanner;
import java.util.regex.Matcher;

import java.util.regex.Pattern;

public class RegularEX {
    public static void main(String[] args) {
        {

            String line;
            while(true)
            {
                Scanner sc = new Scanner(System.in);
                line = sc.nextLine();
                String mail = "[a-z]+[a-z A-Z 0-9]*@[a-z]+.[a-z]+";
//                String name = "[A-Z][a-z]+ [A-Z][a-z]+";
//                String phoneNUM = "01[^0-2][0-9]{8}";
                Pattern r = Pattern.compile(mail);

                Matcher m = r.matcher(line);

                System.out.println( m.matches() ? "Found value: " + line : "NO MATCH" );
            }
}

    }
    
}
