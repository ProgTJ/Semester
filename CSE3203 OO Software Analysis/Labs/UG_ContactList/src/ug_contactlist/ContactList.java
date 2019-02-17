/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ug_contactlist;

import java.util.ArrayList;

/**
 *
 * @author Anala
 */
public class ContactList {
    private ArrayList<Person> persons;

    public ContactList() {
        this.persons = new ArrayList<>();
    }
       
    public void addPerson(Person p){
        //adding person
        persons.add(p);
    }
    
    public void display(){
        //persons.forEach(System.out::println);
        for(var i = 0; i < persons.size(); i++){
            System.out.println(persons.get(i));
        }
    }
    
}
