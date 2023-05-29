/*
Created by Sean Kozina
9/30/2022
CS 315 Programming Project 1

Header File for SocialNetwork Class that stores a vector of Users
and does various operations including printing their information to html


*/





#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "User.h"
#include <algorithm>

using namespace std;

#pragma once
class SocialNetwork
{
public:
	SocialNetwork();
	SocialNetwork(const SocialNetwork& NewSocialNetwork);
	~SocialNetwork();

	void appendUsersToUserArray(User User);
	void printIndexOfUsersHtml(std::string inputFile);

	vector<vector<int>> setsFollowMatrixOfAllCurrUser();
	vector<int> MutualsOfCurrUser(int userCounter);
	vector<int> FollowersOfCurrUser(int userCounter);


private:
	vector<vector<int>> containsFollow;
	std::vector<User> userArray;
	vector<int> mutualFollows;
	vector<int> followersOfTheCurrUser;


	friend class User;
	friend class Tokenizer;
};
