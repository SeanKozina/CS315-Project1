/*

Implementation of User Class

*/



#include "User.h"
#include "SocialNetwork.h"





//Constructor
User::User() {
    idSTR = 0;
    name = "";
    location = "";
    picURL = "";
    usersFollowsArr;
}







//Copy Constructor
User::User(const User& NewUser) {
    idSTR = NewUser.idSTR;
    name = NewUser.name;
    location = NewUser.location;
    picURL = NewUser.picURL;
    usersFollowsArr = NewUser.usersFollowsArr;
}






//Destructor
User::~User() {
}







bool User::operator<(const User& obj) {
    if (idSTR < obj.idSTR) {
        return true;
    }
    return false;
}









//Prints all user variables to html and returns the file name
std::string User::printVariablesToHTML(vector<int> followersOfTheCurrUser, vector <int> mutualFollows, int userCounter, SocialNetwork* NetworkPointer) {
    ofstream myfile;
    string userFileName;

    std::string s = std::to_string(userCounter + 1);
    userFileName = "user"+ s +".html";

    myfile.open(userFileName);

    myfile << "<!DOCTYPE html><html>","<head><title>", name ,"< / title>< / head>"; //starting html
    myfile << "<body>";

    //myfile << endl << "<h1>The user ID is: " << idSTR << "</h1>" << endl;
    myfile << "<h1>Their name is: " << name << "</h1>"<< endl;

    //displays location only if their is one
    if (location != "") {
        myfile << "<h2>They live in: " << location << "</h2>" << endl;
    }
    

    //displays picture only if their is one
    if (picURL != "") {
        myfile << "<h2> Picture of them: ";
        myfile << "<img alt =" << "'Profile pic'" << "src = " << picURL << " />";
        myfile<< "</h2>"  << endl;
    }

    string newfile;
    std::string y;

    //prints the users the current user follows
    if (!empty(usersFollowsArr)) {
        myfile << "<h2> They follow: ";
        for (int i = 0; i < size(usersFollowsArr); i++) {
            if (usersFollowsArr[i] != 0) {
                y = std::to_string(NetworkPointer->userArray[usersFollowsArr[i]-1].idSTR);
                newfile = "user" + y + ".html";
                myfile << "<li><a href=" << newfile << ">" << NetworkPointer->userArray[usersFollowsArr[i]- 1].name;
                myfile << "</a></li>";
            }
        }
 
    }
    myfile << "</h2>";

    //prints the followers of the current user
    myfile << "<h2>These are the followers of the curr user: ";
    for (int s = 0; s < size(followersOfTheCurrUser); s++) {
        if (followersOfTheCurrUser[s] != 0) {
            y = std::to_string(NetworkPointer->userArray[followersOfTheCurrUser[s] - 1].idSTR);
            newfile = "user" + y + ".html";
            myfile << "<li><a href=" << newfile << ">" << NetworkPointer->userArray[followersOfTheCurrUser[s] - 1].name;
            myfile << "</a></li>";

        }
    }
    myfile << "</h2>";

    //prints the mutual follows of the current user
    int counter = 0;
    if (!empty(mutualFollows)) {
        for (int c = 0; c < size(mutualFollows); c++) {
            if (mutualFollows[c] == 0) {
                counter++;
            }
        }
        if (counter != size(mutualFollows)) {
            myfile << "<h2>These are the Mutual User of the Curr User: ";
            for (int x = 0; x < size(mutualFollows); x++) {
                if (mutualFollows[x] != 0) {
                    y = std::to_string(NetworkPointer->userArray[mutualFollows[x] - 1].idSTR);
                    newfile = "user" + y + ".html";
                    myfile << "<li><a href=" << newfile << ">" << NetworkPointer->userArray[mutualFollows[x] - 1].name;
                    myfile << "</a></li>";

                }
            }
        }
    }
    myfile << "</h2>";

    //ending html
    myfile << "</body></html>";
    myfile.close();

    return userFileName;
}
