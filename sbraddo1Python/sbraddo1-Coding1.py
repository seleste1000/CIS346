key = {'a':'n', 'b':'o', 'c':'p', 'd':'q', 'e':'r', 'f':'s', 'g':'t', 'h':'u', 'i':'v', 'j':'w', 'k':'x', 'l':'y', 'm':'z', 'n':'a', 'o':'b', 'p':'c', 'q':'d', 'r':'e', 's':'f', 't':'g', 'u':'h', 'v':'i', 'w':'j', 'x':'k','y':'l', 'z':'m', 'A':'N', 'B':'O', 'C':'P', 'D':'Q', 'E':'R', 'F':'S','G':'T', 'H':'U', 'I':'V', 'J':'W', 'K':'X', 'L':'Y', 'M':'Z', 'N':'A', 'O':'B', 'P':'C', 'Q':'D', 'R':'E', 'S':'F', 'T':'G', 'U':'H', 'V':'I', 'W':'J', 'X':'K', 'Y':'L', 'Z':'M'}


#Implement an encoder/decoder of ROT-13
def ROT_13Cipher():

    #Repeat the function using a while loop so that it won't need to be called
    #multiple times in one sitting

    #While the repeatFunction variable is true, the while loop will continue
    repeatFunction = True

    while (repeatFunction == True): #repeats until user indicates that they want the function to end

        #take in text to be encoded or decoded
        user_input = raw_input("Enter the text to be encoded or decoded: ")

        new_text = ""   #will eventually hold encoded/decoded text

        #decode or encode each letter in the user defined string:

        #loop through string using while loop

        i = 0   #initial value condition for while loop

        string_length = len(user_input)    #find length of the user defined string
        #use length of string as a limiter in while loop

        while ( i < string_length ):
            #use indices to move through string
            #at each index:
            #save character in a temp variable
            temp = user_input[i]
            #check to make sure character is a letter
            #if the character isn't a letter it won't be in the dictionary
            if (temp.isalpha()):
                #letters will be in the dictionary so to encode you have to find the matching key-value pair
                #to find matching character as key in dictionary:
                #loop through each entry in the dictionary using for loop
                for char in key:
                    #if the temp character matches the current key of the current entry
                    if temp == char:
                        #encode/decode the character using the value of the current entry
                        #replace temp variable with the value of the entry (key[char])
                        temp = key[char]
                        #append the encoded/decoded character to encoded/decoded string
                        new_text += temp
                        #increment i to go to the next letter
                        i += 1  #increment the counter
                        #exit the for loop
                        break

            else:   #when the character isn't a letter then just append it to the string with no changes
                new_text += temp
                i += 1  #increment the counter

        #display the encoded/decoded text
        print "The new text is : \n"+new_text

        #ask the user if they want to repeat the program
        toRepeat = raw_input("Do you want to use the cipher again? (y/n)")
        if (toRepeat.lower() == 'y'):
            #repeatFunction is set to True so while loop continues
            repeatFunction = True
        elif (toRepeat.lower() == 'n'):
            #repeatFunction is set to False so while loop ends
            repeatFunction = False
        else:
            #repeatFunction is set to False so while loop ends
            print "I didn't understand your input. The program will exit"
            repeatFunction = False

    #return the decoded/encoded text
    return new_text

ROT_13Cipher()
