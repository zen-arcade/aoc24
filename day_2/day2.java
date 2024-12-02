package day_2;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class day2 {
    public static void main(String[] args) throws Exception{
        int safe = 0;
        String line = "";
        List<String> vals;
        ArrayList<Report> reports = new ArrayList<>();
        BufferedReader br = new BufferedReader(new FileReader("./day_2/data.txt"));

        while((line = br.readLine()) != null){
            vals = Arrays.asList(line.split(" "));
            reports.add(new Report(vals.stream().mapToInt(s -> Integer.parseInt(s)).toArray()));
        }

        for(Report r : reports){
            if(r.isSafe()) safe++;
        }
        
        System.out.println("number of safe reports: " + safe);
    }
}
