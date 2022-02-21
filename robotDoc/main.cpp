#include <iostream>
#include <string>
#include "Robot.h"
#include <vector>
#include <fstream>

using namespace std;

vector<Robot> chargeRobots(){
    ifstream robotHub("Robots.txt");
    vector<Robot> robots;
    Robot tampon;

    while (robotHub>>tampon)
    {
        robots.push_back(tampon);
    }
    robotHub.close();
    return robots;
}


void searchWallE(vector<Robot> robots){
    bool find= false;
    ;
    for ( unsigned int i=0; i<robots.size()&&find!=true;++i)
    {
        if (robots[i].getName().compare("Wall-e"))
        {
            find=true;
        }
        
    }
    cout<<"Wall-e is here"<<endl;

}
//Tri par insertion
void sortVectorRobot(vector<Robot> &robots){
    unsigned int i,j;
    Robot current;
    for ( i = 0; i < robots.size(); i++)
    {
        current=robots[i];
        for ( j=i ; j >0 && current <robots[j - 1]; j--)
        {
            robots[j]=robots[j-1];
        }
        robots[j]=current;
        
    }
    
}

void sortedRobotHub(vector<Robot> robots){
    ofstream sortedFile("SortedRobot.txt",ios::out);
    for (auto const &it: robots)
    {
        sortedFile<<it;
    }
    sortedFile.close();
}


int main()
{
    Robot artificialIntel;
    vector<Robot> robotExposition;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>> New Robot <<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
    cout<<"Type your prefered A.I. "<<endl;
    cin>>artificialIntel;
    cout<<artificialIntel;

    /*">>>>>>>>>>>>>>>>>>>>>>>>>>>> Robot Exposition  preparation <<<<<<<<<<<<<<<<<<<<<<<<<<<"*/
    robotExposition=chargeRobots();
    robotExposition.push_back(artificialIntel);

    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>> WAll-e is it present ? <<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
    searchWallE(robotExposition);

    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>> Robot Exposition  day <<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
    sortVectorRobot(robotExposition);
    
    for (auto const &it: robotExposition)
    {
        cout<<it;
    }

    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>> Robot Exposition end <<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
    sortedRobotHub(robotExposition);

    return 0;
}
