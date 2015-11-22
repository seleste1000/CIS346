class InventoryItem #creates a class called InventoryItem
    
    private #private members
    
    @description #variable for the description
    @cost #variable for the cost
    @units #variable for the units
    
    public #public members
    
    #constructors
    def initialize() #default constructor that has no parameters
        @description = "" #sets the description to an empty string
        @cost = 0.0 #sets the cost to 0.0
        @units = 0 #sets the units to 0
    end #end of function
    
    def initialize(desc) #constructor that takes in a desc for description
        @description = desc #sets the parameter desc to @description
        @cost = 0.0 #sets the cost to 0.0
        @units = 0 #sets the units to 0
    end #end of function
    
    def initialize(desc, c, u) #constructor that takes in 3 parameters
        @description = desc #sets the parameter desc to description
        @cost = c #sets the parameter c to @cost
        @units = u #sets the parameter u to @units
    end #end of function
    
    def setDescription(d) #descirption mutator function
        @description = d #sets @description to the parameter d
    end #end of function
    
    def setCost(c) #cost mutator function
        @cost = c #sets @cost to the parameter c
    end #end of function
    
    def setUnits(u) #units mutator function
        @units = u #sets @units to u
    end #end of function
    
    def getDescription() #description accessor function
        return @description #returns the description
    end #end of function
    
    def getCost() #cost accessor function
        return @cost #returns the cost
    end #end of function
    
    def getUnits() #units accessor function
        return @units #returns the units
    end #end of function
end #end of class

