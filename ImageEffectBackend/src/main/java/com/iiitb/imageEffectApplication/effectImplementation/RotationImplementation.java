package com.iiitb.imageEffectApplication.effectImplementation;
import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
import com.iiitb.imageEffectApplication.libraryInterfaces.RotationInterface;
import com.iiitb.imageEffectApplication.baseEffects.SingleValueDiscreteEffect;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.service.LoggingService;

public class RotationImplementation implements SingleValueDiscreteEffect{
    private int v;
    public void setParameterValue(int v) throws IllegalParameterException{
        if (v<0 || v>3) throw new IllegalParameterException("Illegal parameters");
        this.v = v;
    }
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){
        loggingService.addLog(fileName,"Rotation", Integer.toString(v*90));
        return RotationInterface.applyRotation(image,v);
    }
}
