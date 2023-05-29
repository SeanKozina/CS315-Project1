/*
Created by Sean Kozina
9/25/2022
CS 315 Programming Project 1

Header File for Tokenizer Class that tokenizes SPECIFIC json files appends tokens to 
User objs and then appends the user objs to a Network class that holds a vector of Users

*/



#ifndef TOKENIZER_H
#define TOKENIZER_H
#include "User.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cassert>
#include "SocialNetwork.h"

using namespace std;

// default delimiter(space, tab, newline, colon, left/right curly bracket, quotation mark, left and right bracket)
const std::string DEFAULT_DELIMITER = " \v\t\r\n\"'['':'";//" \t\v\n\"','";

//possible additions but not needed with .json files
// \r\f

class Tokenizer
{
public:
    //constructors/deconstructor
    Tokenizer();
    Tokenizer(const std::string& str, const std::string& delimiter = DEFAULT_DELIMITER);
    ~Tokenizer();

    // set string and delimiter
    void set(const std::string& str, const std::string& delimiter = DEFAULT_DELIMITER);
    void setString(const std::string& str);             // set/reset source string only 
    void setDelimiter(const std::string& delimiter);    // set/reset delimiter string only

    std::string next();                                 // returns next token, but returns "" if nothing exists

    std::vector<std::string> split();                   // return array of tokens from current cursor

    //helper function for ReadsInFile
    //adds the current user to the user array of socialnetwork
    void AddNewUserToArray(SocialNetwork* Network);

    //takes in the .json appends the data to a new user variable and stores them in
    //the network user array
    std::vector<User> ReadsInFileCreatesUserAndAppendUserVariables(Tokenizer* str, SocialNetwork* Network, std::string myFile);

protected:


private:
    void skipDelimiter();                               // helper function ignore leading delimiters
    bool isDelimiter(char c);                           // helper functioncheck if the current char is delimiter

    std::string buffer;                                 // stores the input string
    std::string token;                                  // holds current output
    std::string delimiter;                              // holds delimiter info
    std::string::const_iterator currPos;                // string iterator pointing the current position



    friend class User;
    friend class SocialNetwork;
};
#endif // TOKENIZER_H
