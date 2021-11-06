#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <getopt.h>

std::string getFilename(std::string& fqpn) {

    std::size_t found = fqpn.find_last_of("/\\");
    std::string retval = fqpn.substr(found+1);

    return retval;
}
    
void usage(char* cmd) {

    std::string fn(cmd);
    std::cerr << "Usage: " << getFilename(fn) << " { -f <filename> } { -o <outputfile> }" << std::endl;

}

void parseJsonFile(std::istream& is, std::ostream& os) {

    os << "Output" << std::endl;

}


int main(int argc, char** argv) {

    std::string inFile = "";
    std::string outFile = "";

    //Parse the command line arguments
    for(;;) {
        switch(getopt(argc, argv, "f:ho:")) {
            case '?':
            case 'h':
            default :
                usage(argv[0]);
                return -1;

            case -1:
                break;

            case 'f':
                //std::cout << "Input file set to " << optarg << std::endl;
                inFile = optarg;
                continue;
            case 'o':
                //std::cout << "Output file set to " << optarg << std::endl;
                outFile = optarg;
                continue;
        }
        break;
    }

    if (optind != argc) {
        usage(argv[0]);
        return -1;
    }

    //Set up istream and ostream
    std::ifstream fileIn;
    std::ofstream fileOut;

    if (inFile.length()) {
         fileIn.open(inFile, std::ios::in);
    }

    if (outFile.length()) {
         fileOut.open(outFile, std::ios::out);
    }

    std::istream& is = ((inFile.length()) ? fileIn : std::cin);
    std::ostream& os = ((outFile.length()) ? fileOut : std::cout);
    
    parseJsonFile(is, os);

    return 0;
}

