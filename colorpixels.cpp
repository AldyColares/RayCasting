#include "colorpixels.h"

ColorPixels::ColorPixels()
{
    gridPixel = new GridPixel();
}


GridPixel* ColorPixels::caluletionColorPixels(int pixelRateHorizontal, int pixelRateVertical,
                                              Scenario *scenario)

{

    camera = scenario->getCamera();

    bool thereIsShadow;
    float heighScreen, widthScreen;
    widthScreen = camera->getWidthScreen();
    heighScreen = camera->getHeighScreen();
    vertexPixel = camera->getCenterCamera();

    Pixel pixel;
    float deltaX, deltaY;
    deltaY = heighScreen / pixelRateVertical;
    deltaX = widthScreen / pixelRateHorizontal;
    face3D face;
    FaceFurtherNear* faceFurtherNear = new FaceFurtherNear();
    MapShadow* mapShadow = new MapShadow(scenario->getGroupScenarioObject());

    for (int i = 0; i <= pixelRateHorizontal ; ++i) {
        for (int j = 0; j <= pixelRateVertical; ++j) {

            vertexPixel.x = -widthScreen / 2 + deltaX / 2 + (deltaX * i);
            vertexPixel.y =  heighScreen / 2 - deltaY / 2 - (deltaY * j);

            face = faceFurtherNear->lookUpSmallestDistanceFace(vertexPixel,
                                                               scenario->getGroupScenarioObject());
            if (face.chosenFaceFlag == true){
                face.chosenFaceFlag = false;

                face.light0 = scenario->getLigth();

                coordLight0.x = face.light0.x;
                coordLight0.y = face.light0.y;
                coordLight0.z = face.light0.z;
                pointInsertface.x = face.pointInsertFace.x;
                pointInsertface.y = face.pointInsertFace.y;
                pointInsertface.z = face.pointInsertFace.z;

                VerticesBetweenPointAndLight = generateVector.generateVector(pointInsertface, coordLight0);

                thereIsShadow = mapShadow->findShadow(VerticesBetweenPointAndLight);

                //somaIAmb = ambientColor(face);
                clearVariableDiffuseAndSpecular();
                //thereIsShadow = false;
                if(thereIsShadow == false){
                    somaIDif = diffuseColor(face);
                    somaISpe = specularColor(face);
                }
                pixel.red =   somaIAmb.red   +  somaIDif.red   + somaISpe.red ;
                pixel.green = somaIAmb.green +  somaIDif.green + somaISpe.green ;
                pixel.blue =  somaIAmb.blue  +  somaIDif.blue  + somaISpe.blue ;

                pixel.red *= face.red;
                pixel.green *= face.green;
                pixel.blue  *= face.blue;

                pixel.red   = convertColorForFormatRGB32(pixel.red);
                pixel.green = convertColorForFormatRGB32(pixel.green);
                pixel.blue  = convertColorForFormatRGB32(pixel.blue);

                gridPixel->setColorPixel(i, j, pixel);

            }

        }
    }
    normalizePixel( pixelRateHorizontal , pixelRateVertical, color8bits);
    return gridPixel;
}

light ColorPixels::ambientColor(face3D face)
{
    light IAmb;
    proMat = face.propMaterial;
    light0 = face.light0;
    IAmb.red = light0.red * proMat.materialAmbientRed;
    IAmb.green = light0.green * proMat.materialAmbientGreen;
    IAmb.blue = light0.blue * proMat.materialAmbientBlue;
    return IAmb;
}

void ColorPixels::normalizePixel(int pixelRateHorizontal , int pixelRateVertical , int limitNormalize)
{   int highestValue = 0;
    Pixel pixel;
    float auxPixel;

    for (int i = 0; i < pixelRateHorizontal; ++i) {
        for (int j = 0; j < pixelRateVertical; ++j) {
            pixel = gridPixel->getColorPixel(i, j);
            if (pixel.red > highestValue) {
                highestValue = pixel.red;
            }
            if(pixel.green > highestValue ){
                highestValue = pixel.green;
            }
            if(pixel.blue > highestValue){
                highestValue = pixel.blue;
            }
        }
    }
    if (highestValue > limitNormalize) {
        for (int i = 0; i < pixelRateHorizontal; ++i) {
            for (int j = 0;j < pixelRateVertical; ++j) {
                pixel = gridPixel->getColorPixel(i, j);

                auxPixel = pixel.red/highestValue;
                pixel.red = auxPixel;
                pixel.red = convertColorForFormatRGB32(pixel.red);

                auxPixel = pixel.green/highestValue;
                pixel.green = auxPixel;
                pixel.green = convertColorForFormatRGB32(pixel.green);

                auxPixel = pixel.blue/highestValue;
                pixel.blue = auxPixel;
                pixel.blue = convertColorForFormatRGB32(pixel.blue);
                gridPixel->setColorPixel(i,j, pixel);
            }
        }
    }
}

