/*
 *File: main.cpp
 *Author: Alexander D. Clark
 *Date: February 10 2014
 *Purpose: To serve as the driver of our Steganography project
 */

#include <iostream>
#include "steganography.h"
#include <string>
using namespace std;


int main(){
  //This allows me to use functions from the Steganography class 
  Steganography Steg;

  //Hold the user response to the menu question
  int userResponse;

  //Holds the text file to input in many of the questions
  string textFile;

  //Hold the picture to input in many of the questions
  string pictureFile;

  //Hold the image file to output to in many questions
  string outputImageFile;

  //Holds the output text file in my printCipher function
  string outputCipherFile;
  
  //My beautiful ascii art menu
  cout<<" ------------------------------------------" <<endl;
  cout<<" |          Simple Steganography          |" <<endl;
  cout<<" |       What would you like to do?       |" <<endl;
  cout<<" |                                        |" <<endl;
  cout<<" |[1] Encrypt a text file into a picture  |" <<endl;
  cout<<" |[2] Decipher a picture to extract data  |" <<endl;
  cout<<" |[3] cleanImage [Zeroes out bits]        |" <<endl;
  cout<<" |[4] readCipher and printCipher          |" <<endl;
  cout<<" |[5] readImage and printImage            |" <<endl;
  cout<<" |[6] Exit the program                    |" <<endl;
  cout<<" |                                        |" <<endl;
  cout<<" |      Created by Alexander Clark        |" <<endl;
  cout<<" ------------------------------------------" <<endl;
  
  //Asking the user what they want to do 
  cout<<"Select a task to do: ";

  //Finding out what the user wants to do
  cin>>userResponse;

  //Everything from here done are if statements that correspond to
  //what the user inputted at menu.

  if (userResponse ==1){
    cout<<"Please enter the text file to put into a picture." <<endl;
    cin >> textFile;
    
    cout<<"Please enter the picture to put the text file into" <<endl;
    cin >> pictureFile;    
   
    //Calls readCipherText using textFile as an argument. 
    Steg.readCipherText(textFile);

    //Calls readImage to store the image file in color_data.
    Steg.readImage(pictureFile);

    //Zeroes out all the bits in the pixels to prepare for encipher
    Steg.cleanImage();

    //Calling the encipher function to edit color_data
    Steg.encipher();

    //Pushing data from color_data to pictureFile
    Steg.printImage(pictureFile);
  }
  

  if (userResponse ==2){
    cout<<"Please enter the picture to decrypt." <<endl;
    cin >>pictureFile;
    
    cout<<"Please enter the file to output the text too." <<endl;
    cin >>outputCipherFile;

    //Reading in pictureFile into color_data
    Steg.readImage(pictureFile);

    //Deciphering the message from color_data
    Steg.decipher();

    //Printing the message to the output text file
    Steg.printCipherText(outputCipherFile);
  }
  
  if (userResponse ==6){
    cout<<"Thanks for trying my program!"<<endl;
    return 0;
    
  }
  
  if (userResponse ==3){
    cout<<"Enter the photo to clean"<<endl;
    cin >>pictureFile;

    //Reading pictureFile into color_data
    Steg.readImage(pictureFile);

    //Zeroing out the bits in color_data 
    Steg.cleanImage();
    
  }
  
  if (userResponse ==4){
    cout<<"Enter a file to read" <<endl;
    cin >>textFile;
    
    cout<<"Enter a file to place the data into." <<endl;
    cin >> outputCipherFile;

    //Reading the text from textFile to cipherText
    Steg.readCipherText(textFile);

    //Copying cipherText into outputCipherFile
    Steg.printCipherText(outputCipherFile);
    
  }
  
  if (userResponse ==5){
    
    cout <<"Enter a photo to read"<< endl;
    cin >> pictureFile;
    
    cout <<"Where do you want the photo copied too?"<<endl;
    cin >>outputImageFile;
    
    //Reading the image into color_data
    Steg.readImage(pictureFile);
  
    //Copying color_data to outputImageFile
    Steg.printImage(outputImageFile);
    
  }
  
  //Returning 0 to inform the computer that the program 
  //execution was a success.
  return 0;
  
}
