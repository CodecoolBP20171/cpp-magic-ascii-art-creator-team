//
// Created by jeannie on 2017.10.25..
//


#include "ArgumentsParser.h"

Parser::Parser(int argc, char* argv[])
    : valid(false), colored(false), oversized(false), resize(1) {
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

    if (args.size() == 2 || args[2] != "-t") {
        setFileTypeFromFileName();
    }

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

    if (args.size() >= 5) {
        if (args[4] == "-color") {
                colored = true;
        } else if (!validResizeValueAtIndex(4)) {
            valid = false;
        }
    }

    if (args.size() == 5) return;

    if (args.size() >= 6 && !validResizeValueAtIndex(5)) { valid = false; }

    if (args.size() == 7) {
        if (args[6] == "-color") {
            colored = true;
        } else if (!validResizeValueAtIndex(6)) { valid = false; }
    }
}

void Parser::setFileTypeFromFileName() {
    if (args[1].size() >= 5) {
        if (args[1].compare(args[1].size() - 4, 4, ".bmp") == 0) {
            fileType = "bmp";
            valid = true;
        } else if (args[1].compare(args[1].size() - 4, 4, ".jpg") == 0) {
            fileType = "jpg";
            valid = true;
        } else if (args[1].compare(args[1].size() - 4, 4, ".png") == 0) {
            fileType = "png";
            valid = true;
        }
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
    if (args[index-1] == "-r") {
        try {
            resize = std::stof(args[index]);
            oversized = true;
            return true;
        } catch (std::invalid_argument&) {
            return false;
        }
    }
    return false;
}

const std::string &Parser::getFileName() const {
    return fileName;
}

const std::string &Parser::getFileType() const {
    return fileType;
}

bool Parser::isColored() const {
    return colored;
}

bool Parser::isOversized() const {
    return oversized;
}

float Parser::getResize() const {
    return resize;
}
