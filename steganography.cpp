/*
 *File: Steganography.cpp
 *Author: Alexander Clark
 *Date: Febuary 6th 2014
 *Purpose: To create a simple program that Encipher and Decipher text data from pictures. 
*/
	
#include <iostream>
#include <vector>
#include "steganography.h"
#include <string>
#include <fstream>
#include <ostream>
#include <cmath>

using namespace std;

int Steganography::getNthBit(char cipher_char, int n) {                

  //Getting the last bit of cipher_char to determine whether its even or odd.
  return ((cipher_char >> n) %2 );				

}

void Steganography::readImage(string file_name){                      
  
  //Creating input file stream named file
  ifstream file;							

  //Opening file_name in file stream
  file.open (file_name.c_str());						
  
  //Reading in the image type, width, height, and max color depth into the correct variables. 
  file >> image_type >> width >> height >> max_color_depth;  	
	
  //Creating a temporary variable for the temp read
  int temp;

  //Pushing the starting  Data from file_name into temp variable
  file >> temp; 
       
  //Creating a while loop with the conditon of the file having content
  while (file){ 
    
    //Pushing the data from the picture into the temp variable 
    color_data.push_back (temp);
    
    //Pushing the rest of the file into temp
    file >> temp;
     	
  }

  //Closing the file stream
  file.close();					

}

void Steganography::printImage(string file_name){       

  //Creating an output file stream 
  ofstream file;					 

  //Open file_name in the output file stream
  file.open(file_name.c_str());   			 

  //Printing the header to file
  file <<image_type <<endl;
  file <<width << " " << height <<endl;
  file <<max_color_depth<<endl;
    
  //Starting the loop to print image data
  for (int i = 0; i < (int) color_data.size(); i++){	
    
    //When i==35 print the value of i followed by a return
    if (i%35 ==0 && i!=0){
      file << color_data[i] <<endl;
      
    }

    //When i=! 35 print data followed by a space
    else {
      file << color_data[i];
      file << " ";
    }			        
    
  }
  
  file.close();
  
}

void Steganography::readCipherText(string file_name){   
	
  //Creating a temporary string for a test read 
  string temp;
  
  //Opening an input file stream named file
  ifstream file;				
  
  //Opening file_name in the input file stream
  file.open(file_name.c_str());  		
  
  //Creating a while loop with the condition of the file having content
  while (file) {
    
    //Getting each individual line from file and storing it in temp
    
    getline (file,temp);
    
    //Setting ciphertext equal to temp
    ciphertext +=  temp;
    
  }

  //Closing the input file stream
  file.close();	     			

}

void Steganography::printCipherText(string file_name){  
  
  //Creating output file stream named file
  ofstream file;				
  
  //Opening file_name in file stream
  file.open(file_name.c_str());				
  
  //Putting the contents of cipher_text into file_name
  file << ciphertext;			
  
  //Closing the file stream
  file.close(); 					

}

void Steganography::cleanImage() { 
  
  //Cycles through each pixel if the least significant bit is 1 it makes it a 0 

  for (int i=0; i<(int)color_data.size(); i++){ 
    
    if (color_data[i] %2 != 0){
      color_data[i]--;
      
    }	
    
  }
  
}
void Steganography::encipher(){
  //Keeping up with the total number of bits found 
  int textbitcount=0;
  
  //Cycling through each character in cipher text	
  for (int i=0; i<(int)ciphertext.length();i++){

    //This gets the binary for one character of ciphertext
    for(int bit = 0; bit < 8; bit++) {
      if(getNthBit(ciphertext[i],7 - bit)) {

	//Changing the value of color_data if the result of getNthBit is 1
	color_data[textbitcount]++;
      }
      
      //Increasing the total bit count so far
      textbitcount++;	
    }
    
  }
  
  cout<<"Encipher process complete. Your text file is now embedded into the picture. " <<endl;
  
}

void Steganography::decipher(){
  //Making sure that ciphertext is completely empty to avoid pointless text inside it.  
  ciphertext = "";

  //Counts bits taken from picture. Resets to 0 once it reaches 7.
  int tempbits=0;

  //Holds the ascii value for a bit in binary
  int asciivalue=0;

  //Holds the character that each ascii value represents.
  char text = 0;
  
  //Setting the loop up to look at all of the pixels.
  for (int i=0; i<(int)color_data.size(); i++){

    //Setting the value of bit to either 1 or 0 depending 
    //on the result of the %2 
    int bit  =  color_data[i] %2; 
    
    //Setting the ascii value equal to 2^ 7-tempbits
    asciivalue = (int)  pow(2.0, 7 - tempbits);

    //Setting ascii value equal to asciivalue*bit.
    asciivalue *= bit;

    //Moving the character in ascii value to the text variable to hold the message
    text += (char) asciivalue;
    
    //Loop to reset tempbits to 0 once it reaches 7 and pushing data from the 
    //text varaible into the ciphertext string. While also clearing the text data. 
    if (tempbits == 7){
      tempbits = 0;
      ciphertext.push_back ( text);
      text = 0;
    } 

    //Raising the value of tempbits if tempbits != 7.
    else {
      tempbits++;
    }
    
  }  
  cout<<"Decipher process has been completed. The data that was hidden in the picture is now inside the output file. " <<endl; 
  
}
