package file_read_write;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class SearchFile {
	private String file = "person.txt";
	
	public SearchFile(String file)
	{
		this.file = file;
	}
	
	public String SearchInFile(String content)
	{
		FileReader fr = null;
		BufferedReader br = null;
		String temp=null;
		
		try
		{
			fr = new FileReader(file);
			br = new BufferedReader(fr);
			
			
			String line;
			
			while((line = br.readLine()) != null)
			{
				if(line.contains(content))
				{
					//System.out.println("found!!!!!!!!\n"+line);
					temp = line;
					
					break;
				}
			}
			
			if(br != null)
				br.close();
			
			if(fr != null)
				fr.close();
				
			
		}
		
		catch(IOException e)
		{
			e.printStackTrace();
		}
		
		return temp;	
		
		
	}

}
