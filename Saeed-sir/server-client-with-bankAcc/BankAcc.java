package serverwithourip;

import java.io.Serializable;

public class BankAcc implements Serializable{
        private double amount;
        private String name;
        private int age;
        private String pass;
        
        public BankAcc(String name,int age,double amount,String pass)
        {
            this.name = name;
            this.age = age;
            this.amount = amount;
            this.pass = pass;
        }
        
        public boolean isPass(String pass)
        {
            return this.pass.equals(pass);
        }
        
        public boolean deposit(double amount)
        {
            if(amount>=0)
            {
                this.amount +=amount;
                return true;
            }
            return false;
        }
        
        public boolean withdraw(double amount)
        {
            if(amount>=0 && amount<=this.amount)
            {
                this.amount -= amount;
                return true;
            }
            return false;
        }
        
        @Override
        public String toString()
        {
            
            return "name: "+name +"\nage: " + age + "\nbalance: "+ amount + "\n";
        }
}
