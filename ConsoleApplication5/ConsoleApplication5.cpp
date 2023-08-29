#include <iostream>
#include <fstream>

using namespace std;

const int SIZEX = 10, SIZEY = 10;
int arr[SIZEX][SIZEY];
int x, y;

void inputarr()
{
	cout << "Input the number of values desired for the x coordinates (horizontal): ";
	cin >> x;
	cout << "Input the number of values desired for the y coordinates (vertical): ";
	cin >> y;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			cout << "Input values for square [" << i << "] [" << j << "]: ";
			cin >> arr[i][j];
		}
	}
}

void outputfile()
{
	ofstream outp("Insule.in");
	outp << x << " " << y << endl;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			outp << arr[i][j] << " ";
		}
		outp << endl;
	}
}

void inputfile()
{
	ifstream inp("Insule.in");
	inp >> x;
	inp >> y;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			inp >> arr[i][j];
		}
	}
}

void outarr()
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void newin()
{
	int a = 1;
	while (a != NULL)
	{
		cout << "Introduce the number of the desired function: " << endl;
		cout << "1. Input a new row (horizontal) \n2. Input a new column (vertical)" << endl;
		cin >> a;
		if (a == 1)
		{
			while (a != NULL)
			{
				cout << "Input the row number (rows following the introduced will be moved down, numbers higher than " << y + 1 << " are forbidden): ";
				cin >> a;
				a--;
				if (a > y + 1) {}
				else
				{
					int* temp = new int(x);
					for (int i = 0; i < x; i++)
					{
						cout << "Input values for square [" << a << "] [" << i << "]: ";
						cin >> temp[i];
					}
					for (int i = y + 1; i > a; i--)
					{
						for (int j = 0; j < x; j++)
						{
							arr[i][j] = arr[i - 1][j];
						}
					}
					for (int i = 0; i < x; i++)
					{
						arr[a][i] = temp[i];
					}
					a = NULL;
					y = y + 1;
				}
			}
		}
		else if (a == 2)
		{
			while (a != NULL)
			{
				cout << "Input the column number (rows following the introduced will be moved right, numbers higher than " << x + 1 << " are forbidden): ";
				cin >> a;
				a--;
				if (a > x + 1) {}
				else
				{
					int* temp = new int(y);
					for (int i = 0; i < y; i++)
					{
						cout << "Input values for square [" << i << "] [" << a << "]: ";
						cin >> temp[i];
					}
					for (int i = 0; i < y; i++)
					{
						for (int j = x + 1; j > a; j--)
						{
							arr[i][j] = arr[i][j - 1];
						}
					}
					for (int i = 0; i < y; i++)
					{
						arr[i][a] = temp[i];
					}
					a = NULL;
					x = x + 1;
					delete[] temp;
				}
			}
		}
		else
		{
			cout << "Bad input" << endl;
		}
	}
}

void deletel()
{
	int a = 1;
	while (a != NULL)
	{
		cout << "Introduce the number of the desired function: " << endl;
		cout << "1. Delete a row (horizontal) \n2. Delete a column (vertical)" << endl;
		cin >> a;
		if (a == 1)
		{
			while (a != NULL)
			{
				cout << "Input the row number (rows following the introduced will be moved up, numbers higher than " << y << " are forbidden): ";
				cin >> a;
				a--;
				if (a > y) {}
				else
				{
					for (int i = a; i < y - 1; i++)
					{
						for (int j = 0; j < x; j++)
						{
							arr[i][j] = arr[i + 1][j];
						}
					}
					a = NULL;
					y = y - 1;
				}
			}
		}
		else if (a == 2)
		{
			while (a != NULL)
			{
				cout << "Input the column number (rows following the introduced will be moved left, numbers higher than " << x << " are forbidden): ";
				cin >> a;
				a--;
				if (a > x) {}
				else
				{
					for (int i = 0; i < y; i++)
					{
						for (int j = a; j < x - 1; j++)
						{
							arr[i][j] = arr[i][j + 1];
						}
					}
					a = NULL;
					x = x - 1;
				}
			}
		}
		else
		{
			cout << "Bad input" << endl;
		}
	}
}

void countone()
{
	int a = 1, p = 0;
	while (a != NULL)
	{
		cout << "Introduce the number of the desired function: " << endl;
		cout << "1. Count ones in a row (horizontal) \n2. Count ones in a column (vertical)" << endl;
		cin >> a;
		if (a == 1)
		{
			while (a != NULL)
			{
				cout << "Input the row number (numbers higher than " << y << " are forbidden): ";
				cin >> a;
				a--;
				if (a > y) {}
				else
				{
					for (int j = 0; j < x; j++)
					{
						if (arr[a][j] == 1)
						{
							p++;
						}
					}
					a = NULL;
					cout << p << endl;
				}
			}
		}
		else if (a == 2)
		{
			while (a != NULL)
			{
				cout << "Input the column number (numbers higher than " << x << " are forbidden): ";
				cin >> a;
				a--;
				if (a > x) {}
				else
				{
					for (int i = 0; i < y; i++)
					{
						if (arr[i][a] == 1)
						{
							p++;
						}
					}
					a = NULL;
					cout << p << endl;
				}
			}
		}
		else
		{
			cout << "Bad input" << endl;
		}
	}
}

