// Name: Ryan Griffiths
// Assignment: A2
// Course: CISP400 Fa24
// File name: Encrypt.h
// Purpose: Encrypt class definition. File contains the public interface of Encrypt
//    without revealing implementations of member functions 
//    which are defined in Encrypt.cpp. 


#include <array> // Encrypt class uses a C++ container, array.
#include <cstddef> // C++ standard lib. header for unsigned integer type size_t.
 
// Constant variable for array size. 
const size_t ARRAY_SIZE{ 8 };


class Encrypt 
{
public:
	Encrypt(int); // Constructor for Encrypt
	void displayOriginalData() const; // Function to diplay original entered data
	void storeData(int); // Function to store original and encrypted data
	void displayEncryptedData() const; // Function to display encrypted data 

private:
	std::array<int, ARRAY_SIZE> digits{}; // digits array

}; // end of class Encrypt
