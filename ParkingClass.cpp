#include<iostream>
#include <fstream>
#include <cstring>
using namespace std;
class ParkingBlock
{
private:
	char*** slots;
	int* slotsPerRow, totalRows;
	float x_coordinate, y_coordinate;
public:
	bool isEmpty(int row, int slot) const //row slot index 0th 
	{
		char* p = new char[6];
		p[0] = 'E', p[1] = 'M'; p[2] = 'P', p[3] = 'T', p[4] = 'Y', p[5] = '\0';
		for (int i = 0; i < 6; i++)
		{
			if (p[i] != slots[row][slot][i])
			{
				delete[]p;
				return false;
			}
		}
		delete[]p;
		return true;
	}
	ParkingBlock()
	{
		slots = nullptr;
		slotsPerRow = nullptr;
		totalRows = 0, x_coordinate = 0.0, y_coordinate = 0.0;
	}
	ParkingBlock(const ParkingBlock& source)
	{
		totalRows = source.totalRows;
		slotsPerRow = new int[totalRows];
		for (int i = 0; i < totalRows; i++)
		{
			slotsPerRow[i] = source.slotsPerRow[i];
		}
		this->alot();
		for (int i = 0; i < totalRows; i++)
		{
			for (int j = 0; j < slotsPerRow[i]; j++)
			{
				if (source.isEmpty(i, j))
				{
					slots[i][j] = new char[6];
					for (int k = 0; k < 6; k++)
					{
						slots[i][j][k] = source.slots[i][j][k];
					}
				}
				else
				{
					slots[i][j] = new char[9];
					for (int k = 0; k < 9; k++)
					{
						slots[i][j][k] = source.slots[i][j][k];
					}
				}
			}
		}
		x_coordinate = source.x_coordinate;
		y_coordinate = source.y_coordinate;

	}
	ParkingBlock(int numRows)
	{
		totalRows = numRows;
		slots = new char** [numRows];
		slotsPerRow = new int[numRows];
		for (int i = 0; i < numRows; i++)
		{
			slots[i] = nullptr;
			slotsPerRow[i] = 0;
		}
		x_coordinate = 0.0, y_coordinate = 0.0;
	}
	ParkingBlock(ParkingBlock&& source)
	{
		totalRows = source.totalRows;
		source.totalRows = 0;
		slotsPerRow = source.slotsPerRow;
		source.slotsPerRow = nullptr;
		slots = source.slots;
		source.slots = nullptr;
		x_coordinate = source.x_coordinate;
		y_coordinate = source.y_coordinate;
		source.x_coordinate = 0;
		source.y_coordinate = 0;
	}
	ParkingBlock& operator=(const ParkingBlock& source)
	{
		if (this == &source)
		{
			return *this;
		}
		if (slots != nullptr)
		{
			for (int i = 0; i < totalRows; i++)
			{
				for (int j = 0; j < slotsPerRow[i]; j++)
				{
					delete[]slots[i][j];
					slots[i][j] = nullptr;
				}
				delete[]slots[i];
				slots[i] = nullptr;
			}
			delete[]slots;
			slots = nullptr;
			delete[]slotsPerRow;
			slotsPerRow = nullptr;
		}
		totalRows = source.totalRows;
		slotsPerRow = new int[totalRows];
		for (int i = 0; i < totalRows; i++)
		{
			slotsPerRow[i] = source.slotsPerRow[i];
		}
		this->alot();
		for (int i = 0; i < totalRows; i++)
		{
			for (int j = 0; j < slotsPerRow[i]; j++)
			{
				if (source.isEmpty(i, j))
				{
					slots[i][j] = new char[6];
					for (int k = 0; k < 6; k++)
					{
						slots[i][j][k] = source.slots[i][j][k];
					}
				}
				else
				{
					slots[i][j] = new char[9];
					for (int k = 0; k < 9; k++)
					{
						slots[i][j][k] = source.slots[i][j][k];
					}
				}
			}
		}
		x_coordinate = source.x_coordinate;
		y_coordinate = source.y_coordinate;

		return *this;
	}
	ParkingBlock& operator=(ParkingBlock&& source)
	{
		if (this == &source)
		{
			return *this;
		}
		if (slots != nullptr)
		{
			for (int i = 0; i < totalRows; i++)
			{
				for (int j = 0; j < slotsPerRow[i]; j++)
				{
					delete[]slots[i][j];
					slots[i][j] = nullptr;
				}
				delete[]slots[i];
				slots[i] = nullptr;
			}
			delete[]slots;
			slots = nullptr;
			delete[]slotsPerRow;
			slotsPerRow = nullptr;
		}
		totalRows = source.totalRows;
		source.totalRows = 0;
		slotsPerRow = source.slotsPerRow;
		source.slotsPerRow = nullptr;
		slots = source.slots;
		source.slots = nullptr;
		x_coordinate = source.x_coordinate;
		y_coordinate = source.y_coordinate;
		source.x_coordinate = 0;
		source.y_coordinate = 0;
		return *this;
	}


