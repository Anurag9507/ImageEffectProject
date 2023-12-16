package com.iiitb.imageEffectApplication.service;
import com.iiitb.imageEffectApplication.effectImplementation.*;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.libraryInterfaces.*;
import com.iiitb.imageEffectApplication.utils.ProcessingUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;
import java.io.IOException;

@Service
public class PhotoEffectService{
    @Autowired private ProcessingUtils processingUtils;
    @Autowired private LoggingService loggingService;

    public ResponseEntity<byte[]> applyHueSaturationEffect(float hv,float sv,MultipartFile imageFile){
        try{
            Pixel[][] inputImage = processingUtils.preprocessing(imageFile);
            String imageName = imageFile.getOriginalFilename();
            HueSaturationImplementation obj = new HueSaturationImplementation();
            try{
                obj.setParameter("H",hv);
                obj.setParameter("S",sv);
            }
            catch (IllegalParameterException e){
                e.printStackTrace();
            }
            Pixel[][] modifiedImage = obj.apply(inputImage,imageName,loggingService);
            return processingUtils.postProcessing(modifiedImage);
        } 
        catch (IOException e){
            e.printStackTrace();
            return new ResponseEntity<>(HttpStatus.INTERNAL_SERVER_ERROR);
        }
    }

    public ResponseEntity<byte[]> applyBrightnessEffect(float amount, MultipartFile imageFile){
        try {
            Pixel[][] inputImage = processingUtils.preprocessing(imageFile);
            String imageName = imageFile.getOriginalFilename();
            BrightnessImplementation obj = new BrightnessImplementation();
            try{
                obj.setParameterValue(amount);
            }
            catch(IllegalParameterException e){
                e.printStackTrace();
            }
            Pixel[][] modifiedImage = obj.apply(inputImage,imageName,loggingService); 
            return processingUtils.postProcessing(modifiedImage);
        } 
        catch (IOException e) {
            e.printStackTrace();
            return new ResponseEntity<>(HttpStatus.INTERNAL_SERVER_ERROR);
        }
    }

    public ResponseEntity<byte[]> applyContrastEffect(float amount, MultipartFile imageFile){
        try{
            Pixel[][] inputImage = processingUtils.preprocessing(imageFile);
            String imageName = imageFile.getOriginalFilename();
            ContrastImplementation obj = new ContrastImplementation();
            try{
                obj.setParameterValue(amount);
            }
            catch (IllegalParameterException e){
                e.printStackTrace();
            }
            Pixel[][] modifiedImage = obj.apply(inputImage,imageName,loggingService); 
            return processingUtils.postProcessing(modifiedImage);
        }
        catch (IOException e){
            e.printStackTrace();
            return new ResponseEntity<>(HttpStatus.INTERNAL_SERVER_ERROR);
        }
    }

    public ResponseEntity<byte[]> applyFlipEffect(MultipartFile imageFile,int hf,int vf){
        try{
            Pixel[][] inputImage = processingUtils.preprocessing(imageFile);
            String imageName = imageFile.getOriginalFilename();
            FlipImplementation obj = new FlipImplementation();
            try{
                obj.selectOptionValue("H",hf);
                obj.selectOptionValue("V",vf);
            }
            catch (IllegalParameterException e){
                e.printStackTrace();
            }
            Pixel[][] modifiedImage = obj.apply(inputImage,imageName,loggingService);
            return processingUtils.postProcessing(modifiedImage);
        }
        catch (IOException e){
            e.printStackTrace();
            return new ResponseEntity<>(HttpStatus.INTERNAL_SERVER_ERROR);
        }
    }

    public ResponseEntity<byte[]> applyGaussianBlurEffect(float radius, MultipartFile imageFile){
        try{
            Pixel[][] inputImage = processingUtils.preprocessing(imageFile);
            String imageName = imageFile.getOriginalFilename();
            GaussianBlurImplementation obj = new GaussianBlurImplementation();
            try{
                obj.setParameterValue(radius);
            }
            catch (IllegalParameterException e){
                e.printStackTrace();
            }
            Pixel[][] modifiedImage = obj.apply(inputImage,imageName,loggingService);
            return processingUtils.postProcessing(modifiedImage);
        }
        catch (IOException e){
            e.printStackTrace();
            return new ResponseEntity<>(HttpStatus.INTERNAL_SERVER_ERROR);
        }
    }

