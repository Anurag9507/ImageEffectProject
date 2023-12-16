package com.iiitb.imageEffectApplication.service;
import com.iiitb.imageEffectApplication.model.LogModel;
import org.springframework.stereotype.Service;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;

@Service
public class LoggingService {

    public void addLog(String fileName, String effectName, String optionValues) {
        LocalDateTime localDateTime = LocalDateTime.now();
        String currentTime = localDateTime.toString();
        try{
            FileWriter fileWriter = new FileWriter("logfile.txt", true);
            BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
            bufferedWriter.write(fileName + " / " + effectName + " / " + optionValues + " / " + currentTime);
            bufferedWriter.newLine();
            bufferedWriter.close();
            fileWriter.close();
        }
        catch (IOException e){
            e.printStackTrace();
        }
    }

    public List<LogModel> getAllLogs() {
        List<LogModel> allLogs = new ArrayList<LogModel>();
        try{
            File logFile = new File("logfile.txt");
            FileReader fileReader = new FileReader(logFile);
            BufferedReader bufferedReader = new BufferedReader(fileReader);
            String line;
            while ((line = bufferedReader.readLine()) != null){
                String sp[] = line.split(" / ");
                String fileName = sp[0];
                String effectName = sp[1];
                String optionValues = sp[2];
                String timestamp = sp[3];
                LogModel logModel = new LogModel(timestamp, fileName, effectName, optionValues);
                allLogs.add(logModel);
            }
            bufferedReader.close();
        }
        catch (IOException e){
            e.printStackTrace();
        }
        return allLogs;
    }

    public List<LogModel> getLogsByEffect(String effectName) {
        List<LogModel> logsByEffect = new ArrayList<LogModel>();
        try{
            File logFile = new File("logfile.txt");
            FileReader fileReader = new FileReader(logFile);
            BufferedReader bufferedReader = new BufferedReader(fileReader);
            String line;
            while ((line = bufferedReader.readLine()) != null){
                String sp[] = line.split(" / ");
                String fileName = sp[0];
                String effect = sp[1];
                String optionValues = sp[2];
                String timestamp = sp[3];
                if (effect.equalsIgnoreCase(effectName)){
                    LogModel logModel = new LogModel(timestamp, fileName, effect, optionValues);
                    logsByEffect.add(logModel);
                }
            }
            bufferedReader.close();
        }
        catch (IOException e){
            e.printStackTrace();
        }
        return logsByEffect;
    }

    public void clearLogs() {
        try{
            new FileWriter("logfile.txt", false).close();
        }
        catch (IOException e){
            e.printStackTrace();
        }
    }

    public List<LogModel> getLogsBetweenTimestamps(LocalDateTime startTime, LocalDateTime endTime) {
        List<LogModel> logsBetweenTimestamps= new ArrayList<LogModel>();
        try{
            File logFile = new File("logfile.txt");
            FileReader fileReader = new FileReader(logFile);
            BufferedReader bufferedReader = new BufferedReader(fileReader);
            String line;
            while ((line = bufferedReader.readLine()) != null){
                String sp[] = line.split(" / ");
                String fileName = sp[0];
                String effectName = sp[1];
                String optionValues = sp[2];
                String timestamp = sp[3];
                LocalDateTime effectTimeStamp = LocalDateTime.parse(timestamp);
                if (effectTimeStamp.isAfter(startTime) && effectTimeStamp.isBefore(endTime)){
                    LogModel logModel = new LogModel(timestamp, fileName, effectName, optionValues);
                    logsBetweenTimestamps.add(logModel);
                }
            }
            bufferedReader.close();
        }
        catch (IOException e){
            e.printStackTrace();
        }
        return logsBetweenTimestamps;
    }
}