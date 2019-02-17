/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ug_contactlist;

import java.util.Scanner;

/**
 *
 * @author Anala
 */
public class UG_ContactList {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        run();
    }
    
    public static void run(){
        var contactList = new ContactList();
        System.out.println("WELCOME TO YOUR CONTACTS LIST");
        Scanner scan = new Scanner(System.in);
        while(true){
            System.out.println("0. EXIT");
            System.out.println("1. ENTER NEW CONTACT");
            System.out.println("2. DISPLAY CONTACTS");
            int command = scan.nextInt();
            if(command == 1){
                var person = createPerson();
                contactList.addPerson(person);
            }
            else if(command == 2){
                contactList.display();
            }
            else {
                break;
            }
        }
    }
    
    public static Person createPerson(){
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter first name: ");
        var firstName = scan.next();
        System.out.println("Enter contact number: ");
        var contactNumber = scan.next();
        var person = new Person(firstName,contactNumber);
        return person;
    }
    
}
