import java.util.*;

//Katie Morales
// Programming Paradigms Final
public class FinalExam {
    public String convert(Map<String,List<String>> tree, String root){
         // recursive case... return string: "child parent child"
         if (tree.get(root).size() > 0) {
            // get children 
            String a = convert(tree,tree.get(root).get(0));
            String b = convert(tree,tree.get(root).get(1));
            // get parent (the operation)
            String [] name= root.split("_");
            String operand = name[1]; 
            // return the string
            return a + operand + b;
         }

         // base case, return number (leaf of tree)
         String [] name = root.split("_");
         String number = name[1]; 
         return number;
    } 
    public static void main (String [] args){
        FinalExam conversion = new FinalExam();

        // test 1: "2*7+3"
        /*Map<String, List<String>> tree = new HashMap<>();
        tree.put("n1_+", Arrays.asList("n2_*","n3_3"));
        tree.put("n2_*", Arrays.asList("n4_2","n5_7"));
        tree.put("n4_2", Arrays.asList());
        tree.put("n5_7", Arrays.asList());
        tree.put("n3_3", Arrays.asList());
        String root = "n1_+";*/
        
        // test 2: 3+10/5*2
        /*Map<String, List<String>> tree = new HashMap<>();
        tree.put("n1_+", Arrays.asList("n2_3","n3_*"));
        tree.put("n3_*", Arrays.asList("n4_/","n5_2"));
        tree.put("n4_/", Arrays.asList("n6_10","n7_5"));
        tree.put("n6_10", Arrays.asList());
        tree.put("n7_5", Arrays.asList());
        tree.put("n5_2", Arrays.asList());
        tree.put("n2_3", Arrays.asList());
        String root = "n1_+";*/

        //test3: 2+3
        /*Map<String, List<String>> tree = new HashMap<>();
        tree.put("n1_+", Arrays.asList("n2_2","n3_3"));
        tree.put("n2_2", Arrays.asList());
        tree.put("n3_3", Arrays.asList());
        String root = "n1_+";*/

        // test 4: 2-30*1
        /*Map<String, List<String>> tree = new HashMap<>();
        tree.put("n1_*", Arrays.asList("n2_-","n3_1"));
        tree.put("n2_-", Arrays.asList("n4_2","n25_30"));
        tree.put("n3_1", Arrays.asList());
        tree.put("n4_2", Arrays.asList());
        tree.put("n25_30", Arrays.asList());
        String root = "n1_*";*/

        //System.out.println(conversion.convert(tree,root));
    }
}