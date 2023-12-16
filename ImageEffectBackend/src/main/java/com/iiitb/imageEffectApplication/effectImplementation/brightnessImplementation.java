package com.iiitb.imageEffectApplication.effectImplementation;

import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
import com.iiitb.imageEffectApplication.libraryInterfaces.BrightnessInterface;
import com.iiitb.imageEffectApplication.baseEffects.SingleValueParameterizableEffect;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.service.LoggingService;
import com.iiitb.imageEffectApplication.model.LogModel;

public class brightnessImplementation implements SingleValueParameterizableEffect{
    private float amount;
    public void setParameterValue(float amount) throws IllegalParameterException{
        if (amount < 0 || amount > 200) throw new IllegalParameterException("Illegal parameters");
        this.amount = amount;
    }
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){
        loggingService.addLog(fileName, "Brightness", Float.toString(amount));
        return BrightnessInterface.applyBrightness(image, amount);
    }
}