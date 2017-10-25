#include <iostream>
#include "ascii_art_creator/BmpProcessor.hpp"
#include "Parser.h"


using namespace std;
int main( int argc, char* argv[] )
{
    Parser p(argc, argv);

    if (!p.isValid()) {
        cout << "\nInvalid arguments. "
                "Use: -f <filename>. "
                "Options: -t<type=bmp|jpg|png>, -color, -r<value>.\n";
        return 0;
    }

    BmpProcessor a(argc, argv+1);
    a.showASCIIart();

    return 0;
}
