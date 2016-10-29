#include "loadmaterial.h"
#include <scenarioobject.h>
using namespace std;
ScenarioObject scenarioObject[3];
Dot dot;
CrossProduct crossProduct;

LoadMaterial::LoadMaterial()
{

}
ScenarioObject LoadMaterial::loadObject(){
        ifstream infile("insira o caminho o diretorio aqui/thefile.txt");
        scenarioObject[0] = insertVectorFaces(infile);


        return scenarioObject;
}

 ScenarioObject LoadMaterial::insertVectorFaces(std::ifstream infile)
 {
     ScenarioObject scenarioObjectTmp;
     int counterVector, counterFaces;
     counterVector = 0;
     counterFaces = 0;
     point3D NthVector[4];
     for( string line; getline( infile, line ); )
     {
         istringstream iss(line);
         do
             {
                 string sub;
                 iss >> sub;

                 if (sub.compare("v")){
                     iss >> sub;
                     double x = ::atof(sub.c_str());
                     scenarioObjectTmp.setVectorObjIN3D(x , counterVector);

                     iss >> sub;
                     double y = ::atof(sub.c_str());
                     scenarioObjectTmp.setVectorObjIN3D(y , counterVector);

                     iss >> sub;
                     double z = ::atof(sub.c_str());
                     scenarioObjectTmp.setVectorObjIN3D(z , counterVector);
                     counterVector ++;

                 }else if (sub.compare("f")){
                     iss >> sub;
                     int idVector1_OfFace = ::atoi(sub.c_str());
                     NthVector[v1] = scenarioObjectTmp.getVectorObjIN3D(idVector1_OfFace);

                     iss >> sub;
                     int idVector2_OfFace = ::atoi(sub.c_str());
                     NthVector[v2] = scenarioObjectTmp.getVectorObjIN3D(idVector2_OfFace);

                     iss >> sub;
                     int idVector3_OfFace = ::atoi(sub.c_str());
                     NthVector[v3] = scenarioObjectTmp.getVectorObjIN3D(idVector3_OfFace);

                     NthVector[4] = calculatingNormal(NthVector[]);

                     scenarioObjectTmp.setFaceObjIn3D(NthVector, counterFaces);

                     counterFaces ++;
                 }
             } while (iss);
         return scenarioObjectTmp;
     }

}
LoadMaterial::calculatingNormal(point3D vectorsFace[4])
{

    point3D vectorV1V2, vectorV2V3, point;
    vectorV1V2 = dot.scalarproduct(vectorsFace[v1], vectorsFace[v2]);
    vectorV2V3 = dot.scalarproduct(vectorsFace[v2], vectorsFace[v3]);
    float aux[] = crossProduct.crossProduct(vectorV1V2, vectorV2V3);
    point.x = aux[0];
    point.y = aux[1];
    point.z = aux[2];

    return point;
}
