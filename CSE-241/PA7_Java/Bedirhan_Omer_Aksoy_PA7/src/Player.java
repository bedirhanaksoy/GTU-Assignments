import java.util.ArrayList;                             // import java.util.ArrayList for using array list
import java.util.List;
class Player implements Observer {                                          // Player class that observes playable objects
    private List<Playable> playlist;                                        // list of playable objects
    private Playable currentObject;                                         // current playing playable object

    public Player() {
        playlist = new ArrayList<>();                                       // default constructor creates 
    }

    public void update(DatasetObject object,char a) {                              // if received object is playable type, adds object to playlist 
        if (object instanceof Playable) {
            if(a=='a')  playlist.add((Playable) object);
            else playlist.remove((Playable)object);
        }
    }

    public void showPlaylist() {                                            // shows playlist of playable objects
        for (Playable object : playlist) {
            object.info();
        }
    }

    public Playable currentlyPlaying() {                                    // returns current playing object
        return currentObject;
    }

    public void playNext(String type) {                                    
        int currentIndex = playlist.indexOf(currentObject);                 // current objects index
        int nextIndex = getNextIndex(currentIndex, type, playlist.size());  // returns next same type objects index
        if (nextIndex != -1) {                                              // if next index is -1, it means there is no object of the given type found in the playlist, else next index is found
            currentObject = playlist.get(nextIndex);                        // sets current object to next object of given type in list 
            currentObject.play();                                           // plays object
        }
    }

    public void playPrevious(String type) {                                 
        int currentIndex = playlist.indexOf(currentObject);                             // current objects index
        int previousIndex = getPreviousIndex(currentIndex, type, playlist.size());      // returns previous same type objects index
        if (previousIndex != -1) {                                                      // if next index is -1, it means there is no object of the given type found in the playlist, else next index is found
            currentObject = playlist.get(previousIndex);                                // sets current object to previous same type object in list
            currentObject.play();                                                       // plays object
        }
    }

    private int getNextIndex(int currentIndex, String type, int playlistSize) {
        int nextIndex = currentIndex;
        while (true) {
            nextIndex = (nextIndex + 1) % playlistSize;                                 // (current index + 1) % playlistsize makes index to stay in bounds 
            Playable nextObject = playlist.get(nextIndex);                              // creates playable object and assigns next object in list into it
            if (isTypeMatch(nextObject, type)) {                                        // if type matches, returns index
                return nextIndex;
            }
            if (nextIndex == currentIndex) {                                            // if loop refinds the same object again, it means there isnt any object of given type found in the playlist
                return -1;
            }
        }
    }

    private int getPreviousIndex(int currentIndex, String type, int playlistSize) {     // returns previous index of given type
        int previousIndex = currentIndex;
        while (true) {
            previousIndex = (previousIndex - 1 + playlistSize) % playlistSize;
            Playable previousObject = playlist.get(previousIndex);
            if (isTypeMatch(previousObject, type)) {
                return previousIndex;
            }
            if (previousIndex == currentIndex) {
                return -1; 
            }
        }
    }

    private boolean isTypeMatch(Playable object, String type) {                         // checks if type matches between given inputs
        if (type.equalsIgnoreCase("audio")) {                             // if type is audio
            return object instanceof Audio;                                             // returns if object is audio as well or not
        } else if (type.equalsIgnoreCase("video")) {
            return object instanceof Video;
        } else {
            return false;
        }
    }
}
