#include "colorpixels.h"

ColorPixels::ColorPixels()
{
    gridPixel = new GridPixel();
}


GridPixel* ColorPixels::caluletionColorPixels(int pixelRateHorizontal,
                                              int pixelRateVertical, Scenario *scenario)

{

    camera = scenario->getCamera();
    Point3D vertexPixel;

    float heighScreen, widthScreen;
    widthScreen = camera->getWidthScreen();
    heighScreen = camera->getHeighScreen();
    vertexPixel = camera->getCenterCamera();

    Pixel pixel;
    float deltaX, deltaY;
    //zc = camera.getCameraCoordenadaZ();
    deltaY = heighScreen / pixelRateVertical;
    deltaX = widthScreen / pixelRateHorizontal;
    face3D face;
    FaceFurtherNear* faceFurtherNear = new FaceFurtherNear();

    light somaIAmb, somaIDif, somaISpe;
    for (int i = 0; i <= pixelRateHorizontal ; ++i) {
        for (int j = 0; j <= pixelRateVertical; ++j) {

            vertexPixel.x = -widthScreen / 2 + deltaX / 2 + (deltaX * i);
            vertexPixel.y =  heighScreen / 2 - deltaY / 2 - (deltaY * j);

            face = faceFurtherNear->lookUpSmallestDistanceFace(vertexPixel,
                                                               scenario->getGroupScenarioObject());
            if (face.chosenFaceFlag == true){
                face.chosenFaceFlag = false;


                face.light0 = scenario->getLigth();

                somaIAmb = ambientColor(face);
                somaIDif = diffuseColor(face);
                somaISpe = specularColor(face);

                pixel.red =   somaIAmb.red   +  somaIDif.red   + somaISpe.red ;
                pixel.green = somaIAmb.green +  somaIDif.green + somaISpe.green ;
                pixel.blue =  somaIAmb.blue  +  somaIDif.blue  + somaISpe.blue ;

                pixel.red   = convertColorForFormatRGB32(pixel.red);
                pixel.green = convertColorForFormatRGB32(pixel.green);
                pixel.blue  = convertColorForFormatRGB32(pixel.blue);

                gridPixel->setColorPixel(i, j, pixel);

                /*
                pixel.red   = convertColorForFormatRGB32(face.red);
                pixel.green = convertColorForFormatRGB32(face.green);
                pixel.blue  = convertColorForFormatRGB32(face.blue);
                gridPixel->setColorPixel(i, j, pixel);
                */
            }

        }
    }
    //normalizePixel( pixelRateHorizontal , pixelRateVertical);
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

void ColorPixels::normalizePixel(int pixelRateHorizontal , int pixelRateVertical )
{   int highestValue = 0;
    Pixel pixel;
    float auxPixel;
    int n,m;
    for (int i = 0; i < pixelRateHorizontal; ++i) {
        for (int j = 0; j < pixelRateVertical; ++j) {
            pixel = gridPixel->getColorPixel(i, j);
            if (pixel.red > highestValue) {
                highestValue = pixel.red;
                n = i;
                m = j;
            }
            if(pixel.green > highestValue ){
                highestValue = pixel.green;
                n = i;
                m = j;
            }
            if(pixel.blue > highestValue){
                highestValue = pixel.blue;
                n = i;
                m = j;
            }
        }
    }
    for (int i = 0; i < pixelRateHorizontal; ++i) {
        for (int j = 0;j < pixelRateVertical; ++j) {
            pixel = gridPixel->getColorPixel(i, j);

            auxPixel = pixel.red/highestValue;
            pixel.red = auxPixel;

            auxPixel = pixel.green/highestValue;
            pixel.green = auxPixel;

            auxPixel = pixel.blue/highestValue;
            pixel.blue = auxPixel;

            gridPixel->setColorPixel(i,j, pixel);
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
    produto = dot.scalarproduct(l,face.normal);

    r.x = (2*produto)*(face.normal.x - l.x);
    r.y = (2*produto)*(face.normal.y - l.y);
    r.z = (2*produto)*(face.normal.z - l.z);

    dist = sqrt(pow(r.x, 2) + pow(r.y, 2) + pow(r.z, 2));
    r.x = r.x/dist;
    r.y = r.y/dist;
    r.z = r.z/dist;
    
    // the coordinates the of eye are zero.
    dist = sqrt(pow(pint.x, 2) + pow(pint.y, 2) + pow(pint.z, 2));
    v.x = (-pint.x)/dist;
    v.y = (-pint.y)/dist;
    v.z = (-pint.z)/dist;

    produto = dot.scalarproduct(r,v);
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
        int color8bits = 255;
        return color * color8bits;
    }else{
        std::cout << "Class colorPixels: Deu problema color" << color;
    }
}

Point3D ColorPixels::calculeteVectorV()
{

}
