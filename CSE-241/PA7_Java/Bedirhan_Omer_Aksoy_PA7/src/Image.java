class Image extends DatasetObject implements NonPlayable,Visual {               // Derived class for Image type and inplements nonplayable and visual interfaces
    private String dimensionInfo;                                               // dimension info for image

    public Image(String name, String dimensionInfo, String otherInfo) {         // constructor with name, dimension info and other info
        super(name, otherInfo);                                                 // calls parent classes constructor with name and other info
        this.dimensionInfo = dimensionInfo;                                     // sets dimension info
    }

    public void view() {                                                        // prints name of the image to console
        System.out.println("Viewing image: " + getName());
    }

    public void info() {                                                        // prints name, dimension info and other info to console
        System.out.println("Image: " + getName() + ", Dimensions: " + dimensionInfo + ", Info: " + getOtherInfo());
    }

    public void display() {                                                     // does the same thing with view function
        System.out.println("Displaying Image: " + getName());
    }

}