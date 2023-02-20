#include<iostream>
#include<fstream>
#include "sender.hpp"
using namespace std;

#define SOC_MAX_VALUE 20
#define SOC_MIN_VALUE 0
#define TEMP_MAX_VALUE 30
#define TEMP_MIN_VALUE 10


int main()
{

	SOC_generate_values();
	temp_generate_values();
	return 0;
}

void SOC_generate_values()
{
	int soc_value = 0;
	ifstream SOC;
	SOC.open("SOC.txt");
	cout << " SOC sensor values are below:"<< endl;

	while (SOC >> soc_value)
	{
		if (soc_value < SOC_MAX_VALUE && soc_value > SOC_MIN_VALUE)
		{ 
			print(soc_value);
		}	
	}
}

void temp_generate_values()
{
	int temp_value = 0;
	ifstream temp;
	temp.open("Temp.txt");

	cout << " Temp sensor values are below:" << endl;

	while (temp >> temp_value)
	{
		if (temp_value < TEMP_MAX_VALUE && temp_value > TEMP_MIN_VALUE)
		{
			print(temp_value);
		}
	}

}

void print(int line)
{
	cout << line << endl;
}
