#include "loadmaterial.h"
#include <fstream>
#include <scenarioobject.h>
#include <iostream>

LoadMaterial::LoadMaterial()
{

}
 ScenarioObject LoadMaterial::loadObject(){
    ScenarioObject scenarioObject;
    using namespace std;
    ifstream infile("insira o caminho o diretorio aqui/thefile.txt");
    string NthLineOfFile;


    for( std::string line; getline( infile, line ); )
    {
        std::istringstream iss(line);

        do
        {
            std::string sub;
            iss >> sub;
            std::cout << "Substring: " << sub << std::endl;
        } while (iss);
    }
    return scenarioObject;
}
