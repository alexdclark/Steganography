/*
 * File: steganography.h
 * Author: Joshua T. Guerin
 * Date: Spring 2014
 * Purpose: Class declaration for the Steganography class.  This class is
 *          used to encode/decode  plain text in (P3 ASCII) .ppm images.
 */

#ifndef STEGANOGRAPHY_H
#define STEGANOGRAPHY_H

#include <vector>

class Steganography {
 private:
  // Image header
  std::string image_type;
  int width, height;
  int max_color_depth;
  // Image data
  std::vector<int> color_data;
  
  // Hidden data
  std::string ciphertext;
  
  
  int getNthBit(char cipher_char, int n);
  /*
   * Description:
   *    Returns the nth bit from cipher_char.
   * Note:
   *    This is a helper function used to strip the n'th bit
   *    (the 0'th bit being the least significant) from plaintext in encrypt.
   */


 public:
  void readImage(std::string file_name);
  /* Description:
   *    Reads the ppm image with the name file_name and stores it in member data.
   *
   * Postconditions:
   *    The image header data are stored in image_type, width, height, and max_color_depth.
   *    The image color data is stored in color_data.
   */
  
  
  void printImage(std::string file_name);
  /* Description:
   *    Writes the ppm image stored in member data to the file file_name.
   *
   * Preconditions: 
   *    readImage() has already been called (an image is currently being buffered).
   *
   * Postconditions:
   *    The new image has been written to file_name.
   */
  
  
  void readCipherText(std::string file_name);
  /* Description:
   *    Reads the plain text file (ciphertext) with the name file_name and stores it in member data.
   *
   * Postconditions:
   *    The data from file_name buffered in ciphertext.
   */
  
  
  void printCipherText(std::string file_name);
  /* Description:
   *    Writes the plain text (ciphertext) from ciphertext to the file file_name.
   *
   * Postconditions:
   *    The data from ciphertext has been written to file_name.
   */  
  
  
  void cleanImage();
  /* Description:
   *    Zeros out the least significant bit of each color value in color_data.
   *
   * Preconditions: 
   *    readImage() has already been called (an image is currently being buffered).
   *
   * Postconditions:
   *    All color values are now positive (by zeroing out the least significant bit of color datum).
   */
  
  
  void encipher();
  /* Description:
   *    Stores the text from ciphertext in the image color_data.
   *
   * Preconditions:
   *   The following have already been called:
   *      readCipherText(filename) - Ciphertext is currently buffered.
   *      readImage(filename) - Image is currently buffered.
   *      cleanImage() - The least significant bit of each character has a value of 0.
   *
   * Postconditions:
   *    The ciphertext is stored in the least significant bit of each color value.
   */
  
  
  void decipher();
  /* Description:
   *    Reads the ciphertext back from color_data and stores it in ciphertext.
   * 
   * Preconditions:
   *    readImage(filename) has already been called (image with hidden data is currently buffered).
   *      cleanImage() - The least significant bit of each character has a value of 0.
   *
   * Preconditions:
   *    Plaintext data has been read back from color_data and stored in ciphertext.
   */
};

#endif
