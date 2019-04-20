package file_read_write;

import java.util.Scanner;

public class Main {
	
	public static void main(String[] args)
	{
		FileOperation obj =new FileOperation();
		
		System.out.println("Wlcome");
		
		while(true)
		{
			System.out.println("What do you want to do ?\n1. Search\n2. add");
			
			Scanner input =new Scanner(System.in);
			int choice = input.nextInt();
			
			if(choice == 1)
			{
				System.out.print("enter a registration number you are looking for: ");
				String reg = input.nextLine();
				reg = input.nextLine();
				
				String result = obj.search(reg);
				
				if(result != null)
				{
					String[] lines = result.split(";");
					System.out.println("found!!!!!!!!!!");
					System.out.println(lines[0]);
					System.out.println(lines[1]);
				}
				else
					System.out.println("not found");
			}
			
			if(choice == 2)
			{
				obj.add();
			}
		}
		
	}

}
