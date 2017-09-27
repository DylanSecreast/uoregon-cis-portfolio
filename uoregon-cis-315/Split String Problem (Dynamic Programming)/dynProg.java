import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.ArrayList;

/**
 * Dylan Secreast
 * 3/2/16
 *
 * Takes standard input:
 * java dynProg < inMed.txt
 */

public class dynProg {
    public static Set<String> dictionary = new HashSet<>();
    public static ArrayList<String> fileToTest = new ArrayList<String>();
    public static HashSet<String> memoization = new HashSet<String>();
    public static String splitString = "";

    public static void loadDictionary(String dictionaryFileName) {
        File dictFile = new File(dictionaryFileName);
        try {
            Scanner scan = new Scanner(dictFile);
            String line;
            while (scan.hasNext()) {
                line = scan.next();
                dictionary.add(line.trim());
            }
            scan.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }   // end loadDictionary()

    public static void loadInFile(Scanner in) {
        try {
            String line;
            while (in.hasNext()) {
                line = in.next();
                fileToTest.add(line.trim());
            }
            in.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }   // end loadInFile()

    public static boolean iterativeSplit(String s, String restructure) {
      splitString = "";

      if (s.length() == 0) {
        splitString = restructure;
        return true;
      }
      else {
        int index = 0;
        String word = "";
        while (index < s.length()) {
          word += s.charAt(index);
          if (dictionary.contains(word)) {
            if (iterativeSplit(s.substring(index+1), restructure + word + " ")) {
              return true;
            }
            else {
              index++;
            }
          }
          else {
            index++;
          }
        }
      }
      return false;
    }   // end iterativeSplit()

    public static boolean memoizedSplit(String s, HashSet<String> memory, String restructure) {
        if (s.length() == 0) {
          splitString = restructure;
          return true;
        }
        else if (memory.contains(s)) {
          return false;
        }
        else {
          int index = 0;
          String word = "";
          while (index < s.length()) {
            word += s.charAt(index);
            if (dictionary.contains(word)) {
              if (memoizedSplit(s.substring(index + 1), memory, restructure + word + " ")) {
                return true;
              }
              else {
                index++;
              }
            }
            else {
              index++;
            }
          }
          memory.add(s);
          return false;
        }
    }


    public static void main(String[] args) {
        Scanner file = new Scanner(System.in);
        loadInFile(file);
        loadDictionary("diction10k.txt");

        for (int i = 0; i < fileToTest.size(); i++) {
          System.out.println("----------------------------");

          System.out.println("Phrase Number: " + (i+1));
          System.out.println(fileToTest.get(i) + "\n");

          System.out.println("Iterative Attempt:");
          System.out.println(iterativeSplit(fileToTest.get(i),"") ? "YES, can be split\n" + splitString + "\n" : "NO, cannot be split\n");

          System.out.println("Memoized Attempt:");
          System.out.println(memoizedSplit(fileToTest.get(i), memoization, "") ? "YES, can be split\n" + splitString : "NO, cannot be split");
        }

    }   // end main()

}   // end class dynProg
