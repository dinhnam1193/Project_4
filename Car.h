#pragma once
#include <iostream>
#include <fstream>

using namespace std;


struct CarOSafe
{
	int speedRange[4] = { 0 }; // Mang chua cac moc toc do quy dinh khoang cach
	int arrNumbID[8] = { 0 }; // MANG chua ma so ca nhan 8 chu so
};
class Car
{
private:
	int flagupdate = 0;// Co bao update data
	int _speed = 0; //Toc do xe
	int _current_state = 0; //Trang thai so cua xe
	int active = 0; // Bien dieu khien qua trinh tang giam toc
	string stemp; // bien tam luu gia tri nhap sai
	int before = 0; // Trang thai so truoc do 
	int warning = 0;
	CarOSafe* infoCar = new CarOSafe();
	int arrNumbUserID[8] = { 0 };// MANG chua ma so ca nhan 8 chu so user se nhap vao
public:
	string _arr_Transmis[8] = { "Ready", "P", "R", "N", "D", "POWER OFF" };
	string _arr_Option[5] = { "1. TANG TOC", "2. GIAM TOC", "3. PHANH", "4 .TRO VE MENU" };
	void setSpeed();
	//int getSpeed();
	void setState();
	//int getState();
	//int* getNumID(); // Get Number ID of Car
	void setSpeedRange(); // Function setting Range for distance
	int* getSpeedRange(int index);
	void selectionSort(int* arr, int n); //Sort value of array Range Distance
	void bubbleSort(int* arr, int n);
	void printArray(int arr[], int size);
	void swap(int* xp, int* yp);
	bool comPareID(int arr1[], int arr2[], unsigned int n);
	void checkID();
	void Start();
	Car();
	~Car();
};

