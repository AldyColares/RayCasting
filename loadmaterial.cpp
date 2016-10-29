#include "loadmaterial.h"
#include <scenarioobject.h>

using namespace std;

ScenarioObject scenarioObject;
Dot dot;
CrossProduct crossProduct;
GenerateVetor genevetor;
ifstream infile;

LoadMaterial::LoadMaterial()
{
    infile.open("/home/rin/Documentos/trabalho CG/RayCasting/thefile.txt");

}
ScenarioObject LoadMaterial::loadObject(){
        scenarioObject = insertVectorFaces(infile);
        testOnjectt(scenarioObject);

        return scenarioObject;
}



 ScenarioObject LoadMaterial::insertVectorFaces(ifstream infile)
 {
     ScenarioObject scenarioObjectTmp;
     int counterVector, counterFaces;
     counterVector = 0;
     counterFaces = 0;
     point3D NthVector[4];
     string sub;
     for( string line; getline( infile, line ); )
     {
         istringstream iss(line);
         do
             {
                 iss >> sub;

                 if (sub.compare("v")){
                     iss >> sub;
                     double vx = ::atof(sub.c_str());
                     scenarioObjectTmp.setVectorObjIn3D(vx , counterVector);

                     iss >> sub;
                     double vy = ::atof(sub.c_str());
                     scenarioObjectTmp.setVectorObjIn3D(vy , counterVector);

                     iss >> sub;
                     double vz = ::atof(sub.c_str());
                     scenarioObjectTmp.setVectorObjIn3D(vz , counterVector);

                     counterVector ++;

                 }else if (sub.compare("f")){
                     iss >> sub;
                     int idVector1_OfFace = ::atoi(sub.c_str());
                     NthVector[v1] = scenarioObjectTmp.getVectorObjIn3D(idVector1_OfFace);

                     iss >> sub;
                     int idVector2_OfFace = ::atoi(sub.c_str());
                     NthVector[v2] = scenarioObjectTmp.getVectorObjIn3D(idVector2_OfFace);

                     iss >> sub;
                     int idVector3_OfFace = ::atoi(sub.c_str());
                     NthVector[v3] = scenarioObjectTmp.getVectorObjIn3D(idVector3_OfFace);

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
    vectorV1V2 = genevetor.generateVector(vectorsFace[v1], vectorsFace[v2]);
    vectorV2V3 = genevetor.generateVector(vectorsFace[v2], vectorsFace[v3]);
    point = crossProduct.crossProduct(vectorV1V2, vectorV2V3);

    return point;
}

void LoadMaterial::testOnjectt(ScenarioObject scenarioObject)
{
    for (int var = 0; var < 40; ++var) {

        cout << "face indice: " << var;
        face3D face = scenarioObject.getFaceObjIn3D(var);
        cout << "lista de vetores x: " << face.v1;
        cout << "lista de vetores y: " << face.v2;
        cout << "lista de vetores z: " << face.v3;
        cout << "lista de vetores normal: " << face.normal;


    }
}
