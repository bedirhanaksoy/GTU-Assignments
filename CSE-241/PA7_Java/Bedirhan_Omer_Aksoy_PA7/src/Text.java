class Text extends DatasetObject implements NonPlayable,NonVisual {
    public Text(String name, String otherInfo) {
        super(name, otherInfo);
    }

    public void view() {
        System.out.println("Viewing text: " + getName());
    }

    public void info() {
        System.out.println("Text: " + getName() + ", Info: " + getOtherInfo());
    }

    public void show() {
        System.out.println("Showing Text: " + getName());
    }
}
