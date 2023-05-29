/*
Created by Sean Kozina
9/15/2022
CS 315 Programming Project 1

Header File for User Class that takes in a user information from a
JSON file and has derived function to output html.

*/

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class SocialNetwork;

using namespace std;

#pragma once
class User
{
public:
	//constructors/deconstructors
	User();
	User(const User& NewUser);
	~User();

	//prints the users current variables to html
	std::string printVariablesToHTML(vector<int> followersOfTheCurrUser, vector <int> mutualFollows, int userCounter, SocialNetwork* NetworkPointer);

	bool operator<(const User& obj);


private:
	int idSTR;
	std::string name;
	std::string location;
	std::string picURL;
	std::vector<int> usersFollowsArr;

	friend class Tokenizer;
	friend class SocialNetwork;
};

