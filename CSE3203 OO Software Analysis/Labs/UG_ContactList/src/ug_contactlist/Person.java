/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ug_contactlist;

/**
 *
 * @author Anala
 */
public class Person {
    private  String firstName;
    private String surname;
    private String address;
    private String contactNumber;

    public Person(String firstName, String contactNumber){
        this.firstName = firstName;
        surname = "";
        address = "";
        this.contactNumber = contactNumber;
    }
    
    public Person(String firstName, String surname, String address, String contactNumber) {
        this.firstName = firstName;
        this.surname = surname;
        this.address = address;
        this.contactNumber = contactNumber;
    }
    
    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getSurname() {
        return surname;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public String getContactNumber() {
        return contactNumber;
    }

    public void setContactNumber(String contactNumber) {
        this.contactNumber = contactNumber;
    }

    @Override
    public String toString() {
        return "Person{" + "firstName=" + firstName + ", surname=" + surname + ", address=" + address + ", contactNumber=" + contactNumber + '}';
    }
    
    
}
