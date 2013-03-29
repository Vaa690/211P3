#include "devices.h"
#include "definitions.h"
#include "stdlib.h"
#include "string.h"
#include <iostream>

using namespace std;

// Initializing constructor:
// Sets the count and time data members to 0, and last malfuntion type to NO_MALFUNCTION

malfunctionRecord::malfunctionRecord() {

	mlfn_count = 0;
	mlfn_time = 0;
	mlfn_type = NO_MALFUNCTION;
}

// Increments the count, sets type and time to mlfn and tm respectively

void malfunctionRecord::malfunction(int mlfn, int tm) {

	mlfn_count++;
	mlfn_type = mlfn;
	mlfn_time = tm;

}

// If count is 0: print that the device never malfunctioned
// If count is greater than 0, print the count, last malfunction type, and time

void malfunctionRecord::display() {

	cout<<"\n=========================================="<<endl;
	cout<<"======== MALFUNCTION INFORMATION ========="<<endl;
	cout<<"=========================================="<<endl;

	if(mlfn_count == 0) {
		cout<<"This device has never malfunctioned"<<endl;
	}

	if(mlfn_count>0) {
		cout<<"The number of malfunctions is: "<<mlfn_count<<endl;
		cout<<"\nThe last malfunction type was: "<<mlfn_type<<endl;
		cout<<"\nThe last malfunction time was: "<<mlfn_time<<endl;
	}

}

// Returns the count as the answer
// Sets m to last malfunction type and t to last malfunction time

int malfunctionRecord::getRecord(int* m, int* t) {

	*m = mlfn_type;
	*t = mlfn_time; 

	return mlfn_count;
}

// Use malloc to allocate enough space to hold string n
// The address returned by malloc should be assigned to the data member for the device name

device::device(char* n, int sn) {

	device_name = (char* )malloc(strlen(n)+1);
	strcpy(device_name, n); // WARNING ON STRCPY
	serial_number = sn;
	
}

// Destructor: frees memory allocated to hold the name data member

device::~device() {

	free(device_name);

}

// Display information on the device

void device::display() {

	cout<<"\n========================================"<<endl;
	cout<<"========== Device Information ============"<<endl;
	cout<<"=========================================="<<endl;
	cout<<"The name of the device is: "<<device_name<<endl;
	cout<<"\nThe serial number for the device is: "<<serial_number<<endl;
	cout<<"\nThe device value is: "<<device_value<<endl;
	malf.display();

}

// Has the malfunctionRecord data member call its malfunctionRecord function member

void device::recordMalfunction(int m, int t) {

	malf.malfunction(m, t);

}

// Has the malfunctionRecord data member call its getMalfunctionRecord function member
// Returns the answer as it's own answer

int device::getMalfunctionRecord(int* m, int* t) {
	
	int x = malf.getRecord(m, t);

	return x;

}

// Uses strcmp to compare the devices name with the argument n. Returns 1 if equal, 0 if not.

int device::amIThisDevice(char* n) {
	
	if (strcmp(device_name, n) == 0) {
		return 1;
	}

	else {
		return 0;
	}
}