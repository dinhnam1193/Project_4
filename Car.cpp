#include "Car.h"

void Car::setSpeed()
{
	do
	{
		cout << " ---------------BAN DANG O SO " << _arr_Transmis[this->_current_state] << "-----------------" << endl;
		cout << "------ TOC DO HIEN TAI: " << this->_speed << "km/h" << endl;
		/*SET CANH BAO NGUY HIEM*/
		if ((_speed > 20 && _current_state == 2) || (_speed > 60 && _current_state == 4))
		{
			cout << "TOC DO NGUY HIEM, BAN NEN GIAM TOC DO" << endl;

		}
		/*SET CANH BAO KHOAN CACH */
		if (_speed < *getSpeedRange(1)) {
			cout << "BAN CHU Y GIU KHOANG CACH TOI THIEU LA 20m" << endl;
		}
		else if (_speed < *getSpeedRange(2))
		{
			cout << "BAN CHU Y GIU KHOANG CACH TOI THIEU LA 55m" << endl;
		}
		else if (_speed < *getSpeedRange(3))
		{
			cout << "BAN CHU Y GIU KHOANG CACH TOI THIEU LA 70m" << endl;
		}
		else
		{
			cout << "BAN CHU Y GIU KHOANG CACH TOI THIEU LA 100m" << endl;
		}

		cout << " XIN MOI LUA CHON: " << endl;
		cout << _arr_Option[0] << endl << _arr_Option[1] << endl << _arr_Option[2] << endl << _arr_Option[3] << endl;
		cin >> active;
		system("cls");
		if (active > 0 && active <= 4) {
			break;
		}
		else if (active > 4)
		{
			cout << "***************************NHAP SAI LUA CHON!************************* " << endl;
		}
		else {
			cin.clear();
			cin >> stemp;
			cout << "***************************NHAP SAI LUA CHON!************************* " << endl;
		}
	} while (true);

	switch (active)
	{
	case 1:
		if (_speed == 0) //Lan tang toc se tang len 7km/h
		{
			_speed = 7;
		}
		else
		{
			_speed += 5;
		}
		break;
	case 2:
		_speed -= 5;
		if (_speed < 0)
		{
			_speed = 0;
		}
		break;
	case 3:
		_speed = 0;
		break;
	default:
		break;
	}
}

void Car::setState()
{
	cout << "XIN CHAO 12345678" << endl;
	do
	{
		cout << "SO HIEN TAI LA SO: " << _arr_Transmis[before] << endl;
		cout << "------ TOC DO HIEN TAI: " << _speed << "km/h" << endl;
		if (warning == 1) {
			cout << "_________VUI LONG DUA TOC DO VE 0 km/h THI MOI DC CHUYEN SO_________" << endl;

		}
		else if (warning == 2)
		{
			cout << "_________VUI LONG DUA TOC DO VE 0 km/h THI MOI DC CHUYEN SO_________" << endl;
		}
		cout << " XIN MOI LUA CHON: " << endl;
		cout << "1. P" << endl << "2. R" << endl << "3. N" << endl << "4. D" << endl << "5. POWER OFF" << endl;


		do //Nhap so xe va kiem tra 
		{
			cin >> _current_state;
			system("cls");
			if (_current_state > 0 && _current_state < 6)
			{
				break;
			}
			else if (_current_state >= 6)
			{
				system("cls");
				cout << "***********************************NHAP SAI SO!**************************************" << endl;
				cout << " XIN MOI LUA CHON: " << endl;
				cout << "1. P" << endl << "2. R" << endl << "3. N" << endl << "4. D" << endl << "5. POWER OFF" << endl;
			}
			else {
				cin.clear();
				cin >> stemp; // bat ky tu loi	
				system("cls");
				cout << "***********************************NHAP SAI SO!**************************************" << endl;
				cout << " XIN MOI LUA CHON: " << endl;
				cout << "1. P" << endl << "2. R" << endl << "3. N" << endl << "4. D" << endl << "5. POWER OFF" << endl;
			}
		} while (true);

		switch (_current_state)
		{
		case 1: // Trang thai P dau xe
		case 3: // Trang thai N dung xe
			if (_speed == 0)
			{
				cout << "CHU Y SU DUNG PHANH TAY DE DAM BAO AN TOAN" << endl << endl;
				before = _current_state;
			}
			else
			{
				cout << "HAY CHAC CHAN XE DA DUNG VA VAN TOC DA VE 0 km/h" << endl << endl;
			}
			break;
		case 2: // Trang thai R Lui xe
			if (before != _current_state && before != 0 && before != 3 && before != 1 && _speed != 0) {
				warning = 1;
				break;
			}
			else
			{
				warning = 0;
			}
			do
			{
				this->setSpeed();
			} while (active != 4);
			before = _current_state;
			break;
		case 4://Trang thai D tien len
			if (before != _current_state && before != 0 && before != 3 && before != 1 && _speed != 0) {
				warning = 2;
				break;
			}
			else
			{
				warning = 0;
			}
			//cout << " --------------- BAN DAN O SO " << SoXe[current_state - 1] << " -----------------" << endl;
			do
			{
				this->setSpeed();
			} while (active != 4);
			before = _current_state;
			break;
		default:
			break;
		}
	} while (_current_state != 5);
}

