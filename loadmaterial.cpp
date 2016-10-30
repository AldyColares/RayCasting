#include "loadmaterial.h"
#include <scenarioObject.h>

using namespace std;

ScenarioObject scenarioObject;
Dot dot;
CrossProduct crossProduct;
GenerateVetor genevetor;

LoadMaterial::LoadMaterial()
{

}
ScenarioObject LoadMaterial::loadObject(){

    ifstream infile("/home/rin/Documentos/trabalho CG/RayCasting/thefile.txt");

    scenarioObject = insertVectorFaces(infile);
    testOnjectt(scenarioObject);

    return scenarioObject;
}



ScenarioObject LoadMaterial::insertVectorFaces(ifstream& infile)
{
   int counterVector, counterFaces;
   counterVector = 0;
   counterFaces = 0;
   face3D NthVector;
   string sub;
   ScenarioObject scenarioObjectTmp;

   for( string line; getline( infile, line ); )
   {
       istringstream iss(line);
       float vetor[3];
       iss >> sub;
       if (sub.compare("v") == 0){

           iss >> sub;
           istringstream(sub) >> vetor[0];

           iss >> sub;
           istringstream(sub) >> vetor[1];

           iss >> sub;
           istringstream(sub) >> vetor[2];
           scenarioObjectTmp.setVectorObjIn3D(vetor , counterVector);

           counterVector ++;

       }else if (sub.compare("f") == 0){
           iss >> sub;

           int idVector1_OfFace = ::stoi(sub.c_str());
           NthVector.v1 = scenarioObjectTmp.getVectorObjIn3D(idVector1_OfFace);

           iss >> sub;
           int idVector2_OfFace = ::stoi(sub.c_str());
           NthVector.v2 = scenarioObjectTmp.getVectorObjIn3D(idVector2_OfFace);

           iss >> sub;
           int idVector3_OfFace = ::stoi(sub.c_str());
           NthVector.v3 = scenarioObjectTmp.getVectorObjIn3D(idVector3_OfFace);

           NthVector.normal = calculatingNormal(NthVector);

           scenarioObjectTmp.setFaceObjIn3D(NthVector, counterFaces);

           counterFaces ++;
       }


   }

   return scenarioObjectTmp;
}
point3D LoadMaterial::calculatingNormal(face3D vectorsFace)
{

    point3D vectorV1V2, vectorV2V3, point;
    vectorV1V2 = genevetor.generateVector(vectorsFace.v1, vectorsFace.v2);
    vectorV2V3 = genevetor.generateVector(vectorsFace.v2, vectorsFace.v3);
    point = crossProduct.crossProduct(vectorV1V2, vectorV2V3);

    return point;
}

void LoadMaterial::testOnjectt(ScenarioObject scenarioObject)
{
    for (int var = 0; var < 40  ; ++var) {

      point3D point = scenarioObject.getVectorObjIn3D(var);

       cout << "índice do vetor: "<< var << "| x:" << point.x
                    << "| y: " << point.y <<"| z: " << point.z;


        cout << "\nface índice: " << var;
        face3D face = scenarioObject.getFaceObjIn3D(var);
        cout << "\n lista de vetores v1 x:"
             << face.v1.x << "|  y:" << face.v1.y << "|  z:" << face.v1.z;

         cout << "\n lista de vetores v2: x:"
              << face.v2.x << "|  y:" << face.v2.y << "|  z:" << face.v2.z;


        cout << "\n lista de vetores v3: x:"
             << face.v3.x << "|  y:" << face.v3.y << "|  z:" << face.v3.z;


        cout << "\n lista de vetores normal: x:"
        << face.normal.x << "|  y:" << face.normal.y<< "|  z:" << face.normal.z<< "\n\n";


    }
}
