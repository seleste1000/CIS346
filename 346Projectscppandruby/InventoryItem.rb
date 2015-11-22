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

