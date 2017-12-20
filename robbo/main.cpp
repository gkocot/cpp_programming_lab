#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "mapka.h"

using namespace std;



int main(int argc, char** argv) {
	srand (time(NULL));
	mapka m;
	m.otworz(argv[1]);
	m.graj();
	return 0;
}
