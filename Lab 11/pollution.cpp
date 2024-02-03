/*
	Title:  	pollution.cpp
	Author:  	April R Crockett
	Date:  		11/13/2021
	Purpose:  	A lab assignment to practice with array of pointers
*/

//NOTE TO STUDENTS:  YOU SHOULD NOT MODIFY THIS FILE!!!

#include "pollution.h"

int main()
{
	//Size = 3
	//*****VARIABLE DEFINITIONS*****//
	int years;
	string factoryNames[SIZE];
	string horizontalLine(80,'-');
	float* factoryCOData[SIZE];
	float* factoryNO2Data[SIZE];
	float* factoryO3Data[SIZE];
	float largest;
	string largestFactory;
	int largestYear;

	cout << endl << endl << horizontalLine << endl;
	cout << horizontalLine << endl;

	//*****GET USER DATA*****/
	enterFactoryNames(factoryNames);

	
	
	cout << "\nHow many years of data do you have?\n";
	cin >> years;
	
	//make each array dynamically and enter data into the array from the user
	cout << "\n\nPlease enter data for each factory.\n";
	for(int x=0; x<SIZE; x++)
	{
		cout << horizontalLine << endl;
		cout << "\n\nFACTORY:  " << *(factoryNames+x) << endl;
		*(factoryCOData+x) = makeArray(years);
		enterCOData(*(factoryCOData+x), years);
		*(factoryNO2Data+x) = makeArray(years);
		enterNO2Data(*(factoryNO2Data+x), years);
		*(factoryO3Data+x) = makeArray(years);
		enterO3Data(*(factoryO3Data+x), years);
	}
	cout << horizontalLine << endl;
	cout << horizontalLine << endl;
	
	//******RESULTS & OUTPUT*****//
	
	//print the factories that are over the allowed limit for carbon monoxide
	cout << "\n\nFACTORIES over the CARBON MONOXIDE pollutant level (" << CO_MAX_LIMIT << "):\n";
	printOverLimit(factoryNames, factoryCOData, years, CO_MAX_LIMIT);
	
	//print the factories that are over the allowed limit for nitrogen dioxide
	cout << "\n\nFACTORIES over the NITROGEN DIOXIDE pollutant level (" << NO2_MAX_LIMIT << "):\n";
	printOverLimit(factoryNames, factoryNO2Data, years, NO2_MAX_LIMIT);
	
	//print the factories that are over the allowed limit for ozone
	cout << "\n\nFACTORIES over the OZONE pollutant level (" << O3_MAX_LIMIT << "):\n";
	printOverLimit(factoryNames, factoryO3Data, years, O3_MAX_LIMIT);
	cout << horizontalLine << endl;
	
	//print the factory, year & amount with the largest carbon monoxide level
	getLargest(factoryNames, factoryCOData, years, largest, largestFactory, largestYear);
	cout << "\n\nThe " << largestFactory << " factory produced the most carbon monoxide\npollution with ";
	cout << largest << " parts per million in year " << (largestYear+1) << ".\n\n";	
	
	//print the factory, year & amount with the largest nitrogen dixoide level
	getLargest(factoryNames, factoryNO2Data, years, largest, largestFactory, largestYear);
	cout << "The " << largestFactory << " factory produced the most nitrogen dioxide pollution\nwith ";
	cout << largest << " parts per million in year " << (largestYear+1) << ".\n\n";	
	
	//print the factory, year & amount with the largest ozone level
	getLargest(factoryNames, factoryO3Data, years, largest, largestFactory, largestYear);
	cout << "The " << largestFactory << " factory produced the most ozone pollution with ";
	cout << largest << " \nparts per million in year " << (largestYear+1) << ".\n\n";	
	
	cout << horizontalLine << endl;
	cout << horizontalLine << endl;
	
	//Release dynamically allocated arrays
	for(int x=0; x<SIZE; x++)
	{
		delete [] *(factoryCOData+x);
		delete [] *(factoryNO2Data+x);
		delete [] *(factoryO3Data+x);
	}
	
	return 0;
	
	
}

