
class Video extends DatasetObject implements Playable,Visual {                  
    private String duration;                                                   

    public Video(String name, String duration, String otherInfo) {              
        super(name, otherInfo);                                                 // calls parent classes constructor with name and other info
        this.duration = duration;                                               // sets duration
    }

    public void play() {
        System.out.println("Playing video: " + getName());
    }

    public void info() {
        System.out.println("Video: " + getName() + ", Duration: " + duration + ", Info: " + getOtherInfo());
    }

    public void display() {
        System.out.println("Displaying Video: " + getName());
        // Display the video
    }
}


