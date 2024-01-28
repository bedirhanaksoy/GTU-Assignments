
import java.util.ArrayList;                             // import java.util.ArrayList for using array list
import java.util.List;
class Viewer implements Observer {
    private List<NonPlayable> viewList;
    private NonPlayable currentObject;

    public Viewer() {
        viewList = new ArrayList<>();
    }

    public void update(DatasetObject object,char a) {
        if (object instanceof NonPlayable) {
            if(a=='a') viewList.add((NonPlayable) object);
            else viewList.remove((NonPlayable)object);
        }
    }

    public void showViewList() {
        for (NonPlayable object : viewList) {
            object.info();
        }
    }

    public NonPlayable currentlyViewing() {
        return currentObject;
    }

    public void viewNext(String type) {
        int currentIndex = viewList.indexOf(currentObject);
        int nextIndex = getNextIndex(currentIndex, type, viewList.size());
        if (nextIndex != -1) {
            currentObject = viewList.get(nextIndex);
            currentObject.view();
        }
    }

    public void viewPrevious(String type) {
        int currentIndex = viewList.indexOf(currentObject);
        int previousIndex = getPreviousIndex(currentIndex, type, viewList.size());
        if (previousIndex != -1) {
            currentObject = viewList.get(previousIndex);
            currentObject.view();
        }
    }

    private int getNextIndex(int currentIndex, String type, int viewListSize) {
        int nextIndex = currentIndex;
        while (true) {
            nextIndex = (nextIndex + 1) % viewListSize;
            NonPlayable nextObject = viewList.get(nextIndex);
            if (isTypeMatch(nextObject, type)) {
                return nextIndex;
            }
            if (nextIndex == currentIndex) {
                return -1; 
            }
        }
    }

    private int getPreviousIndex(int currentIndex, String type, int viewListSize) {
        int previousIndex = currentIndex;
        while (true) {
            previousIndex = (previousIndex - 1 + viewListSize) % viewListSize;
            NonPlayable previousObject = viewList.get(previousIndex);
            if (isTypeMatch(previousObject, type)) {
                return previousIndex;
            }
            if (previousIndex == currentIndex) {
                return -1; 
            }
        }
    }

    private boolean isTypeMatch(NonPlayable object, String type) {
        if (type.equalsIgnoreCase("text")) {
            return object instanceof Text;
        } else if (type.equalsIgnoreCase("image")) {
            return object instanceof Image;
        } else {
            return false;
        }
    }
}