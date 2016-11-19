#include "loadmaterial.h"
#include <scenarioObject.h>

using namespace std;

LoadMaterial::LoadMaterial()
{
    scenarioObject = new ScenarioObject();

}
ScenarioObject* LoadMaterial::loadObject(){

    ifstream infile("/home/rin/Documentos/trabalho CG/RayCasting/thefile.txt");
    scenarioObject = insertVectorFaces(infile);

    testOnjectt(scenarioObject);


    return scenarioObject;
}



ScenarioObject* LoadMaterial::insertVectorFaces(ifstream& infile)
{
    int counterVector;
    counterVector = 0;
    face3D NthFace;
    string sub;
    ScenarioObject* scenarioObjectTmp = new ScenarioObject();
    int idVectorN_OfFace;
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
            scenarioObjectTmp->setVectorObjIn3D(vetor);


            counterVector ++;

        }else if (sub.compare("f") == 0){

            iss >> sub;
            istringstream(sub) >> idVectorN_OfFace;
            NthFace.idV1 = idVectorN_OfFace;

            iss >> sub;
            istringstream(sub) >> idVectorN_OfFace;
            NthFace.idV2 = idVectorN_OfFace;

            iss >> sub;
            istringstream(sub) >> idVectorN_OfFace;
            NthFace.idV3 = idVectorN_OfFace;

            NthFace.normal = calculatingNormal(NthFace, scenarioObjectTmp);

            scenarioObjectTmp->setFaceObjIn3D(NthFace);

            // I know it breaks the encapsulation!!
        }else if (sub.compare("material_ambient")){

            iss >> sub;
            istringstream(sub) >> scenarioObjectTmp->propMat.materialAmbientRed;
            iss >> sub;
            istringstream(sub) >> scenarioObjectTmp->propMat.materialAmbientGreen;
            iss >> sub;
            istringstream(sub) >> scenarioObjectTmp->propMat.materialAmbientBlue;

        }else if(sub.compare("material_diffuse")){
            iss >> sub;
            istringstream(sub) >> scenarioObjectTmp->propMat.materialDiffuseRed;
            iss >> sub;
            istringstream(sub) >> scenarioObjectTmp->propMat.materialDiffuseGreen;
            iss >> sub;
            istringstream(sub) >> scenarioObjectTmp->propMat.materialDiffuseBlue;
        }else if (sub.compare("material_specular")){
            iss >> sub;
            istringstream(sub) >> scenarioObjectTmp->propMat.materialSpecularRed;
            iss >> sub;
            istringstream(sub) >> scenarioObjectTmp->propMat.materialSpecularGreen;
            iss >> sub;
            istringstream(sub) >> scenarioObjectTmp->propMat.materialSpecularBlue;
        }else if (sub.compare("material_shininess")){
            iss >> sub;
            istringstream(sub) >> scenarioObjectTmp->propMat.materialShininess;
        }
    }
    infile.close();
    return scenarioObjectTmp;
}
Point3D LoadMaterial::calculatingNormal(face3D vectorsFace, ScenarioObject* sceOnj)
{


    Point3D vectorV1V2, vectorV2V3, point;
    vectorV1V2 = genevetor.generateVector(sceOnj->getVectorObjIn3D(vectorsFace.idV1),
                                          sceOnj->getVectorObjIn3D(vectorsFace.idV2));

    vectorV2V3 = genevetor.generateVector(sceOnj->getVectorObjIn3D(vectorsFace.idV1),
                                          sceOnj->getVectorObjIn3D(vectorsFace.idV3));

    point = crossProduct.crossProduct(vectorV1V2, vectorV2V3);


    return point;
}

void LoadMaterial::testOnjectt(ScenarioObject* scenarioObject)
{
    Point3D test;
    for (int var = 1; var < 7  ; ++var) {


        Point3D point = scenarioObject->getVectorObjIn3D(var);

        cout << "índice do vetor: "<< var << "| x:" << point.x
             << "| y: " << point.y <<"| z: " << point.z;


        cout << "\nface índice: " << var;
        face3D face = scenarioObject->getFaceObjIn3D(var);

        test = scenarioObject->getVectorObjIn3D(face.idV1);
        cout << "\n lista de vetores v1 x:"
             << test.x << "|  y:" << test.y << "|  z:" << test.z;

        test = scenarioObject->getVectorObjIn3D(face.idV2);
        cout << "\n lista de vetores v2: x:"
             << test.x << "|  y:" << test.y << "|  z:" << test.z;

        test = scenarioObject->getVectorObjIn3D(face.idV3);
        cout << "\n lista de vetores v3: x:"
             << test.x << "|  y:" << test.y << "|  z:" << test.z;


        cout << "\n lista de vetores normal: x:"
             << face.normal.x << "|  y:" << face.normal.y<< "|  z:" << face.normal.z<< "\n\n";

    }
}