	void coordinate(float x, float y)
	{
		x_coordinate = x, y_coordinate = y;
	}
	bool isEmp(int row,int slot) //row slot index 0th 
	{
		char* p = new char[6];
		p[0] = 'E', p[1] = 'M'; p[2] = 'P', p[3] = 'T', p[4] = 'Y', p[5] = '\0';
		for (int i = 0; i<6; i++)
		{
			if (p[i] != slots[row][slot][i])
			{
				delete[]p;
				return false;
			}
		}
		delete[]p;
		return true;
	}
	void alot()
	{
		slots = new char** [totalRows];
		for (int i = 0; i < totalRows; i++)
		{
			slots[i] = new char* [slotsPerRow[i]];
		}
	}
	void empty(int row,int s)
	{
		slots[row][s] = new char[6];
		char* p = new char[6];
		p[0] = 'E', p[1] = 'M'; p[2] = 'P', p[3] = 'T', p[4] = 'Y', p[5] = '\0';
		for (int i = 0; i < 6; i++)
		{
			slots[row][s][i] = p[i];
		}
		delete[]p;
	}
	void ParkingStructure()
	{
		Rows://label just
		cout << "\nEnter the Number of Rows : ";
		cin >> totalRows;
		if ((totalRows < 0))
		{
			cout << "Wrong Row-Numbers! Enter Again : \n";
			goto Rows;
		}
		slotsPerRow = new int[totalRows];
		for (int i = 0; i < totalRows; i++)
		{
			sN://slot number
			cout << "\nEnter the Number of Slots for " << i+1 << "th Row : ";
			cin >> slotsPerRow[i];
			if ((slotsPerRow[i] < 0))
			{
				cout << "Wrong Slot-Numbers! Enter Again : \n";
				goto sN;
			}
		}
		alot();
		for (int i = 0; i < totalRows; i++)
		{
			for (int j = 0; j < slotsPerRow[i]; j++)
			{
				empty(i, j);
			}
		}
	}
	bool validate(int row, int slot)//row slot validation
	{
		if ((row <= 0 or row > totalRows))
		{
			cout << "\nInvalid Row Number !";
			return false;
		}
		if ((slot <= 0 or slot > slotsPerRow[row - 1]))
		{
			cout << "\nInvalid Slot Number !";
			return false;
		}
		return true;
	}
	void parkCar(int row, int slot, char*&vehicleNumber)
	{
		if (!(validate(row, slot)))
			return;
		if (isEmp(row-1, slot-1))
		{
			delete[]slots[row - 1][slot - 1];
			slots[row - 1][slot - 1] = new char[9];
			for (int i = 0; i < 9; i++)
			{
				slots[row - 1][slot - 1][i] = vehicleNumber[i];
			}
			cout << "\n-----------------------------";
			cout << "\nCar License Number : " << vehicleNumber <<"\nSuccessfully Parked" << endl;
			cout << "-----------------------------\n";
			delete[]vehicleNumber;
			vehicleNumber = nullptr;
		}
		else
		{
			cout << "\nSlots is Not Avaliable";
		}
	}
	void removeCar(int row, int slot)
	{
		if (!(validate(row, slot)))
			return;
		if (!(isEmp(row - 1, slot - 1)))
		{
			cout << "\n-----------------------------";
			cout << "\nCar License Number : " << slots[row-1][slot-1] << "\nSuccessfully UnParked" << endl;
			cout << "-----------------------------\n";
			delete[]slots[row - 1][slot - 1];
			empty(row - 1, slot - 1);
		}
		else
		{
			cout << "\nSlot is Already Empty!";
		}
	}
	