void Car::setSpeedRange()
{
	int tempspeed = 0;

	char ctemp = ' ';
	cout << "BAN CO MUON CAP NHAT Range Speed Warning(y/n): " << endl;
	cin >> ctemp;
	if (ctemp == 'y' || ctemp == 'Y') {
		flagupdate = 2;
		cout << "CAI DAT VAN TOC CANH BAO KHOANG CACH AN TOAN VOI 3 MOC TOC DO: " << endl;
		for (size_t i = 0; i < 3; i++)
		{
			do
			{
				cout << "VAN TOC MUC " << i + 1 << ": ";
				cin >> tempspeed;
				if (tempspeed > 0) {
					this->infoCar->speedRange[i + 1] = tempspeed;
					break;
				}
				else if (cin.fail()) {
					cin.clear();
					cin >> stemp;
					cout << "***************************NHAP SAI LUA CHON!************************* " << endl;
				}
			} while (true);
		}
		this->selectionSort(this->infoCar->speedRange, 4);
		//Write Speed Range to binary file 
		/*std::fstream file;
		file = fstream("speedrange.bin", std::ios::out | std::ios_base::binary);
		if (file.is_open())
		{
			for (size_t i = 0; i < 4; i++)
			{
				file.write((char*)&this->speedRange[i], sizeof(int));
			}
			file.close();
		}*/
	}
	else if (cin.fail())
	{
		cin.clear();
		cin >> stemp; // bat ky tu loi
	}

	//Read Speed Range from binary file
	/*ifstream rfile("speedrange.bin", ios::out | ios::binary);
	if (rfile.is_open() && !(ctemp == 'y' || ctemp == 'Y'))
	{
		for (size_t i = 0; i < 4; i++)
		{
			rfile.read((char*)&speedRange[i], sizeof(int));
			//std::cout << "Read data stats: " << speedRange[i] << std::endl;
		}
		rfile.close();
		system("cls");
		std::cout << "Finished reading binary data from speedrange.bin." << std::endl;
	}
	else 
	if (!(ctemp == 'y' || ctemp == 'Y'))*/
	if(!this->infoCar->speedRange[2])
	{
		flagupdate = 2;
		std::cerr << "Couldn't open speedrange.bin for reading." << std::endl;
		cout << "Please Enter Range Speed Warning before Start: " << endl;
		cout << "CAI DAT VAN TOC CANH BAO KHOANG CACH AN TOAN VOI 3 MOC TOC DO: " << endl;
		for (size_t i = 0; i < 3; i++)
		{
			do
			{
				cout << "VAN TOC MUC " << i + 1 << ": ";
				cin >> tempspeed;
				if (tempspeed > 0) {
					this->infoCar->speedRange[i + 1] = tempspeed;
					break;
				}
				else if (cin.fail()) {
					cin.clear();
					cin >> stemp;
					cout << "***************************NHAP SAI LUA CHON!************************* " << endl;
				}
			} while (true);
		}
		this->selectionSort(this->infoCar->speedRange, 4);
		/*std::fstream file;
		file = fstream("speedrange.bin", std::ios::out | std::ios_base::binary);
		if (file.is_open())
		{
			for (size_t i = 0; i < 4; i++)
			{
				file.write((char*)&this->speedRange[i], sizeof(int));
			}
			file.close();
		}*/
		system("cls");
	}
}

int* Car::getSpeedRange(int index)
{
	return this->infoCar->speedRange+index;
}

void Car::selectionSort(int* arr, int n)
{
	int i, j, min_idx, numofloop = 0;

	for (i = 0; i < n - 1; i++)
	{
		// Tim so nho nhap chua duoc sap xep  
		min_idx = i;
		for (j = i + 1; j < n; j++) {
			if (*(arr + j) < *(arr + min_idx))
				min_idx = j;
			numofloop++;
		}
		// Thay doi vi tri so nho nhap vua tim dc  
		swap(arr + min_idx, arr + i);
	}
	cout << "So lan loop cua thuat toan sap sep Selection: " << numofloop << endl;
}

void Car::bubbleSort(int* arr, int n)
{
	int i, j, numofloop = 0;
	for (i = 0; i < n - 1; i++)// 3(n-1)
	{
		for (j = 0; j < n - i - 1; j++) //7(n-1)/2
		{
			if (*(arr + j) > * (arr + (j + 1)))
			{
				swap(arr + j, arr + (j + 1));
			}
			numofloop++;
		}
	}
	cout << "So lan loop cua thuat toan sap sep Bubble: " << numofloop << endl;
}

