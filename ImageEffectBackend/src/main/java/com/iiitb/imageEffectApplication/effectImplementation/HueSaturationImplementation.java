package com.iiitb.imageEffectApplication.effectImplementation;
import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
import com.iiitb.imageEffectApplication.libraryInterfaces.HueSaturationInterface;
import com.iiitb.imageEffectApplication.baseEffects.ParameterizableEffect;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.service.LoggingService;

public class HueSaturationImplementation implements ParameterizableEffect{
    private float hv,sv;
    public void setParameter(String s, float v) throws IllegalParameterException{
        if (v<0 || v>100) throw new IllegalParameterException("Illegal parameters");
        if(s.equals("H")) this.hv = v;
        else this.sv = v;
    }
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){
        String s = "Hue = " + Float.toString(hv) + " , Saturation = " + Float.toString(sv);
        loggingService.addLog(fileName,"Hue Saturation",s);
        return HueSaturationInterface.applyHueSaturation(image,hv,sv);
    }
}