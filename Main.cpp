/*
Created by Sean Kozina
9/5/2022
CS 315 Programming Project 1

Main file to test all 3 classes together

*/





#include "User.h"
#include "Tokenizer.h"
#include "SocialNetwork.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
using std::string;
using std::cout;
using std::endl;

const std::string inputFile = "big.json";

int main()
{
    SocialNetwork SocialNetwork;

    SocialNetwork.printIndexOfUsersHtml(inputFile);

    return 0;
}


