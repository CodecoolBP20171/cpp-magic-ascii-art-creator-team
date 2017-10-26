//
// Created by jeannie on 2017.10.25..
//

#ifndef CPP_MAGIC_ASCII_ART_CREATOR_TEAM_PARSER_H
#define CPP_MAGIC_ASCII_ART_CREATOR_TEAM_PARSER_H

#include <string>
#include <vector>
#include <regex>

class Parser {

public:
    Parser(int argc, char* argv[]);
    virtual ~Parser();

    bool isValid() const;

    const std::string &getFileName() const;

    const std::string &getFileType() const;

    bool isColored() const;

    bool isOversized() const;

    float getResize() const;

private:
    std::vector<std::string> args;
    bool valid;
    std::string fileName;
    std::string fileType;
    bool colored;
    bool oversized;
    float resize;

    void parseArguments();
    void setFileTypeFromFileName();
    void setFileTypeFromFileType();
    bool validResizeValueAtIndex(int index);
};


#endif //CPP_MAGIC_ASCII_ART_CREATOR_TEAM_PARSER_H