	void displayBlock()
	{
		cout << "\nBlock's Coordinates (x : " << x_coordinate << " , y : " << y_coordinate<<")\n";
		for (int i = 0; i < totalRows; i++)
		{
			cout << "Row : " << i + 1<<" ";
			for (int j = 0; j < slotsPerRow[i]; j++)
				cout << slots[i][j] << "     ";
			cout << endl;
		}
	}
	void increaseSlots(int row, int newSize)// 1th base index
	{
		if (row <= 0 || row > totalRows || newSize <= 0 || newSize <= slotsPerRow[row - 1])
		{
			cout << "\nInvalid Input!";
			return;
		}
		char** p = new char* [newSize];
		for (int i = 0; i < slotsPerRow[row - 1]; i++)
		{
			if (isEmp(row - 1, i))
			{
				p[i] = new char[6];
				p[i][0] = 'E', p[i][1] = 'M', p[i][2] = 'P', p[i][3] = 'T', p[i][4] = 'Y', p[i][5] = '\0';
			}
			else
			{
				p[i] = new char[9];
				for (int j = 0; j < 9; j++)
				{
					p[i][j] = slots[row - 1][i][j];
				}
			}
		}
		for (int i = 0; i < slotsPerRow[row - 1]; i++)
		{
			delete[]slots[row - 1][i];
			slots[row - 1][i] = nullptr;
		}
		delete[]slots[row - 1];
		slots[row - 1] = nullptr;
		for (int i = slotsPerRow[row - 1]; i < newSize; i++)
		{
			p[i] = new char[6];
			p[i][0] = 'E', p[i][1] = 'M', p[i][2] = 'P', p[i][3] = 'T', p[i][4] = 'Y', p[i][5] = '\0';
		}
		slots[row - 1] = p;
		p = nullptr;
		slotsPerRow[row - 1] = newSize;

	}
	void decreaseSlots(int row, int newSize)
	{
		if (row <= 0 or row > totalRows or newSize >= slotsPerRow[row - 1] or newSize <= 0)
		{
			cout << "\nInvalid Input!";
			return;
		}
		for (int i = newSize-1; i < slotsPerRow[row - 1]; i++)
		{
			if (!(isEmp(row - 1, i)))
			{
				cout << "\nCan't be Decreased As there are Vehicles Parked!";
				return;
			}
		}
		char** p = new char* [newSize];
		for (int i = 0; i < newSize; i++)
		{
			if (isEmp(row - 1, i))
			{
				p[i] = new char[6];
				p[i][0] = 'E', p[i][1] = 'M', p[i][2] = 'P', p[i][3] = 'T', p[i][4] = 'Y', p[i][5] = '\0';
			}
			else
			{
				p[i] = new char[9];
				for (int j = 0; j < 9; j++)
				{
					p[i][j] = slots[row - 1][i][j];
				}
			}
		}
		for (int i = 0; i < slotsPerRow[row - 1]; i++)
		{
			delete[]slots[row - 1][i];
			slots[row - 1][i] = nullptr;
		}
		delete[]slots[row - 1];
		slots[row - 1] = p;
		p = nullptr;
		slotsPerRow[row - 1] = newSize;
	}
	int* searchVehicle(char* vehicleNumber)
	{
		int count = 0,*f=nullptr;
		for (int i = 0; i < totalRows; i++)
		{
			for (int j = 0; j < slotsPerRow[i]; j++)
			{
				if (!isEmp(i, j))
				{
					count = 0;
					for (int k = 0; k < 9; k++)
					{
						if (slots[i][j][k] != vehicleNumber[k])
							break;
						count++;
					}
					if (count == 9)
					{
						f = new int[2];
						f[0] = i;
						f[1] = j;
						return f;
					}
				}
			}
		}
		return f;//delete problem
	}
	void emptyRow(int row)  //Object is not Creating so there Will be no Copy or Assignment
	{
		for (int i = 0; i < slotsPerRow[row - 1]; i++)
		{
			if (!isEmp(row - 1, i))
			{
				delete[]slots[row - 1][i];
				slots[row - 1][i] = new char[6];
				slots[row - 1][i][0] = 'E', slots[row - 1][i][1] = 'M', slots[row - 1][i][2] = 'P';
				slots[row - 1][i][3] = 'T', slots[row - 1][i][4] = 'Y', slots[row - 1][i][5] = '\0';

			}
		}
	}
	void emptyBlock()
	{
		for (int i = 0; i < totalRows; i++)
		{
			emptyRow(i + 1);//EmptyRow calling isEmp(row-1)
		}
	}
	void deep(ParkingBlock& source)
	{
		totalRows = source.totalRows;
		slotsPerRow = new int[totalRows];
		for (int i = 0; i < totalRows; i++)
		{
			slotsPerRow[i] = source.slotsPerRow[i];
		}
		slots = new char** [totalRows];
		for (int i = 0; i < totalRows; i++)
		{
			slots[i] = new char* [slotsPerRow[i]];
		}
		for (int i = 0; i < totalRows; i++)
		{
			for (int j = 0; j < slotsPerRow[i]; j++)
			{
				if (!source.isEmp(i, j))
				{
					slots[i][j] = new char[9];
					for (int k = 0; k < 9; k++)
					{
						slots[i][j][k] = source.slots[i][j][k];
					}
				}
				else
				{
					slots[i][j] = new char[6];
					for (int k = 0; k < 6; k++)
					{
						slots[i][j][k] = source.slots[i][j][k];
					}
				}
			}
		}
	}
	void transferVehicles(ParkingBlock& source)
	{
		for (int i = 0; i < totalRows; i++)
		{
			for (int j = 0; j < slotsPerRow[i]; j++)
			{
				delete[]slots[i][j];
				slots[i][j] = nullptr;
			}
			delete[]slots[i];
			slots[i] = nullptr;
		}
		delete[]slots;
		slots = nullptr;
		delete[]slotsPerRow;
		slotsPerRow = nullptr;
		deep(source);
	}
	void smartAllocate(char* &vehicleNumber, int desiredBlockIndex)
	{
		float x = 0.0, y = 0.0;
		double minDis = 1000000.0,dis=0;
		int row = 0, slot = 0;
		bool find = false;
		for (int i = 0; i < totalRows; i++)
		{
			for (int j = 0; j < slotsPerRow[i]; j++)
			{
				if (isEmp(i, j))
				{
					x = x_coordinate + j * 8;
					y = y_coordinate + i * 16;
					dis = sqrt((x - x_coordinate) * (x - x_coordinate) + (y - y_coordinate) * (y - y_coordinate));
					if (dis < minDis)
					{
						find = true;
						minDis = dis;
						row = i + 1;
						slot = j + 1;
					}
				}
			}
		}
		if (!find)
		{
			cout << "\nBlock Is Filled! ";
		}
		else
		{
			cout << "\nMinimum Walking Distance : " << minDis <<"\nBlock : "<<desiredBlockIndex+1 << "\nRow : " << row << "\nSlot : " << slot << endl;
			parkCar(row, slot, vehicleNumber);
		}
	}
	void addSlots(int row, int n)//row as index
	{
		slots[row] = new char* [n];
		slotsPerRow[row] = n;
		for (int i = 0; i < n; i++)
		{
			empty(row, i);
		}
	}
	void addRows(int n)
	{
		totalRows=n;
		slots = new char** [n];
		slotsPerRow = new int[n];
		for (int i = 0; i < n; i++)
			slots[i] = nullptr;
	}
	void count(ParkingBlock& source, int row, int& Ecount, int& Vcount)
	{
		for (int i = 0; i < slotsPerRow[row]; i++)
		{
			if (isEmp(row, i))
				Ecount++;
		}
		for (int i = 0; i < source.slotsPerRow[row]; i++)
		{
			if (!source.isEmp(row, i))
				Vcount++;
		}
	}
	void copy(ParkingBlock& source, int row,int slot)
	{
		for (int i = 0; i < slotsPerRow[row]; i++)
		{
			if (slots[row][i] == nullptr || isEmp(row, i))
			{
				if (slots[row][i] != nullptr)
				{
					delete[]slots[row][i];
				}
				slots[row][i] = new char[9];
				for (int j = 0; j < 9; j++)
				{
					slots[row][i][j] = source.slots[row][slot][j];
				}
				return;//one one copy and move back
			}
		}
	}
	void additionofslots(int row,int n)
	{
		char** NewS = new char* [slotsPerRow[row] + n];
		for (int i = 0; i < slotsPerRow[row]; i++)// slotsPerRow[row] is setted to 0 in addition of Rows function
		{
			if (slots[row][i] == nullptr || isEmp(row, i)) //slots[row][i] == nullptr is already handeled but for good practice
			{
				NewS[i] = new char[6];
				for (int j = 0; j < 6; j++)
				{
					NewS[i][j] = slots[row][i][j];
				}
			}
			else
			{
				NewS[i] = new char[9];
				for (int j = 0; j < 9; j++)
				{
					NewS[i][j] = slots[row][i][j];
				}
			}
		}
		for (int i = slotsPerRow[row]; i < slotsPerRow[row] + n; i++)//for optimization
		{
			NewS[i] = nullptr;
		}
		for (int i = 0; i < slotsPerRow[row]; i++)
		{
			if (slots[row][i] != nullptr)//->Already handled but for good practice 
			{
				delete[]slots[row][i];
				slots[row][i] = nullptr;
			}
		}
		if(slots[row]!=nullptr)
			delete[]slots[row];
		slots[row] = NewS;
		NewS = nullptr;
		slotsPerRow[row] += n;

	}
	void additionofRows(int n)
	{
		char*** NewS = new char** [totalRows + n];
		for (int i = 0; i < totalRows; i++)
		{
			NewS[i] = new char* [slotsPerRow[i]];
			for (int j = 0; j < slotsPerRow[i]; j++)
			{
				if (isEmp(i, j))
				{
					NewS[i][j] = new char[6];
					for (int k = 0; k < 6; k++)
					{
						NewS[i][j][k] = slots[i][j][k];
					}
				}
				else
				{
					NewS[i][j] = new char[9];
					for (int k = 0; k < 9; k++)
					{
						NewS[i][j][k] = slots[i][j][k];
					}
				}
			}
		}
		for (int i = totalRows; i < totalRows + n; i++)
		{
			NewS[i] = nullptr;
		}
		int* Nspr = new int[totalRows + n]; //number of slots copying
		for (int i = 0; i < totalRows + n; i++)
		{
			if (i < totalRows)
				Nspr[i] = slotsPerRow[i];
			else
				Nspr[i] = 0;
		}


		for (int i = 0; i < totalRows; i++)
		{
			for (int j = 0; j < slotsPerRow[i]; j++)
			{
				delete[]slots[i][j];
				slots[i][j] = nullptr;
			}
			delete[]slots[i];
			slots[i] = nullptr;
		}
		delete[]slots;
		slots = nullptr;
		delete[]slotsPerRow;
		slotsPerRow = nullptr;

		slots = NewS;
		NewS = nullptr;
		totalRows += n;
		slotsPerRow = Nspr;
		Nspr = nullptr;

		
	}
	void mergeVehicles(ParkingBlock& source)
	{
		
		for (int i = 0; i < totalRows && i<source.totalRows; i++)//i -> row 0th based
		{
			int Ecount = 0, Vcount = 0;
			count(source, i, Ecount, Vcount);

			if (Ecount >= Vcount)
			{
				for (int j = 0; j < source.slotsPerRow[i]; j++)
				{
					if (!source.isEmp(i, j))
					{
						copy(source, i, j);
					}
				}
			}
			else
			{
				//addition of slots Vcount-Ecount =n;
				int n = Vcount - Ecount;
				additionofslots(i, n);
				for (int j = 0; j < source.slotsPerRow[i]; j++)
				{
					if (!source.isEmp(i, j))
					{
						copy(source, i, j);
					}
				}

			}
		}
		if (totalRows < source.totalRows)
		{
			int drn = totalRows; //destination num-of-rows as it will the same after calling Addition of Row
			int n = source.totalRows - totalRows;
			//addition of Rows -> source.totalRows - totalRows=n
			additionofRows(n);
			for (int i = drn; i < drn + n; i++)
			{
				int Vcount = 0;
				for (int j = 0; j < source.slotsPerRow[i]; j++)
				{
					if (!source.isEmp(i, j))
					{
						Vcount++;
					}					
				}
				additionofslots(i, Vcount);
				for (int j = 0; j < source.slotsPerRow[i]; j++)
				{
					if (!source.isEmp(i, j))
					{
						copy(source, i, j);
					}
				}

				
			}


		}
	}
	~ParkingBlock()
	{
		for (int i = 0; i < totalRows; i++)
		{
			for (int j = 0; j < slotsPerRow[i]; j++)
			{
				delete[]slots[i][j];
				slots[i][j] = nullptr;
			}
			delete[]slots[i];
			slots[i] = nullptr;
		}
		delete[]slots;
		slots = nullptr;
		delete[]slotsPerRow;
		slotsPerRow = nullptr;
	}
};




