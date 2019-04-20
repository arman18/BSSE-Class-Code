package serialization;

import java.io.Serializable;


public class Student implements Serializable{ // must otherwise it will throw NotSerializableException
    private String name;
    private double age;
    private String roll;
    
    public Student(String name, double age, String roll){
        this.name  = name;
        this.age = age;
        this.roll = roll;
    }
    public String getName(){
        return name;
    }
    public String getRoll(){
        return roll;
    }
    public double getAge(){
        return age;
    }
    @Override
    public String toString(){
        return "NAME: " + name + " ROLL: " + roll + " AGE: " + age;
    }
            
}
