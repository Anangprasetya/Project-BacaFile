using namespace std;
#include <iostream>
#include <fstream>
#include "myFile.h"

int main(){
	Link file("test.ang");
	file.ambilKolom();
	file.ambilBaris();

	return 0;
}