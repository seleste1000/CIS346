import java.util.Arrays;
import java.util.Scanner;
import java.util.ArrayList;



class IntegerLists {
    
    public static void main(String args[]) {
        //System.out.println("Hello world!");
        boolean runAgain = false;
        do { //loop continues until user decides to leave
            
            System.out.println("Enter a list of non-negative integers separated by a dash (-) character."); //prompt user for input
            
            Scanner in = new Scanner(System.in); //create an instance of Scanner class
            
            String userInput = in.nextLine(); //get user input and store in a string
            
            String[] stritems = userInput.split("-"); //splits string at - and stores in a string array
            
            Integer[] intitems = new Integer[stritems.length]; //creates an integer array with the same length as the string array
            
            int i = 0; //counter for for-loop
            boolean validArray = true;
            
            for (i = 0; i < intitems.length; i++) { //for loop to go through each index of the string array and check for valid items
                
                String alldigits = "\\d+"; //contains one or more digits (and nothing else)
                
                if (stritems[i].matches(alldigits)) { //checks whether current item is an integer by matching the string to the alldigits property
                    
                    Integer n = new Integer(stritems[i]); //converts the current string to an integer and
                    intitems[i] = n; //
                    //intitems[i] = Integer.parseInt(stritems[i]);
                    
                } else { //if the current index isn't an integer
                    
                    System.out.println("The string you entered isn't valid."); //error message
                    validArray = false;
                    break; //exit the for loop
                    
                } //end if-else statement
                
            } //end for-loop
            
            //if (i == intitems.length) { //if the counter got to the end of the array (the for loop didn't break early)
            if (validArray) { //the user input a valid list of integers
                
                //validArray = true; //the user input a valid list of integers
                
                System.out.println("Your input was valid");
                
                System.out.println("Here are the numbers you entered:");
                
                for (int m: intitems) { //loops through each int in intitems
                
                    System.out.println(m); //prints the current number
                
                } //end for loop
                
                checkSeq(intitems); //calling function to check if the integers were in a valid sequence
                
                checkPairs(intitems); //calling function to check if the array contains any duplicates
            
            } else { //the user's input was invalid
                //validArray = false
                //System.out.println("Your input was invalid."); //error message
            }
            
            
            System.out.println("Do you want to test another sequence? Enter y/n");
            
            boolean invalidEntry = false;
            do{
                
                String goAgain = in.nextLine();
                
                if (goAgain.matches("y")) {
                    //run again
                    invalidEntry = false;
                    runAgain = true;
                } else if (goAgain.matches("n")) {
                    //leave
                    invalidEntry = false;
                    runAgain = false;
                } else { //if the input is invalid
                    System.out.println("Your input was invalid. Please enter only 'y' or 'n' and try again");
                    invalidEntry = true;
                }
                
            }while(invalidEntry);
            
        }while(runAgain);
        
        return;
        
    } //end main
    
    public static boolean checkSeq(Integer[] intarray){ //check for correct sequence
        
        int i=0;
        
        for (i=0; i < intarray.length - 1 ; i++ ){
        
            if (intarray[i+1] != intarray[i]+1) { //checks to see if the next number in the array is equal to the next consecutive value from the current index
                
                System.out.println("This was not a consecutive sequence."); //error message
                
                return false; //the list is not consecutive so the function returns false
            
            } else { //if the list is consecutive so far
                //don't do anything
            
            }//end if-else statement
        
        }//end for loop
        
        System.out.println("This was a consecutive sequence!");
        
        return true; //this was a consecutive sequence
    
    } //end checkSeq function
    
    
    
   public static boolean checkPairs(Integer[] intarray){ //check for correct sequence
       
        //System.out.println("Inside checkPairs function..."); //testing
       
        ArrayList<Integer> dupes = new ArrayList<Integer>(); //creates a list of variable length
        //System.out.println("dupes was created!"); //testing
       
        for (int i = 0; i < intarray.length; i++){ //goes through each element of the integer array
        
            int m = intarray[i]; //stores the value at the current index in a temp var
            
            //System.out.println("Current index's item: "+m); //testing
            
            int k = i+1; //index counter for while loop
            
            while (k < intarray.length) { //loops through the rest of the array
            
                if (m == intarray[k]){ //if m is = to any other value in the array
                
                    //System.out.println("Duplicate found" ); //testing
                    
                    if (dupes.contains(m)){ //if the number is already accounted for
                        //System.out.println("m is already in dupes"); //testing

                        //don't put it there again
                    
                    } else { //if the number hasn't been added to the array
                   
                        //System.out.println("Adding "+m+" to the dupes array"); //testing
                        
                        dupes.add(m); //add the integer to the array

                    }
                
                } else {
                
                    //dont do anything
                
                } //end if else statement
                
                k++; //increment the counter
            
            } //end while loop
        
        } //end for loop
        
        if (dupes.size() != 0){ //there are duplicates
            
            System.out.println("Listed below are the duplicates: ");
        
            for (int p: dupes){ //loop through each element
            
                System.out.println(p); //display each duplicate
            
            } //end for loop
           
            return true; //there are duplicates
        
        } else {
            
            System.out.println("There were no duplicates in this sequence.");
        
            return false; //there arent an duplicates
        
        } //end if-else statement
    
    } //end checkPairs function
    
    
    
} //end IntegerLists class

