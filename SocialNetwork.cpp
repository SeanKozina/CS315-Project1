/*

Implementation of the SocialNetwork Class

*/



#include "SocialNetwork.h"
#include "Tokenizer.h"






//constructor
SocialNetwork::SocialNetwork() {
	std::vector<User> userArray = {};
	std::vector<vector<int>> containsFollow = {};
	vector<int> mutualFollows = {};
	vector<int> followersOfTheCurrUser = {};
}







//copy constructor
SocialNetwork::SocialNetwork(const SocialNetwork& NewSocialNetwork) {
	std::vector<User> userArray = NewSocialNetwork.userArray;
	std::vector<vector<int>> containsFollow = NewSocialNetwork.containsFollow;
	vector<int> mutualFollows = NewSocialNetwork.mutualFollows;
	vector<int> followersOfTheCurrUser = NewSocialNetwork.followersOfTheCurrUser;
}







//destructor
SocialNetwork::~SocialNetwork() {

}







//Adds a new user to the User array network variable
void SocialNetwork::appendUsersToUserArray(User User) {
	userArray.push_back(User);
}







//fix to where im not creating a new social network obj in this class
void SocialNetwork::printIndexOfUsersHtml(std::string inputFile) {
	ofstream myfileIndex;
	myfileIndex.open("Index.html");
	myfileIndex << "<!DOCTYPE html>","<html> < head > < title> 'MySocialNetwork' < / title > < / head> < body>";

	Tokenizer str;


	
	userArray = str.ReadsInFileCreatesUserAndAppendUserVariables(&str, this, inputFile);
	std::sort(userArray.begin(), userArray.end());

	containsFollow = setsFollowMatrixOfAllCurrUser();


	myfileIndex << "<h1>My Social Network: User List";
	myfileIndex << "</h1>";
	myfileIndex << "<ol>";
	for (int j = 0; j < size(userArray); j++) {
		string newfile;
		followersOfTheCurrUser = FollowersOfCurrUser(j);
		mutualFollows = MutualsOfCurrUser(j);
		newfile = userArray[j].printVariablesToHTML(followersOfTheCurrUser, mutualFollows , j, this);
		
		myfileIndex << "<li><a href=" << newfile << ">" << userArray[j].name;
		myfileIndex<< "</a></li>";  
		
	}
	myfileIndex << "</p></body></html>";
	myfileIndex.close();
}








//creates a 2d vector that shows follower information
vector<vector<int>> SocialNetwork::setsFollowMatrixOfAllCurrUser()
{
	containsFollow.resize(size(userArray));          //resize contains follow array to size of User array
	for (int i = 0; i < size(userArray); i++) {
		userArray[i].usersFollowsArr.resize(size(userArray)); //resizes again for each nested vector
		//for instance [3,4] becomes [3,4,0,0]

		mutualFollows.resize(size(userArray));
		containsFollow[i].resize(size(userArray[i].usersFollowsArr)); 		//resizes the users followers array 

		for (int j = 0; j < size(userArray[i].usersFollowsArr); j++) {
			if (userArray[i].usersFollowsArr[j] != 0) {
				containsFollow[i][(userArray[i].usersFollowsArr[j]) - 1] = (userArray[i].usersFollowsArr[j]);
			} //iterates through and sorts the numbers based on their numerical slot value
		}
	}
	return containsFollow;
}








//creates vector for the followers of the curr user
vector<int> SocialNetwork::FollowersOfCurrUser(int userCounter) {
	followersOfTheCurrUser.resize(size(containsFollow));

	for (int i = 0; i < size(containsFollow); i++) {
		for (int j = 0; j < size(containsFollow); j++) {
			if (containsFollow[j][i] == userArray[userCounter].idSTR && containsFollow[j][i] != 0) {
				followersOfTheCurrUser.push_back(j+1);
			}
		}
	}



	return followersOfTheCurrUser;
}









//creates and returns the mutuals of the current user
vector<int> SocialNetwork::MutualsOfCurrUser(int userCounter){
	mutualFollows.resize(size(containsFollow));
	for (int p = 0; p < size(followersOfTheCurrUser); p++) {
		for (int i = 0; i < size(userArray[userCounter].usersFollowsArr); i++) {
			if (userArray[userCounter].usersFollowsArr[i] == followersOfTheCurrUser[p]) {
				mutualFollows.push_back(followersOfTheCurrUser[p]);
			}
		}
	}
	return mutualFollows;
}