    public ResponseEntity<byte[]> applyGrayscaleEffect(MultipartFile imageFile){
        try {
            Pixel[][] inputImage = processingUtils.preprocessing(imageFile);
            String imageName = imageFile.getOriginalFilename();
            GrayscaleImplementation obj = new GrayscaleImplementation();
            Pixel[][] modifiedImage = obj.apply(inputImage,imageName,loggingService); 
            return processingUtils.postProcessing(modifiedImage);
        }
        catch (IOException e) {
            e.printStackTrace();
            return new ResponseEntity<>(HttpStatus.INTERNAL_SERVER_ERROR);
        }
    }

    public ResponseEntity<byte[]> applyInvertEffect(MultipartFile imageFile){
        try{
            Pixel[][] inputImage = processingUtils.preprocessing(imageFile);
            String imageName = imageFile.getOriginalFilename();
            InvertImplementation obj = new InvertImplementation();
            Pixel[][] modifiedImage = obj.apply(inputImage,imageName,loggingService);
            return processingUtils.postProcessing(modifiedImage);
        } 
        catch (IOException e){
            e.printStackTrace();
            return new ResponseEntity<>(HttpStatus.INTERNAL_SERVER_ERROR);
        }
    }

    public ResponseEntity<byte[]> applyRotationEffect(int v, MultipartFile imageFile){
        try{
            Pixel[][] inputImage = processingUtils.preprocessing(imageFile);
            String imageName = imageFile.getOriginalFilename();
            RotationImplementation obj = new RotationImplementation();
            try{
                obj.setParameterValue(v);
            }
            catch (IllegalParameterException e){
                e.printStackTrace();
            }
            Pixel[][] modifiedImage = obj.apply(inputImage,imageName,loggingService);
            return processingUtils.postProcessing(modifiedImage);
        } 
        catch (IOException e){
            e.printStackTrace();
            return new ResponseEntity<>(HttpStatus.INTERNAL_SERVER_ERROR);
        }
    }

    public ResponseEntity<byte[]> applySepiaEffect(MultipartFile imageFile){
        try{
            Pixel[][] inputImage = processingUtils.preprocessing(imageFile);
            String imageName = imageFile.getOriginalFilename();
            SepiaImplementation obj = new SepiaImplementation();
            Pixel[][] modifiedImage = obj.apply(inputImage,imageName,loggingService);
            return processingUtils.postProcessing(modifiedImage);
        }
        catch (IOException e){
            e.printStackTrace();
            return new ResponseEntity<>(HttpStatus.INTERNAL_SERVER_ERROR);
        }
    }

    public ResponseEntity<byte[]> applySharpenEffect(float amount, MultipartFile imageFile){
        try{
            Pixel[][] inputImage = processingUtils.preprocessing(imageFile);
            String imageName = imageFile.getOriginalFilename();
            SharpenImplementation obj = new SharpenImplementation();
            try{
                obj.setParameterValue(amount);
            }
            catch (IllegalParameterException e){
                e.printStackTrace();
            }
            Pixel[][] modifiedImage = obj.apply(inputImage,imageName,loggingService);
            return processingUtils.postProcessing(modifiedImage);
        }
        catch (IOException e) {
            e.printStackTrace();
            return new ResponseEntity<>(HttpStatus.INTERNAL_SERVER_ERROR);
        }
    }

    public ResponseEntity<byte[]> getDominantColour(MultipartFile imageFile){
        try{
            Pixel[][] inputImage = processingUtils.preprocessing(imageFile);
            String imageName = imageFile.getOriginalFilename();
            DominantColourImplementation obj = new DominantColourImplementation();
            Pixel[][] modifiedImage = obj.apply(inputImage,imageName,loggingService); 
            return processingUtils.postProcessing(modifiedImage);
        }
        catch (IOException e) {
            e.printStackTrace();
            return new ResponseEntity<>(HttpStatus.INTERNAL_SERVER_ERROR);
        }
    }
}