ParkingBlock* loadParkingLot(string filename, int& totalBlocks) 
{
	ifstream file(filename);
	if (!file) 
	{
		cout << "\nFile not found!" << endl;
		totalBlocks = 0;
		return nullptr;
	}

	file >> totalBlocks;
	ParkingBlock* blocks = new ParkingBlock[totalBlocks];

	for (int i = 0; i < totalBlocks; i++) 
	{
		int totalRows;
		file >> totalRows;

		blocks[i].addRows(totalRows);

		for (int j = 0; j < totalRows; j++)
		{
			int slotsPerRow;
			file >> slotsPerRow;
			blocks[i].addSlots(j, slotsPerRow); 
		}
	}

file.close();
return blocks;
}
void loadBlockCoordinates(string filename, ParkingBlock* blocks, int totalBlocks)
{
	ifstream file(filename);
	if (!file)
	{
		cout << "\nFile not found!" << endl;
		return;
	}
	float x, y;
	int count = 0;
	while (file >> x >> y && count < totalBlocks)
	{
		blocks[count++].coordinate(x, y);
	}

}
void menu()
{

	cout << "\n---------------ParkingMenu-------------------";
	cout << "\n 1   Park a vehicle\n 2   Remove a vehicle\n 3   Display full parking system\n 4   Increase slots in a row\n 5   Decrease slots in a row\n 6   Search for a vehicle\n 7   Empty a row\n 8   Empty a block\n 9   Transfer vehicles between blocks\n 10  Smart allocate a vehicle\n 11  Load block coordinates from file\n 12  Merge vehicles into a block\n 13  Exit\n";
	cout << "-----------------------------------------------\n";
}



