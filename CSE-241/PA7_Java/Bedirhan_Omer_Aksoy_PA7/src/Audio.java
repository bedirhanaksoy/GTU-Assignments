class Audio extends DatasetObject implements Playable,NonVisual {               // Derived class for Audio type and implemens playable and nonvisual interfaces
    private String duration;                                                    // duration info for audio 

    public Audio(String name, String duration, String otherInfo) {              // constructor with name, duration and other info
        super(name, otherInfo);                                                 // calls parent classes constructor with name and other info
        this.duration = duration;                                               // sets duration
    }

    public void play() {
        System.out.println("Playing audio: " + getName());                      // prints audio's name to console
    }

    public void info() {                                                        // prints name, duration and other info
        System.out.println("Audio: " + getName() + ", Duration: " + duration + ", Info: " + getOtherInfo());
    }

    public void show() {                                                        // does the same thing with play
        System.out.println("Playing Audio: " + getName());
    }
}
