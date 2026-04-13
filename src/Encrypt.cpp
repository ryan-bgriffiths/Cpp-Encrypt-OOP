// Name: Ryan Griffiths
// Assignment: A2
// Course: CISP400 Fa24
// File name: Encrypt.cpp
// Purpose: File contains Class and member function definitions 

#include <iostream>
#include "Encrypt.h" // include definition of class Encrypt 
using namespace std;

// Encrypt Constructor: stores original number and encrypted number using member functions,
//    displays the original data, encrypted data, and constructor call message. 
Encrypt::Encrypt(int input_data) {
	cout << "\n\n** The default constructor is called\n   and the passed in number is " <<
		input_data << ".**" << endl;

	Encrypt::storeData(input_data);
	Encrypt::displayOriginalData();
	Encrypt::displayEncryptedData();
} // End of constructor. 

// Function uses for loop to step through 1st 4 elements of digits to display original data
void Encrypt::displayOriginalData() const{
	cout << "\n     The original data is";
	for (int i{ 0 }; i < 4; ++i) {
		cout << " " << digits[i];
	}
	cout << ".\n";
}// End of function

// Function stores original data in 1st 4 elements of digits array
//   and stores encrypted data in last 4 elements of digits array. 
void Encrypt::storeData(int input_data) {
	if (input_data <= 0) { // test for values less than or equal to 0 & set to 9436
		digits[0] = 9;
		digits[1] = 4;
		digits[2] = 3;
		digits[3] = 6;
		cout << "\n XXX The input number is less than or equal to 0." <<
			"\n     The number is reset to 9436. XXX" << endl;
	}
	else if (input_data < 10) { // test for a single digit integer & store
		for (int i{ 0 }; i < 3; ++i) {
			digits[i] = 0;
		}
		digits[3] = input_data;
	}
	else if (input_data < 100) { // test for double digit integer & store  
		digits[0] = 0;
		digits[1] = 0;
		digits[2] = input_data / 10;
		digits[3] = input_data % 10;
	}
	else if (input_data < 1000) { // test for tripple digit integer & store
		digits[3] = (input_data % 100) % 10;
		digits[2] = (input_data / 10) % 10;
		digits[1] = input_data / 100;
		digits[0] = 0;
	}
	else if (input_data < 10000) { // test for 4 digit integer & store
		digits[3] = input_data % 10;
		digits[2] = (input_data % 100) / 10;
		digits[1] = (input_data % 1000) / 100;
		digits[0] = input_data / 1000;
	}
	else {
		int temp{ input_data % 10000 }; // store any integer larger than 4 digits
		digits[3] = temp % 10;
		digits[2] = (temp % 100) / 10;
		digits[1] = (temp % 1000) / 100;
		digits[0] = temp / 1000;
	}

	// Start of Encrypting the data in the last 4 elements of digits array
	for (int i{ 0 }; i < 4; ++i) {
		digits[i + 4] = (digits[i] + 7) % 10;
	}

	int swap_value{ 0 }; // variable to hold one of the values to swap

	swap_value = digits[4]; // swap 1st value with 3rd value of
	digits[4] = digits[6];  //   the last 4 elements of digits array.
	digits[6] = swap_value;  

	swap_value = digits[5]; // swap the 2nd value with the 4th value of
	digits[5] = digits[7];  //   the last 4 elements of digits array. 
	digits[7] = swap_value;
	// End of encryption steps

}// End of function

// Function to display the encrypted data
void Encrypt::displayEncryptedData() const{
	cout << "     The encrypted data is";
	// For loop to step through the last 4 elements of digits array. 
	for (int i{ 4 }; i < ARRAY_SIZE; ++i) {
		cout << " " << digits[i]; 
	}
	cout << ".\n";
}// End of function.