import java.util.ArrayList;                             // import java.util.ArrayList for using array list
import java.util.List;

interface Observer {                                                                // Observer interface 
    void update(DatasetObject object, char a);                                              // updates database object
}
class Dataset {                                                             // Dataset class
    private List<DatasetObject> objects;                                    // includes list of dataset objects
    private List<Observer> observers;                                       // includes list of observers

    public Dataset() {                                                      // default constructor creates empty array lists of objects and observers
        objects = new ArrayList<>();
        observers = new ArrayList<>();
    }

    public void register(Observer observer) {                               // adds new observers to observers array list          
        observers.add(observer);
    }

    public void remove(Observer observer) {                                 // removes observer from observers array list
        observers.remove(observer);
        System.out.println("Observer removed\n");

    }

    public void add(DatasetObject object) {                                 // adds dataset objects to objects array list
        objects.add(object);
        notifyObservers(object,'a');                                            // notifies related observers about new added object
    }

    public void remove(Playable object) {                                   // removes playable type objects
        objects.remove((DatasetObject)object);
        System.out.println("Playable object removed\n");
        notifyPlayableObservers(object,'r');
    }
    private void notifyPlayableObservers(Playable object,char a) {          // notifies player observers
        for (Observer observer : observers) {
            if (observer instanceof Player) {
                observer.update((DatasetObject) object,a);
            }
        }
    }
    public void remove(NonPlayable object) {                                // removes nonplayable objects
        objects.remove((DatasetObject)object);
        System.out.println("NonPayable object removed\n");
        notifyNonPlayableObservers(object,'r');
    }
    private void notifyNonPlayableObservers(NonPlayable object,char a) {    // notifies viewer observers
        for (Observer observer : observers) {
            if (observer instanceof Viewer) {
                observer.update((DatasetObject) object,a);
            }
        }
    }
    
    public void remove(DatasetObject object) {
        objects.remove(object);
        notifyObservers(object,'r');
    }
    
    private void notifyObservers(DatasetObject object,char a) {                    // updates observers about changings in dataset 
        for (Observer observer : observers) {
            observer.update(object,a);
        }
    }

    public void next(String type){

    }
}