class Register #creates a class called register
    
    private #private members
    
    @inventory = Array.new #creates an array that will hold the store's inventory
    @itemindex #holds the index of the item the code needs to reference
    @subtotal #holds the subtotal
    @tax #holds the tax
    @purchasetotal #holds the purchase total
    @order = Hash.new #creates a new hash that will hold the quantity of each product the user would like to buy
    
    public #public member functions
    
    def initialize() #constructor
        shirt = InventoryItem.new("shirt", 5.50, 10) #makes a new instance of the InventoryItem class for shirts
        pants = InventoryItem.new("pants", 12.50, 10) #makes a new instance of the InventoryItem class for pants
        skirt = InventoryItem.new("skirt", 15.50, 10) #makes a new instance of the InventoryItem class for skirts
        shoes = InventoryItem.new("shoes", 20.00, 10) #makes a new instance of the InventoryItem class for shoes
        @inventory = [shirt, pants, skirt, shoes] #puts those instances into an array
        @order = { 0 => 0, 1 => 0, 2 => 0, 3 => 0} #creates a hash that has the index of the item in the array as the key and the quantity that the user wants of that item as the value
    end #ends the constructor
    
    def itemquantity #starts the member function itemquantity
        
        @item #will hold tthe name of the item the user is asking for
        @itemindex #will hold the index of the item that the user wants
        @quantity #holds the quantity that the user wants, forced as an integer rather than a string
   
        
        puts "WELCOME TO OUR STORE!" #welcomes the user to the store
        loop do #starts a do while loop
            @found = false #sets found to false
            loop do #starts a do while loop
                puts "Currently we have" #displays what is in the store's inventory
                @inventory.each { |x| puts "#{x.getUnits()}  #{x.getDescription()}(s) in stock for a unit price of $#{('%.2f' % (x.getCost()))} each and a store price of $#{('%.2f' % (x.getCost()*1.3))}."} #uses each member function of the array to go trough each element of the array
                puts "Please enter the item from the inventory list that is in stock." #asks the user to enter which item they would like to purchase
                @item = gets.chomp #puts input into @item and chomps the end line character
                @item.downcase! #puts @item into lowercase
                @inventory.each_with_index do |x, index| #goes through each element of the array and holds x as the value and index as the index
              
              if (@item == x.getDescription()) #if the user defined @item is found as a description in one of the objects in the array
                  if (x.getUnits() != 0) #does not allow a user to input an item if it is out of stock
                      @found = true #makes found true to exit the do while loop
                      @itemindex = index #makes the index the itemindex
                  else
                    puts "\n Please only enter an item that is in stock. \n"
                  end #ends nested if statement
              end #ends if statement
            end #ends loop
                if (@found == false)
                    puts "\n Invalid input. Please enter an item in the inventory. \n \n"
                end
            break if @found == true #breaks the while loop to be a do while if the description was found
        end #ends do while loop
        
        puts "Please enter the quantity you would like of this item" #prompts the usr to enter a quantity
        @quantity = gets.chomp #quantity is held in @quantity
        while @quantity !~ /^[1-9]\d*$/ #if the usr input is anything other than a integer
            puts "input_data can't be 0 or a negative integer or in decimal format or alphanumeric. Please input another number" #prompts user for valid input
            @quantity = gets.chomp #allows them to re enter the quantity
        end #ends the while loop
        
        @quantity = @quantity.to_i #converts the quantity to an integer
        
        while @quantity > 10 || @quantity > @inventory[@itemindex].getUnits()  #while the user tried to buy more than 10 items or the a quantity higher than the number of items the store has
            puts "We do not have that many units in stock. \n Please enter a lower, positive quantity" #prompts user for a smaller number
            @quantity = gets.chomp #lets user re enter a quantity
               while @quantity !~ /^[1-9]\d*$/ do #if the usr input is anything other than a integer

               puts "The quantity cannot be 0 or a negative integer or in decimal format or alphanumeric. Please input another quantity." #asks user for a valid input
               @quantity = gets.chomp #holds the usr input in @quantity
               end #ends the while loop
               @quantity = @quantity.to_i #converts the user input to an integer
        end #ends the while loop
        
        @inventory[@itemindex].setUnits((@inventory[@itemindex].getUnits()-@quantity)) #updates the quantity of the item in the inventory
      
      @order[@itemindex] += @quantity #adds the quantity to the value of the index key in the hash order
      puts "You ordered #{@order[@itemindex]} of #{@inventory[@itemindex].getDescription()} for a subtotal of $#{'%.2f' % ((@inventory[@itemindex].getCost()*1.3) * (@order[@itemindex])) }"
      
      puts "Would you like to purchase another item?(yes or no)" #asks if the user would like to get more items
               @ans = gets.chomp #user input
               while @ans != "yes" && @ans != "no" #if they user did not say yes or no
               puts "Please only enter either yes or no (lowercase)" #prompts the usr for a valid input
               @ans = gets.chomp #user input
               end #ends the while loop
        break if @ans == "no" #condition for the do while loop
        end #ends do while loop
      
    end #ends member function
    
               
               
               
    def subtotal1 #creates member function subtotal
               @subtotal = 0 #makes subtotal = 0
        @inventory.each_with_index do |x, index| #loops through each element in the array and holds the value in x and the index in index
               if (@order[index] != 0) #if the value of the key, index, is 0 or if the user wants to purchase that item
               @subtotal += (@inventory[index].getCost() * 1.3)*(@order[index]) #adds the price which is the cost *1.3 of the number of items specified to the subtotal
               end #ends if statement
        end #ends loop
               @subtotal = @subtotal.round(2) #rounds the subtotal to 2 decimal palces
        @tax = @subtotal * 0.06 #calculates the tax
        @tax = @tax.round(2) #rounds the tax to 2 decimal palces
        @purchasetotal = @tax + @subtotal #calculates the purchase total
        @purchasetotal = @purchasetotal.round(2) #rounds the purchase to 2 decimal palces
    end #ends member function
    
               
               
               
    def display #creates a member function called display
            puts "\n You purchase included: " #starts to display what the user wanted to purchase
            @inventory.each_with_index do |x, index| #goes through each element in the array and holds the value in x and the index in index
               if (@order[index] != 0) #if the user would like to purchase 1 or more of the iems
               puts "#{@order[index]} #{@inventory[index].getDescription()}(s) \n" #prints the number of each item the user asked to purchase
               end #ends if statement
            end #ends loop
               
               
        puts "Subtotal: $#{'%.2f' %@subtotal}" #prints the subtotal
        puts "6% Tax: $#{'%.2f' %@tax}" #prints the taxes
        puts "Purchase Total(Subtotal + Tax): $#{'%.2f' %@purchasetotal}" #prints the purchase total
        #clears the hash
        @order[0] = 0 #sets the quantity to 0 for the first index
        @order[1] = 0 #sets the quantity to 0 for the second index
        @order[2] = 0 #sets the quantity to 0 for the third index
        @order[3] = 0 #sets the quantity to 0 for the fourth index
    end #ends member function
               
end #ends class








#main function
    @response #creates a variable that will hold the response
    reg = Register.new() #creates an instance of the class Regiser
    loop do #starts do while loop
               reg.itemquantity #calls the method itemquantity of the reg object
               reg.subtotal1 #calls the method subtotal1 of the reg object
               reg.display #calls the method display of the reg object
               puts "Would you like to start a new order?" #asks the user if they would like a new order
               @response = gets.chomp #puts the user input in @reponse
               while @response != "yes" && @response != "no" #if the @reponse is not yes or no
               puts "Please only enter either yes or no" #prompts the user for a valid input
               @response = gets.chomp #allows the user to re enter
               end #ends the while loop
    break if @response == "no" #condition to end the do while looop
    end #ends do while loop