light ColorPixels::diffuseColor(face3D face)
{
    light IDif;
    proMat = face.propMaterial;
    light0 = face.light0;
    Point3D pint = face.pointInsertFace;

    Point3D l;
    float dist, produto;

    dist = sqrt(pow((light0.x - pint.x), 2) + pow((light0.y - pint.y), 2) + pow((light0.z - pint.z), 2));
    l.x = (light0.x - pint.x)/dist;
    l.y = (light0.y - pint.y)/dist;
    l.z = (light0.z - pint.z)/dist;


    produto = dot.scalarproduct(face.normal, l);
    if (produto > 1){
        std::cout << "produto acima de 1 no diffuso.";
    }
    if(produto >= 0.000){
        IDif.red = light0.red * proMat.materialDiffuseRed * produto;
        IDif.green = light0.green * proMat.materialDiffuseGreen * produto;
        IDif.blue = light0.blue * proMat.materialDiffuseBlue * produto;
        return IDif;
    }else{
        IDif.red = 0.00;
        IDif.green = 0.00;
        IDif.blue = 0.00;
        return IDif;
    }

}

light ColorPixels::specularColor(face3D face)
{
    light ISpe;
    Point3D l, r, v;
    float dist, produto;
    proMat = face.propMaterial;
    light0 = face.light0;
    Point3D pint = face.pointInsertFace;

    dist = sqrt(pow((light0.x - pint.x), 2) + pow((light0.y - pint.y), 2) + pow((light0.z - pint.z), 2));
    l.x = (light0.x - pint.x)/dist;
    l.y = (light0.y - pint.y)/dist;
    l.z = (light0.z - pint.z)/dist;
    produto = dot.scalarproduct(l, face.normal);

    r.x = (2*produto)*(face.normal.x - l.x);
    r.y = (2*produto)*(face.normal.y - l.y);
    r.z = (2*produto)*(face.normal.z - l.z);

    dist = sqrt(pow(r.x, 2) + pow(r.y, 2) + pow(r.z, 2));
    r.x = (r.x)/dist;
    r.y = (r.y)/dist;
    r.z = (r.z)/dist;

    // the coordinates the of eye are zero.
    dist = sqrt(pow(pint.x, 2) + pow(pint.y, 2) + pow(pint.z, 2));
    v.x = (-pint.x)/dist;
    v.y = (-pint.y)/dist;
    v.z = (-pint.z)/dist;

    produto = dot.scalarproduct(r,v);
    if (produto > 1){
        std::cout << "produto acima de 1 no specular.";
    }
    if (produto >= 0.000 ) {
        ISpe.red = light0.red * proMat.materialSpecularRed * pow(produto, proMat.materialShininess);
        ISpe.green = light0.green * proMat.materialSpecularGreen * pow(produto, proMat.materialShininess);
        ISpe.blue = light0.blue * proMat.materialSpecularBlue * pow(produto, proMat.materialShininess);
        return ISpe;
    }else{
        ISpe.red = 0.00;
        ISpe.green = 0.00;
        ISpe.blue = 0.00;
        return ISpe;
    }
}

int ColorPixels::convertColorForFormatRGB32(float color)
{
    if (color >= 0){

        return color * color8bits;
    }else{
        std::cout << "Class colorPixels: Deu problema color" << color;
        return 0;
    }
}

void ColorPixels::clearVariableDiffuseAndSpecular()
{
    somaIDif.red = 0;
    somaIDif.green = 0;
    somaIDif.blue = 0;
    somaISpe.red = 0;
    somaISpe.green = 0;
    somaISpe.blue = 0;
}
