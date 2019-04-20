package file_read_write;

import java.util.Scanner;

public class FileOperation {
//	private String academicFile = "academic.txt";
//	private String personalFile = "person.txt";
	Scanner cin =new Scanner(System.in);

	public String search(String reg)
	{
		
		SearchFile sf = new SearchFile("academic.txt");
		String result = sf.SearchInFile(reg);
		
		if(result != null)
		{
//			System.out.println("found!!!!!");
//			System.out.println(result);
			String temp ="";
			temp += result;
			
			sf = new SearchFile("person.txt");
			result = sf.SearchInFile(reg);
			//System.out.println(result);
			temp += ";"+result;
			
			return temp;
		}
		
		else
		{
			//System.out.println("not found in the file");
			
			return null;
		}
	}
	
	public void replace(String file, String old, String newContent)
	{
		Replace rp = new Replace(file); 
		rp.replace(old, newContent);
	}
	
	public void add()
	{
		System.out.println("enter academic informations in format- reg,session,semseter,year,cgpa,roll");
		String academic = cin.nextLine();
		String[] words = academic.split(",");
		
		String temp = search(words[0]);
				
		//System.out.println(st[0]);
		
		if(temp != null )
		{
			String[] st = temp.split(";");
			System.out.println("this registration number already exists");
			System.out.println("do you want to replace this ? (y/n)");
			
			char ans = cin.next().charAt(0);
			
			if(ans == 'y')
				replace("academic.txt",st[0], academic);
			else
			{
				System.out.println("ok");
			}
		}
		
		else
		{
			MyFileWriter mfw =new MyFileWriter("academic.txt");
			mfw.writeToFile(academic,true);
			
			System.out.println("enter personal informations in format- name,f-name,m-name,dob,nid,address,reg");
			String personal = cin.nextLine();
			
			 mfw =new MyFileWriter("person.txt");
			mfw.writeToFile(personal,true);
			
			System.out.println("append done!!!");
		}
		
	}
	
	

}
