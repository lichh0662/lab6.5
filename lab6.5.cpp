// laba6_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;


int main()
{
    map <string, string> group;
    list <string> data;
    string line;

    cout << "Student: ";
    getline(cin, line);// add first student
    while (line != ".") {
        if (group.find(line.substr(0, line.find(' '))) != group.end()) { // if there is a student so continue

            auto num = ++find(data.begin(), data.end(), group[line.substr(0, line.find(' '))]);// we order the numbers of the group
            data.insert(num, line);

            group[line.substr(0, line.find(' '))] = line;  // we read the string and change the last line in order of the groups num
        }
        else {

            data.push_back(line);// we add student to the end of the list
            group.insert(pair<string, string>(line.substr(0, line.find(' ')), line));//insert the string to the map
        }

        cout << "Student: "; // add the next student the loop will stop when we add "."
        getline(cin, line);
    }

    // print out our list

    for (auto i = data.begin(); i != data.end(); i++) { // read from the beginig to the end of the list
        cout << *i << '\n'; // print out all elements
    }
}