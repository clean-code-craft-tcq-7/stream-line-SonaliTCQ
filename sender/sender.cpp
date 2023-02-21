#include<iostream>
#include<fstream>
#include "sender.hpp"
using namespace std;
#include <map>

#define SOC_MAX_VALUE 51
#define SOC_MIN_VALUE 0
#define TEMP_MAX_VALUE 61
#define TEMP_MIN_VALUE 10
#define STREAM_READINGS 50

extern nof_readings = 0;

int SOC_generate_values()
{
	int soc_value = 0 ;
	ifstream SOC;
	SOC.open("./sender/SOC.txt");
	cout << "SOC sensor values are below:"<< endl;
	while (SOC >> soc_value && nof_readings <= STREAM_READINGS)
	{
		if (soc_value < SOC_MAX_VALUE && soc_value > SOC_MIN_VALUE)
		{ 
			print(soc_value);
			nof_readings ++;
		}
	}
	return 1;
}

int temp_generate_values()
{
	int temp_value = 0;
	ifstream temp;
	temp.open("./sender/Temp.txt");

	cout << "Temp sensor values are below:" << endl;

	while (temp >> temp_value && nof_readings <= STREAM_READINGS)
	{
		if (temp_value < TEMP_MAX_VALUE && temp_value > TEMP_MIN_VALUE)
		{
			print(temp_value);
			nof_readings ++;
		}
	}
	return 1;
}

void print(int line)
{
	cout << line << endl;
}

