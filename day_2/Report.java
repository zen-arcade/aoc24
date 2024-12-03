package day_2;

import java.util.ArrayList;
import java.util.Collections;

public class Report {
    public ArrayList<Integer> levels;
    boolean ascending = false;
    boolean descending = false;

    public Report(int[] levels){
        this.levels = new ArrayList<Integer>(levels.length);
        for(int l : levels){
            this.levels.add(l);
        }
    }

    public Report(Report other){
        this.levels = new ArrayList<>(other.levels);
    }

    public boolean isSafe(){
        int diff;

        for(int i = 0; i < levels.size() - 1; i++){
            diff = Math.abs(levels.get(i) - levels.get(i + 1));
            if(diff < 1 || diff > 3){ 
                return false;
            } 
        }

        ArrayList<Integer> copy = new ArrayList<>(levels);
        Collections.sort(copy);
        if(levels.equals(copy)) ascending = true;
        Collections.reverse(copy);
        if(levels.equals(copy)) descending = true;

        return (ascending || descending);
    }

    public boolean isTolerated(){
        for(int i = 0; i < levels.size(); i++){
            Report newRep = new Report(this);
            newRep.levels.remove(i);
            if(newRep.isSafe()) return true;
        }
        return false;
    }
}
