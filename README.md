
# ImageEffectApplication

ImageEffectApplication is a software that applies various image effects, such as contrast, saturation etc. to the image and stores logs of each applied effect.

We have implemented this project as part of our Programming-2 course.

## Individual contributions

IMT2022103 Anurag Ramaswamy: Implemented Brightness and Contrast and completed logs for Brightness and Contrast.

IMT2022076 Mohit Naik: Implemented Sharpen, HueSaturation and Dominant Color and completed logs for Sharpen, HueSaturation and Dominant Color.

IMT2022008 Harsh Dhruv: Implemented Gaussian Blur and Flip and completed logs for Gaussian Blur.

IMT2022065 Amruth Gadepalli: Implemented Sepia and Grayscale and completed logs for Sepia.

IMT2022014 Shashank Tippanavar: Implemented Rotation and completed logs for Flip and Rotation.

IMT2022046 Aryan Vaghasiya: Implemented Invert and completed logs for Invert and Grayscale.

## Effects implemented

• Brightness

• Contrast

• Dominant Color

• Flip (Horizontal/Vertical)

• Gaussian Blur

• Grayscale

• Hue/Saturation

• Invert

• Rotation (0°/90°/180°/270°)

• Sepia

• Sharpen

## Logs

Logs for each applied effect can be found in the Logs section of the frontend. You can fiter out logs by the effect name, and you can also find all logs in a certain time period.

## Run Locally
Clone the project
```bash
  git clone https://github.com/Anurag9507/ImageEffectProject
```
### Go to the project directory
```bash
  cd ImageEffectProject
```
### Run backend
Go to the backend directory
```bash
  cd ImageEffectBackend
```
Run make command to compile code and generate libraries
```bash
  make clean && make
```
Use this if you have maven installed 
```bash
  sudo mvn clean package
```
Otherwise use
```bash
  ./mvnw clean package
```
Run the application 
```bash
  java -jar target/imageEffectApplication-0.0.1-SNAPSHOT.jar
```
### Run frontend
Go to the frontend directory
```bash
  cd ImageEffectFrontend
```
Install Node
```bash
  npm install
```

Start the server

```bash
  npm i
```

```bash
  npm start
```
Check the localhost url/port and open it in your local broswer.