int main()
{
	int n, choice, nb;
	ParkingBlock* blocks = nullptr;
	wrong:

	cout << " Initialize: \n0 -> load from file \n1 -> Enter layout manually at runtime\n";
	cin >> n;
	if (n != 0 && n != 1)
	{
		cout << "Wrong Input! Enter Again : \n";
		goto wrong;
	}
	if (n == 1)
	{
	b:
		cout << "Enter Number of Blocks : ";
		cin >> nb;
		if ((nb < 0))
		{
			cout << "Wrong Block-Number! Enter Again : \n";
			goto b;
		}
		blocks = new ParkingBlock[nb];
		for (int i = 0; i < nb; i++)
		{
			blocks[i].ParkingStructure();
		}
	}
	else
	{
		string s = "block.txt";
		blocks = loadParkingLot(s, nb);
	}
	while (1)
	{

		menu();
		c:
		cout << "\nEnter Your Choice : ";
		cin >> choice;
		if (choice <= 0 or choice > 13)
		{
			cout << "Invalid Choice!\nEnter Again -> ";
			goto c;
		}
		switch (choice)
		{
		case 1:
		{
			int b, r, s;
			block:
			cout << "\nEnter the Block Number : ";
			cin >> b;
			if (b <= 0 or b > nb)
			{
				cout << "\nWrong Block-Number!";
				goto block;
			}
			cout << "Enter Row Number : ";
			cin >> r;
			cout << "Enter the Slot Number : ";
			cin >> s;
			char* Vehicle = new char[9];
			cout << "\n---------------------------------------------\n";
			cout << "Enter License of Car i.e (ABC-1234) : ";

			for (int i = 0; i < 8; i++) {
				while (true) {
					cin >> Vehicle[i];

					if (i < 3) 
					{ 
						if ((Vehicle[i] >= 'A' && Vehicle[i] <= 'Z') || (Vehicle[i] >= 'a' && Vehicle[i] <= 'z'))
						{
							break; 
						}
						else 
						{
							cout << "\nWrong character! Enter an alphabet: at place "<< i+1;
						}
					}
					else if (i == 3)
					{ 
						if (Vehicle[i] == '-')
							break;
						else 
							cout << "\nWrong character! Enter '-': at place " << i + 1;
					}
					else 
					{ 
						if (Vehicle[i] >= '0' && Vehicle[i] <= '9') break;
						else cout << "\nWrong character! Enter a digit: at place " << i + 1;
					}
				}
			}

			Vehicle[8] = '\0'; 
			cout << "License Entered: " << Vehicle << endl;
			blocks[b - 1].parkCar(r, s, Vehicle);
			break;
		}
		case 2:
		{
			int b, r, s;
			block1:
			cout << "\nEnter the Block Number : ";
			cin >> b;
			if (b <= 0 or b > nb)
			{
				cout << "\nWrong Block-Number!";
				goto block1;
			}
			cout << "Enter Row Number : ";
			cin >> r;
			cout << "Enter the Slot Number : ";
			cin >> s;
			blocks[b - 1].removeCar(r, s);
			break;
		}
		case 3:
		{
			cout << endl;
			string s = "coordinate.txt";
			loadBlockCoordinates(s, blocks, nb);
			for (int i = 0; i < nb; i++)
			{
				blocks[i].displayBlock();
			}
			break;
		}
		case 4:
		{
			int b, r, ns;
			block2:
			cout << "\nEnter the Block Number : ";
			cin >> b;
			if (b <= 0 or b > nb)
			{
				cout << "\nWrong Block-Number!";
				goto block2;
			}
			cout << "Enter the Row Number : ";
			cin >> r;
			cout << "Enter the New-Size of Row : ";
			cin >> ns;
			blocks[b - 1].increaseSlots(r, ns);
			break;
		}
		case 5:
		{
			int b, r, ns;
			block3:
			cout << "\nEnter the Block Number : ";
			cin >> b;
			if (b <= 0 or b > nb)
			{
				cout << "\nWrong Block-Number!";
				goto block3;
			}
			cout << "Enter the Row Number : ";
			cin >> r;
			cout << "Enter the New-Size of Row : ";
			cin >> ns;
			blocks[b - 1].decreaseSlots(r, ns);
			break;
		}
		case 6:
		{
			char* Vehicle = new char[9];
			cout << "\n---------------------------------------------\n";
			cout << "Enter License of Car i.e (ABC-1234) : ";
			for (int i = 0; i < 8; i++) {
				while (true) {
					cin >> Vehicle[i];

					if (i < 3)
					{
						if ((Vehicle[i] >= 'A' && Vehicle[i] <= 'Z') || (Vehicle[i] >= 'a' && Vehicle[i] <= 'z'))
						{
							break;
						}
						else
						{
							cout << "\nWrong character! Enter an alphabet: at place " << i + 1;
						}
					}
					else if (i == 3)
					{
						if (Vehicle[i] == '-')
							break;
						else
							cout << "\nWrong character! Enter '-': at place " << i + 1;
					}
					else
					{
						if (Vehicle[i] >= '0' && Vehicle[i] <= '9') 
							break;
						else 
							cout << "\nWrong character! Enter a digit: at place " << i + 1;
					}
				}
			}
			Vehicle[8] = '\0';
			int* search = nullptr;
			for (int i = 0; i < nb; i++)
			{
				search = blocks[i].searchVehicle(Vehicle);
				if (search != nullptr)
				{
					cout << "Vehicle found!\nBlock number : " << i + 1 << "\nRow Number     : " << search[0] + 1 << "\nSlot Number   : " << search[1] + 1 << "\nVehicle Number : " << Vehicle << endl;
					delete[]search;
					delete[]Vehicle;
					Vehicle = nullptr;
					break;
				}
			}
			if (search == nullptr)
				cout << "\nVehicle is Not Found!";
			delete[]Vehicle;
			break;
		}
		case 7:
		{
			int b, r;
			block4:
			cout << "\nEnter the Block Number : ";
			cin >> b;
			if (b <= 0 or b > nb)
			{
				cout << "\nWrong Block-Number!";
				goto block4;
			}
			cout << "Enter the Row Number : ";
			cin >> r;
			blocks[b - 1].emptyRow(r);
			break;
		}
		case 8:
		{
			int b;
			block5:
			cout << "\nEnter the Block Number : ";
			cin >> b;
			if (b <= 0 or b > nb)
			{
				cout << "\nWrong Block-Number!";
				goto block5;
			}
			blocks[b - 1].emptyBlock();
			break;
		}
		case 9:
		{
			int sb, db;
			sblock:
			cout << "\nEnter the Source Block : ";
			cin >> sb;
			if (sb <= 0 or sb > nb)
			{
				cout << "\nWrong Source-Block!";
				goto sblock;
			}
			dblock:
			cout << "\nEnter the Destination-Block : ";
			cin >> db;
			if (db <= 0 or db > nb)
			{
				cout << "\nWrong Destination Block!";
				goto dblock;
			}
			blocks[db - 1].transferVehicles(blocks[sb - 1]);
			break;
			
			
		}
		case 10:
		{
			int b;
			block6:
			cout << "\nEnter the Block Number : ";
			cin >> b;
			if (b <= 0 or b > nb)
			{
				cout << "\nWrong Block-Number!";
				goto block6;
			}
			char* Vehicle = new char[9];
			cout << "\n---------------------------------------------\n";
			cout << "Enter License of Car i.e (ABC-1234) : ";
			for (int i = 0; i < 8; i++) {
				while (true) {
					cin >> Vehicle[i];

					if (i < 3)
					{
						if ((Vehicle[i] >= 'A' && Vehicle[i] <= 'Z') || (Vehicle[i] >= 'a' && Vehicle[i] <= 'z'))
						{
							break;
						}
						else
						{
							cout << "\nWrong character! Enter an alphabet: at place " << i + 1;
						}
					}
					else if (i == 3)
					{
						if (Vehicle[i] == '-')
							break;
						else
							cout << "\nWrong character! Enter '-': at place " << i + 1;
					}
					else
					{
						if (Vehicle[i] >= '0' && Vehicle[i] <= '9') break;
						else cout << "\nWrong character! Enter a digit: at place " << i + 1;
					}
				}
			}
			Vehicle[8] = '\0';
			string s = "coordinate.txt";
			loadBlockCoordinates(s, blocks, nb);
			blocks[b - 1].smartAllocate(Vehicle, b - 1);
			break;
		}
		case 11:
		{
			string s = "coordinate.txt";
			loadBlockCoordinates(s, blocks, nb);
			cout << "\nCoordinates Loaded! ";
			break;
		}
		case 12:
		{
			int sb, db;
			sblock1:
			cout << "\nEnter the Source Block : ";
			cin >> sb;
			if (sb <= 0 or sb > nb)
			{
				cout << "\nWrong Source-Block!";
				goto sblock1;
			}
			dblock1:
			cout << "\nEnter the Destination-Block : ";
			cin >> db;
			if (db <= 0 or db > nb)
			{
				cout << "\nWrong Destination Block!";
				goto dblock1;
			}
			blocks[db - 1].mergeVehicles(blocks[sb - 1]);
			break;
		}
		default:
		{
			return 0;
		}
		}
	}
	return 0;
}