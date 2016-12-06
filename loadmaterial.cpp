#include "loadmaterial.h"

using namespace std;

LoadMaterial::LoadMaterial()
{
    scenarioObject = new ScenarioObject();
    vectorScenarioObject = new vector<ScenarioObject*>;
    auxPoint3d.w = 1;

}
vector<ScenarioObject*> *LoadMaterial::loadObject(){
    //thefile.txt
    //mesa.txt
    vector<string> setMaterial;
    //setMaterial.push_back("triforce.txt");
    //setMaterial.push_back("mesa.txt");

    setMaterial.push_back("cubeDepurer.txt");
    setMaterial.push_back("floor.txt");



    //home/0338159/Documentos/RayCasting
    //home/rin/Documentos/trabalho CG/RayCasting
    string pathFile ="/home/rin/Documentos/trabalho CG/RayCasting/resources/";

    int setMaterialSize = setMaterial.size();
    for (int var = 0; var < setMaterialSize; ++var) {

        ifstream infile( pathFile + setMaterial[var]);
        scenarioObject = insertVectorFaces(infile);
        //testOnjectt(scenarioObject);

        vectorScenarioObject->push_back(scenarioObject );
    }

    return vectorScenarioObject;
}



ScenarioObject* LoadMaterial::insertVectorFaces(ifstream& infile)
{
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

        }else if (sub.compare("f") == 0){
            float aux;
            iss >> sub;
            istringstream(sub) >> idVectorN_OfFace;
            NthFace.idV1 = idVectorN_OfFace;

            iss >> sub;
            istringstream(sub) >> idVectorN_OfFace;
            NthFace.idV2 = idVectorN_OfFace;

            iss >> sub;
            istringstream(sub) >> idVectorN_OfFace;
            NthFace.idV3 = idVectorN_OfFace;

            iss >> sub;
            istringstream(sub) >> aux;
            NthFace.red = aux;

            iss >> sub;
            istringstream(sub) >> aux;
            NthFace.green = aux;

            iss >> sub;
            istringstream(sub) >> aux;
            NthFace.blue = aux;

            NthFace.normal = calculatingNormal(NthFace, scenarioObjectTmp);

            scenarioObjectTmp->setFaceObjIn3D(NthFace);

        }else if (sub.compare("#") == 0){
            continue;

        }else if(sub.compare("centroid") == 0){
            iss >> sub;
            istringstream(sub) >> auxPoint3d.x;

            iss >> sub;
            istringstream(sub) >> auxPoint3d.y;

            iss >> sub;
            istringstream(sub) >> auxPoint3d.z;
            scenarioObjectTmp->setCentroid(auxPoint3d);
        }else if(sub.compare("front") == 0 ){
            iss >> sub;
            istringstream(sub) >> auxPoint3d.x;

            iss >> sub;
            istringstream(sub) >> auxPoint3d.y;

            iss >> sub;
            istringstream(sub) >> auxPoint3d.z;
            scenarioObjectTmp->setFront(auxPoint3d);
        }else if(sub.compare("right") == 0){
            iss >> sub;
            istringstream(sub) >> auxPoint3d.x;

            iss >> sub;
            istringstream(sub) >> auxPoint3d.y;

            iss >> sub;
            istringstream(sub) >> auxPoint3d.z;
            scenarioObjectTmp->setSideRight(auxPoint3d);
        }else if(sub.compare("top") == 0){
            iss >> sub;
            istringstream(sub) >> auxPoint3d.x;

            iss >> sub;
            istringstream(sub) >> auxPoint3d.y;

            iss >> sub;
            istringstream(sub) >> auxPoint3d.z;
            scenarioObjectTmp->setTop(auxPoint3d);

        }else if (sub.compare("materialAmbient") == 0){

            iss >> sub;
            istringstream(sub) >> propMat.materialAmbientRed;
            iss >> sub;
            istringstream(sub) >> propMat.materialAmbientGreen;
            iss >> sub;
            istringstream(sub) >> propMat.materialAmbientBlue;

        }else if(sub.compare("materialDiffuse") == 0){
            iss >> sub;
            istringstream(sub) >> propMat.materialDiffuseRed;
            iss >> sub;
            istringstream(sub) >> propMat.materialDiffuseGreen;
            iss >> sub;
            istringstream(sub) >> propMat.materialDiffuseBlue;

        }else if (sub.compare("materialSpecular") == 0){
            iss >> sub;
            istringstream(sub) >> propMat.materialSpecularRed;
            iss >> sub;
            istringstream(sub) >> propMat.materialSpecularGreen;
            iss >> sub;
            istringstream(sub) >> propMat.materialSpecularBlue;

        }else if (sub.compare("materialShininess") == 0){
            iss >> sub;
            istringstream(sub) >> propMat.materialShininess;
        }
    }
    infile.close();
    scenarioObjectTmp->setPropertyMaterial(propMat);
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
