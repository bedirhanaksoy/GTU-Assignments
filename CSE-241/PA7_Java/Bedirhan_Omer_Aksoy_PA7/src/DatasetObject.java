class DatasetObject {                                           // Base class for all objects
    private String name;                                        // name of object 
    private String otherInfo;                                   // other info of object

    public DatasetObject(String name, String otherInfo) {       // constructor with name and info
        this.name = name;
        this.otherInfo = otherInfo;
    }

    public String getName() {                                   // returns name
        return name;
    }

    public String getOtherInfo() {                              // returns other info
        return otherInfo;
    }
}
