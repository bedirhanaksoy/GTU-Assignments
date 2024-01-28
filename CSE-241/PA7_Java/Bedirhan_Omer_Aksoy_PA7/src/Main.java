interface Playable {                                    //Interface for playable object
    void play();
    void info();
}

interface NonPlayable {                                 // Interface for non-playable objects
    void view();
    void info();
}

interface Visual {                                      // Interface for visual objects
    void display();
}

interface NonVisual {                                   // Interface for NonVisual objects
    void show();
}

class Main {
    public static void main(String[] args) {
        Dataset ds = new Dataset();

        Player p1 = new Player();
        Player p2 = new Player();
        Viewer v1 = new Viewer();
        Viewer v2 = new Viewer();

        ds.register(p1);
        ds.register(p2);
        ds.register(v1);
        ds.register(v2);

        ds.add(new Image("imagename1", "dimension info1", "other info1"));
        ds.add(new Image("imagename2", "dimension info2", "other info2"));
        ds.add(new Image("imagename3", "dimension info3", "other info3"));
        ds.add(new Image("imagename4", "dimension info4", "other info4"));
        ds.add(new Image("imagename5", "dimension info5", "other info5"));

        ds.add(new Audio("audioname1", "duration1", "other info1"));
        ds.add(new Audio("audioname2", "duration2", "other info2"));
        ds.add(new Audio("audioname3", "duration3", "other info3"));

        ds.add(new Video("videoname1", "duration1", "other info1"));
        ds.add(new Video("videoname2", "duration2", "other info2"));
        ds.add(new Video("videoname3", "duration3", "other info3"));

        ds.add(new Text("textname1", "other info1"));
        ds.add(new Text("textname2", "other info2"));
        ds.add(new Text("textname3", "other info3"));

        p1.playNext("video");

        Playable po = p1.currentlyPlaying();
        po.info();
        ds.remove(p1);
        System.out.println("\n");

        v1.viewNext("image");

        NonPlayable np = v1.currentlyViewing();
        np.info(); 
        ds.remove(np);
        ds.add(new Text("textname56", "other info56"));

        v1.viewNext("image");
        v1.viewNext("image");
        v1.viewNext("image");
        v1.viewPrevious("image");
        v1.viewNext("image");
        v1.viewNext("text");

        System.out.println("\n");

        v1.showViewList();

        System.out.println("\n");


        ds.add(new Video("videoname45", "duration45", "other info45"));
        p1.showPlaylist();
        System.out.println("\n");

        p1.playNext("video");
        p1.playNext("video");
        p1.playNext("video");

        System.out.println("\n");

       
    }
}


