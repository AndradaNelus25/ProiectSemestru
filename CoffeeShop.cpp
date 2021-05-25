#include <iostream>
using namespace std;
#include "UI.h"
#include "Tests.h"

int main() {
	UI ui;
	Tests test;

	ui.run();
	test.StartTests();
	
}
