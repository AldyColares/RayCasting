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
   face3D NthFace;
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
                 NthFace.idV1 = idVector1_OfFace;

                 iss >> sub;
                 int idVector2_OfFace = ::stoi(sub.c_str());
                 NthFace.idV2 = idVector2_OfFace;

                 iss >> sub;
                 int idVector3_OfFace = ::stoi(sub.c_str());
                 NthFace.idV3 = idVector3_OfFace;

                 NthFace.normal = calculatingNormal(NthFace, scenarioObjectTmp);

                 scenarioObjectTmp.setFaceObjIn3D(NthFace);

             }

   }

   return scenarioObjectTmp;
}
point3D LoadMaterial::calculatingNormal(face3D vectorsFace, ScenarioObject sceOnj)
{

    point3D vectorV1V2, vectorV2V3, point;
    vectorV1V2 = genevetor.generateVector(sceOnj.getVectorObjIn3D(vectorsFace.idV1),
                                          sceOnj.getVectorObjIn3D(vectorsFace.idV2));

    vectorV2V3 = genevetor.generateVector(sceOnj.getVectorObjIn3D(vectorsFace.idV1),
                                          sceOnj.getVectorObjIn3D(vectorsFace.idV3));

    point = crossProduct.crossProduct(vectorV1V2, vectorV2V3);

    return point;
}

void LoadMaterial::testOnjectt(ScenarioObject scenarioObject)
{
    point3D test;
    for (int var = 0; var < 4  ; ++var) {

      point3D point = scenarioObject.getVectorObjIn3D(var);

       cout << "índice do vetor: "<< var << "| x:" << point.x
                    << "| y: " << point.y <<"| z: " << point.z;


        cout << "\nface índice: " << var;
        face3D face = scenarioObject.getFaceObjIn3D(var);

        test = scenarioObject.getVectorObjIn3D(face.idV1);
        cout << "\n lista de vetores v1 x:"
             << test.x << "|  y:" << test.y << "|  z:" << test.z;

        test = scenarioObject.getVectorObjIn3D(face.idV2);
        cout << "\n lista de vetores v2: x:"
              << test.x << "|  y:" << test.y << "|  z:" << test.z;

        test = scenarioObject.getVectorObjIn3D(face.idV3);
        cout << "\n lista de vetores v3: x:"
             << test.x << "|  y:" << test.y << "|  z:" << test.z;


        cout << "\n lista de vetores normal: x:"
        << face.normal.x << "|  y:" << face.normal.y<< "|  z:" << face.normal.z<< "\n\n";

    }
}
