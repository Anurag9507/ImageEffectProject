package com.iiitb.imageEffectApplication.effectImplementation;
import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
import com.iiitb.imageEffectApplication.libraryInterfaces.FlipInterface;
import com.iiitb.imageEffectApplication.baseEffects.DiscreteEffect;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.service.LoggingService;

public class FlipImplementation implements DiscreteEffect{
    private int hf,vf;
    public void selectOptionValue(String s, int v) throws IllegalParameterException{
        if (v<0 || v>1) throw new IllegalParameterException("Illegal parameters");
        if(s.equals("H")) this.hf = v;
        else this.vf = v;
    }
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){
        String s="";
        if(hf!=0) s = "Horizontal";
        if(vf!=0) s = "Vertical";
        if(hf!=0 && vf!=0) s = "Horizontal + Vertical";
        loggingService.addLog(fileName,"Flip",s);
        return FlipInterface.applyFlip(image,hf,vf);
    }
}