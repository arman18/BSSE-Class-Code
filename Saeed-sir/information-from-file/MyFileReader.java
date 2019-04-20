package file_read_write;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class MyFileReader {
	
	private String file = "person.txt";
	
	public MyFileReader(String file)
	{
		this.file = file;
	}
	
	public void readFromFile()
	{
		
		BufferedReader br = null;
		FileReader fr = null;
		
		try
		{
			fr = new FileReader(file);
			br = new BufferedReader(fr);
			String str;
			
			while((str = br.readLine()) != null )
				System.out.println(str);
			
			if(br != null)
				br.close();
			
			if(fr != null)
				br.close();
		}
		
		catch(IOException e)
		{
			e.printStackTrace();
		}
	}

}
