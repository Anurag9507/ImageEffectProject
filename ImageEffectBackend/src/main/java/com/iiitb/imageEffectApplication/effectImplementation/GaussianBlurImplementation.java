package com.iiitb.imageEffectApplication.effectImplementation;
import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
import com.iiitb.imageEffectApplication.libraryInterfaces.GaussianBlurInterface;
import com.iiitb.imageEffectApplication.baseEffects.SingleValueParameterizableEffect;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.service.LoggingService;

public class GaussianBlurImplementation implements SingleValueParameterizableEffect{
    private float amount;
    public void setParameterValue(float amount) throws IllegalParameterException{
        if (amount < 0 || amount > 50) throw new IllegalParameterException("Illegal parameters");
        this.amount = amount;
    }
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){
        loggingService.addLog(fileName, "Gaussian Blur", Float.toString(amount));
        return GaussianBlurInterface.applyGaussianBlur(image,amount);
    }
}