void Car::printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void Car::swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

bool Car::comPareID(int arr1[], int arr2[], unsigned int n)
{
	for (size_t i = 0; i < n; i++)
	{
		if (arr1[i] != arr2[i])
			return false;
	}
	return true;
}

void Car::checkID()
{
	int tempID = -1;
	do
	{
		cout << "NHAP MA SO CA NHAN, MANG 8 SO: " << endl;
		for (size_t i = 0; i < 8; i++) //Khoi LENH nhap nhap ma so ca nhan ID
		{
			do {
				cout << "SO THU " << i + 1 << " : ";
				cin >> tempID;
				if (cin.fail())
				{
					cin.clear();
					cin >> stemp; // bat ky tu loi
					//continue;
				}
			} while (tempID > 9 || tempID < 0);
			arrNumbUserID[i] = tempID;
		}
		system("cls");
		//arrNumberID = cartemp.getNumID();
		cout << "MANG NHAP VAO TRUOC KHI SAP XEP: ";
		printArray(arrNumbUserID, 8);
		bubbleSort(arrNumbUserID, 8);
		cout << "---> MANG NHAP VAO SAU KHI SAP XEP: ";
		printArray(arrNumbUserID, 8);
		cout << "MANG SO CA NHAN TRUOC KHI SAP XEP: ";
		printArray(this->infoCar->arrNumbID, 8);
		selectionSort(this->infoCar->arrNumbID, 8);
		cout << "---> MANG SO CA NHAN SAU KHI SAP XEP: ";
		printArray(this->infoCar->arrNumbID, 8);
		if (comPareID(this->infoCar->arrNumbID, arrNumbUserID, 8)) {
			break;
		}
		else {
			cout << "------------------BAN DA NHAP SAI MA SO XIN MOI NHAP LAI------------------" << endl;
		}
	} while (true);
}

void Car::Start()
{
	this->checkID();
	this->setSpeedRange();
	this->setState();
}

Car::Car()
{
	//Read number ID from binary file
	ifstream rfile("inforcar.bin", ios::out | ios::binary);
	if (rfile.is_open())
	{
		//for (size_t i = 0; i < 8; i++)
		//{
		//	rfile.read((char*)&arrNumbID[i], sizeof(int));
		//	//std::cout << "Read data stats: " << arrNumbID[i] << std::endl;
		//}
		rfile.read((char*)this->infoCar, sizeof(CarOSafe));
		rfile.close();
		system("cls");
		std::cout << "Finished reading binary data from inforcar.bin." << std::endl;
	}
	else
	{
		std::cerr << "Couldn't open inforcar.bin for reading." << std::endl;
		cout << "Please Enter Number ID before Start: " << endl;
		//int arrNumbIDtemp[8] = { 0 };
		int tempID = -1;
		cout << "NHAP MA SO CA NHAN, MANG 8 SO: " << endl;
		for (size_t i = 0; i < 8; i++) // Enter ID number
		{
			do {
				cout << "SO THU " << i + 1 << " : ";
				cin >> tempID;
				if (cin.fail())
				{
					cin.clear();
					cin >> stemp; // bat ky tu loi
				}
			} while (tempID > 9 || tempID < 0);
			this->infoCar->arrNumbID[i] = tempID;
			//memcpy((char*)this->infoCar->arrNumbID[i], (char*)tempID, sizeof(int));
		}

		system("cls");
		cout << "NHAP LAI DE XAC NHAN MA SO CA NHAN" << endl;
	}
}

Car::~Car()
{
	//Write number ID to binary file 
	char ctemp = ' ';
	int tempID = -1;
	cout << "BAN CO MUON CAP NHAT MSCN(y/n): " << endl;
	cin >> ctemp;
	if (ctemp == 'y' || ctemp == 'Y') {
		flagupdate = 1;
		int arrNumbIDtemp[8] = { 0 };

		//do
		{
			cout << "NHAP MA SO CA NHAN, MANG 8 SO: " << endl;
			for (size_t i = 0; i < 8; i++) // Enter ID number
			{
				do {
					cout << "SO THU " << i + 1 << " : ";
					cin >> tempID;
					if (cin.fail())
					{
						cin.clear();
						cin >> stemp; // bat ky tu loi
						//continue;
					}
				} while (tempID > 9 || tempID < 0);
				arrNumbIDtemp[i] = tempID;
				this->infoCar->arrNumbID[i] = tempID;
			}
		} //while (true);
		
	}
	if (flagupdate) {
		std::fstream file;
		file = fstream("inforcar.bin", std::ios::out | std::ios_base::binary);
		if (file.is_open())
		{
			file.write((char*)this->infoCar, sizeof(CarOSafe));
			file.close();
		}
	}
	cout << "____________________________POWER OFF_________________________" << endl;
	cout << " ____________________________BYE BYE_________________________" << endl;
}
