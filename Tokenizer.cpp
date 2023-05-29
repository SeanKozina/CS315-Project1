/*

Implementation of Tokenizer Class 

*/



#include "Tokenizer.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>






//Class constructor
Tokenizer::Tokenizer() : buffer(""), token(""), delimiter(DEFAULT_DELIMITER)
{
    currPos = buffer.begin();
}






//Class copy constructor
Tokenizer::Tokenizer(const std::string& str, const std::string& delimiter) : buffer(str), token(""), delimiter(delimiter)
{
    currPos = buffer.begin();
}







//Class destructor
Tokenizer::~Tokenizer()
{
}







//reset all variables with new info using next three functions
void Tokenizer::set(const std::string& str, const std::string& delimiter)
{
    this->buffer = str;
    this->delimiter = delimiter;
    this->currPos = buffer.begin();
}






void Tokenizer::setString(const std::string& str)
{
    this->buffer = str;
    this->currPos = buffer.begin();
}






void Tokenizer::setDelimiter(const std::string& delimiter)
{
    this->delimiter = delimiter;
    this->currPos = buffer.begin();
}







// helper function that returns the next token
std::string Tokenizer::next()
{
    if (buffer.size() <= 0) return "";           // returns empty string, if buffer is empty

    token.clear();                              // reset token string
    this->skipDelimiter();                      // skip leading delimiters

    // append each char to token string until it meets delimiter
    while (currPos != buffer.end() && !isDelimiter(*currPos))
    {
        token += *currPos;
        ++currPos;
        assert(currPos <= buffer.end());
    }
    return token;
}








// skip ang leading delimiters
void Tokenizer::skipDelimiter()
{
    while (currPos != buffer.end() && isDelimiter(*currPos)) {
        ++currPos;
        assert(currPos<= buffer.end());
    }
}







// helper function that will
// return true if the char is delimiter
bool Tokenizer::isDelimiter(char c)
{
    return (delimiter.find(c) != std::string::npos);
}








//split the input string into multiple tokens
//pushes back current token and then returns
std::vector<std::string> Tokenizer::split()
{
    std::vector<std::string> tokens;
    std::string token;
    while ((token = this->next()) != "")
    {
        tokens.push_back(token);
    }

    return tokens;
}








//appends a new user to the socialnetwork user array
void Tokenizer::AddNewUserToArray(SocialNetwork* Network) {
        User NewUser;
        Network->appendUsersToUserArray(NewUser);
}








//takes in the .json appends the data to a new user variable and stores them in the network user array
std::vector<User> Tokenizer::ReadsInFileCreatesUserAndAppendUserVariables(Tokenizer* str, SocialNetwork* Network, std::string myFile) {
    int i = -2;
    string line;
    string tempNextStr;

    ifstream myfile(myFile);
    if (myfile.is_open())
    {
        while (getline(myfile, line)) {   //iterates through everyline of the file
            str->set(line);
            while ((token = str->next()) != "") {      //keeps iterating through that line until the next string is empty
                //if(token.length() > 1){
			//cout << "current token: " << token << endl;
			//cout << (int)(token[1]) << endl;
		//}
		    
		//cout << (token) << endl;
		//cout << token.length() << endl;
		if (token == "{") {
                    if (i >= -1) {
                        str->AddNewUserToArray(Network);  //appends new user to the user array
                    }
                    i++;
		    //cout << i << endl;
                }
                else if (token == "id_str") {
		    int placeHolder;
		    placeHolder = stoi(str -> next());
		    //cout << "id str i" << i <<endl;
                    Network->userArray[i].idSTR = placeHolder; 
                    //sets the current user's id value in user array to the files data
                }
                else if (token == "name") {
                    Network->userArray[i].name = str->next();
                    //sets the current user's name value in user array to the files data
                }
                else if (token == "location") {
                    Network->userArray[i].location = str->next();
                    //sets the current user's location value in user array to the files data
                    tempNextStr = str->next();
                    if (tempNextStr != ",") {
                        Network->userArray[i].location = Network->userArray[i].location+ " " + tempNextStr;
                    }
                }
                else if (token == "pic_url") {
                    tempNextStr = str->next();
                    Network->userArray[i].picURL = tempNextStr + ':' + str->next();
                    //sets the current user's id value in user array to the files data
                }
                else if (token == "follows") {
                    while (token != "]") {
                        token = str->next();
                        if (token != "," && token != "]") {
                            Network->userArray[i].usersFollowsArr.push_back(stoi(token));
                            //sets the current user's follows value in user array to the files data
                        }
                    }
                }
                else if (token == "}") {
                    myfile.close();
                    return Network->userArray;
                }
            }
        }
        myfile.close();
    }
    else cout << "Unable to open file";
}
