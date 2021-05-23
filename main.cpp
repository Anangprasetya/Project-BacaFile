using namespace std;
#include <iostream>
#include <fstream>
#include "myFile.h"

int main(){
	Link file("test.ang");

	file.ambilKolom();	// Fitur Pertama
	file.ambilBaris();	// Fitur Kedua
	file.dataFrame();	// Fitur Ketiga

	return 0;
}