
#include <iostream>
#include <string>

using namespace std;

void minimal(int* arr, int length)
{
	int min = *arr;
	for (int i = 0; i < length; i++)
	{
		if (min > *(arr + i))
		{
			min = *(arr + i);
		}

	}
	cout << "Minimal: " << min << endl;
}

int main()
{
	setlocale(LC_ALL, "RU");
	
	int num;
	cin >> num;
	if (num > 3)
	{
		cout << "+";
	}
}