void countSort() {
	int* temp = new int[x];

	for (int j = 0; j < x; j++) {
		int p = 0;

		for (int i = 0; i < y; i++) {
			if (arr[i][j] == 1) {
				p++;
			}
		}

		temp[j] = p;
	}


	int maxCount = *max_element(temp, temp + x);
	int* count = new int[maxCount + 1] {0};

	for (int i = 0; i < x; i++) {
		count[temp[i]]++;
	}

	int index = 0;
	for (int i = maxCount; i >= 0; i--) {
		while (count[i] > 0) {
			temp[index] = i;
			index++;
			count[i]--;
		}
	}


	for (int i = 0; i < x; i++) {
		cout << temp[i] << " ";
	}

	delete[] temp;
	delete[] count;
}
bool visited[SIZEX][SIZEY];
int largestIslandSize = 0;

int dfs(int x, int y) {
	visited[x][y] = true;
	int islandSize = 1;

	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };

	for (int i = 0; i < 4; i++) {
		int newX = x + dx[i];
		int newY = y + dy[i];

		if (newX >= 0 && newX < SIZEX && newY >= 0 && newY < SIZEY &&
			arr[newX][newY] == 1 && !visited[newX][newY]) {
			islandSize += dfs(newX, newY);
		}
	}

	return islandSize;
}

int countIslands() {
	int islandCount = 0;
	largestIslandSize = 0;
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if (arr[j][i] == 1 && !visited[j][i]) {
				islandCount++;
				int islandSize = dfs(j, i);
				largestIslandSize = max(largestIslandSize, islandSize);
			}
		}
	}

	return islandCount ;
}



int getLargestIslandSize() {
	countIslands();
	return largestIslandSize;
}













bool isValidSquare(int x, int y) {
	int size = min(::x - x, ::y - y);

	for (int i = 0; i < size; i++) {
		if (arr[x + i][y + size - i - 1] != 0) {
			return false;
		}
	}

	return true;
}

int calculateSquareArea(int x, int y) {
	int size = min(::x - x, ::y - y);
	return size;
}

void findMaxSquare() {
	int maxArea = 0;
	int startX = -1, startY = -1;

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if (arr[j][i] == 0 && isValidSquare(j, i)) {
				int area = calculateSquareArea(j, i);
				if (area > maxArea) {
					maxArea = area;
					startX = j;
					startY = i;
				}
			}
		}
	}

	if (maxArea > 0) {
		cout << "Maximal square found: " << endl;
		cout << "Area: " << maxArea << endl;
		cout << "Coordinates: (" << startX << ", " << startY << ") - (" << startX + maxArea - 1 << ", " << startY + maxArea - 1 << ")" << endl;
	}
	else {
		cout << "No square with zeros on the secondary diagonal found." << endl;
	}
}

int main()
{
	int menu = -1;
	while (menu != 0)
	{
		cout << "Introduce the number of the desired function: " << endl;
		cout << "1. Input array from keyboard (old will be deleted if existent)" << endl;
		cout << "2. Input array from file" << endl;
		cout << "3. Output array to file" << endl;
		cout << "4. Output array to console" << endl;
		cout << "5. Input new row/column" << endl;
		cout << "6. Delete an existing row/column" << endl;
		cout << "7. Count ones in a row/column" << endl;
		cout << "8. Sort array columns in descending order of number of ones" << endl;
		cout << "9. Count islands" << endl;
		cin >> menu;
		cout << endl;
		switch (menu)
		{
		case 1:
		{
			inputarr();
			break;
		}
		case 2:
		{
			inputfile();
			break;
		}
		case 3:
		{
			outputfile();
			break;
		}
		case 4:
		{
			outarr();
			break;
		}
		case 5:
		{
			newin();
			break;
		}
		case 6:
		{
			deletel();
			break;
		}
		case 7:
		{
			countone();
			break;
		}
		case 8:
		{
			countSort();
			break;
		}
		case 9:
		{
			cout << countIslands() << endl;
			break;
		}
		case 10:
		{
			cout << getLargestIslandSize()<<endl;
			break;
		}
		case 11:
		{
			findMaxSquare();
			break;
		}
		default:
		{
			cout << "Bad input" << endl;
			break;
		}
		}
	}

	return 0;
}
