#include <string>
#include "Scanner.h"


int main(int argc, char* argv[])
{

	Scanner scanner{};

	scanner.read(argv[1]);

	return 0;
}