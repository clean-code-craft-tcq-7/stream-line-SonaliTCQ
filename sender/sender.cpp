#include<iostream>
#include<fstream>
#include "sender.hpp"
using namespace std;

#define MAX_VALUE 60
#define MIN_VALUE 0
#define STREAM_READINGS 50

int SOC_read_values()
{
	int nof_readings = 0;
	int soc_value = 0;
	ifstream SOC;
	SOC.open("./sender/SOC.txt");
	cout << "SOC sensor values are below:" << endl;
	while (SOC >> soc_value && nof_readings < STREAM_READINGS)
	{
		send_values(soc_value, nof_readings);
	}
	return 1;
}


int temp_read_values()
{
	int nof_readings = 0;
	int temp_value = 0;
	ifstream temp;
	temp.open("./sender/Temp.txt");
	cout << "Temp sensor values are below:" << endl;
	while (temp >> temp_value && nof_readings < STREAM_READINGS)
	{
		send_values(temp_value, nof_readings);
	}
	return 1;
}

void send_values(int value, int max_no)
{
	if (value <= MAX_VALUE && value >= MIN_VALUE)
	{
		print(value);
		max_no++;
	}
}

void print(int line)
{
	cout << line << endl;
}
