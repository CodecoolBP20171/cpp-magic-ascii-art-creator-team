#include <iostream>
#include "ArgumentsParser.h"


using namespace std;
int main( int argc, char* argv[] )
{


    char *fsw = "-f";
    char *fname = "test.bmp";
    char *tsw = "-t";
    char *ft = "bmp";
    char *colsw = "-color";
    char *sizesw = "-r";
    char *size = "0.5";

    char* arr[] = {fname, fsw, fname, sizesw, size};

    Parser p(5, arr);

    std::cout << "Valid: " << p.isValid();
    std::cout << ", filename: " << p.getFileName();
    std::cout << ", filetype: " << p.getFileType();
    std::cout << ", color: " << p.isColored();
    std::cout << ", resize: " << p.isOversized();
    std::cout << ", value: " << p.getResize();


    /*if (!p.isValid()) {
        cout << "\nInvalid arguments. "
                "Use: -f <filename>. "
                "Options: -t<type=bmp|jpg|png>, -color, -r<value>.\n";
        return 0;
    }*/

    return 0;
}
