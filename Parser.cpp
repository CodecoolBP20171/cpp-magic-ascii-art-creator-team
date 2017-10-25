//
// Created by jeannie on 2017.10.25..
//


#include "Parser.h"

Parser::Parser(int argc, char* argv[])
    : valid(false), colored(false), oversized(false) {
    if (argc < 3) {
        return;
    }
    args.assign(argv + 1, argv + argc);
    parseArguments();
}

Parser::~Parser() {}

bool Parser::isValid() const { return valid; }


void Parser::parseArguments() {
    if (args[0]!="-f") return;

    fileName = args[1];

    if (args.size() == 2 || args[2] != "-t") { setFileTypeFromFileName(); }

    if (args.size() == 2) return;

    if (args.size() >= 3) {
        if (args[2] == "-color") {
            colored = true;
        } else if (args.size() == 3) { valid = false; }
    }

    if (args.size() == 3) return;

    if (args.size() >= 4) {
        if (args[2] == "-t") {
            setFileTypeFromFileType();
        } else if (!validResizeValueAtIndex(3)) {
            valid = false;
        }
    }

    if (args.size() == 4) return;

    if (args.size() == 5) {
        if (args[4] == "-color") {
                colored = true;
        } else if (!validResizeValueAtIndex(4)) {
            valid = false;
        }
        return;
    }

    if (args.size() != 6 || !validResizeValueAtIndex(5)) { valid = false; }
}

void Parser::setFileTypeFromFileName() {
    if (args[1].compare(args[1].size()-4,4,".bmp") == 0) {
        fileType = "bmp";
        valid = true;
    } else if (args[1].compare(args[1].size()-4,4,".jpg") == 0) {
        fileType = "jpg";
        valid = true;
    } else if (args[1].compare(args[1].size()-4,4,".png") == 0) {
        fileType = "png";
        valid = true;
    }
}

void Parser::setFileTypeFromFileType() {
    if (args[3] == "bmp") {
        fileType = "bmp";
        valid = true;
    } else if (args[3] == "jpg") {
        fileType = "jpg";
        valid = true;
    } else if (args[3] == "png") {
        fileType = "jpg";
        valid = true;
    } else valid = false;
}

bool Parser::validResizeValueAtIndex(int index) {
    if (args[index-1] == "-r"
        && std::all_of(args[index].begin(),
                       args[index].end(),
                       ::isdigit)) {
        oversized = true;
        resize = std::stod(args[index]);
        return true;
    }
    return false;
}