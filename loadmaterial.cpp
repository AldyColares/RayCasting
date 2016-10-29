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
    cout << "oi";

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

       if (sub.compare("v")){
           iss >> sub;
           vetor[0] = ::atof(sub.c_str());

           iss >> sub;
           vetor[1] = ::atof(sub.c_str());

           iss >> sub;
           vetor[2] = ::atof(sub.c_str());
           scenarioObjectTmp.setVectorObjIn3D(vetor , counterVector);

           counterVector ++;

       }else if (sub.compare("f")){
           iss >> sub;
           int idVector1_OfFace = ::atoi(sub.c_str());
           NthVector.v1 = scenarioObjectTmp.getVectorObjIn3D(idVector1_OfFace);

           iss >> sub;
           int idVector2_OfFace = ::atoi(sub.c_str());
           NthVector.v2 = scenarioObjectTmp.getVectorObjIn3D(idVector2_OfFace);

           iss >> sub;
           int idVector3_OfFace = ::atoi(sub.c_str());
           NthVector.v3 = scenarioObjectTmp.getVectorObjIn3D(idVector3_OfFace);

           NthVector.normal = calculatingNormal(NthVector);

           scenarioObjectTmp.setFaceObjIn3D(NthVector, counterFaces);

           counterFaces ++;
       }


   }

   cout << "oi";
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
    for (int var = 0; var < 4; ++var) {

        cout << "\nface indice: " << var;
        face3D face = scenarioObject.getFaceObjIn3D(var);
        cout << "\n lista de vetores x: " << face.v1.x << face.v1.y << face.v1.z;


        cout << "\n lista de vetores y: " << face.v2.x << face.v2.y << face.v2.z;


        cout << "\n lista de vetores z: "
        << face.v3.x << face.v3.y << face.v3.z;

        cout << "\n lista de vetores normal: "
        << face.normal.x << face.normal.y<< face.normal.z;


    }
}
