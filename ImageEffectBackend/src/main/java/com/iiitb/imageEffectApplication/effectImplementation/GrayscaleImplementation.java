package com.iiitb.imageEffectApplication.effectImplementation;
import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
import com.iiitb.imageEffectApplication.libraryInterfaces.GrayscaleInterface;
import com.iiitb.imageEffectApplication.baseEffects.PhotoEffect;
import com.iiitb.imageEffectApplication.service.LoggingService;

public class GrayscaleImplementation implements PhotoEffect{
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){
        loggingService.addLog(fileName, "Grayscale","No options");
        return GrayscaleInterface.applyGrayscale(image);
    }
}
