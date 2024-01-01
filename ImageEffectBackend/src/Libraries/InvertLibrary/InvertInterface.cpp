#include "com_iiitb_imageEffectApplication_libraryInterfaces_InvertInterface.h"
#include "Invert.h"
#include "../Pixel.h"
#include <vector>
using namespace std;

JNIEXPORT jobjectArray JNICALL Java_com_iiitb_imageEffectApplication_libraryInterfaces_InvertInterface_applyInvert
  (JNIEnv * env, jclass jobj, jobjectArray image) {

    // Convert Java image array to C++ vector of vectors
    vector< vector<Pixel> > imageVector;
    jsize rows = env->GetArrayLength(image);
    jclass pixelArrayClass, pixelClass;

    // Iterate through rows of the Java image array
    for (jsize i = 0; i < rows; ++i) {
        // Extract each row of the Java image array
        jobjectArray rowArray = (jobjectArray)env->GetObjectArrayElement(image, i);
        jsize cols = env->GetArrayLength(rowArray);
        pixelArrayClass = env->GetObjectClass(rowArray);

        // Convert Java row array to C++ vector
        vector<Pixel> rowVector;
        for (jsize j = 0; j < cols; ++j) {
            // Extract Pixel object from the Java row array
            jobject pixelObj = env->GetObjectArrayElement(rowArray, j);

            // Extract RGB values from the Pixel object
            pixelClass = env->GetObjectClass(pixelObj);
            jfieldID rField = env->GetFieldID(pixelClass, "r", "I");
            jfieldID gField = env->GetFieldID(pixelClass, "g", "I");
            jfieldID bField = env->GetFieldID(pixelClass, "b", "I");

            jint rValue = env->GetIntField(pixelObj, rField);
            jint gValue = env->GetIntField(pixelObj, gField);
            jint bValue = env->GetIntField(pixelObj, bField);

            // Create a C++ Pixel object and add it to the row vector
            Pixel pixel;
            pixel.r = static_cast<int>(rValue);
            pixel.g = static_cast<int>(gValue);
            pixel.b = static_cast<int>(bValue);

            rowVector.push_back(pixel);

            // Release local reference to the Pixel object
            env->DeleteLocalRef(pixelObj);
        }

        // Add the row vector to the image vector
        imageVector.push_back(rowVector);

        // Release local reference to the Java row array
        env->DeleteLocalRef(rowArray);
    }

    // Call the C++ function to apply the image inversion
    applyInvert(imageVector);

    // Retrieve dimensions of the result image
    int nrows = imageVector.size();
    int ncols = imageVector[0].size();

    // Create a new Java object array to store the result image
    jobjectArray resultArray = env->NewObjectArray(nrows, pixelArrayClass, nullptr);

    // Iterate through rows of the result image vector
    for (jsize i = 0; i < nrows; ++i) {
        // Retrieve the number of columns in the current row
        jsize cols = imageVector[i].size();

        // Create a new Java row array to store the current row of the result image
        jobjectArray rowArray = env->NewObjectArray(ncols, pixelClass, nullptr);

        // Iterate through columns of the result image vector
        for (jsize j = 0; j < ncols; ++j) {
            // Retrieve the Pixel object from the result image vector
            const Pixel &pixel = imageVector[i][j];

            // Create a new Java Pixel object
            jobject pixelObj = env->AllocObject(pixelClass);

            // Set the RGB values of the Java Pixel object
            env->SetIntField(pixelObj, env->GetFieldID(pixelClass, "r", "I"), pixel.r);
            env->SetIntField(pixelObj, env->GetFieldID(pixelClass, "g", "I"), pixel.g);
            env->SetIntField(pixelObj, env->GetFieldID(pixelClass, "b", "I"), pixel.b);

            // Set the Java Pixel object in the current row array
            env->SetObjectArrayElement(rowArray, j, pixelObj);

            // Release local reference to the Java Pixel object
            env->DeleteLocalRef(pixelObj);
        }

        // Set the Java row array in the result image array
        env->SetObjectArrayElement(resultArray, i, rowArray);

        // Release local reference to the Java row array
        env->DeleteLocalRef(rowArray);
    }

    // Return the result image array
    return resultArray;
}
